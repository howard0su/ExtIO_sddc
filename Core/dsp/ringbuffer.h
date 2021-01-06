#pragma once

#include <mutex>
#include <condition_variable>

const int default_count = 1024;
#define ALIGN (64)

template<typename T> class ringbuffer {
    typedef T* TPtr;

public:
    ringbuffer(int count = default_count) :
        max_count(count),
        read_index(0),
        write_index(0)
    {
        block_size = 0;
        buffers = new TPtr[max_count];
        buffers[0] = nullptr;
    }

    ~ringbuffer()
    {
        if (buffers[0])
            delete[] buffers[0];

        delete[] buffers;
    }

    void setBlockSize(int size)
    {
        if (block_size != size)
        {
            block_size = size;

            if (buffers[0])
                delete[] buffers[0];

            int aligned_block_size = (block_size + ALIGN - 1) & (~(ALIGN - 1));

            auto data = new T[max_count * aligned_block_size];

            for (int i = 0; i < max_count; ++i)
            {
                buffers[i] = &data[i * aligned_block_size];
            }
        }
    }

    T* peekWritePtr(int offset)
    {
        return buffers[(write_index + offset) % max_count];
    }

    T* getWritePtr()
    {
        // if there is still space
        if ((write_index + 1) % max_count == read_index)
        {
            std::unique_lock<std::mutex> lk(mutex);
            nonfullCV.wait(lk, [this] {
                return (write_index + 1) % max_count != read_index;
            });
        }

        return buffers[(write_index) % max_count];
    }

    void WriteDone()
    {
        std::unique_lock<std::mutex> lk(mutex);
        if (read_index == write_index)
        {
            write_index = (write_index + 1) % max_count;
            nonemptyCV.notify_all();
        }
        else
        {
            write_index = (write_index + 1) % max_count;
        }
    }

    const T* getReadPtr()
    {
        // if not empty
        if (read_index == write_index)
        {
            std::unique_lock<std::mutex> lk(mutex);
            nonemptyCV.wait(lk, [this] {
                return read_index != write_index;
            });
        }

        return buffers[read_index];
    }

    void ReadDone()
    {
        std::unique_lock<std::mutex> lk(mutex);
        if ((write_index + 1) % max_count == read_index)
        {
            read_index = (read_index + 1) % max_count;
            nonfullCV.notify_all();
        }
        else
        {
            read_index = (read_index + 1) % max_count;
        }
    }

    int getBlockSize() const { return block_size; }

    void Stop()
    {
        read_index = 0;
        write_index = max_count / 2;
        nonfullCV.notify_all();
        nonemptyCV.notify_all();
    }

private:
    int max_count;
    int block_size;

    TPtr* buffers;

    int read_index;
    int write_index;

    std::mutex mutex;
    std::condition_variable nonemptyCV;
    std::condition_variable nonfullCV;
};