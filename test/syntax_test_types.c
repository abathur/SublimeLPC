// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
/* Won't update directly; relies on structs only present when included in lpc.c */
#define CRASH_WARNING 1 //see use below; don't change this value
//SECTION 1: OBJECT-GLOBAL VARIABLES
//basic declarations
closure types_a;
//<-storage.type.lpc
float types_b;
int types_c;
mapping types_d;
mixed types_e;
object types_f;
string types_g;
struct StructBlue types_h;
//<-storage.type.lpc
//     ^ storage.type.lpc entity.name.struct.lpc
symbol types_i;

//array declarations
closure * types_array_a;
//<-storage.type.lpc
//      ^ storage.type.array.lpc
float * types_array_b;
int * types_array_c;
mapping * types_array_d;
mixed * types_array_e;
object * types_array_f;
string * types_array_g;
struct StructBlue * types_array_h;
//<-storage.type.lpc
//     ^ storage.type.lpc entity.name.struct.lpc
//                ^ storage.type.array.lpc
symbol * types_array_i;

//simple literals
float types_literal_a = 1.1333333;
//<-storage.type.lpc
//                        ^ constant.numeric.float.lpc
int types_literal_b = 113333;
//<-storage.type.lpc
//                        ^ constant.numeric.integer.lpc
string types_literal_c = "super calloused" + "fragile mystic";
//<-storage.type.lpc
//                        ^ string.quoted.double.lpc
symbol types_literal_d = 'types_literal_b;
//<-storage.type.lpc
//                        ^ variable.other.symbol.lpc

//simple array literals
float * types_literal_array_a = ({1.113, 3.111});
//<-source.lpc storage.type.lpc
//                                   ^ meta.array.lpc constant.numeric.float.lpc
//                                         ^ meta.array.lpc constant.numeric.float.lpc
int * types_literal_array_b = ({1113, 3111});
//<-source.lpc storage.type.lpc
//                                ^ meta.array.lpc constant.numeric.integer.lpc
//                                     ^ meta.array.lpc constant.numeric.integer.lpc
string * types_literal_array_c = ({"one", "two", "three"});
//<-source.lpc storage.type.lpc
//                                 ^ meta.array.lpc string.quoted.double.lpc
//                                                  ^ meta.array.lpc string.quoted.double.lpc
mixed * types_literal_array_d = ({"one", 1, 1.0});
//<-source.lpc storage.type.lpc
//                                 ^ meta.array.lpc string.quoted.double.lpc
//                                            ^ meta.array.lpc constant.numeric.float.lpc
object * types_literal_array_e = ({this_object(), this_object()});

//complex array literals
#if LDMUD_VERSION >= VERSION(3, 5, 0)
float ** types_literal_array_a = ({({1.113, 3.111})});
//<-storage.type.lpc
//     ^ storage.type.array.lpc
int ** types_literal_array_b = ({({1113, 3111})});
//                                      ^ source.lpc meta.array.lpc meta.array.lpc
string ** types_literal_array_c = ({({"one", "two", "three"})});
mixed ** types_literal_array_d = ({({"one", 1, 1.0})});
object ** types_literal_array_e = ({({this_object(), this_object()})});
#endif


