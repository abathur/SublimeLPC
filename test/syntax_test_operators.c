// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
public int operators()
{
    int operators_a = 10;
//                  ^ keyword.operator.assignment.lpc
    float operators_b;
    return 2, 3;
    return 2 , 3;
    operators_a = 3;
//              ^ keyword.operator.assignment.lpc
    operators_a += 4;
//              ^ keyword.operator.assignment.lpc
    operators_a -= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a &= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a |= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a ^= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a <<= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a >>= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a >>>= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a *= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a %= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a /= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a &&= 1;
//              ^ keyword.operator.assignment.lpc
    operators_a ||= 4;
//              ^ keyword.operator.assignment.lpc
    operators_a -= 3 || 4 != 4 && 5 == 7 ? (3 | 5 ^ 6 & 7) : (4);
//              ^ keyword.operator.assignment.lpc
//                   ^ keyword.operator.logical.lpc
//                        ^ keyword.operator.comparison.lpc
//                             ^ keyword.operator.logical.lpc
//                                  ^ keyword.operator.comparison.lpc
//                                       ^ keyword.operator.ternary.lpc
//                                            ^ keyword.operator.bitwise.lpc
//                                                ^ keyword.operator.bitwise.lpc
//                                                    ^ keyword.operator.bitwise.lpc
//                                                         ^ keyword.operator.ternary.lpc
    operators_a += 3 || 4 >= 4 && 5 << 7 ? (3 | 5 ^ 6 & 7) : (4>>>3);
//              ^ keyword.operator.assignment.lpc
    operators_a = ~4;
//              ^ keyword.operator.assignment.lpc
    operators_b = (float) operators_a;
//              ^ keyword.operator.assignment.lpc
    operators_a++;
//              ^ keyword.operator.increment-decrement.lpc
    operators_a--;
//              ^ keyword.operator.increment-decrement.lpc

    int * operators_c = ({1, 2, 3});
//                    ^ keyword.operator.assignment.lpc
    operators_c[0] = operators_c[<1];
/*              ^ keyword.operator.index.lpc*/
    operators_c[0..1] = operators_c[<1..<2];
/*              ^ keyword.operator.index.lpc*/
/*               ^ keyword.operator.index.range.lpc*/
/*                                  ^ keyword.operator.index.reverse.lpc*/
/*                                   ^ keyword.operator.index.lpc*/


    mapping operators_d;
    operators_d = ([1:2;3, "one":"two";operators_a]);
//              ^ keyword.operator.assignment.lpc
//                ^ punctuation.definition.mapping.begin.lpc
//                   ^ punctuation.separator.mapping.key-value.lpc
//                     ^ punctuation.separator.mapping.value-value.lpc
//                       ^ punctuation.separator.mapping.row.lpc
//                              ^ punctuation.separator.mapping.key-value.lpc
//                                    ^ punctuation.separator.mapping.value-value.lpc
//                                                ^ punctuation.definition.mapping.end.lpc
    operators_d[1, 1] = operators_d["one", 1];
//                    ^ keyword.operator.assignment.lpc
/*                                         ^ keyword.operator.index.lpc*/
/*              ^ keyword.operator.index.lpc*/
/*               ^ punctuation.separator.mapping.index.lpc*/
/*                 ^ keyword.operator.index.lpc*/
/*                                      ^ keyword.operator.index.lpc*/
/*                                       ^ punctuation.separator.mapping.index.lpc*/
/*                                         ^ keyword.operator.index.lpc*/
    implode(({({"one", "two"}), "three"})...);
//          ^ punctuation.definition.array.begin.lpc
//            ^ punctuation.definition.array.begin.lpc
//                           ^ punctuation.definition.array.end.lpc
//                                     ^ punctuation.definition.array.end.lpc
//                                        ^ keyword.operator.flatten.lpc
/*                   ^ punctuation.separator.array.value.lpc*/
/*                            ^ punctuation.separator.array.value.lpc*/
}
