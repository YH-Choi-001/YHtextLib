#ifndef YHTEXTLIB_H
#define YHTEXTLIB_H __DATE__ ", " __TIME__

#include <stddef.h> // for definition of NULL
#include <math.h> // for definition of NAN and INFINITY detection

#include "../YHtypeLib/YHtypeLib.h"


#define JOIN_TOKENS(LHS,RHS) LHS##RHS
#define TO_STRING(X) #X

#define ASCII_CHECK() ( \
    '\0' == 0x00 \
    && '\a' == 0x07 \
    && '\b' == 0x08 \
    && '\t' == 0x09 \
    && '\n' == 0x0A \
    && '\v' == 0x0B \
    && '\f' == 0x0C \
    && '\r' == 0x0D \
    && '\e' == 0x1B \
    \
    && ' ' == 0x20 \
    && '!' == 0x21 \
    && '\"' == 0x22 \
    && '#' == 0x23 \
    && '$' == 0x24 \
    && '%' == 0x25 \
    && '&' == 0x26 \
    && '\'' == 0x27 \
    && '(' == 0x28 \
    && ')' == 0x29 \
    && '*' == 0x2A \
    && '+' == 0x2B \
    && ',' == 0x2C \
    && '-' == 0x2D \
    && '.' == 0x2E \
    && '/' == 0x2F \
    \
    && '0' == 0x30 \
    && '1' == 0x31 \
    && '2' == 0x32 \
    && '3' == 0x33 \
    && '4' == 0x34 \
    && '5' == 0x35 \
    && '6' == 0x36 \
    && '7' == 0x37 \
    && '8' == 0x38 \
    && '9' == 0x39 \
    \
    && ':' == 0x3A \
    && ';' == 0x3B \
    && '<' == 0x3C \
    && '=' == 0x3D \
    && '>' == 0x3E \
    && '?' == 0x3F \
    && '\?' == 0x3F \
    && '@' == 0x40 \
    \
    && 'A' == 0x41 \
    && 'B' == 0x42 \
    && 'C' == 0x43 \
    && 'D' == 0x44 \
    && 'E' == 0x45 \
    && 'F' == 0x46 \
    && 'G' == 0x47 \
    && 'H' == 0x48 \
    && 'I' == 0x49 \
    && 'J' == 0x4A \
    && 'K' == 0x4B \
    && 'L' == 0x4C \
    && 'M' == 0x4D \
    && 'N' == 0x4E \
    && 'O' == 0x4F \
    && 'P' == 0x50 \
    && 'Q' == 0x51 \
    && 'R' == 0x52 \
    && 'S' == 0x53 \
    && 'T' == 0x54 \
    && 'U' == 0x55 \
    && 'V' == 0x56 \
    && 'W' == 0x57 \
    && 'X' == 0x58 \
    && 'Y' == 0x59 \
    && 'Z' == 0x5A \
    \
    && '[' == 0x5B \
    && '\\' == 0x5C \
    && ']' == 0x5D \
    && '^' == 0x5E \
    && '_' == 0x5F \
    && '`' == 0x60 \
    \
    && 'a' == 0x61 \
    && 'b' == 0x62 \
    && 'c' == 0x63 \
    && 'd' == 0x64 \
    && 'e' == 0x65 \
    && 'f' == 0x66 \
    && 'g' == 0x67 \
    && 'h' == 0x68 \
    && 'i' == 0x69 \
    && 'j' == 0x6A \
    && 'k' == 0x6B \
    && 'l' == 0x6C \
    && 'm' == 0x6D \
    && 'n' == 0x6E \
    && 'o' == 0x6F \
    && 'p' == 0x70 \
    && 'q' == 0x71 \
    && 'r' == 0x72 \
    && 's' == 0x73 \
    && 't' == 0x74 \
    && 'u' == 0x75 \
    && 'v' == 0x76 \
    && 'w' == 0x77 \
    && 'x' == 0x78 \
    && 'y' == 0x79 \
    && 'z' == 0x7A \
    \
    && '{' == 0x7B \
    && '|' == 0x7C \
    && '}' == 0x7D \
    && '~' == 0x7E \
)

#if (ASCII_CHECK())
#define ASCII_BASED_CHARSET 1
#else
#define ASCII_BASED_CHARSET 0
#endif // verify if local machine uses ascii-based characters