//complex literals
//closure types_literal_e1 = (:"I hope so" + implode(types_literal_array_c, types_literal_c) + $1:);
closure types_literal_e2 = #'this_player;
closure types_literal_e3 = lambda( ({ 'x }), ({ #'environment, 'x }) );
#if CRASH_WARNING
//WARNING: If enabled, the following else block will (in conjunction with some other lines in this file) cause a segfault and hard crash the next time this object is destructed. It's being preprocessor-guarded so we can test syntax highlighting on it without running it.
#else
closure types_literal_e4 = function int (int val) : int x = 2 * types_literal_b { return val * x; };
#endif
mapping types_literal_f = ([1:2;3, "one":"two";"three"]);
//<-storage.type.lpc
//                        ^ meta.mapping.lpc punctuation.definition.mapping.begin.lpc
//                          ^ meta.mapping.key.lpc constant.numeric.integer.lpc
//                           ^ punctuation.separator.mapping.key-value.lpc
//                            ^ meta.mapping.value.lpc constant.numeric.integer.lpc
//                             ^ punctuation.separator.mapping.value-value.lpc
//                              ^ meta.mapping.value.lpc constant.numeric.integer.lpc
//                               ^ punctuation.separator.mapping.row.lpc
//                                   ^ meta.mapping.key.lpc string.quoted.double.lpc
//                                      ^ punctuation.separator.mapping.key-value.lpc
//                                        ^ meta.mapping.value.lpc string.quoted.double.lpc
//                                            ^ punctuation.separator.mapping.value-value.lpc
//                                                ^ meta.mapping.value.lpc string.quoted.double.lpc
//                                                     ^ punctuation.definition.mapping.end.lpc
mapping types_literal_g = ([1, 2, 3, "one", "two", "three"]);
//                        ^ meta.mapping.lpc punctuation.definition.mapping.begin.lpc
//                          ^ meta.mapping.key.lpc constant.numeric.integer.lpc
//                           ^ punctuation.separator.mapping.row.lpc
//                             ^ meta.mapping.key.lpc constant.numeric.integer.lpc
//                              ^ punctuation.separator.mapping.row.lpc
//                                ^ meta.mapping.key.lpc constant.numeric.integer.lpc
//                                 ^ punctuation.separator.mapping.row.lpc

struct StructOne types_literal_g1 = (<StructOne> //valid
//<- source.lpc -meta.mapping.lpc
//<- source.lpc storage.type.lpc
//                                   ^ punctuation.definition.struct.literal.begin.lpc
//                                    ^ entity.name.struct.lpc
//                                                ^ comment.line.double-slash.lpc punctuation.definition.comment.lpc
    one_a: #'this_object, //valid
//  ^ meta.struct.literal.key.lpc
//       ^ punctuation.separator.key-value.struct
//           ^ meta.struct.literal.value.lpc
    one_b: /*valid */1.11, one_c: 111,
    one_d: ([1:2;3, /*valid*/ "four":"five";"six"]),
//                     ^ meta.struct.literal.value.lpc meta.mapping.lpc meta.mapping.key.lpc comment.block.lpc
    one_e: 0 /*valid */|| "zero",
    /*valid*/one_f: this_object(),
    one_g: "string",
//valid
//<-comment.line.double-slash.lpc punctuation.definition.comment.lpc
    one_h: (<StructBlue> three_a: 1, three_b: "ok"/*valid*/),
    one_i: 'wow_much_symbolism,
);
struct StructBlue types_literal_g2 = (<StructBlue> 1, "ok");
/* union types */
#if LDMUD_VERSION >= VERSION(3, 5, 0)

closure|float union_aa;
//<- storage.type.union.lpc storage.type.lpc
//     ^ punctuation.separator.union.lpc
//       ^storage.type.union.lpc storage.type.lpc
closure|float|int|mapping|mixed|object union_ab;
closure|float|int|mapping|mixed|object|string union_ac;

closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol union_a;
<closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol>* union_b;
//<- punctuation.definition.union.array.begin.lpc
/*      ^ punctuation.separator.union.lpc */
//                                                                     ^ punctuation.definition.union.array.end.lpc
closure *|float*|int *|mapping *|mixed *|object *|string *|struct StructBlue *|symbol * union_c;
<closure|float>*|struct StructBlue * union_d;
<closure|float>** union_e; //an array that can contain arrays that are either all float or all closure
//              ^ storage.type.array.lpc
#endif

//SECTION 2: FUNCTIONS
    //declarations
        //simple
closure func_types_a();
//<- storage.type.lpc
//      ^ entity.name.function.declaration.lpc
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
static varargs struct StructBlue * func_complex_types_f(int * arg1, struct StructBlue blue, varargs string * extra);
//<- storage.modifier.function.lpc
//      ^ storage.modifier.function.lpc
//              ^ storage.type.lpc
//                      ^ storage.type.lpc entity.name.struct.lpc
//                               ^ storage.type.array.lpc
//                                    ^ entity.name.function.declaration.lpc
//                                                       ^ storage.type.lpc
//                                                          ^ storage.type.array.lpc
//                                                                            ^ storage.type.lpc entity.name.struct.lpc
//                                                                                          ^ storage.modifier.variable.lpc
//                                                                                                         ^ storage.type.array.lpc
    //definitions
        //simple
#if LDMUD_VERSION >= VERSION(3, 5, 0)
<int|int*>* func_array_types_j()
//<- punctuation.definition.union.array.begin.lpc
//  ^ punctuation.separator.union.lpc
//      ^ storage.type.array.lpc
//       ^ punctuation.definition.union.array.begin.lpc
//        ^ storage.type.array.lpc
//           ^ entity.name.function.definition.lpc
{
    return ({ 1, 2, 3, ({4, 5, 6}), 7, 8, 9});
}
#else
mixed * func_array_types_e()
//    ^ storage.type.array.lpc
//           ^ entity.name.function.definition.lpc
{
    return ({ 1, 2, 3, ({4, 5, 6}), 7, 8, 9});
}
#endif
        //complex
struct StructBlue post_structuralism(int one, struct StructOne two, string three)
//<- storage.type.lpc
//      ^ entity.name.struct.lpc
//                 ^ entity.name.function.definition.lpc
//                                    ^ storage.type.lpc
//                                             ^ storage.type.lpc
//                                                     ^ storage.type.lpc entity.name.struct.lpc
//                                                                    ^ storage.type.lpc
{
    return two->one_h;
/*             ^ keyword.operator.lookup.struct.member.lpc */
/*              ^ entity.name.struct.member.lpc */
    return two->("one_h");
/*                ^ entity.name.struct.member.lpc */
    return two->(three);
/*              ^ entity.name.struct.member.lpc */
}

/* union types */
#if LDMUD_VERSION >= VERSION(3, 5, 0)
private varargs <int|float>*|struct StructOne * lets_get_meta_structural(int|float arg1a, int*|float* arg1b, <int|float>* arg1c, struct StructOne * two, varargs string * extra);

private varargs <int|float>*|struct StructOne * lets_get_meta_structural(int|float arg1a, int*|float* arg1b, <int|float>* arg1c, struct StructOne * two, varargs string * extra)
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

/* test deprecated modifier */
#if LDMUD_VERSION >= VERSION(3, 3, 720)
//not 100% sure the driver will let us use this as a variable name
deprecated int danger = 1;
deprecated int dont_call_me_bro();
deprecated int dont_call_me_bro()
{
    danger = 2; //should be a deprecation warning
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
    string local_types_literal_c = "super calloused" + "fragile mystic";
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
#if CRASH_WARNING
//WARNING: If enabled, the following else block will (in conjunction with some other lines in this file) cause a segfault and hard crash the next time this object is destructed. It's being preprocessor-guarded so we can test syntax highlighting on it without running it.
#else
    closure local_types_literal_e4 = function int (int val) : int x = 2 * local_types_literal_b { return val * x; };
#endif
    mapping local_types_literal_f = ([1:2;3, "one":"two";"three"]);

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
    closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol local_union_a;
    <closure|float|int|mapping|mixed|object|string|struct StructBlue|symbol>* local_union_b;
    closure *|float*|int *|mapping *|mixed *|object *|string *|struct StructBlue *|symbol *local_union_c;
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
    local_types_literal_b = 0x1000 + 0o000 + 0b000 + 'x' + ';' + 'a';

    local_types_literal_c = "super calloused" + "fragile mystic";
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


#if CRASH_WARNING
//WARNING: If enabled, the following else block will (in conjunction with some other lines in this file) cause a segfault and hard crash the next time this object is destructed. It's being preprocessor-guarded so we can test syntax highlighting on it without running it.
#else
    local_types_literal_e4 = function int (int val) : int x = 2 * local_types_literal_b { return val * x; };
#endif
    local_types_literal_f = ([1:2;3, "one":"two";"three"]);

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
