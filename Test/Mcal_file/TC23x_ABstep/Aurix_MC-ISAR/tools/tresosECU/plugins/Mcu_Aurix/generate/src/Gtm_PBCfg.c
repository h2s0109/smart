[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\9 $                                        **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  BSW Module Description : Mcu.xdm                                          **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: 
    [cover parentID=DS_NAS_GTM_PR655,DS_NAS_GTM_PR741,DS_NAS_GTM_PR739,
    DS_NAS_GTM_PR446,SAS_NAS_GTM_PR63_PR65,SAS_NAS_GTM_PR64,SAS_NAS_GTM_PR77
    SAS_NAS_GTM_PR63_1,SAS_NAS_GTM_PR63_2,SAS_NAS_GTM_PR63_3,SAS_NAS_GTM_PR63_4,
    SAS_NAS_GTM_PR63_5,SAS_NAS_GTM_PR63_6,SAS_NAS_GTM_PR63_7,SAS_NAS_GTM_PR63_8,
    SAS_NAS_GTM_PR63_9,SAS_NAS_GTM_PR63_10,SAS_NAS_GTM_PR63_11,
    SAS_NAS_GTM_PR63_12,SAS_NAS_GTM_PR63_13,SAS_NAS_GTM_PR63_14,
    SAS_NAS_GTM_PR63_15,SAS_NAS_GTM_PR63_16,SAS_NAS_GTM_PR63_17,
    SAS_NAS_GTM_PR63_18,SAS_NAS_GTM_PR63_19,SAS_NAS_GTM_PR63_20,
    SAS_NAS_GTM_PR63_21,SAS_NAS_GTM_PR63_22,SAS_NAS_GTM_PR63_23,
    SAS_NAS_GTM_PR63_24,SAS_NAS_GTM_PR63_25,SAS_NAS_GTM_PR63_26,
    SAS_NAS_GTM_PR63_27,SAS_NAS_GTM_PR63_28,SAS_NAS_GTM_PR63_29,
    SAS_NAS_GTM_PR63_30,SAS_NAS_GTM_PR63_31,SAS_NAS_GTM_PR63_32,
    SAS_NAS_GTM_PR63_33,SAS_NAS_GTM_PR63_34,SAS_NAS_GTM_PR63_35,
    SAS_NAS_GTM_PR63_36,SAS_NAS_GTM_PR63_37,SAS_NAS_GTM_PR63_38,
    SAS_NAS_GTM_PR63_39,SAS_NAS_GTM_PR63_40,SAS_NAS_GTM_PR63_41,
    SAS_NAS_GTM_PR63_42,SAS_NAS_GTM_PR63_43,SAS_NAS_GTM_PR63_44,
    SAS_NAS_GTM_PR63_45,SAS_NAS_GTM_PR63_46,SAS_NAS_GTM_PR63_47,
    SAS_NAS_GTM_PR63_48,SAS_NAS_GTM_PR63_49,SAS_NAS_GTM_PR63_50,
    SAS_NAS_GTM_PR63_51,SAS_NAS_GTM_PR63_52,SAS_NAS_GTM_PR63_53,
    SAS_NAS_GTM_PR63_54,SAS_NAS_GTM_PR63_55,SAS_NAS_GTM_PR63_56,
    SAS_NAS_GTM_PR63_57,SAS_NAS_GTM_PR63_58,SAS_NAS_GTM_PR63_59,
    SAS_NAS_GTM_PR63_60,SAS_NAS_GTM_PR63_61,SAS_NAS_GTM_PR63_62,
    SAS_NAS_GTM_PR63_63,SAS_NAS_GTM_PR63_64,SAS_NAS_GTM_PR63_65,
    SAS_NAS_GTM_PR63_66,SAS_NAS_GTM_PR63_67,SAS_NAS_GTM_PR63_68,
    SAS_NAS_GTM_PR63_69,SAS_NAS_GTM_PR63_70,SAS_NAS_GTM_PR63_71,
    SAS_NAS_GTM_PR63_72,SAS_NAS_GTM_PR63_73,SAS_NAS_GTM_PR63_74,
    SAS_NAS_GTM_PR63_75,SAS_NAS_GTM_PR63_76,SAS_NAS_GTM_PR63_77,
    SAS_NAS_GTM_PR63_78,SAS_NAS_GTM_PR63_79,SAS_NAS_GTM_PR63_80,
    SAS_NAS_GTM_PR63_81,SAS_NAS_GTM_PR63_82,SAS_NAS_GTM_PR63_83,
    SAS_NAS_GTM_PR63_84,SAS_NAS_GTM_PR63_85,SAS_NAS_GTM_PR63_86,
    SAS_NAS_GTM_PR63_87,SAS_NAS_GTM_PR63_88,SAS_NAS_GTM_PR63_89,
    SAS_NAS_GTM_PR63_90,SAS_NAS_GTM_PR63_91,SAS_NAS_GTM_PR63_92,
    SAS_NAS_GTM_PR63_93,SAS_NAS_GTM_PR63_94,SAS_NAS_GTM_PR63_95,
    SAS_NAS_GTM_PR63_96,SAS_NAS_GTM_PR63_97,SAS_NAS_GTM_PR63_98,
    SAS_NAS_GTM_PR63_99,SAS_NAS_GTM_PR63_100,SAS_NAS_GTM_PR63_101,
    SAS_NAS_GTM_PR63_102,SAS_NAS_GTM_PR63_103,SAS_NAS_GTM_PR63_104,
    SAS_NAS_GTM_PR63_105,SAS_NAS_GTM_PR63_106,SAS_NAS_GTM_PR63_107,
    SAS_NAS_GTM_PR63_108,SAS_NAS_GTM_PR63_109,SAS_NAS_GTM_PR63_110,
    SAS_NAS_GTM_PR63_111,SAS_NAS_GTM_PR63_112,SAS_NAS_GTM_PR63_113,
    SAS_NAS_GTM_PR63_114,SAS_NAS_GTM_PR63_115,SAS_NAS_GTM_PR63_116,
    SAS_NAS_GTM_PR63_117,SAS_NAS_GTM_PR63_118,SAS_NAS_GTM_PR63_119,
    SAS_NAS_GTM_PR63_120,SAS_NAS_GTM_PR63_121,SAS_NAS_GTM_PR63_122,
    SAS_NAS_GTM_PR63_123,SAS_NAS_GTM_PR63_124,SAS_NAS_GTM_PR63_125,
    SAS_NAS_GTM_PR63_126,SAS_NAS_GTM_PR63_127,SAS_NAS_GTM_PR63_128,
    SAS_NAS_GTM_PR63_129,SAS_NAS_GTM_PR63_130,SAS_NAS_GTM_PR63_131,
    SAS_NAS_GTM_PR63_132,SAS_NAS_GTM_PR63_133,SAS_NAS_GTM_PR63_134,
    SAS_NAS_GTM_PR63_135,SAS_NAS_GTM_PR63_136,SAS_NAS_GTM_PR63_137,
    SAS_NAS_GTM_PR63_138,SAS_NAS_GTM_PR63_139,SAS_NAS_GTM_PR63_140,
    SAS_NAS_GTM_PR63_141,SAS_NAS_GTM_PR63_142,SAS_NAS_GTM_PR63_143,
    SAS_NAS_GTM_PR63_144,SAS_NAS_GTM_PR63_145,SAS_NAS_GTM_PR63_146,
    SAS_NAS_GTM_PR63_147,SAS_NAS_GTM_PR63_148,SAS_NAS_GTM_PR63_149,
    SAS_NAS_GTM_PR63_150,SAS_NAS_GTM_PR63_151,SAS_NAS_GTM_PR63_152,
    SAS_NAS_GTM_PR63_153,SAS_NAS_GTM_PR63_154,SAS_NAS_GTM_PR63_155,
    SAS_NAS_GTM_PR63_156,SAS_NAS_GTM_PR63_157,SAS_NAS_GTM_PR63_158,
    SAS_NAS_GTM_PR63_159,SAS_NAS_GTM_PR63_160,SAS_NAS_GTM_PR63_161,
    SAS_NAS_GTM_PR63_162,SAS_NAS_GTM_PR63_163,SAS_NAS_GTM_PR63_164,
    SAS_NAS_GTM_PR63_165,SAS_NAS_GTM_PR63_166,SAS_NAS_GTM_PR63_167,
    SAS_NAS_GTM_PR63_168,SAS_NAS_GTM_PR63_169,SAS_NAS_GTM_PR63_170,
    SAS_NAS_GTM_PR63_171,SAS_NAS_GTM_PR63_172,SAS_NAS_GTM_PR63_173,
    SAS_NAS_GTM_PR63_174,SAS_NAS_GTM_PR63_175,SAS_NAS_GTM_PR63_176,
    SAS_NAS_GTM_PR63_177,SAS_NAS_GTM_PR63_178,SAS_NAS_GTM_PR63_179,
    SAS_NAS_GTM_PR63_180,SAS_NAS_GTM_PR63_181,SAS_NAS_GTM_PR63_182,
    SAS_NAS_GTM_PR63_183,SAS_NAS_GTM_PR63_184,SAS_NAS_GTM_PR63_185,
    SAS_NAS_GTM_PR63_186,SAS_NAS_GTM_PR63_187,SAS_NAS_GTM_PR63_188,
    SAS_NAS_GTM_PR63_189,SAS_NAS_GTM_PR63_190,SAS_NAS_GTM_PR63_191,
    SAS_NAS_GTM_PR63_192,SAS_NAS_GTM_PR63_193,SAS_NAS_GTM_PR63_194,
    SAS_NAS_GTM_PR63_195,SAS_NAS_GTM_PR63_196,SAS_NAS_GTM_PR63_197,
    SAS_NAS_GTM_PR63_198,SAS_NAS_GTM_PR63_199,SAS_NAS_GTM_PR63_200,
    SAS_NAS_GTM_PR63_201,SAS_NAS_GTM_PR63_202,SAS_NAS_GTM_PR63_203,
    SAS_NAS_GTM_PR63_204,SAS_NAS_GTM_PR63_205,SAS_NAS_GTM_PR63_206,
    SAS_NAS_GTM_PR63_207,SAS_NAS_GTM_PR63_208,SAS_NAS_GTM_PR63_209,
    SAS_NAS_GTM_PR63_210,SAS_NAS_GTM_PR63_211,SAS_NAS_GTM_PR63_212,
    SAS_NAS_GTM_PR63_213,SAS_NAS_GTM_PR63_214,SAS_NAS_GTM_PR63_215,
    SAS_NAS_GTM_PR63_216,SAS_NAS_GTM_PR63_217,SAS_NAS_GTM_PR63_218,
    SAS_NAS_GTM_PR63_219,SAS_NAS_GTM_PR63_220,SAS_NAS_GTM_PR63_221,
    SAS_NAS_GTM_PR63_222,SAS_NAS_GTM_PR63_223,SAS_NAS_GTM_PR63_224,
    SAS_NAS_GTM_PR63_225,SAS_NAS_GTM_PR63_226,SAS_NAS_GTM_PR63_227,
    SAS_NAS_GTM_PR63_228,SAS_NAS_GTM_PR63_229,SAS_NAS_GTM_PR63_230,
    SAS_NAS_GTM_PR63_231,SAS_NAS_GTM_PR63_232,SAS_NAS_GTM_PR63_233,
    SAS_NAS_GTM_PR63_234,SAS_NAS_GTM_PR63_235,SAS_NAS_GTM_PR63_236,
    SAS_NAS_GTM_PR63_237,SAS_NAS_GTM_PR63_238,SAS_NAS_GTM_PR63_239,
    SAS_NAS_GTM_PR63_240,SAS_NAS_GTM_PR63_241,SAS_NAS_GTM_PR63_242,
    SAS_NAS_GTM_PR63_243,SAS_NAS_GTM_PR63_244,SAS_NAS_GTM_PR63_245,
    SAS_NAS_GTM_PR63_246,SAS_NAS_GTM_PR63_247,SAS_NAS_GTM_PR63_248,
    SAS_NAS_GTM_PR63_249,SAS_NAS_GTM_PR63_250,SAS_NAS_GTM_PR63_251,
    SAS_NAS_GTM_PR63_252,SAS_NAS_GTM_PR63_253,SAS_NAS_GTM_PR63_254,
    SAS_NAS_GTM_PR63_255,SAS_NAS_GTM_PR63_256,SAS_NAS_GTM_PR63_257,
    SAS_NAS_GTM_PR63_258,SAS_NAS_GTM_PR63_259,SAS_NAS_GTM_PR63_260,
    SAS_NAS_GTM_PR63_261,SAS_NAS_GTM_PR63_262,SAS_NAS_GTM_PR63_263,
    SAS_NAS_GTM_PR63_264,SAS_NAS_GTM_PR63_265,SAS_NAS_GTM_PR63_266,
    SAS_NAS_GTM_PR63_267,SAS_NAS_GTM_PR63_268,SAS_NAS_GTM_PR63_269,
    SAS_NAS_GTM_PR63_270,SAS_NAS_GTM_PR63_271,SAS_NAS_GTM_PR63_272,
    SAS_NAS_GTM_PR63_273,SAS_NAS_GTM_PR63_274,SAS_NAS_GTM_PR63_275,
    SAS_NAS_GTM_PR63_276,SAS_NAS_GTM_PR63_277,SAS_NAS_GTM_PR63_278,
    SAS_NAS_GTM_PR63_279,SAS_NAS_GTM_PR63_280,SAS_NAS_GTM_PR63_281,
    SAS_NAS_GTM_PR63_282,SAS_NAS_GTM_PR63_283,SAS_NAS_GTM_PR63_284,
    SAS_NAS_GTM_PR63_285,SAS_NAS_GTM_PR63_286,SAS_NAS_GTM_PR63_287,
    SAS_NAS_GTM_PR63_288,SAS_NAS_GTM_PR63_289,SAS_NAS_GTM_PR63_290,
    SAS_NAS_GTM_PR63_291,SAS_NAS_GTM_PR63_292,SAS_NAS_GTM_PR63_293,
    SAS_NAS_GTM_PR63_294,SAS_NAS_GTM_PR63_295,SAS_NAS_GTM_PR63_296,
    SAS_NAS_GTM_PR63_297,SAS_NAS_GTM_PR63_298,SAS_NAS_GTM_PR63_299,
    SAS_NAS_GTM_PR63_300,SAS_NAS_GTM_PR63_301,SAS_NAS_GTM_PR63_302,
    SAS_NAS_GTM_PR63_303,SAS_NAS_GTM_PR63_304,SAS_NAS_GTM_PR63_305,
    SAS_NAS_GTM_PR63_306,SAS_NAS_GTM_PR63_307,SAS_NAS_GTM_PR63_308,
    SAS_NAS_GTM_PR63_309,SAS_NAS_GTM_PR63_310,SAS_NAS_GTM_PR63_311,
    SAS_NAS_GTM_PR63_312,SAS_NAS_GTM_PR63_313,SAS_NAS_GTM_PR63_314,
    SAS_NAS_GTM_PR63_315,SAS_NAS_GTM_PR63_316,SAS_NAS_GTM_PR63_317,
    SAS_NAS_GTM_PR63_318,SAS_NAS_GTM_PR63_319,SAS_NAS_GTM_PR63_320,
    SAS_NAS_GTM_PR63_321,SAS_NAS_GTM_PR63_322,SAS_NAS_GTM_PR63_323,
    SAS_NAS_GTM_PR63_324,SAS_NAS_GTM_PR63_325,SAS_NAS_GTM_PR63_326,
    SAS_NAS_GTM_PR63_327,SAS_NAS_GTM_PR63_328,SAS_NAS_GTM_PR63_329,
    SAS_NAS_GTM_PR63_330,SAS_NAS_GTM_PR63_331,SAS_NAS_GTM_PR63_332,
    SAS_NAS_GTM_PR63_333,SAS_NAS_GTM_PR63_334,SAS_NAS_GTM_PR63_335,
    SAS_NAS_GTM_PR63_336,SAS_NAS_GTM_PR63_337,SAS_NAS_GTM_PR63_338,
    SAS_NAS_GTM_PR63_339,SAS_NAS_GTM_PR63_340,SAS_NAS_GTM_PR63_341,
    SAS_NAS_GTM_PR63_342,SAS_NAS_GTM_PR63_343,SAS_NAS_GTM_PR63_344,
    SAS_NAS_GTM_PR63_345,SAS_NAS_GTM_PR63_346,SAS_NAS_GTM_PR63_347,
    SAS_NAS_GTM_PR63_348,SAS_NAS_GTM_PR63_349,SAS_NAS_GTM_PR63_350,
    SAS_NAS_GTM_PR63_351,SAS_NAS_GTM_PR63_352,SAS_NAS_GTM_PR63_353,
    SAS_NAS_GTM_PR63_354,SAS_NAS_GTM_PR63_355,SAS_NAS_GTM_PR63_356,
    SAS_NAS_GTM_PR63_357,SAS_NAS_GTM_PR63_358,SAS_NAS_GTM_PR63_359,
    SAS_NAS_GTM_PR63_360,SAS_NAS_GTM_PR63_361,SAS_NAS_GTM_PR63_362,
    SAS_NAS_GTM_PR63_363,SAS_NAS_GTM_PR63_364,SAS_NAS_GTM_PR63_365,
    SAS_NAS_GTM_PR63_366,SAS_NAS_GTM_PR63_367,SAS_NAS_GTM_PR63_368,
    SAS_NAS_GTM_PR63_369,SAS_NAS_GTM_PR63_370,SAS_NAS_GTM_PR63_371,
    SAS_NAS_GTM_PR63_372,SAS_NAS_GTM_PR63_373,SAS_NAS_GTM_PR63_374,
    SAS_NAS_GTM_PR63_375,SAS_NAS_GTM_PR63_376,SAS_NAS_GTM_PR63_377,
    SAS_NAS_GTM_PR63_378,SAS_NAS_GTM_PR63_379,SAS_NAS_GTM_PR63_380,
    SAS_NAS_GTM_PR63_381,SAS_NAS_GTM_PR63_382,SAS_NAS_GTM_PR63_383,
    SAS_NAS_GTM_PR63_384,SAS_NAS_GTM_PR63_385,SAS_NAS_GTM_PR63_386,
    SAS_NAS_GTM_PR63_387,SAS_NAS_GTM_PR63_388,SAS_NAS_GTM_PR63_389,
    SAS_NAS_GTM_PR63_390,SAS_NAS_GTM_PR63_391,SAS_NAS_GTM_PR63_392,
    SAS_NAS_GTM_PR63_393,SAS_NAS_GTM_PR63_394,SAS_NAS_GTM_PR63_395,
    SAS_NAS_GTM_PR63_396,SAS_NAS_GTM_PR63_397,SAS_NAS_GTM_PR63_398,
    SAS_NAS_GTM_PR63_399,SAS_NAS_GTM_PR63_400,SAS_NAS_GTM_PR63_401,
    SAS_NAS_GTM_PR63_402,SAS_NAS_GTM_PR63_403,SAS_NAS_GTM_PR63_404,
    SAS_NAS_GTM_PR63_405,SAS_NAS_GTM_PR63_406,SAS_NAS_GTM_PR63_407,
    SAS_NAS_GTM_PR63_408,SAS_NAS_GTM_PR63_409,SAS_NAS_GTM_PR63_410,
    SAS_NAS_GTM_PR63_411,SAS_NAS_GTM_PR63_412,SAS_NAS_GTM_PR63_413,
    SAS_NAS_GTM_PR63_414,SAS_NAS_GTM_PR63_415,SAS_NAS_GTM_PR63_416,
    SAS_NAS_GTM_PR63_417,SAS_NAS_GTM_PR63_418,SAS_NAS_GTM_PR63_419,
    SAS_NAS_GTM_PR63_420,SAS_NAS_GTM_PR63_421,SAS_NAS_GTM_PR63_422,
    SAS_NAS_GTM_PR63_423,SAS_NAS_GTM_PR63_424,SAS_NAS_GTM_PR63_425,
    SAS_NAS_GTM_PR63_426,SAS_NAS_GTM_PR63_427,SAS_NAS_GTM_PR63_428,
    SAS_NAS_GTM_PR63_429,SAS_NAS_GTM_PR63_430,SAS_NAS_GTM_PR63_431,
    SAS_NAS_GTM_PR63_432,SAS_NAS_GTM_PR63_433,SAS_NAS_GTM_PR63_434,
    SAS_NAS_GTM_PR63_435,SAS_NAS_GTM_PR63_436,SAS_NAS_GTM_PR63_437,
    SAS_NAS_GTM_PR63_438,SAS_NAS_GTM_PR63_439,SAS_NAS_GTM_PR63_440,
    SAS_NAS_GTM_PR63_441,SAS_NAS_GTM_PR63_442,SAS_NAS_GTM_PR63_443,
    SAS_NAS_GTM_PR63_444,SAS_NAS_GTM_PR63_445,SAS_NAS_GTM_PR63_446,
    SAS_NAS_GTM_PR63_447,SAS_NAS_GTM_PR63_448,SAS_NAS_GTM_PR63_449,
    SAS_NAS_GTM_PR63_450,SAS_NAS_GTM_PR63_451,SAS_NAS_GTM_PR63_452,
    SAS_NAS_GTM_PR63_453,SAS_NAS_GTM_PR63_454,SAS_NAS_GTM_PR63_455,
    SAS_NAS_GTM_PR63_456,SAS_NAS_GTM_PR63_457,SAS_NAS_GTM_PR63_458,
    SAS_NAS_GTM_PR63_459,SAS_NAS_GTM_PR63_460,SAS_NAS_GTM_PR63_461,
    SAS_NAS_GTM_PR63_462,SAS_NAS_GTM_PR63_463,SAS_NAS_GTM_PR63_464,
    SAS_NAS_GTM_PR63_465,SAS_NAS_GTM_PR63_466,SAS_NAS_GTM_PR63_467,
    SAS_NAS_GTM_PR63_468,SAS_NAS_GTM_PR63_469,SAS_NAS_GTM_PR63_470,
    SAS_NAS_GTM_PR63_471,SAS_NAS_GTM_PR63_472,SAS_NAS_GTM_PR63_473,
    SAS_NAS_GTM_PR63_474,SAS_NAS_GTM_PR63_475,SAS_NAS_GTM_PR63_476,
    SAS_NAS_GTM_PR63_477,SAS_NAS_GTM_PR63_478,SAS_NAS_GTM_PR63_479,
    SAS_NAS_GTM_PR63_480,SAS_NAS_GTM_PR63_481,SAS_NAS_GTM_PR63_482,
    SAS_NAS_GTM_PR63_483,SAS_NAS_GTM_PR63_484,SAS_NAS_GTM_PR63_485,
    SAS_NAS_GTM_PR63_486,SAS_NAS_GTM_PR63_487,SAS_NAS_GTM_PR63_488,
    SAS_NAS_GTM_PR63_489,SAS_NAS_GTM_PR63_490,SAS_NAS_GTM_PR63_491,
    SAS_NAS_GTM_PR63_492,SAS_NAS_GTM_PR63_493,SAS_NAS_GTM_PR63_494,
    SAS_NAS_GTM_PR63_495,SAS_NAS_GTM_PR63_496,SAS_NAS_GTM_PR63_497,
    SAS_NAS_GTM_PR63_498,SAS_NAS_GTM_PR63_499,SAS_NAS_GTM_PR63_500,
    SAS_NAS_GTM_PR63_501,SAS_NAS_GTM_PR63_502,SAS_NAS_GTM_PR63_503,
    SAS_NAS_GTM_PR63_504,SAS_NAS_GTM_PR63_505,SAS_NAS_GTM_PR63_506,
    SAS_NAS_GTM_PR63_507,SAS_NAS_GTM_PR63_508,SAS_NAS_GTM_PR63_509,
    SAS_NAS_GTM_PR63_510,SAS_NAS_GTM_PR63_511,SAS_NAS_GTM_PR63_512,
    SAS_NAS_GTM_PR63_513,SAS_NAS_GTM_PR63_514,SAS_NAS_GTM_PR63_515,
    SAS_NAS_GTM_PR63_516,SAS_NAS_GTM_PR63_517,SAS_NAS_GTM_PR63_518,
    SAS_NAS_GTM_PR63_519,SAS_NAS_GTM_PR63_520,SAS_NAS_GTM_PR63_521,
    SAS_NAS_GTM_PR63_522,SAS_NAS_GTM_PR63_523,SAS_NAS_GTM_PR63_524,
    SAS_NAS_GTM_PR63_525,SAS_NAS_GTM_PR63_526,SAS_NAS_GTM_PR63_527,
    SAS_NAS_GTM_PR63_528,SAS_NAS_GTM_PR63_529,SAS_NAS_GTM_PR63_530,
    SAS_NAS_GTM_PR63_531,SAS_NAS_GTM_PR63_532,SAS_NAS_GTM_PR63_533,
    SAS_NAS_GTM_PR63_534,SAS_NAS_GTM_PR63_535,
    SAS_NAS_GTM_PR63_537,SAS_NAS_GTM_PR63_538,SAS_NAS_GTM_PR63_539,
    SAS_NAS_GTM_PR63_540,SAS_NAS_GTM_PR63_541,SAS_NAS_GTM_PR63_542,
    SAS_NAS_GTM_PR63_543,SAS_NAS_GTM_PR63_544,SAS_NAS_GTM_PR63_545,
    SAS_NAS_GTM_PR63_546,SAS_NAS_GTM_PR63_547,SAS_NAS_GTM_PR63_548,
    SAS_NAS_GTM_PR63_549,SAS_NAS_GTM_PR63_550,SAS_NAS_GTM_PR63_551,
    SAS_NAS_GTM_PR63_552,SAS_NAS_GTM_PR63_553,SAS_NAS_GTM_PR63_554,
    SAS_NAS_GTM_PR63_555,SAS_NAS_GTM_PR63_556,SAS_NAS_GTM_PR63_557,
    SAS_NAS_GTM_PR63_558,SAS_NAS_GTM_PR63_560,SAS_NAS_GTM_PR63_561,
    SAS_NAS_GTM_PR63_562,SAS_NAS_GTM_PR63_563,DS_NAS_GTM_PR78_1,
    DS_NAS_GTM_PR446,DS_NAS_GTM_PR699,DS_NAS_GTM_PR647,DS_NAS_GTM_PR69_PR469,
    DS_NAS_GTM_PR700,DS_NAS_GTM_PR701,DS_NAS_GTM_PR704,DS_NAS_GTM_PR707,
    DS_NAS_GTM_PR708,DS_NAS_GTM_PR712,DS_NAS_GTM_PR713,DS_NAS_GTM_PR716,
    DS_NAS_GTM_PR717,DS_NAS_GTM_PR719,DS_NAS_GTM_PR720,DS_NAS_GTM_PR723,DS_NAS_GTM_PR724,
    DS_NAS_GTM_PR728,DS_NAS_GTM_PR709,DS_NAS_GTM_PR228,
    SAS_NAS_GTM_PR82,SAS_NAS_GTM_PR227,SAS_NAS_GTM_PR640,
    SAS_AS4XX_GTM_PR680,SAS_NAS_GTM_PR916,SAS_NAS_GTM_PR667,SAS_NAS_GTM_PR646,
    SAS_NAS_GTM_PR123]
    ASW:1455 to DS_NAS_GTM_PR228 map to Mcu.xdm. It is mapped here to 
    avoid conflicts with MCU traceability
**                                                                            **
**  DESCRIPTION  : Code template for Gtm_PBCfg.c file                         **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
********************************************************************************
** VS          Vinod Shankar                                                  **
** RC          Rashmi Chadaga                                                 **
** KP          Kaushal Purohit                                                **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V2.0.4: 2013-08-19,  KP   : minor correction for compilation errors
 * V2.0.3: 2013-07-23,  KP   : Changed for UTP [AI00198181]
 * V2.0.2: 2013-04-22,  KP   : Changed for UTP [AI00171967]
 * V2.0.1: 2013-03-26,  KP   : updated as per review comments [REV_004335]
 * V2.0.0: 2013-03-14,  KP   : Added Bstep changes
 * V0.0.11: 2012-11-13, VS   : Gtm_kFifoConfig made const
 * V0.0.10: 2012-11-07, VS   : MISRA fix
 * V0.0.9 : 2012-10-30, RC   : Traceability Added 
 * V0.0.8 : 2012-09-25, RC   : CCU corrections. AI00066335 
 * V0.0.7 : 2012-09-10, VS   : Support of CCU. AI00066335 
 * V0.0.6 : 2012-07-04, VS   : Fix for AI00076259 
 * V0.0.5 : 2012-06-14, VS   : Changes done for BMD 
 * V0.0.4 : 2012-04-25, VS   : a) Requirement Traceability Added
 *                            b) GTM Enhancement - Notification Included
 * V0.0.3 : 2011-10-05, VS   : Misra related Changes
 * V0.0.2 : 2011-04-05, VS   : Review Changes
 * V0.0.1 : 2011-02-12, VS   : Initial version
 *                                                                            