// WARNING! THIS MACRO DOES NOT SUPPORT 0 ARGUMENTS
#define COUNT_ARGS(...) COUNT_ARGS_(__VA_ARGS__,REVERS_COUNT_ARGS_())
#define COUNT_ARGS_(...) COUNT_ARGS__(__VA_ARGS__)
#define COUNT_ARGS__(                                                     \
    _0001, _0002, _0003, _0004, _0005, _0006, _0007, _0008, _0009, _0010, \
    _0011, _0012, _0013, _0014, _0015, _0016, _0017, _0018, _0019, _0020, \
    _0021, _0022, _0023, _0024, _0025, _0026, _0027, _0028, _0029, _0030, \
    _0031, _0032, _0033, _0034, _0035, _0036, _0037, _0038, _0039, _0040, \
    _0041, _0042, _0043, _0044, _0045, _0046, _0047, _0048, _0049, _0050, \
    _0051, _0052, _0053, _0054, _0055, _0056, _0057, _0058, _0059, _0060, \
    _0061, _0062, _0063, _0064, _0065, _0066, _0067, _0068, _0069, _0070, \
    _0071, _0072, _0073, _0074, _0075, _0076, _0077, _0078, _0079, _0080, \
    _0081, _0082, _0083, _0084, _0085, _0086, _0087, _0088, _0089, _0090, \
    _0091, _0092, _0093, _0094, _0095, _0096, _0097, _0098, _0099, _0100, \
    _0101, _0102, _0103, _0104, _0105, _0106, _0107, _0108, _0109, _0110, \
    _0111, _0112, _0113, _0114, _0115, _0116, _0117, _0118, _0119, _0120, \
    _0121, _0122, _0123, _0124, _0125, _0126, _0127, _0128, _0129, _0130, \
    _0131, _0132, _0133, _0134, _0135, _0136, _0137, _0138, _0139, _0140, \
    _0141, _0142, _0143, _0144, _0145, _0146, _0147, _0148, _0149, _0150, \
    _0151, _0152, _0153, _0154, _0155, _0156, _0157, _0158, _0159, _0160, \
    _0161, _0162, _0163, _0164, _0165, _0166, _0167, _0168, _0169, _0170, \
    _0171, _0172, _0173, _0174, _0175, _0176, _0177, _0178, _0179, _0180, \
    _0181, _0182, _0183, _0184, _0185, _0186, _0187, _0188, _0189, _0190, \
    _0191, _0192, _0193, _0194, _0195, _0196, _0197, _0198, _0199, _0200, \
    _0201, _0202, _0203, _0204, _0205, _0206, _0207, _0208, _0209, _0210, \
    _0211, _0212, _0213, _0214, _0215, _0216, _0217, _0218, _0219, _0220, \
    _0221, _0222, _0223, _0224, _0225, _0226, _0227, _0228, _0229, _0230, \
    _0231, _0232, _0233, _0234, _0235, _0236, _0237, _0238, _0239, _0240, \
    _0241, _0242, _0243, _0244, _0245, _0246, _0247, _0248, _0249, _0250, \
    _0251, _0252, _0253, _0254, _0255, _0256, _0257, _0258, _0259, _0260, \
    _0261, _0262, _0263, _0264, _0265, _0266, _0267, _0268, _0269, _0270, \
    _0271, _0272, _0273, _0274, _0275, _0276, _0277, _0278, _0279, _0280, \
    _0281, _0282, _0283, _0284, _0285, _0286, _0287, _0288, _0289, _0290, \
    _0291, _0292, _0293, _0294, _0295, _0296, _0297, _0298, _0299, _0300, \
    _0301, _0302, _0303, _0304, _0305, _0306, _0307, _0308, _0309, _0310, \
    _0311, _0312, _0313, _0314, _0315, _0316, _0317, _0318, _0319, _0320, \
    _0321, _0322, _0323, _0324, _0325, _0326, _0327, _0328, _0329, _0330, \
    _0331, _0332, _0333, _0334, _0335, _0336, _0337, _0338, _0339, _0340, \
    _0341, _0342, _0343, _0344, _0345, _0346, _0347, _0348, _0349, _0350, \
    _0351, _0352, _0353, _0354, _0355, _0356, _0357, _0358, _0359, _0360, \
    _0361, _0362, _0363, _0364, _0365, _0366, _0367, _0368, _0369, _0370, \
    _0371, _0372, _0373, _0374, _0375, _0376, _0377, _0378, _0379, _0380, \
    _0381, _0382, _0383, _0384, _0385, _0386, _0387, _0388, _0389, _0390, \
    _0391, _0392, _0393, _0394, _0395, _0396, _0397, _0398, _0399, _0400, \
    _0401, _0402, _0403, _0404, _0405, _0406, _0407, _0408, _0409, _0410, \
    _0411, _0412, _0413, _0414, _0415, _0416, _0417, _0418, _0419, _0420, \
    _0421, _0422, _0423, _0424, _0425, _0426, _0427, _0428, _0429, _0430, \
    _0431, _0432, _0433, _0434, _0435, _0436, _0437, _0438, _0439, _0440, \
    _0441, _0442, _0443, _0444, _0445, _0446, _0447, _0448, _0449, _0450, \
    _0451, _0452, _0453, _0454, _0455, _0456, _0457, _0458, _0459, _0460, \
    _0461, _0462, _0463, _0464, _0465, _0466, _0467, _0468, _0469, _0470, \
    _0471, _0472, _0473, _0474, _0475, _0476, _0477, _0478, _0479, _0480, \
    _0481, _0482, _0483, _0484, _0485, _0486, _0487, _0488, _0489, _0490, \
    _0491, _0492, _0493, _0494, _0495, _0496, _0497, _0498, _0499, _0500, \
    _0501, _0502, _0503, _0504, _0505, _0506, _0507, _0508, _0509, _0510, \
    _0511, _0512, _0513, _0514, _0515, _0516, _0517, _0518, _0519, _0520, \
    _0521, _0522, _0523, _0524, _0525, _0526, _0527, _0528, _0529, _0530, \
    _0531, _0532, _0533, _0534, _0535, _0536, _0537, _0538, _0539, _0540, \
    _0541, _0542, _0543, _0544, _0545, _0546, _0547, _0548, _0549, _0550, \
    _0551, _0552, _0553, _0554, _0555, _0556, _0557, _0558, _0559, _0560, \
    _0561, _0562, _0563, _0564, _0565, _0566, _0567, _0568, _0569, _0570, \
    _0571, _0572, _0573, _0574, _0575, _0576, _0577, _0578, _0579, _0580, \
    _0581, _0582, _0583, _0584, _0585, _0586, _0587, _0588, _0589, _0590, \
    _0591, _0592, _0593, _0594, _0595, _0596, _0597, _0598, _0599, _0600, \
    _0601, _0602, _0603, _0604, _0605, _0606, _0607, _0608, _0609, _0610, \
    _0611, _0612, _0613, _0614, _0615, _0616, _0617, _0618, _0619, _0620, \
    _0621, _0622, _0623, _0624, _0625, _0626, _0627, _0628, _0629, _0630, \
    _0631, _0632, _0633, _0634, _0635, _0636, _0637, _0638, _0639, _0640, \
    _0641, _0642, _0643, _0644, _0645, _0646, _0647, _0648, _0649, _0650, \
    _0651, _0652, _0653, _0654, _0655, _0656, _0657, _0658, _0659, _0660, \
    _0661, _0662, _0663, _0664, _0665, _0666, _0667, _0668, _0669, _0670, \
    _0671, _0672, _0673, _0674, _0675, _0676, _0677, _0678, _0679, _0680, \
    _0681, _0682, _0683, _0684, _0685, _0686, _0687, _0688, _0689, _0690, \
    _0691, _0692, _0693, _0694, _0695, _0696, _0697, _0698, _0699, _0700, \
    _0701, _0702, _0703, _0704, _0705, _0706, _0707, _0708, _0709, _0710, \
    _0711, _0712, _0713, _0714, _0715, _0716, _0717, _0718, _0719, _0720, \
    _0721, _0722, _0723, _0724, _0725, _0726, _0727, _0728, _0729, _0730, \
    _0731, _0732, _0733, _0734, _0735, _0736, _0737, _0738, _0739, _0740, \
    _0741, _0742, _0743, _0744, _0745, _0746, _0747, _0748, _0749, _0750, \
    _0751, _0752, _0753, _0754, _0755, _0756, _0757, _0758, _0759, _0760, \
    _0761, _0762, _0763, _0764, _0765, _0766, _0767, _0768, _0769, _0770, \
    _0771, _0772, _0773, _0774, _0775, _0776, _0777, _0778, _0779, _0780, \
    _0781, _0782, _0783, _0784, _0785, _0786, _0787, _0788, _0789, _0790, \
    _0791, _0792, _0793, _0794, _0795, _0796, _0797, _0798, _0799, _0800, \
    _0801, _0802, _0803, _0804, _0805, _0806, _0807, _0808, _0809, _0810, \
    _0811, _0812, _0813, _0814, _0815, _0816, _0817, _0818, _0819, _0820, \
    _0821, _0822, _0823, _0824, _0825, _0826, _0827, _0828, _0829, _0830, \
    _0831, _0832, _0833, _0834, _0835, _0836, _0837, _0838, _0839, _0840, \
    _0841, _0842, _0843, _0844, _0845, _0846, _0847, _0848, _0849, _0850, \
    _0851, _0852, _0853, _0854, _0855, _0856, _0857, _0858, _0859, _0860, \
    _0861, _0862, _0863, _0864, _0865, _0866, _0867, _0868, _0869, _0870, \
    _0871, _0872, _0873, _0874, _0875, _0876, _0877, _0878, _0879, _0880, \
    _0881, _0882, _0883, _0884, _0885, _0886, _0887, _0888, _0889, _0890, \
    _0891, _0892, _0893, _0894, _0895, _0896, _0897, _0898, _0899, _0900, \
    _0901, _0902, _0903, _0904, _0905, _0906, _0907, _0908, _0909, _0910, \
    _0911, _0912, _0913, _0914, _0915, _0916, _0917, _0918, _0919, _0920, \
    _0921, _0922, _0923, _0924, _0925, _0926, _0927, _0928, _0929, _0930, \
    _0931, _0932, _0933, _0934, _0935, _0936, _0937, _0938, _0939, _0940, \
    _0941, _0942, _0943, _0944, _0945, _0946, _0947, _0948, _0949, _0950, \
    _0951, _0952, _0953, _0954, _0955, _0956, _0957, _0958, _0959, _0960, \
    _0961, _0962, _0963, _0964, _0965, _0966, _0967, _0968, _0969, _0970, \
    _0971, _0972, _0973, _0974, _0975, _0976, _0977, _0978, _0979, _0980, \
    _0981, _0982, _0983, _0984, _0985, _0986, _0987, _0988, _0989, _0990, \
    _0991, _0992, _0993, _0994, _0995, _0996, _0997, _0998, _0999, _1000, \
    _1001, _1002, _1003, _1004, _1005, _1006, _1007, _1008, _1009, _1010, \
    _1011, _1012, _1013, _1014, _1015, _1016, _1017, _1018, _1019, _1020, \
    _1021, _1022, _1023, _1024, _NOPQ, ... \
) _NOPQ
#define REVERS_COUNT_ARGS_() \
    1024, 1023, 1022, 1021, 1020, 1019, 1018, 1017, 1016, 1015, \
    1014, 1013, 1012, 1011, 1010, 1009, 1008, 1007, 1006, 1005, \
    1004, 1003, 1002, 1001, 1000,  999,  998,  997,  996,  995, \
     994,  993,  992,  991,  990,  989,  988,  987,  986,  985, \
     984,  983,  982,  981,  980,  979,  978,  977,  976,  975, \
     974,  973,  972,  971,  970,  969,  968,  967,  966,  965, \
     964,  963,  962,  961,  960,  959,  958,  957,  956,  955, \
     954,  953,  952,  951,  950,  949,  948,  947,  946,  945, \
     944,  943,  942,  941,  940,  939,  938,  937,  936,  935, \
     934,  933,  932,  931,  930,  929,  928,  927,  926,  925, \
     924,  923,  922,  921,  920,  919,  918,  917,  916,  915, \
     914,  913,  912,  911,  910,  909,  908,  907,  906,  905, \
     904,  903,  902,  901,  900,  899,  898,  897,  896,  895, \
     894,  893,  892,  891,  890,  889,  888,  887,  886,  885, \
     884,  883,  882,  881,  880,  879,  878,  877,  876,  875, \
     874,  873,  872,  871,  870,  869,  868,  867,  866,  865, \
     864,  863,  862,  861,  860,  859,  858,  857,  856,  855, \
     854,  853,  852,  851,  850,  849,  848,  847,  846,  845, \
     844,  843,  842,  841,  840,  839,  838,  837,  836,  835, \
     834,  833,  832,  831,  830,  829,  828,  827,  826,  825, \
     824,  823,  822,  821,  820,  819,  818,  817,  816,  815, \
     814,  813,  812,  811,  810,  809,  808,  807,  806,  805, \
     804,  803,  802,  801,  800,  799,  798,  797,  796,  795, \
     794,  793,  792,  791,  790,  789,  788,  787,  786,  785, \
     784,  783,  782,  781,  780,  779,  778,  777,  776,  775, \
     774,  773,  772,  771,  770,  769,  768,  767,  766,  765, \
     764,  763,  762,  761,  760,  759,  758,  757,  756,  755, \
     754,  753,  752,  751,  750,  749,  748,  747,  746,  745, \
     744,  743,  742,  741,  740,  739,  738,  737,  736,  735, \
     734,  733,  732,  731,  730,  729,  728,  727,  726,  725, \
     724,  723,  722,  721,  720,  719,  718,  717,  716,  715, \
     714,  713,  712,  711,  710,  709,  708,  707,  706,  705, \
     704,  703,  702,  701,  700,  699,  698,  697,  696,  695, \
     694,  693,  692,  691,  690,  689,  688,  687,  686,  685, \
     684,  683,  682,  681,  680,  679,  678,  677,  676,  675, \
     674,  673,  672,  671,  670,  669,  668,  667,  666,  665, \
     664,  663,  662,  661,  660,  659,  658,  657,  656,  655, \
     654,  653,  652,  651,  650,  649,  648,  647,  646,  645, \
     644,  643,  642,  641,  640,  639,  638,  637,  636,  635, \
     634,  633,  632,  631,  630,  629,  628,  627,  626,  625, \
     624,  623,  622,  621,  620,  619,  618,  617,  616,  615, \
     614,  613,  612,  611,  610,  609,  608,  607,  606,  605, \
     604,  603,  602,  601,  600,  599,  598,  597,  596,  595, \
     594,  593,  592,  591,  590,  589,  588,  587,  586,  585, \
     584,  583,  582,  581,  580,  579,  578,  577,  576,  575, \
     574,  573,  572,  571,  570,  569,  568,  567,  566,  565, \
     564,  563,  562,  561,  560,  559,  558,  557,  556,  555, \
     554,  553,  552,  551,  550,  549,  548,  547,  546,  545, \
     544,  543,  542,  541,  540,  539,  538,  537,  536,  535, \
     534,  533,  532,  531,  530,  529,  528,  527,  526,  525, \
     524,  523,  522,  521,  520,  519,  518,  517,  516,  515, \
     514,  513,  512,  511,  510,  509,  508,  507,  506,  505, \
     504,  503,  502,  501,  500,  499,  498,  497,  496,  495, \
     494,  493,  492,  491,  490,  489,  488,  487,  486,  485, \
     484,  483,  482,  481,  480,  479,  478,  477,  476,  475, \
     474,  473,  472,  471,  470,  469,  468,  467,  466,  465, \
     464,  463,  462,  461,  460,  459,  458,  457,  456,  455, \
     454,  453,  452,  451,  450,  449,  448,  447,  446,  445, \
     444,  443,  442,  441,  440,  439,  438,  437,  436,  435, \
     434,  433,  432,  431,  430,  429,  428,  427,  426,  425, \
     424,  423,  422,  421,  420,  419,  418,  417,  416,  415, \
     414,  413,  412,  411,  410,  409,  408,  407,  406,  405, \
     404,  403,  402,  401,  400,  399,  398,  397,  396,  395, \
     394,  393,  392,  391,  390,  389,  388,  387,  386,  385, \
     384,  383,  382,  381,  380,  379,  378,  377,  376,  375, \
     374,  373,  372,  371,  370,  369,  368,  367,  366,  365, \
     364,  363,  362,  361,  360,  359,  358,  357,  356,  355, \
     354,  353,  352,  351,  350,  349,  348,  347,  346,  345, \
     344,  343,  342,  341,  340,  339,  338,  337,  336,  335, \
     334,  333,  332,  331,  330,  329,  328,  327,  326,  325, \
     324,  323,  322,  321,  320,  319,  318,  317,  316,  315, \
     314,  313,  312,  311,  310,  309,  308,  307,  306,  305, \
     304,  303,  302,  301,  300,  299,  298,  297,  296,  295, \
     294,  293,  292,  291,  290,  289,  288,  287,  286,  285, \
     284,  283,  282,  281,  280,  279,  278,  277,  276,  275, \
     274,  273,  272,  271,  270,  269,  268,  267,  266,  265, \
     264,  263,  262,  261,  260,  259,  258,  257,  256,  255, \
     254,  253,  252,  251,  250,  249,  248,  247,  246,  245, \
     244,  243,  242,  241,  240,  239,  238,  237,  236,  235, \
     234,  233,  232,  231,  230,  229,  228,  227,  226,  225, \
     224,  223,  222,  221,  220,  219,  218,  217,  216,  215, \
     214,  213,  212,  211,  210,  209,  208,  207,  206,  205, \
     204,  203,  202,  201,  200,  199,  198,  197,  196,  195, \
     194,  193,  192,  191,  190,  189,  188,  187,  186,  185, \
     184,  183,  182,  181,  180,  179,  178,  177,  176,  175, \
     174,  173,  172,  171,  170,  169,  168,  167,  166,  165, \
     164,  163,  162,  161,  160,  159,  158,  157,  156,  155, \
     154,  153,  152,  151,  150,  149,  148,  147,  146,  145, \
     144,  143,  142,  141,  140,  139,  138,  137,  136,  135, \
     134,  133,  132,  131,  130,  129,  128,  127,  126,  125, \
     124,  123,  122,  121,  120,  119,  118,  117,  116,  115, \
     114,  113,  112,  111,  110,  109,  108,  107,  106,  105, \
     104,  103,  102,  101,  100,   99,   98,   97,   96,   95, \
      94,   93,   92,   91,   90,   89,   88,   87,   86,   85, \
      84,   83,   82,   81,   80,   79,   78,   77,   76,   75, \
      74,   73,   72,   71,   70,   69,   68,   67,   66,   65, \
      64,   63,   62,   61,   60,   59,   58,   57,   56,   55, \
      54,   53,   52,   51,   50,   49,   48,   47,   46,   45, \
      44,   43,   42,   41,   40,   39,   38,   37,   36,   35, \
      34,   33,   32,   31,   30,   29,   28,   27,   26,   25, \
      24,   23,   22,   21,   20,   19,   18,   17,   16,   15, \
      14,   13,   12,   11,   10,    9,    8,    7,    6,    5, \
       4,    3,    2,    1,    0

