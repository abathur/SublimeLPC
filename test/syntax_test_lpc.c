// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
// syntax highlighting test for LPC
#include <strings.h>
#define ST_BASE __DIR__ + "syntax_test_"

#include ST_BASE + "preprocessor.h"

/* This test file (and others in this directory) should demonstrate all major features of LPC as well as some common syntactical edge cases for the purpose of testing the robustness of the syntax highlighter. This file should successfully compile (at least on 3.5.x)... */

/* Test inheritance options */
inherit INHERIT_TEST;
public functions private variables inherit ST_BASE + "closures.c";
public functions private variables virtual inherit ST_BASE + "flow.c";

default private variables public functions;

//just inheriting other tests now
inherit ST_BASE + "structs.c";
inherit ST_BASE + "sprintf_format.c";

public int operators()
{
	operators::operators();
}

void reset(int arg)
{
	"*"::reset();
	efuns();
}

//modifiers, declarations, definitions, literals, and assignments are also all tested here;
//implicitly tests efuns if they aren't tested better elsewhere; closures partially tested via literals, but they're more thoroughly exercised in closures.c
#include ST_BASE + "types.c"

//play with indexing
void indexing()
{
	//arrays
	types_literal_array_c[0];
	int one = 1;
	types_literal_array_c[one];
	types_literal_array_c[one]++;
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
	types_literal_f[1, 2];
}
