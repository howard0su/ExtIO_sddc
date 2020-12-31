#ifndef _HTFIR4H
#define _HTFIR4H

// fir lowpass real 1.8M
float FIR4[1025] = {
    0.000000037310,
    0.000000051748,
    0.000000067043,
    0.000000082484,
    0.000000097240,
    0.000000110384,
    0.000000120927,
    0.000000127858,
    0.000000130197,
    0.000000127038,
    0.000000117610,
    0.000000101325,
    0.000000077835,
    0.000000047073,
    0.000000009294,
   -0.000000034896,
   -0.000000084528,
   -0.000000138264,
   -0.000000194413,
   -0.000000250965,
   -0.000000305641,
   -0.000000355953,
   -0.000000399294,
   -0.000000433027,
   -0.000000454598,
   -0.000000461648,
   -0.000000452130,
   -0.000000424432,
   -0.000000377484,
   -0.000000310862,
   -0.000000224870,
   -0.000000120606,
    0.000000000000,
    0.000000134180,
    0.000000278351,
    0.000000428175,
    0.000000578651,
    0.000000724251,
    0.000000859074,
    0.000000977045,
    0.000001072125,
    0.000001138552,
    0.000001171077,
    0.000001165220,
    0.000001117502,
    0.000001025669,
    0.000000888887,
    0.000000707900,
    0.000000485137,
    0.000000224773,
   -0.000000067274,
   -0.000000383418,
   -0.000000714535,
   -0.000001050176,
   -0.000001378833,
   -0.000001688276,
   -0.000001965938,
   -0.000002199345,
   -0.000002376577,
   -0.000002486744,
   -0.000002520463,
   -0.000002470311,
   -0.000002331253,
   -0.000002101002,
   -0.000001780319,
   -0.000001373217,
   -0.000000887063,
   -0.000000332574,
    0.000000276318,
    0.000000922717,
    0.000001587147,
    0.000002248051,
    0.000002882399,
    0.000003466398,
    0.000003976273,
    0.000004389107,
    0.000004683705,
    0.000004841461,
    0.000004847191,
    0.000004689901,
    0.000004363464,
    0.000003867161,
    0.000003206085,
    0.000002391348,
    0.000001440106,
    0.000000375365,
   -0.000000774429,
   -0.000001976012,
   -0.000003192142,
   -0.000004382624,
   -0.000005505505,
   -0.000006518414,
   -0.000007379987,
   -0.000008051361,
   -0.000008497668,
   -0.000008689484,
   -0.000008604179,
   -0.000008227114,
   -0.000007552644,
   -0.000006584856,
   -0.000005338031,
   -0.000003836771,
   -0.000002115790,
   -0.000000219330,
    0.000001799768,
    0.000003881361,
    0.000005959609,
    0.000007964884,
    0.000009825914,
    0.000011472100,
    0.000012835959,
    0.000013855583,
    0.000014477057,
    0.000014656741,
    0.000014363327,
    0.000013579594,
    0.000012303776,
    0.000010550489,
    0.000008351146,
    0.000005753824,
    0.000002822565,
   -0.000000363909,
   -0.000003714047,
   -0.000007125847,
   -0.000010489725,
   -0.000013691785,
   -0.000016617414,
   -0.000019155085,
   -0.000021200258,
   -0.000022659253,
   -0.000023452953,
   -0.000023520209,
   -0.000022820818,
   -0.000021337947,
   -0.000019079896,
   -0.000016081103,
   -0.000012402327,
   -0.000008129955,
   -0.000003374409,
    0.000001732326,
    0.000007040019,
    0.000012384289,
    0.000017591378,
    0.000022483463,
    0.000026884370,
    0.000030625513,
    0.000033551855,
    0.000035527717,
    0.000036442210,
    0.000036214104,
    0.000034795934,
    0.000032177184,
    0.000028386380,
    0.000023491985,
    0.000017602011,
    0.000010862292,
    0.000003453415,
   -0.000004413632,
   -0.000012503037,
   -0.000020560809,
   -0.000028322337,
   -0.000035520641,
   -0.000041895072,
   -0.000047200197,
   -0.000051214577,
   -0.000053749140,
   -0.000054654854,
   -0.000053829417,
   -0.000051222691,
   -0.000046840655,
   -0.000040747665,
   -0.000033066896,
   -0.000023978849,
   -0.000013717904,
   -0.000002566947,
    0.000009149837,
    0.000021075840,
    0.000032832353,
    0.000044030055,
    0.000054281336,
    0.000063213082,
    0.000070479519,
    0.000075774687,
    0.000078844127,
    0.000079495358,
    0.000077606738,
    0.000073134374,
    0.000066116744,
    0.000056676810,
    0.000045021438,
    0.000031438038,
    0.000016288427,
   -0.000000000000,
   -0.000016945603,
   -0.000034026059,
   -0.000050693798,
   -0.000066392881,
   -0.000080576810,
   -0.000092726736,
   -0.000102369468,
   -0.000109094690,
   -0.000112570795,
   -0.000112558745,
   -0.000108923446,
   -0.000101642155,
   -0.000090809535,
   -0.000076639070,
   -0.000059460643,
   -0.000039714223,
   -0.000017939717,
    0.000005236825,
    0.000029120334,
    0.000052966737,
    0.000076005319,
    0.000097462783,
    0.000116588283,
    0.000132678649,
    0.000145102983,
    0.000153325797,
    0.000156927894,
    0.000155624209,
    0.000149277935,
    0.000137910329,
    0.000121705725,
    0.000101011420,
    0.000076332255,
    0.000048319871,
    0.000017756818,
   -0.000014464164,
   -0.000047365168,
   -0.000079911798,
   -0.000111044685,
   -0.000139712914,
   -0.000164908342,
   -0.000185699717,
   -0.000201265483,
   -0.000210924148,
   -0.000214161162,
   -0.000210651287,
   -0.000200275601,
   -0.000183132377,
   -0.000159541304,
   -0.000130040656,
   -0.000095377292,
   -0.000056489560,
   -0.000014483414,
    0.000029397682,
    0.000073808320,
    0.000117341183,
    0.000158570419,
    0.000196097045,
    0.000228594966,
    0.000254856161,
    0.000273833515,
    0.000284679848,
    0.000286781743,
    0.000279786927,
    0.000263624072,
    0.000238514181,
    0.000204972871,
    0.000163803225,
    0.000116079127,
    0.000063119321,
    0.000006452738,
   -0.000052224060,
   -0.000111096185,
   -0.000168285103,
   -0.000221907088,
   -0.000270133666,
   -0.000311252166,
   -0.000343724427,
   -0.000366241694,
   -0.000377773822,
   -0.000377611019,
   -0.000365396549,
   -0.000341149067,
   -0.000305273542,
   -0.000258560072,
   -0.000202170259,
   -0.000137611213,
   -0.000066697640,
    0.000008497112,
    0.000085699811,
    0.000162504289,
    0.000236444684,
    0.000305072781,
    0.000366037106,
    0.000417161250,
    0.000456518897,
    0.000482503034,
    0.000493886938,
    0.000489874744,
    0.000470139655,
    0.000434848203,
    0.000384669377,
    0.000320767878,
    0.000244781268,
    0.000158781266,
    0.000065219995,
   -0.000033137533,
   -0.000133292922,
   -0.000232103672,
   -0.000326379639,
   -0.000412983789,
   -0.000488934128,
   -0.000551503568,
   -0.000598314458,
   -0.000627424606,
   -0.000637401771,
   -0.000627383939,
   -0.000597123009,
   -0.000547010063,
   -0.000478080865,
   -0.000392000874,
   -0.000291029672,
   -0.000177965392,
   -0.000056070349,
    0.000071020247,
    0.000199404044,
    0.000325028771,
    0.000443817508,
    0.000551798190,
    0.000645233337,
    0.000720745841,
    0.000775436694,
    0.000806990658,
    0.000813766169,
    0.000794866176,
    0.000750187125,
    0.000680443930,
    0.000587169490,
    0.000472688067,
    0.000340062685,
    0.000193017523,
    0.000035837110,
   -0.000126755071,
   -0.000289735264,
   -0.000447931417,
   -0.000596183976,
   -0.000729510584,
   -0.000843269553,
   -0.000933316834,
   -0.000996151327,
   -0.001029043576,
   -0.001030143307,
   -0.000998561820,
   -0.000934425945,
   -0.000838901089,
   -0.000714181827,
   -0.000563449483,
   -0.000390797177,
   -0.000201123875,
    0.000000000000,
    0.000206491868,
    0.000411936782,
    0.000609782529,
    0.000793544229,
    0.000957012190,
    0.001094456469,
    0.001200821582,
    0.001271904888,
    0.001304512574,
    0.001296587692,
    0.001247305460,
    0.001157131939,
    0.001027843283,
    0.000862503914,
    0.000665403255,
    0.000441951947,
    0.000198539781,
   -0.000057641122,
   -0.000318803214,
   -0.000576794702,
   -0.000823348333,
   -0.001050340349,
   -0.001250051685,
   -0.001415423197,
   -0.001540296681,
   -0.001619633706,
   -0.001649704742,
   -0.001628241847,
   -0.001554549133,
   -0.001429566424,
   -0.001255882872,
   -0.001037698813,
   -0.000780735692,
   -0.000492095583,
   -0.000180073387,
    0.000146073582,
    0.000476392478,
    0.000800530816,
    0.001108052803,
    0.001388766694,
    0.001633053141,
    0.001832184234,
    0.001978622957,
    0.002066293110,
    0.002090810454,
    0.002049666778,
    0.001942359865,
    0.001770463850,
    0.001537636177,
    0.001249559256,
    0.000913816910,
    0.000539707754,
    0.000137999653,
   -0.000279368605,
   -0.000699630525,
   -0.001109570459,
   -0.001495926627,
   -0.001845806663,
   -0.002147103061,
   -0.002388895528,
   -0.002561827360,
   -0.002658443390,
   -0.002673477921,
   -0.002604082315,
   -0.002449983507,
   -0.002213566583,
   -0.001899876790,
   -0.001516538653,
   -0.001073592415,
   -0.000583250566,
   -0.000059579757,
    0.000481884142,
    0.001024577831,
    0.001551397149,
    0.002045214696,
    0.002489413401,
    0.002868420062,
    0.003168222414,
    0.003376853351,
    0.003484826465,
    0.003485508110,
    0.003375412727,
    0.003154410131,
    0.002825835814,
    0.002396498024,
    0.001876578318,
    0.001279425448,
    0.000621245626,
   -0.000079304546,
   -0.000801613071,
   -0.001523683194,
   -0.002222764713,
   -0.002876028791,
   -0.003461267272,
   -0.003957596224,
   -0.004346142721,
   -0.004610693750,
   -0.004738286648,
   -0.004719721592,
   -0.004549978392,
   -0.004228522149,
   -0.003759485128,
   -0.003151715467,
   -0.002418686956,
   -0.001578267977,
   -0.000652351767,
    0.000333645800,
    0.001351410676,
    0.002370463324,
    0.003358982053,
    0.004284696396,
    0.005115827255,
    0.005822048624,
    0.006375444310,
    0.006751432498,
    0.006929631139,
    0.006894638036,
    0.006636701181,
    0.006152257244,
    0.005444319207,
    0.004522697763,
    0.003404045267,
    0.002111715595,
    0.000675438111,
   -0.000869191037,
   -0.002481392065,
   -0.004116046004,
   -0.005724682651,
   -0.007256589973,
   -0.008660019145,
   -0.009883456303,
   -0.010876929654,
   -0.011593319004,
   -0.011989633979,
   -0.012028227362,
   -0.011677910987,
   -0.010914943538,
   -0.009723862348,
   -0.008098134819,
   -0.006040609332,
   -0.003563750295,
   -0.000689647298,
    0.002550206062,
    0.006115362285,
    0.009957091811,
    0.014019263612,
    0.018239416174,
    0.022549995428,
    0.026879731726,
    0.031155124183,
    0.035301997690,
    0.039247095736,
    0.042919671036,
    0.046253035643,
    0.049186033042,
    0.051664396381,
    0.053641959651,
    0.055081692127,
    0.055956530635,
    0.056249989140,
    0.055956530635,
    0.055081692127,
    0.053641959651,
    0.051664396381,
    0.049186033042,
    0.046253035643,
    0.042919671036,
    0.039247095736,
    0.035301997690,
    0.031155124183,
    0.026879731726,
    0.022549995428,
    0.018239416174,
    0.014019263612,
    0.009957091811,
    0.006115362285,
    0.002550206062,
   -0.000689647298,
   -0.003563750295,
   -0.006040609332,
   -0.008098134819,
   -0.009723862348,
   -0.010914943538,
   -0.011677910987,
   -0.012028227362,
   -0.011989633979,
   -0.011593319004,
   -0.010876929654,
   -0.009883456303,
   -0.008660019145,
   -0.007256589973,
   -0.005724682651,
   -0.004116046004,
   -0.002481392065,
   -0.000869191037,
    0.000675438111,
    0.002111715595,
    0.003404045267,
    0.004522697763,
    0.005444319207,
    0.006152257244,
    0.006636701181,
    0.006894638036,
    0.006929631139,
    0.006751432498,
    0.006375444310,
    0.005822048624,
    0.005115827255,
    0.004284696396,
    0.003358982053,
    0.002370463324,
    0.001351410676,
    0.000333645800,
   -0.000652351767,
   -0.001578267977,
   -0.002418686956,
   -0.003151715467,
   -0.003759485128,
   -0.004228522149,
   -0.004549978392,
   -0.004719721592,
   -0.004738286648,
   -0.004610693750,
   -0.004346142721,
   -0.003957596224,
   -0.003461267272,
   -0.002876028791,
   -0.002222764713,
   -0.001523683194,
   -0.000801613071,
   -0.000079304546,
    0.000621245626,
    0.001279425448,
    0.001876578318,
    0.002396498024,
    0.002825835814,
    0.003154410131,
    0.003375412727,
    0.003485508110,
    0.003484826465,
    0.003376853351,
    0.003168222414,
    0.002868420062,
    0.002489413401,
    0.002045214696,
    0.001551397149,
    0.001024577831,
    0.000481884142,
   -0.000059579757,
   -0.000583250566,
   -0.001073592415,
   -0.001516538653,
   -0.001899876790,
   -0.002213566583,
   -0.002449983507,
   -0.002604082315,
   -0.002673477921,
   -0.002658443390,
   -0.002561827360,
   -0.002388895528,
   -0.002147103061,
   -0.001845806663,
   -0.001495926627,
   -0.001109570459,
   -0.000699630525,
   -0.000279368605,
    0.000137999653,
    0.000539707754,
    0.000913816910,
    0.001249559256,
    0.001537636177,
    0.001770463850,
    0.001942359865,
    0.002049666778,
    0.002090810454,
    0.002066293110,
    0.001978622957,
    0.001832184234,
    0.001633053141,
    0.001388766694,
    0.001108052803,
    0.000800530816,
    0.000476392478,
    0.000146073582,
   -0.000180073387,
   -0.000492095583,
   -0.000780735692,
   -0.001037698813,
   -0.001255882872,
   -0.001429566424,
   -0.001554549133,
   -0.001628241847,
   -0.001649704742,
   -0.001619633706,
   -0.001540296681,
   -0.001415423197,
   -0.001250051685,
   -0.001050340349,
   -0.000823348333,
   -0.000576794702,
   -0.000318803214,
   -0.000057641122,
    0.000198539781,
    0.000441951947,
    0.000665403255,
    0.000862503914,
    0.001027843283,
    0.001157131939,
    0.001247305460,
    0.001296587692,
    0.001304512574,
    0.001271904888,
    0.001200821582,
    0.001094456469,
    0.000957012190,
    0.000793544229,
    0.000609782529,
    0.000411936782,
    0.000206491868,
    0.000000000000,
   -0.000201123875,
   -0.000390797177,
   -0.000563449483,
   -0.000714181827,
   -0.000838901089,
   -0.000934425945,
   -0.000998561820,
   -0.001030143307,
   -0.001029043576,
   -0.000996151327,
   -0.000933316834,
   -0.000843269553,
   -0.000729510584,
   -0.000596183976,
   -0.000447931417,
   -0.000289735264,
   -0.000126755071,
    0.000035837110,
    0.000193017523,
    0.000340062685,
    0.000472688067,
    0.000587169490,
    0.000680443930,
    0.000750187125,
    0.000794866176,
    0.000813766169,
    0.000806990658,
    0.000775436694,
    0.000720745841,
    0.000645233337,
    0.000551798190,
    0.000443817508,
    0.000325028771,
    0.000199404044,
    0.000071020247,
   -0.000056070349,
   -0.000177965392,
   -0.000291029672,
   -0.000392000874,
   -0.000478080865,
   -0.000547010063,
   -0.000597123009,
   -0.000627383939,
   -0.000637401771,
   -0.000627424606,
   -0.000598314458,
   -0.000551503568,
   -0.000488934128,
   -0.000412983789,
   -0.000326379639,
   -0.000232103672,
   -0.000133292922,
   -0.000033137533,
    0.000065219995,
    0.000158781266,
    0.000244781268,
    0.000320767878,
    0.000384669377,
    0.000434848203,
    0.000470139655,
    0.000489874744,
    0.000493886938,
    0.000482503034,
    0.000456518897,
    0.000417161250,
    0.000366037106,
    0.000305072781,
    0.000236444684,
    0.000162504289,
    0.000085699811,
    0.000008497112,
   -0.000066697640,
   -0.000137611213,
   -0.000202170259,
   -0.000258560072,
   -0.000305273542,
   -0.000341149067,
   -0.000365396549,
   -0.000377611019,
   -0.000377773822,
   -0.000366241694,
   -0.000343724427,
   -0.000311252166,
   -0.000270133666,
   -0.000221907088,
   -0.000168285103,
   -0.000111096185,
   -0.000052224060,
    0.000006452738,
    0.000063119321,
    0.000116079127,
    0.000163803225,
    0.000204972871,
    0.000238514181,
    0.000263624072,
    0.000279786927,
    0.000286781743,
    0.000284679848,
    0.000273833515,
    0.000254856161,
    0.000228594966,
    0.000196097045,
    0.000158570419,
    0.000117341183,
    0.000073808320,
    0.000029397682,
   -0.000014483414,
   -0.000056489560,
   -0.000095377292,
   -0.000130040656,
   -0.000159541304,
   -0.000183132377,
   -0.000200275601,
   -0.000210651287,
   -0.000214161162,
   -0.000210924148,
   -0.000201265483,
   -0.000185699717,
   -0.000164908342,
   -0.000139712914,
   -0.000111044685,
   -0.000079911798,
   -0.000047365168,
   -0.000014464164,
    0.000017756818,
    0.000048319871,
    0.000076332255,
    0.000101011420,
    0.000121705725,
    0.000137910329,
    0.000149277935,
    0.000155624209,
    0.000156927894,
    0.000153325797,
    0.000145102983,
    0.000132678649,
    0.000116588283,
    0.000097462783,
    0.000076005319,
    0.000052966737,
    0.000029120334,
    0.000005236825,
   -0.000017939717,
   -0.000039714223,
   -0.000059460643,
   -0.000076639070,
   -0.000090809535,
   -0.000101642155,
   -0.000108923446,
   -0.000112558745,
   -0.000112570795,
   -0.000109094690,
   -0.000102369468,
   -0.000092726736,
   -0.000080576810,
   -0.000066392881,
   -0.000050693798,
   -0.000034026059,
   -0.000016945603,
   -0.000000000000,
    0.000016288427,
    0.000031438038,
    0.000045021438,
    0.000056676810,
    0.000066116744,
    0.000073134374,
    0.000077606738,
    0.000079495358,
    0.000078844127,
    0.000075774687,
    0.000070479519,
    0.000063213082,
    0.000054281336,
    0.000044030055,
    0.000032832353,
    0.000021075840,
    0.000009149837,
   -0.000002566947,
   -0.000013717904,
   -0.000023978849,
   -0.000033066896,
   -0.000040747665,
   -0.000046840655,
   -0.000051222691,
   -0.000053829417,
   -0.000054654854,
   -0.000053749140,
   -0.000051214577,
   -0.000047200197,
   -0.000041895072,
   -0.000035520641,
   -0.000028322337,
   -0.000020560809,
   -0.000012503037,
   -0.000004413632,
    0.000003453415,
    0.000010862292,
    0.000017602011,
    0.000023491985,
    0.000028386380,
    0.000032177184,
    0.000034795934,
    0.000036214104,
    0.000036442210,
    0.000035527717,
    0.000033551855,
    0.000030625513,
    0.000026884370,
    0.000022483463,
    0.000017591378,
    0.000012384289,
    0.000007040019,
    0.000001732326,
   -0.000003374409,
   -0.000008129955,
   -0.000012402327,
   -0.000016081103,
   -0.000019079896,
   -0.000021337947,
   -0.000022820818,
   -0.000023520209,
   -0.000023452953,
   -0.000022659253,
   -0.000021200258,
   -0.000019155085,
   -0.000016617414,
   -0.000013691785,
   -0.000010489725,
   -0.000007125847,
   -0.000003714047,
   -0.000000363909,
    0.000002822565,
    0.000005753824,
    0.000008351146,
    0.000010550489,
    0.000012303776,
    0.000013579594,
    0.000014363327,
    0.000014656741,
    0.000014477057,
    0.000013855583,
    0.000012835959,
    0.000011472100,
    0.000009825914,
    0.000007964884,
    0.000005959609,
    0.000003881361,
    0.000001799768,
   -0.000000219330,
   -0.000002115790,
   -0.000003836771,
   -0.000005338031,
   -0.000006584856,
   -0.000007552644,
   -0.000008227114,
   -0.000008604179,
   -0.000008689484,
   -0.000008497668,
   -0.000008051361,
   -0.000007379987,
   -0.000006518414,
   -0.000005505505,
   -0.000004382624,
   -0.000003192142,
   -0.000001976012,
   -0.000000774429,
    0.000000375365,
    0.000001440106,
    0.000002391348,
    0.000003206085,
    0.000003867161,
    0.000004363464,
    0.000004689901,
    0.000004847191,
    0.000004841461,
    0.000004683705,
    0.000004389107,
    0.000003976273,
    0.000003466398,
    0.000002882399,
    0.000002248051,
    0.000001587147,
    0.000000922717,
    0.000000276318,
   -0.000000332574,
   -0.000000887063,
   -0.000001373217,
   -0.000001780319,
   -0.000002101002,
   -0.000002331253,
   -0.000002470311,
   -0.000002520463,
   -0.000002486744,
   -0.000002376577,
   -0.000002199345,
   -0.000001965938,
   -0.000001688276,
   -0.000001378833,
   -0.000001050176,
   -0.000000714535,
   -0.000000383418,
   -0.000000067274,
    0.000000224773,
    0.000000485137,
    0.000000707900,
    0.000000888887,
    0.000001025669,
    0.000001117502,
    0.000001165220,
    0.000001171077,
    0.000001138552,
    0.000001072125,
    0.000000977045,
    0.000000859074,
    0.000000724251,
    0.000000578651,
    0.000000428175,
    0.000000278351,
    0.000000134180,
    0.000000000000,
   -0.000000120606,
   -0.000000224870,
   -0.000000310862,
   -0.000000377484,
   -0.000000424432,
   -0.000000452130,
   -0.000000461648,
   -0.000000454598,
   -0.000000433027,
   -0.000000399294,
   -0.000000355953,
   -0.000000305641,
   -0.000000250965,
   -0.000000194413,
   -0.000000138264,
   -0.000000084528,
   -0.000000034896,
    0.000000009294,
    0.000000047073,
    0.000000077835,
    0.000000101325,
    0.000000117610,
    0.000000127038,
    0.000000130197,
    0.000000127858,
    0.000000120927,
    0.000000110384,
    0.000000097240,
    0.000000082484,
    0.000000067043,
    0.000000051748,
    0.000000037310
};
#endif