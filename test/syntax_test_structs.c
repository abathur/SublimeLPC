// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"

struct StructBlue;
// <- meta.struct.declaration.lpc storage.type.struct.lpc
//     ^ entity.name.struct.declaration.lpc
struct StructOne
// <- meta.struct.definition.lpc storage.type.struct.lpc
//     ^ entity.name.struct.definition.lpc
{
    closure one_a;
//  ^ meta.struct.definition.lpc storage.type.lpc
    float one_b;
    int one_c;
    mapping one_d;
    mixed one_e;
    object one_f;
    string one_g;
    struct StructBlue one_h;
//  ^ meta.struct.definition.lpc meta.block.lpc storage.type.lpc
//         ^ meta.struct.definition.lpc meta.block.lpc storage.type.lpc entity.name.struct.lpc
    symbol one_i;
    object blueprint; //just making sure we don't match efuns somewhere we shouldn't.
};

struct StructTwo (StructOne)
// <- meta.struct.definition.lpc storage.type.struct.lpc
//     ^ entity.name.struct.definition.lpc
//               ^ meta.struct.definition.lpc meta.struct.definition.parent.lpc
//                ^ entity.name.struct.parent.lpc
{
// <- meta.struct.definition.lpc
    closure * two_a;
//  ^ meta.struct.definition.lpc storage.type.lpc
//          ^ meta.struct.definition.lpc storage.type.array.lpc
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