// EXAMPLE OF USAGE
//
// #define mean(__VA_ARGS__) mean##_(COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)
// long double mean_(int count, ...);

#define PRINT_VA_COUNTER(PRINTER,MAX) { \
    std::string to_print = "\n" \
    "// WARNING! THIS MACRO DOES NOT SUPPORT 0 ARGUMENTS\n" \
    "#define COUNT_ARGS(...) COUNT_ARGS_(__VA_ARGS__,REVERS_COUNT_ARGS_())\n" \
    "#define COUNT_ARGS_(...) COUNT_ARGS__(__VA_ARGS__)\n" \
    "#define COUNT_ARGS__(" \
    "                                                     \\\n    "; \
    for (int i = 1; i <= MAX; i++) { \
        to_print += "_"; \
        if (i < 1000) to_print += "0"; \
        if (i < 100) to_print += "0"; \
        if (i < 10) to_print += "0"; \
        to_print += std::to_string(i); \
        to_print += ", "; \
        if (!(i % 10)) to_print += "\\\n    "; \
    } \
    to_print += "_NOPQ, ... \\\n" \
                ") _NOPQ\n" \
                "#define REVERS_COUNT_ARGS_() \\\n    "; \
    for (int i = MAX; i >= 0; i--) { \
        if (i < 1000) to_print += " "; \
        if (i < 100) to_print += " "; \
        if (i < 10) to_print += " "; \
        to_print += std::to_string(i); \
        if (i > 0) to_print += ", "; \
        if (((MAX - i) % 10) == 9) to_print += "\\\n    "; \
    } \
    to_print += "\n\n" \
    "// EXAMPLE OF USAGE\n" \
    "//\n" \
    "// #define mean(__VA_ARGS__) mean##_(COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)\n" \
    "// long double mean_(int count, ...);\n"; \
    PRINTER << to_print << "\n"; \
}

