// SYNTAX TEST "Packages/C/C.sublime-syntax"
/* Won't update directly; relies on structs only present when included in lpc.c */
//SECTION 1: OBJECT-GLOBAL VARIABLES
//basic declarations
closure types_a;
float types_b;
int types_c;
mapping types_d;
mixed types_e;
object types_f;
string types_g;
struct StructBlue types_h;
symbol types_i;

//array declarations
closure * types_array_a;
float * types_array_b;
int * types_array_c;
mapping * types_array_d;
mixed * types_array_e;
object * types_array_f;
string * types_array_g;
struct StructBlue * types_array_h;
symbol * types_array_i;

//simple literals
float types_literal_a = 1.1333333;
int types_literal_b = 113333;
string types_literal_c = "super calloused"+ "fragile mystic";
symbol types_literal_d = 'types_literal_b;

//simple array literals
float * types_literal_array_a = ({1.113, 3.111});
int * types_literal_array_b = ({1113, 3111});
string * types_literal_array_c = ({"one", "two", "three"});
mixed * types_literal_array_d = ({"one", 1, 1.0});
object * types_literal_array_e = ({this_object(), this_object()});

//complex literals
closure types_literal_e1 = (:"I hope so" + implode(types_literal_array_c, types_literal_c) + $1:);
closure types_literal_e2 = #'this_player;
closure types_literal_e3 = lambda( ({ 'x }), ({ #'environment, 'x }) );
closure types_literal_e4 = function int (int val) : int x = 2 * types_literal_b { return val * x; };
mapping types_literal_f = ([1:2;3, "one":"two";"three"]);

//TODO: something goes awry in the struct
struct StructOne types_literal_g1 = (<StructOne>
	one_a: #'this_object,
	one_b: 1.11, one_c: 111,
	one_d: ([1:2;3, "four":"five";"six"]),
	one_e: 0 || "zero",
	one_f: this_object(),
	one_g: "string",
	one_h: (<StructBlue> three_a: 1, three_b: "ok"),
	one_i: 'wow_much_symbolism,
);
struct StructBlue types_literal_g2 = (<StructBlue> 1, "ok");

/* union types */
#if LDMUD_VERSION >= VERSION(3, 5, 0)

closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol|void union_a;
<closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol|void>* union_b;
closure *|float*|int *|mapping *|mixed *|object *|string *|struct StructBlue *|symbol *|void * union_c;
<closure|float>*|struct StructBlue * union_d; //not positive this is valid
#endif

//SECTION 2: FUNCTIONS
	//declarations
		//simple
closure func_types_a();
float func_types_b();
int func_types_c();
mapping func_types_d();
mixed func_types_e();
object func_types_f();
string func_types_g();
struct StructBlue func_types_h();
symbol func_types_i();

		//array
closure * func_array_types_a();
float * func_array_types_b();
int * func_array_types_c();
mapping * func_array_types_d();
mixed * func_array_types_e();
object * func_array_types_f();
string * func_array_types_g();
struct StructBlue * func_array_types_h();
symbol * func_array_types_i();

		//complex
			//access
nomask mapping * func_complex_types_a();
private mapping * func_complex_types_b();
protected mapping * func_complex_types_c();
public struct StructBlue * func_complex_types_d();
static mapping * func_complex_types_e();

			//varargs
static varargs struct StructBlue * func_complex_types_f(int * arg1, struct StructBlue blue, varargs string * extra); //TODO: varargs missed in argument context

	//definitions
		//simple
#if LDMUD_VERSION >= VERSION(3, 5, 0)
<int|int*>* func_array_types_j()
{
	return ({ 1, 2, 3, ({4, 5, 6}), 7, 8, 9});
}
#else
mixed * func_array_types_e()
{
	return ({ 1, 2, 3, ({4, 5, 6}), 7, 8, 9});
}
#endif
		//complex
struct StructBlue post_structuralism(int one, struct StructOne two, string three)
{
	return two->one_h;
	return two->("one_h");
	return two->(three);
}

/* union types */
#if LDMUD_VERSION >= VERSION(3, 5, 0)
private varargs <int|float>*|struct StructBlue * lets_get_meta_structural(int|float arg1a, int*|float* arg1b, <int|float>* arg1c, struct StructOne two, varargs string * extra);

private varargs <int|float>*|struct StructBlue * lets_get_meta_structural(int|float arg1a, int*|float* arg1b, <int|float>* arg1c, struct StructOne * two, varargs string * extra)
{
	if(random(2))
	{
		return ({1, 2.2});
	}
	else
	{
		return two;
	}
}
#endif

//SECTION 3: FUNCTION-LOCAL VARIABLES
void types()
{
	//basic declarations
	closure local_types_a;
	float local_types_b;
	int local_types_c;
	mapping local_types_d;
	mixed local_types_e;
	object local_types_f;
	string local_types_g;
	struct StructBlue local_types_h;
	symbol local_types_i;

	//array declarations
	closure * local_types_array_a;
	float * local_types_array_b;
	int * local_types_array_c;
	mapping * local_types_array_d;
	mixed * local_types_array_e;
	object * local_types_array_f;
	string * local_types_array_g;
	struct StructBlue * local_types_array_h;
	symbol * local_types_array_i;

	//simple literals
	float local_types_literal_a = 1.1333333;
	int local_types_literal_b = 113333;
	string local_types_literal_c = "super calloused"+ "fragile mystic";
	symbol local_types_literal_d = 'local_types_literal_b;

	//simple array literals
	float * local_types_literal_array_a = ({1.113, 3.111});
	int * local_types_literal_array_b = ({1113, 3111});
	string * local_types_literal_array_c = ({"one", "two", "three"});
	mixed * local_types_literal_array_d = ({"one", 1, 1.0});
	object * local_types_literal_array_e = ({this_object(), this_object()});

	//complex literals
	closure local_types_literal_e1 = (:"I hope so" + implode(local_types_literal_array_c, local_types_literal_c) + $1:);
	closure local_types_literal_e2 = #'this_player;
	closure local_types_literal_e3 = lambda( ({ 'x }), ({ #'environment, 'x }) );
	closure local_types_literal_e4 = function int (int val) : int x = 2 * local_types_literal_b { return val * x; };
	mapping local_types_literal_f = ([1:2;3, "one":"two";"three"]);

	//TODO: something goes awry in the struct
	struct StructOne local_types_literal_g1 = (<StructOne>
		one_a: #'this_object,
		one_b: 1.11, one_c: 111,
		one_d: ([1:2;3, "four":"five";"six"]),
		one_e: 0 || "zero",
		one_f: this_object(),
		one_g: "string",
		one_h: (<StructBlue> three_a: 1, three_b: "ok"),
		one_i: 'wow_much_symbolism,
	);
	struct StructBlue local_types_literal_g2 = (<StructBlue> 1, "ok");

/* union types */
#if LDMUD_VERSION >= VERSION(3, 5, 0)
	closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol|void local_union_a;
	<closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol|void>* local_union_b;
	closure *|float*|int *|mapping *|mixed *|object *|string *|struct StructBlue *|symbol *|void * local_union_c;
	<closure|float>*|struct StructBlue * local_union_d; //not positive this is valid
#endif

	//assignments (this is mostly just a repeat of the above sans type)
	//a few globals
	types_literal_a = 11.33333;
	types_literal_b = to_int(types_literal_a);
	types_literal_c += "vexed with halitosis";
	types_literal_g2 = (<StructBlue> 2, "testing");

	//simple literals
	local_types_literal_a = 1.1333333;

	//some more advanced int/char literals
	//TODO: symbol matching too aggressively;
	local_types_literal_b = 0x1000 + 0o000 + 0b000 + 'x' + ';' + 'a';

	local_types_literal_c = "super calloused"+ "fragile mystic";
	local_types_literal_b;

	//simple array literals
	local_types_literal_array_a = ({1.113, 3.111});
	local_types_literal_array_b = ({1113, 3111});
	local_types_literal_array_c = ({"one", "two", "three"});
	local_types_literal_array_d = ({"one", 1, 1.0});
	local_types_literal_array_e = ({this_object(), this_object()});

	//complex literals
	local_types_literal_e1 = (:"I hope so" + implode(local_types_literal_array_c, local_types_literal_c) + $1:);
	local_types_literal_e2 = #'this_player;
	local_types_literal_e3 = lambda( ({ 'x }), ({ #'environment, 'x }) );
	local_types_literal_e4 = function int (int val) : int x = 2 * local_types_literal_b { return val * x; };
	local_types_literal_f = ([1:2;3, "one":"two";"three"]);

	//TODO: something goes awry in the struct
	local_types_literal_g1 = (<StructOne>
		one_a: #'this_object,
		one_b: 1.11, one_c: 111,
		one_d: ([1:2;3, "four":"five";"six"]),
		one_e: 0 || "zero",
		one_f: this_object(),
		one_g: "string",
		one_h: (<StructBlue> three_a: 1, three_b: "ok"),
		one_i: 'wow_much_symbolism,
	);
	local_types_literal_g2 = (<StructBlue> 1, "ok");
#if LDMUD_VERSION >= VERSION(3, 3, 720)
	dont_call_me_bro(); //should be a deprecation warning
#endif
}

/* test deprecated modifier */
#if LDMUD_VERSION >= VERSION(3, 3, 720)
//not 100% sure the driver will let us use this as a variable name
deprecated int deprecated = 1; //TODO: should only match modifiers before type(s)
deprecated int dont_call_me_bro();
deprecated int dont_call_me_bro()
{
	deprecated = 2; //should be a deprecation warning
}
#endif
