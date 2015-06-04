// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
/* struct def */
struct StructBlue;
struct StructOne
{
	/* struct variable types: closure, float, int, mapping, mixed, object, string, struct, symbol, void */
	closure one_a;
	float one_b;
	int one_c;
	mapping one_d;
	mixed one_e;
	object one_f;
	string one_g;
	struct StructBlue one_h;
	symbol one_i;
	object blueprint; //just making sure we don't match efuns somewhere we shouldn't.
};
/*
fixlist:
inherit
struct definition name
#' closure format
 */
 struct StructTwo (StructOne)
{
	/* struct variable array types: closure, float, int, mapping, mixed, object, string, struct, symbol, void */
	closure * two_a;
	float * two_b;
	int * two_c;
	mapping * two_d;
	mixed * two_e;
	object * two_f;
	string * two_g;
	struct StructBlue * two_h;
	symbol * two_i;
};

struct StructBlue
{
	int three_a;
	string three_b;
};

//see types.c for literals
