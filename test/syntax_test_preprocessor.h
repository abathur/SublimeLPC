// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
#if 0
Test out the preprocessor
#elif 0
#define ASSERT _setAssertLocation(__FILE__+ " " +__LINE__),assert
#else
#define crouching_tiger_hidden_macro(I,A) member((A),(I))
#endif

#define ST_BASE __DIR__ + "syntax_test_"

#ifndef INHERIT_TEST
#define INHERIT_TEST ST_BASE + "operators.c"
#endif
#define TEST2 2
#define TEST3 /* stay in school */ ({1, "two", 3.3333})
#pragma rtt_checks, strict_types

#undef TEST3 3

#echo //test (the presence of this comment breaks the next line, happens not just for echo)
#echo test2 //TODO
#echo 1

#line 1

#define VERSION(MAJOR, MINOR, MICRO) ( \
	MAJOR * 1000000 + \
	MINOR * 10000 + \
	MICRO \
	)

#define LDMUD_VERSION VERSION(__VERSION_MAJOR__, __VERSION_MINOR__, __VERSION_MICRO__)
