// SYNTAX TEST "Packages/SublimeLPC/LPC.sublime-syntax"
#if 0
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
//  ^ constant.numeric.integer.lpc
Test out the preprocessor
// <- comment.other.preprocessor-disabled.lpc
#elif 0
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
//    ^ constant.numeric.integer.lpc
#define ASSERT _setAssertLocation(__FILE__+ " " +__LINE__),assert
// <- meta.preprocessor.macro.lpc
// ^  keyword.other.preprocessor.define.lpc
//       ^ entity.name.constant.preprocessor.lpc
//                                        ^ keyword.operator.arithmetic.lpc
//                                          ^ string.quoted.double.lpc punctuation.definition.string.begin.lpc
/*                                  ^ support.constant.predefined.lpc */
/*                                                ^ support.constant.predefined.lpc */
/*  TODO:                        ^   ^    ^ ^^^ ^   ^    ^^^ */
#else
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
#define crouching_tiger_hidden_macro(I,A) member((A),(I))
// <- meta.preprocessor.macro.lpc
// ^  keyword.other.preprocessor.define.lpc
//       ^ meta.preprocessor.macro.lpc entity.name.function.preprocessor.lpc
//                                  ^ meta.preprocessor.macro.parameters.lpc
//                                   ^ variable.parameter.lpc
//                                    ^ punctuation.separator.parameter.lpc
#endif
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
#define ST_BASE __DIR__ + "syntax_test_"
// <- meta.preprocessor.macro.lpc
// ^  keyword.other.preprocessor.define.lpc
//       ^ entity.name.constant.preprocessor.lpc
//                      ^ keyword.operator.arithmetic.lpc
//                        ^ string.quoted.double.lpc punctuation.definition.string.begin.lpc
/*              ^ support.constant.predefined.lpc */

#ifndef INHERIT_TEST
#define INHERIT_TEST ST_BASE + "operators.c"
#endif
#define TEST2 2 //don't do drugs
// <- meta.preprocessor.macro.lpc
// ^ keyword.other.preprocessor.define.lpc
//       ^ entity.name.constant.preprocessor.lpc
//            ^ constant.numeric.integer.lpc
#define TEST3 /* stay in school */ ({1, "two", 3.3333})
// <- meta.preprocessor.macro.lpc
// ^ keyword.other.preprocessor.define.lpc
//       ^ entity.name.constant.preprocessor.lpc
//                                  ^ punctuation.definition.array.begin.lpc
//                                   ^ constant.numeric.integer.lpc
//                                      ^ string.quoted.double.lpc punctuation.definition.string.begin.lpc
//                                              ^ constant.numeric.float.lpc
//                                                   ^ punctuation.definition.array.end.lpc
#pragma rtt_checks, strict_types
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
//TODO: does more explicit matching add anything?

#undef TEST3
// <- meta.preprocessor.undef.lpc
// ^ keyword.other.preprocessor.lpc

#echo test2
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc
#echo 1
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc

#line 1
// <- meta.preprocessor.directive.lpc keyword.other.preprocessor.lpc

#define VERSION(MAJOR, MINOR, MICRO) ( \
    MAJOR * 1000000 + \
    MINOR * 10000 + \
    MICRO \
    )

#if 0
#define VERSION(MAJOR, MINOR, MICRO) ( \
// <- meta.preprocessor.macro.lpc
// ^  keyword.other.preprocessor.define.lpc
//       ^ meta.preprocessor.macro.lpc entity.name.function.preprocessor.lpc
//             ^ meta.preprocessor.macro.parameters.lpc
//               ^ variable.parameter.lpc
//                   ^ punctuation.separator.parameter.lpc
//                                     ^ punctuation.separator.continuation.lpc keyword.other.line-continuation.lpc
    MAJOR * 1000000 + \
// <- meta.preprocessor.macro.lpc
//                    ^ punctuation.separator.continuation.lpc keyword.other.line-continuation.lpc
    MINOR * 10000 + \
// <- meta.preprocessor.macro.lpc
//                  ^ punctuation.separator.continuation.lpc keyword.other.line-continuation.lpc
    MICRO \
// <- meta.preprocessor.macro.lpc
//        ^ punctuation.separator.continuation.lpc keyword.other.line-continuation.lpc
    )
// <- meta.preprocessor.macro.lpc
#endif

#define LDMUD_VERSION VERSION(__VERSION_MAJOR__, __VERSION_MINOR__, __VERSION_MICRO__)
// <- meta.preprocessor.macro.lpc
// ^  keyword.other.preprocessor.define.lpc
//       ^ entity.name.constant.preprocessor.lpc
/*                                  ^ support.constant.predefined.lpc */
/*                                                ^ support.constant.predefined.lpc */
/*                                                                    ^ support.constant.predefined.lpc */