namespace YH {
    namespace Lib {
        namespace Func {
            namespace texts {
                enum ascii_t {
                    // '0x00' '^@\' null-character
                    NUL = 0x00,
                    // '0x01' '^A' start of heading
                    SOH = 0x01,
                    // '0x02' '^B' start of text
                    STX = 0x02,
                    // '0x03' '^C' end of text
                    ETX = 0x03,
                    // '0x04' '^D' end of transmission
                    EOT = 0x04,
                    // '0x05' '^E' enquiry
                    ENQ = 0x05,
                    // '0x06' '^F' acknowledge
                    ACK = 0x06,
                    // '0x07' '^G' bell
                    BEL = 0x07,
                    // '0x08' '^H' backspace
                    BS  = 0x08,
                    // '0x09' '^I' horizontal tabulation
                    HT  = 0x09,
                    // '0x0a' '^J' line feed
                    LF  = 0x0a,
                    // '0x0b' '^K' vertical tabulation
                    VT  = 0x0b,
                    // '0x0c' '^L' form feed
                    FF  = 0x0c,
                    // '0x0d' '^M' carriage return
                    CR  = 0x0d,
                    // '0x0e' '^N' shift out
                    SO  = 0x0e,
                    // '0x0f' '^O' shift in
                    SI  = 0x0f,
                    // '0x10' '^P' data link escape
                    DLE = 0x10,
                    // '0x11' '^Q' device control one
                    DC1 = 0x11,
                    // '0x12' '^R' device control two
                    DC2 = 0x12,
                    // '0x13' '^S' device control three
                    DC3 = 0x13,
                    // '0x14' '^T' device control four
                    DC4 = 0x14,
                    // '0x15' '^U' negative acknowledge
                    NAK = 0x15,
                    // '0x16' '^V' synchronous idle
                    SYN = 0x16,
                    // '0x17' '^W' end of transmission block
                    ETB = 0x17,
                    // '0x18' '^X' cancel
                    CAN = 0x18,
                    // '0x19' '^Y' end of medium
                    EM  = 0x19,
                    // '0x1a' '^Z' substitute
                    SUB = 0x1a,
                    // '0x1b' '^[' escape
                    ESC = 0x1b,
                    // '0x1c' '^\\' file separator
                    FS  = 0x1c,
                    // '0x1d' '^]' group separator
                    GS  = 0x1d,
                    // '0x1e' '^^' record separator
                    RS  = 0x1e,
                    // '0x1f' '^_' unit separator
                    US  = 0x1f,
                    // '0x7f' '^?' delete
                    DEL = 0x7f
                };
                extern const char vers [];
                extern const char capital_letters [];
                extern const char small_letters [];
                extern const char number_chars [];
                extern const char symbol_chars [];
                // perform checks to identify if the running architecture uses ASCII
                const bool is_charset_ascii = ASCII_CHECK();
                types::largest_uint strlen (const char * const str);
                // behaves like: dest = src
                int8_t strcpy (char *dest, const char *src);
                // behaves like: dest = src
                types::largest_uint strncpy (char *dest, const char *src, types::largest_uint maxlen);
                // strcmp ("lhs", "rhs");
                int8_t strcmp (const char *lhs, const char *rhs);
                // strncmp("Hello, world!", "Hello, there!", 7);
                int8_t strncmp (const char *lhs, const char * rhs, types::largest_uint maxlen);
                // sets all chars in the string to '\0'
                types::largest_uint strclr (char *str, types::largest_uint strsize);
            // numbers and characters conversion
                // converts inputed value to a character
                char val_to_char (const uint8_t input, const uint8_t base = 10);
                // converts inputed character to a value
                int8_t char_to_val (const char input, const uint8_t base = 10);
            // capital and small letters conversion
                // converts capital letter to small letter
                char capital_to_small (const char input);
                // converts small letter to capital letter
                char small_to_capital (const char input);
            // if the character is of the specific type
                // returns 1 if inputed char is a number, else return 0
                bool is_num (const char input, const uint8_t base = 10);
                // returns 1 if inputed char is a small letter, else return 0
                bool is_capital (const char input);
                // returns 1 if inputed char is a capital letter, else return 0
                bool is_small (const char input);
                // returns 1 if inputed char is a letter (including spacebar), else return 0
                bool is_letter (const char input);
                // returns 1 if inputed char is a symbol, else return 0
                bool is_symbol (const char input);
            // if the string contains some type of characters
                // returns 1 if contain number, else return 0
                bool cont_num (const char *str);
                // returns 1 if contain capital letter, else return 0
                bool cont_capital (const char *str);
                // returns 1 if contain small letter, else return 0
                bool cont_small (const char *str);
                // return 1 if contain capital or small letter (including spacebar), else return 0
                bool cont_letter (const char *str);
                // returns 1 if contain symbols, else return 0
                bool cont_symbol (const char *str);
            // do all characters belong to the specific type
                // returns 1 if all characters are numbers, else return 0
                bool is_all_num (const char *str, const uint8_t base = 10);
                // returns 1 if the string represents a floating-point number, including '-' and '.', else return 0
                bool is_float (const char *str);
                // returns 1 if all characters are capital letters, else return 0
                bool is_all_capital (const char *str);
                // returns 1 if all characters are small letters, else return 0
                bool is_all_small (const char *str);
                // returns 1 if all characters are letters, else return 0
                bool is_all_letter (const char *str);
                // returns 1 if all characters are symbols, else return 0
                bool is_all_symbol (const char *str);
                // converts alphabetical characters into numbers
                // atod family
                         short     atos     (const char *src);
                         int       atoi     (const char *src);
                         long      atol     (const char *src);
                         long long atoll    (const char *src);
                // strtod family
                         short     strtos   (const char *src, char **rejected_str, const uint8_t base = 10);
                         int       strtoi   (const char *src, char **rejected_str, const uint8_t base = 10);
                         long      strtol   (const char *src, char **rejected_str, const uint8_t base = 10);
                         long long strtoll  (const char *src, char **rejected_str, const uint8_t base = 10);
                // converts alphabetical characters into unsigned numbers
                // atoud family
                unsigned short     atous    (const char *src);
                unsigned int       atoui    (const char *src);
                unsigned long      atoul    (const char *src);
                unsigned long long atoull   (const char *src);
                // strtoud family
                unsigned short     strtous  (const char *src, char **rejected_str, const uint8_t base = 10);
                unsigned int       strtoui  (const char *src, char **rejected_str, const uint8_t base = 10);
                unsigned long      strtoul  (const char *src, char **rejected_str, const uint8_t base = 10);
                unsigned long long strtoull (const char *src, char **rejected_str, const uint8_t base = 10);
                // converts alphabetical characters into floating-point numbers
                // atoxf family
                float              atof     (const char *src);
                double             atolf    (const char *src);
                long double        atold    (const char *src);
                // strtoxf family
                float              strtof   (const char *src, char **rejected_str, const uint8_t base = 10);
                double             strtolf  (const char *src, char **rejected_str, const uint8_t base = 10);
                long double        strtold  (const char *src, char **rejected_str, const uint8_t base = 10);
                //
                template <class T>
                // converts alphabetical characters into user-defined type
                // requires definition of type's arithmetic operators and assignment operator
                // requires definition of Type operator+(Type, char) &&
                //                      ( Type operator*(Type, int) || int operator*(Type, int) ) &&
                //                      ( Type operator/(Type, int) || int operator/(Type, int) ) &&
                //                      ( Type Type.operator=(Type) || int Type.operator=(int) )
                T strtoType (const char *src, char **rejected_str, const uint8_t base = 10);
                // converts floating-point number to char[]
                const char *fptos (types::largest_float val, types::largest_uint max_length = 10);