*************************************************************************/!][!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\9 $                                        **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver implementation                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!/*
*/!][!INCLUDE "Gtm.m"!][!/*
*/!][!SELECT "as:modconf('Mcu')[1]"!][!/*
*/!][!VAR "RelDerivate" = "ecu:get('Rel.Derivate')"!][!/* 
*/!][!IF "($RelDerivate = '_TRICORE_TC234')"!][!/*
*/!][!VAR "RelDerivate" = "'TC23x'"!][!/*
*/!][!ENDIF!][!/*
[!/*
*/!][!/* Generate this file only if Gtm is configured
*/!][!NOCODE!][!/*
*/!][!/* To Count the Number of Gtm Configurations inside all the Mcu PB Containers */!][!/*
*/!][!VAR "TotalGtmConfig" = "num:i(0)"!][!/*
*/!][!VAR "McuSelect" = "'McuModuleConfiguration'"!][!/*
*/!][!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!][!/*
*/!][!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!][!/*
*/!][!IF "$Count > num:i(0)"!][!/*    
*/!][!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TotalGtmConfigInAllContainers" = "num:i(count(McuModuleConfiguration/*/GtmConfiguration/*))"!][!/*
*/!][!ASSERT "($TotalGtmConfigInAllContainers = num:i(0)) or ($TotalGtmConfigInAllContainers =  (num:i(count(McuModuleConfiguration/*))))"!][!/*
*/!]Configuration Error: If any one MCU config set has GTM configured, then all the MCU config sets should have GTM configured
[!ENDASSERT!][!/*
To determine the Post Build Type
*/!][!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalGtmConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMPostBuildConfigType) ='true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
*/!][!ENDNOCODE!][!/*
*/!][!/* Run the Code generator only if there is atleast 1 Gtm Configuration among the containers
*/!][!IF "$TotalGtmConfig > num:i(0)"!][!/*
*/!]
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)


