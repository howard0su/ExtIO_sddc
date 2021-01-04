#pragma once

#include <mutex>
#include <condition_variable>

const int default_count = 1024;

template<typename T> class ringbuffer {
    typedef T* TPtr;

public:
    ringbuffer(int size, int count) :
        max_count(count),
        block_size(size),
        read_index(0),
        write_index(0)
    {
        buffers = new TPtr[max_count];

        for (int i = 0; i < max_count; ++i)
        {
            buffers[i] = new T[size];
        }
    }

    ~ringbuffer()
    {
        for (int i = 0; i < max_count; ++i)
        {
            delete[] buffers[i];
        }

        delete[] buffers;
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
        read_index = (read_index + 1) % max_count;

        nonfullCV.notify_all();
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