                // functions below are originally developed in YHmathsLib, but moved to this library due to its purposes
                // complicated functions converting bases of strings containing values
                // converts inputed string to a base-10 value (supports strings with floating-points)
                types::largest_float base_n_to_base_10 (const char *str, const uint16_t base_from, char* *remaining_unrecognised_str = 0);
                // converts inputed floating-point value to a string in another base
                // also act as val to str converting function when base_to == 10
                // note: str_max_len includes the '\\0' char
                const char *base_10_to_base_n (const types::largest_float val, const uint16_t base_to, types::largest_uint str_max_len = 24U, const bool round_off_last_digit = 1);
                // converts C-string of an argumented base to another C-string of another argumented base
                const char *change_base_of_str (const char *inputed_str, const uint16_t base_from, const uint16_t base_to, const types::largest_uint str_max_len = 24U);
            }
        }
        #define VARG_LEN(...) sizeof((YH::Lib::Varg_input []){__VA_ARGS__}) / sizeof(YH::Lib::Varg_input)
        struct Varg_input{template<class T>Varg_input(T){}};
        /*
        class Text {
            private:
                char capital [27];
                char small [27];
                char amount_of_eng_letters;
                char num [11];
                char version [28];
            public:
                Text ();
                char small_to_capital (char input);
                char capital_to_small (char input);
                char char_to_num (char input);
                char num_to_char (short input);
                bool is_num (char input);
                bool is_capital (char input);
                bool is_small (char input);
                const char *vers () const;
        };
        */
    }
}

// typedef YH::Lib::Text YHtextLib;

#endif // #ifndef YHTEXTLIB_H