#define TSPP1_SUBUNIT_OUTPUT 5

/* For Tbu */
#define BITS_0_TO_23   (0U)
#define BITS_3_TO_26   (1U)
#define FREE_RUNNING_COUNTER_MODE      (0)
#define FORWARD_BACKWARD_COUNTER_MODE  (1)

#define Gtm_lTbuBuildControl(Bit0, Bit123, Bit5)                              \
 (0x00U | (uint8)(Bit0) | (uint8)((uint8)(Bit123) << 1) |                     \
                                                 (uint8)((uint8)(Bit5) << 5))
#define Gtm_lTimerCtrlValue(Word, ClockValue)                                 \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 12))
#define Gtm_TimbuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word)| (uint32)((uint32)(ClockValue) << 24))
#define Gtm_TimTduBuildReg(Word, ClockValue)                                  \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 28))
/* For Interrupt Mode Appending */
#define Gtm_lIncludeIntMode8Bit(Bytevalue, IrqMode)                           \
                          ((uint8)(Bytevalue) | (uint8)((uint8)(IrqMode) << 6))
#define Gtm_lIncludeIntMode16Bit(Intvalue, IrqMode)                           \
                       ((uint16)(Intvalue) | (uint16)((uint16)(IrqMode) << 14))
#define Gtm_lIncludeIntMode32Bit(Wordvalue, IrqMode)                          \
                      ((uint32)(Wordvalue) | (uint32)((uint32)(IrqMode) << 30))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!NOCODE!][!/*
*/!][!VAR "IsBmdUsed" = "'false'"!][!/*
*/!][!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!/*
*/!][!ENDNOCODE!][!/*
*/!][!VAR "PortConfigPresent" = "num:i(0)"!][!/*
*/!][!VAR "ClockConfigExist" = "num:i(0)"!][!/*
*/!][!FOR "ModuleId" ="num:i(0)" TO "(num:i($TotalMcuConfig)-1)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleId + 1,']')"!][!/*
*/!][!SELECT "node:ref($McuSelectIndex)"!][!/*
*/!][!IF "node:exists(GtmConfiguration/*[1]/Cmu/*[1])"!][!/*
*/!][!VAR "ClockConfigExist" = "bit:bitset($ClockConfigExist,$ModuleId)"!][!/*
*/!]static const Gtm_ClockSettingType Gtm_kClockSetting[!"$ModuleId"!] = 
{
[!NOCODE!][!//
[!VAR "BuildReg" = "num:i(0)"!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk0)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk1)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk2)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk3)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 6)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk4)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk5)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk6)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk7)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 14)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk0)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk1)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 19)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk2)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuFixedClock/CmuEnableAllFixedClocks)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 23)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!//	
[!ENDIF!][!//
[!ENDNOCODE!][!//
  [!"num:inttohex($BuildReg,8)"!]U,
  {
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk0Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk1Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk2Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk3Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk4Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk5Div, 8)"!]U,
[!VAR "BuildReg" = "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk6Div"!][!/*
*/!]    [!"num:inttohex($BuildReg, 8)"!]U,
[!VAR "BuildReg" = "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk7Div"!][!/*
*/!]    [!"num:inttohex($BuildReg, 8)"!]U,
  },
[!IF "./CmuFixedClock/CmuFxdClkSourceSelect = 'GTM_GLOBAL_CLOCK'"!][!/*
*/!][!VAR "ClockVal" = "num:i(0)"!][!/*
*/!][!"num:inttohex($ClockVal,1)"!]U,
  [!ELSE!][!/*
*/!][!VAR "ClockVal" = "text:split(GtmConfiguration/*[1]/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect, '_')[position()-1 = 2]"!]
    [!"num:inttohex(($ClockVal+1),1)"!]U,
[!ENDIF!]
  {
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk0Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk0Denominator,8)"!]U[!/*
*/!]  },
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk1Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk1Denominator,8)"!]U[!/*
*/!]  },
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk2Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk2Denominator,8)"!]U[!/*
*/!]  }
  }[!/*
*/!]
};
[!ENDIF!][!/* [!IF "node:exists(GtmConfiguration/*[1]/Cmu/*[1])"!]
*/!][!/*
*/!]
static const Gtm_GeneralConfigType Gtm_kGeneralConfig[!"$ModuleId"!] =
{[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmGeneral/GtmEnRstAndForceIntFunctionality)"!][!/*
*/!][!IF "$BuildRegTemp = 'false'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeOutMode)"!][!/*
*/!][!IF "$BuildRegTemp = 'ABORT'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeOutValue)"!][!/*
*/!][!VAR "BuildRegTemp" = "bit:shl($BuildRegTemp,4)"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,$BuildRegTemp)"!][!/*
*/!]
  [!"num:inttohex($BuildReg,4)"!]U,[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeoutExceptionIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedAddressIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiIllegalModuleAddIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedByteEnIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeoutExceptionErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedAddressErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiIllegalModuleAddErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedByteEnErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiInterruptMode)"!][!/*
