// SYNTAX TEST "Packages/SublimeLPC/LPC.sublime-syntax"
// syntax highlighting test for LPC
/* This test file (and others in this directory) should demonstrate all major features of LPC as well as some common syntactical edge cases for the purpose of testing the robustness of the syntax highlighter. This file should successfully compile (at least on 3.5.x)... */


#include <strings.h>
// <- meta.preprocessor.include.lpc keyword.other.preprocessor.include.lpc
//       ^ meta.preprocessor.lpc meta.preprocessor.include.lpc string.quoted.other.lt-gt.include.lpc punctuation.definition.string.begin.lpc
#include "syntax_test_preprocessor.h"
// <- meta.preprocessor.include.lpc keyword.other.preprocessor.include.lpc
//       ^ meta.preprocessor.lpc meta.preprocessor.include.lpc string.quoted.double.include.lpc punctuation.definition.string.begin.lpc

/* Test inheritance options */
inherit INHERIT_TEST;
// <- meta.inherit.lpc keyword.other.inherit.lpc
//      ^ entity.other.inherit.lpc
public functions private variables inherit ST_BASE + "closures.c";
// <- meta.inherit.lpc
// ^ meta.modifiers.inherit.lpc storage.modifier.inherit.lpc
//     ^ storage.type.inherit.lpc
//               ^ meta.modifiers.inherit.lpc storage.modifier.inherit.lpc
//                       ^ storage.type.inherit.lpc
//                                 ^ keyword.other.inherit.lpc
//                                                    ^ entity.other.inherit.lpc
public functions private variables virtual inherit ST_BASE + "flow.c";
// <- meta.inherit.lpc
// ^ meta.modifiers.inherit.lpc storage.modifier.inherit.lpc
//     ^ storage.type.inherit.lpc
//               ^ meta.modifiers.inherit.lpc storage.modifier.inherit.lpc
//                       ^ storage.type.inherit.lpc
//                                 ^ keyword.other.inherit.lpc
//                                                    ^ entity.other.inherit.lpc

default private variables public functions;

//just inheriting other tests now
inherit ST_BASE + "structs.c";
inherit ST_BASE + "sprintf.c";

public int operators()
{
	syntax_test_operators::operators();
}

//modifiers, declarations, definitions, literals, and assignments are also all tested here;
//implicitly tests efuns if they aren't tested better elsewhere; closures partially tested via literals, but they're more thoroughly exercised in closures.c
#include "syntax_test_types.c"

//play with indexing
void indexing()
{
	//arrays
	types_literal_array_c[0];
	int one = 1;
	types_literal_array_c[one];
	types_literal_array_c[one] += "test";
	types_literal_array_c[0..];
	types_literal_array_c[>0..];
	types_literal_array_c[>0];
	types_literal_array_c[<1..];
	types_literal_array_c[<1];
	types_literal_array_c[0..<2];
	types_literal_array_c[..<1];

	//mappings
	types_literal_f["one"];
	types_literal_f["one", 1];
	types_literal_f[1, 0];
}

void reset(int arg)
{
	"*"::reset();
	efuns();
	operators();
	indexing();
	types();

	object obj;
	obj = this_object();
	obj = efun::this_object();
	this_object();
	efun::this_object();
}