*/!]
  Gtm_lIncludeIntMode8Bit([!"$BuildReg"!]U,[!"$BuildRegTemp"!])[!/*
*/!]
  };

[!/* 
**********************************************************************************************************
**********************************************************************************************************
          Validation of TOM Channels used by PWM, GPT and Complex Driver
**********************************************************************************************************
**********************************************************************************************************
*/!][!/*
*/!][!/* For Port Configuration
*/!][!VAR "ToutSel0" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel1" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel2" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel3" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel4" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel5" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel6" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel7" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel8" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel9" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel10" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel11" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel12" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel13" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel14" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel15" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel16" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_ClearToutSelCheck"!][!/*

*/!][!VAR "TomModuleLookUp1"  = "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp2"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage1"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage2"  = "num:i(0)"!][!/*
*/!][!VAR "TomTGCUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./PwmAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: PWM: PWMAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"  = "bit:bitset($TomModuleLookUp1, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp2"  = "bit:bitset($TomModuleLookUp2, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/*
*/!][!/* Information from GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!ASSERT "node:refexists(./GptAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: GPT: GptAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"  = "bit:bitset($TomModuleLookUp1, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp2"  = "bit:bitset($TomModuleLookUp2, $SetPosition + 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*[!IF "$ModuleType = 'Tom'"!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/* Information in GTM as Complex
*/!][!VAR "ComplexDriverTomConfig" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!LOOP "Tom/*"!][!/*
*/!][!LOOP "TomChannel/*"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTomConfig" = "1"!][!/*  
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp1"  = "bit:or($TomModuleLookUp1, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp2"  = "bit:or($TomModuleLookUp2, bit:shl(3,$SetPosition))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDLOOP!][!/*

*/!][!ENDLOOP!][!/*
*/!][!/* For Debug
Tom Lookup1 is [!"num:inttohex($TomModuleLookUp1)"!]
Tom Lookup2 is [!"num:inttohex($TomModuleLookUp2)"!]
*/!][!ENDSELECT!][!/*
*/!][!/* Generating variables for Configuration usage */!][!/*
*/!][!/* TOM Usage Bit Coded Info */!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "15"!][!/*
*/!][!IF "bit:and($TomModuleLookUp1, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage0" = "bit:or($TomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "31"!][!/*
*/!][!IF "bit:and($TomModuleLookUp2, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage0" = "bit:or($TomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
         For TOM TGC Usage bit Coded Information 
*/!][!FOR "Count1" = "0" TO "3"!][!/*
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($TomUsage0,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomTGCUsage0" = "bit:or($TomTGCUsage0, bit:shl($BuildTemp, $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!/* 
*******************************************************************************
*******************************************************************************
                              Configuration for TOM
*******************************************************************************
*******************************************************************************
*/!][!/*
*/!][!/* To decide if TOM structure should be generated or not */!]
[!VAR "TGCBitCodedInfo" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0)"!][!/* If any TOM Channel is used
*/!][!IF "$ComplexDriverTomConfig = 1"!][!/*
*/!]static const Gtm_TomTgcConfigGroupType Gtm_kTomTgcConfigGroup[!"$ModuleId"!][] =
{
[!/* This structure is available only for those channels configured as Complex Driver
 Handling for Tom Modules 0 and 1   
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!]
};

[!/* To generate GTM_TOMChannelConfig structure 
*/!]static const Gtm_TomChannelConfigType Gtm_kTomChannelConfig[!"$ModuleId"!][]=
{
[!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*  
*/!][!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!]
};
[!ENDIF!][!/* IF "$ComplexDriverTomConfig = 1"
*/!][!/* Generation of GTM_TOMTGCConfig
*/!]static const Gtm_TomTgcConfigType Gtm_kTomTgcConfig[!"$ModuleId"!][] =
{
[!VAR "TGCConfigureCount" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!]
};

static const Gtm_TomConfigType Gtm_kTomConfig[!"$ModuleId"!][] = 
{
[!VAR "TomConfigureCount"  = "num:i(-1)"!][!/* To identify the index of the Tom Channel Config structure
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!]
};
[!ENDIF!][!/* [!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0)"!]
*/!][!/* 




*******************************************************************************
*******************************************************************************
                          Configuration for TIM
*******************************************************************************
*******************************************************************************
*/!][!/* Validation of TIM from ICU */!][!/*
*/!][!VAR "IcuId" = "$ModuleId"!][!/*
*/!][!VAR "TimModuleLookUp1" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup1" = "num:i(0)"!][!/*
*/!][!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: ICU: Reference cell [!"@name"!] not provided - configure AssignedHwUnit
[!ENDASSERT!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "TimChannel") = 'true'"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./IcuAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp1"  = "bit:bitset($TimModuleLookUp1, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup1"  = "bit:bitset($TimTimeStampLookup1, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/* IF "contains($ChannelLocation, "TimChannel") = 'true'"
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/* Validation of TIM from Complex */!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "num:i(0)"!][!/*
*/!][!LOOP "Tim/*"!][!/*
*/!][!LOOP "TimChannel/*"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "1"!][!/*  
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp1"  = "bit:bitset($TimModuleLookUp1, num:i($SetPosition + 1))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/*
*/!][!/* Generating variables for Configuration usage */!][!/*
*/!][!/* TIM Usage Bit Coded Info */!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!VAR "TimFltCount" = "num:i(0)"!][!/*
*/!][!VAR "TimUsage0" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($TimModuleLookUp1, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage0" = "bit:bitset($TimUsage0,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!/* Generating TIM Filter Structure 
*/!][!IF "$TimModuleLookUp1 != 0"!][!/*
*/!][!VAR "TimFltFirstTime" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!IF "$TimFltFirstTime = num:i(1)"!][!/*
*/!]};
[!ENDIF!][!/* IF "$TimFltFirstTime = num:i(1)
*/!][!ENDIF!][!/* [!IF "$TimModuleLookUp1 != 0"!]
*/!][!/* TIM Config Structure */
*/!][!VAR "TimSel0" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TbuUsageInTim" = "num:i(0)"!][!/* For Port Configuration
*/!][!IF "$TimModuleLookUp1 != 0"!][!/*
*/!]

static const Gtm_TimConfigType Gtm_kTimConfig[!"$ModuleId"!][] =
{
[!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp1", "TimTimeStampLookup"="$TimTimeStampLookup1", "ModuleNumber"="0"!][!/*
*/!]
};
[!ENDIF!]
static const Gtm_ModUsageConfigType Gtm_kModUsage[!"$ModuleId"!] =
{  
   /*TIM Module Usage */
    [!/*
*/!][!VAR "TotalGtmTimConf" = "num:i(-1)"!][!/* Holds the no of Tim channels configured for GTM complex driver
*/!][!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
    {   /*TOM module Usage */[!/*
*/!]
     /*TOM Module 0 Usage*/[!/*
*/!][!VAR "TotalGtmTomConf" = "num:i(-1)"!][!/* Holds the no of Tim channels configured for GTM complex driver
*/!][!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
     /*TOM Module 1 Usage*/[!/*
*/!]
[!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!],[!/*
*/!]
  }

};

[!/*
*******************************************************************************
*******************************************************************************
                  Configuration for TBU Connection
*******************************************************************************
*******************************************************************************
*/!][!/*
*/!][!VAR "TbuPresent" = "num:i(0)"!][!/*
*/!][!IF "node:exists(Tbu/*[1])"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(Tbu/*[1]/TbuChannel/*)"!][!/*
*/!][!IF "(node:value(./TbuChannelUsage) = 'USED_BY_GTM_DRIVER') or (bit:getbit($TbuUsageInTim, $LoopCount))"!][!/*
*/!][!VAR "TbuPresent" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDIF!][!/*


*/!][!IF "$TbuPresent = num:i(1)"!][!/*
*/!]
static const Gtm_TbuConfigType Gtm_kTbuConfig[!"$ModuleId"!][GTM_NO_OF_TBU_CHANNELS] = 
{
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(Tbu/*[1]/TbuChannel/*)"!][!/*
*/!]  {[!/*
*/!][!IF "(node:value(./TbuChannelUsage) = 'USED_BY_GTM_DRIVER') or (bit:getbit($TbuUsageInTim, $LoopCount))"!][!/*
*/!][!IF "node:value(./TbuEnableChannel) = 'true'"!][!/*
*/!][!VAR "TempTbuVal" = "num:i(1)"!][!/*   
*/!][!ELSE!][!/*
*/!][!VAR "TempTbuVal" = "num:i(0)"!][!/*     
*/!][!ENDIF!][!/*
*/!][!IF "contains(node:name(.), 0)"!][!/* If Tbu Channel 0 */!][!/*
*/!]  Gtm_lTbuBuildControl([!"./TbuChannelResolution"!], [!"./TbuChannelClockSource"!], [!"$TempTbuVal"!]U),[!/* 
*/!][!ELSE!][!/*
*/!]  Gtm_lTbuBuildControl([!"./TbuChannelModeSelect"!], [!"./TbuChannelClockSource"!], [!"$TempTbuVal"!]U),[!/* 
*/!][!ENDIF!][!/*
*/!]  [!"./TbuTimebaseValue"!]U[!/*  
*/!][!ELSE!][!/*
*/!]  GTM_SETUNUSED8 ,0x00000000U [!/*
*/!][!ENDIF!][!/*  
*/!]  },
[!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]};[!/*
*/!][!ENDIF!][!/*
*/!]

[!/*
*******************************************************************************
*******************************************************************************
                        Configuration for ADC Connection
*******************************************************************************
*******************************************************************************
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!]
static const uint8 Gtm_kAdcConnections[!"$ModuleId"!][GTM_NO_OF_ADC_MODULES] = 
{
[!LOOP "node:order(./GtmConnections/*[1]/GtmTriggerForAdc/*)"!][!/*
*/!][!VAR "SelectTrigger0" = "text:split(./GtmTrigger0Select, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SelectTrigger1" = "text:split(./GtmTrigger1Select, '_')[position()-1 = 1]"!][!/*
*/!]  [!"num:inttohex(bit:or(num:i($SelectTrigger0), bit:shl(num:i($SelectTrigger1), 4)),2)"!]U,[!/*
*/!][!ENDLOOP!]
};
[!ENDIF!][!/*
*/!][!/*
******************************************************************************
******************************************************************************
                       Configuration for Port Configuration
******************************************************************************
******************************************************************************
*/!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0)"!][!/*
*/!][!IF "$IsBmdUsed = 'true'"!][!/*
*/!][!VAR "ToutValue" = "num:i(0)"!][!/*
*/!][!VAR "PrepareString" = "num:i(0)"!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!IF "node:empty(./GtmConnections/*[1]/GtmToutConnections/*[1])"!][!/*
*/!][!VAR "ToutMajorCount" = "num:i(0)"!][!/*  
*/!][!LOOP "(./GtmConnections/*[1]/GtmToutConnections/*)"!][!/*
*/!][!VAR "ToutCount" = "num:i(0)"!][!/*
*/!][!LOOP "(./GtmToutSelect/*)"!][!/*
SELECT_TIMER_A
*/!][!VAR "ToutValue" = "text:split(node:value(./GtmTimerSelect), '_')[position()-1 = 2]"!][!/*
*/!][!IF "$ToutValue = 'A'"!][!/*
*/!][!VAR "ToutValue" = "num:i(0)"!][!/*
*/!][!ELSEIF "$ToutValue = 'B'"!][!/*
*/!][!VAR "ToutValue" = "num:i(1)"!][!/*
*/!][!ELSEIF "$ToutValue = 'C'"!][!/*
*/!][!VAR "ToutValue" = "num:i(2)"!][!/*
*/!][!ELSEIF "$ToutValue = 'D'"!][!/*
*/!][!VAR "ToutValue" = "num:i(3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "PrepareString" = "bit:or($PrepareString , bit:shl($ToutValue,($ToutCount * 2)))"!][!/*
*/!][!VAR "ToutCount" = "$ToutCount + 1"!][!/*
*/!][!ENDLOOP!][!/* "(./GtmToutSelect/*)"
*/!][!VAR "TempStore" = "var:set(concat('ToutSel', num:i($ToutMajorCount)),$PrepareString)"!][!/*
*/!][!VAR "PrepareString" = "num:i(0)"!][!/*
*/!][!VAR "ToutMajorCount" = "$ToutMajorCount + 1"!][!/*
*/!][!ENDLOOP!][!/* "(./GtmConnections/*[1]/GtmToutConnections/*)"
*/!][!ENDIF!][!/* "node:empty(./GtmConnections/*[1]/GtmToutConnections/*[1])"
*/!][!ENDIF!][!/* "node:exists(./GtmConnections/*[1])"
*/!][!ENDIF!][!/* "$IsBmdUsed = 'true'"
*/!]

static const Gtm_PortConfigType Gtm_kPortConfig[!"$ModuleId"!] =
{
  {
    [!"num:inttohex($TimSel0,8)"!]U,
  },
  {
    [!"num:inttohex($ToutSel0,8)"!]U,
    [!"num:inttohex($ToutSel1,8)"!]U,
    [!"num:inttohex($ToutSel2,8)"!]U,
    [!"num:inttohex($ToutSel3,8)"!]U,
    [!"num:inttohex($ToutSel4,8)"!]U,
    [!"num:inttohex($ToutSel5,8)"!]U,
    [!"num:inttohex($ToutSel6,8)"!]U,
    [!"num:inttohex($ToutSel7,8)"!]U,
  }
};
[!ENDIF!][!/*
*/!][!/*
********************************************************************************
********************************************************************************
                         Configuration for Module Configuration
********************************************************************************
********************************************************************************
*/!][!/* 
*/!]
static const Gtm_ModuleConfigType Gtm_kModuleConfig[!"$ModuleId"!] =
{

  [!"node:value(GtmGeneral/GtmSleepMode)"!],  /* Module Sleep Mode */
  [!"GtmGeneral/GtmGlobalClkDivNumerator"!]U,  /* Global Clock Configuration - Numerator */
  [!"GtmGeneral/GtmGlobalClkDivDenominator"!]U,/* Global Clock Configuration - Denominator */
  
[!IF "node:exists(GtmAccessEnable/*[1])"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*  
*/!][!FOR "LoopCountTemp" = "0" TO "31"!][!/* Loop through the 32 bits of GtmEnableAccForTagId
*/!][!VAR "BitName" = "concat('GtmEnableAccForTagId_',$LoopCountTemp)"!][!/*
*/!][!SELECT "./GtmAccessEnable/*"!][!/*
*/!][!SELECT "./GtmEnableAccForTagId/*[@name=$BitName]"!][!/*
*/!][!IF "node:value(./GtmEnableAccessForTagId) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDSELECT!][!/*	
*/!][!ENDSELECT!][!/*	
*/!][!ENDFOR!][!/*

*/!]  [!"num:inttohex($BuildReg,8)"!]U,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
[!ELSE!][!/*
*/!]  0xFFFFFFFFU,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
[!ENDIF!][!/*
*/!][!IF "$TimModuleLookUp1 != 0"!][!/*
*/!][!VAR "TimMergeLookUp1" = "$TimModuleLookUp1"!]
  {  [!"num:inttohex($TimMergeLookUp1, 4)"!]U
  },    /* TIM Module Usage by GTM and ICU driver*/
  {  [!"num:inttohex($TimUsage0,2)"!]U
  },  /* TIM Usage */
  &Gtm_kTimConfig[!"$ModuleId"!][0],  /* TIM Configuration Pointer */
[!ELSE!][!/*  
*/!]  {0U},
  {0U},  /* TIM Usage */  
  NULL_PTR,  /* TIM Configuration Pointer */
[!ENDIF!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0)"!][!/* If any TOM Channel is used
*/!]  {[!"num:inttohex($TomTGCUsage0,2)"!]U},  /* TOM TGC Usage */
  &Gtm_kTomTgcConfig[!"$ModuleId"!][0],  /* TOM TGC Configuration Pointer */
  {[!"num:inttohex($TomModuleLookUp1, 8)"!]U,
   [!"num:inttohex($TomModuleLookUp2,8)"!]U,[!/* 
   */!]
   },
  {[!"num:inttohex($TomUsage0,8)"!]U
  },  /* TOM Usage */
  &Gtm_kTomConfig[!"$ModuleId"!][0],  /* TOM Configuration Pointer */
[!ELSE!][!/*
*/!]  {0U},  /* TOM TGC Usage */
  NULL_PTR,  /* TOM TGC Configuration Pointer */
  {[!/*
*/!][!VAR "TomCount" = "ecu:get('Gtm.NumberOfTomModules')"!][!/*
*/!][!VAR "TomChannelCount" = "ecu:get('Gtm.NumberOfTomChannels')"!][!/*
*/!][!VAR "TotalTomChannel" = "$TomCount * $TomChannelCount"!][!/*
*/!][!FOR "ModuleIndex" = "1" TO "(($TotalTomChannel - 1) div 16) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]},  
  {
[!FOR "ModuleIndex" = "1" TO "(($TotalTomChannel - 1) div 32) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]
  },  /* TOM Usage */
  NULL_PTR,  /* TOM Configuration Pointer */  
[!ENDIF!]
  &Gtm_kModUsage[!"$ModuleId"!], /* Configuration for GTM Usage by other modules */
  &Gtm_kGeneralConfig[!"$ModuleId"!],  /* GTM General Configuration */
[!IF "$TbuPresent = num:i(1)"!][!/*
*/!]  &Gtm_kTbuConfig[!"$ModuleId"!][0],  /* TBU Configuration Pointer */
[!ELSE!][!/*
*/!]  NULL_PTR,  /* TBU Configuration Pointer */
[!ENDIF!][!/*
*/!]
[!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!]  &Gtm_kAdcConnections[!"$ModuleId"!][0],  /* Adc Connections Configuration Pointer*/
[!ELSE!][!/*
*/!]
  NULL_PTR,  /* Adc Connections Configuration Pointer*/
[!ENDIF!][!/*
*/!]  {
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmTtcanTrigger/*)"!][!/*
*/!][!VAR "TriggerNumber" = "text:split(./GtmTriggerSelect, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TriggerNumber" = "text:split($TriggerNumber, 'EL')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($TriggerNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount +  4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]    [!"num:inttohex($BuildReg,4)"!]U,  /* Ttcan Connections Configuration*/
  },
};
[!/*
*/!][!ENDSELECT!][!/* SELECT "GtmConfiguration/*[1] 
*/!][!IF "((bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or $TimModuleLookUp1 != 0) "!][!/*
*/!][!VAR "PortConfigPresent" = "bit:bitset($PortConfigPresent, $ModuleId)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDSELECT!][!// [!SELECT "node:ref($McuSelectIndex)"!]
[!ENDFOR!][!/* FOR "ModuleId" ="num:i(0)" TO "(num:i($TotalMcuConfig)-1)"
*/!][!/*
********************************************************************************
********************************************************************************
               Configuration for Config Root Structure
********************************************************************************
********************************************************************************
*/!][!/* 
*/!]const Gtm_ConfigType Gtm_ConfigRoot[GTM_CONFIG_COUNT]  =
{
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!/*
*/!]  {
    /*  GTM Module Clock Settings  */
[!IF "bit:getbit($ClockConfigExist,$ModuleIndex) = num:i(1)"!][!/*
*/!]    &Gtm_kClockSetting[!"$ModuleIndex"!],
[!ELSE!][!/*
*/!]    NULL_PTR, 
[!ENDIF!][!/*
*/!]    /*  Pointer to Gtm Configuration structure  */
[!IF "bit:getbit($PortConfigPresent, $ModuleIndex) = 1"!][!/*
*/!]    &Gtm_kPortConfig[!"$ModuleIndex"!],
[!ELSE!][!/*
*/!]    NULL_PTR,
[!ENDIF!][!/*  
*/!]    &Gtm_kModuleConfig[!"$ModuleIndex"!],
  },
[!ENDFOR!][!/*
*/!]};
#define MCU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!ELSE!][!//
/*******************************************************************************
**                      GTM Not Configured                                    **
*******************************************************************************/
[!ENDIF!][!//  [!IF "$TotalGtmConfig > num:i(0)"!]
[!ENDSELECT!][!//[!SELECT "as:modconf('Mcu')[1]"!][!//

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

