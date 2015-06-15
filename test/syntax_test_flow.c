// SYNTAX TEST "Packages/SublimeLPC/LPC.sublime-syntax"
//demonstrate flow-control keywords and some related concepts

void reset()
//<- storage.type.lpc
//    ^ meta.function.lpc
//    ^ entity.name.function.definition.lpc
//        ^ meta.parens.lpc
/*<- meta.function.definition.lpc*/
{
//<- meta.function.lpc meta.block.lpc
    mixed tricky;
//   ^ storage.type.lpc

    if(1)
    //<- keyword.control.lpc
    {
//  ^ meta.block.lpc meta.block.lpc
        switch(10)
//      ^ keyword.control.lpc
//              ^ meta.parens.lpc constant.numeric.integer.lpc
        {
            //<- meta.block.lpc meta.block.lpc meta.block.lpc
            case 0:
//          ^ keyword.control.lpc
//               ^ constant.numeric.integer.lpc
/*                ^ we.need.something.better.than.operator.ternary.for.this */
/* but I don't really know if that means tightening up ternary matching and making a better default scope, or writing a full switch matcher, or an abbreviated case matcher... (it may be the case that some common issues with case statements can be well highlighted if the matching is explicit, but it may also be a lot of werk...) */
                break;
//              ^ keyword.control.lpc
            case 1:
                break;
            case 2..22:
//          ^ keyword.control.lpc
//               ^ constant.numeric.integer.lpc
//                  ^ constant.numeric.integer.lpc
/*                 ^ should.this.be.matched? */
                //fall through
            default:
//          ^ keyword.control.lpc
                return;
//              ^ keyword.control.lpc
        }
        switch("ten")
//      ^ keyword.control.lpc
//              ^ meta.parens.lpc string.quoted.double.lpc
        {
            case 0:
                break;
            case "one":
//          ^ keyword.control.lpc
//                ^ string.quoted.double.lpc
                break;
            case "two":
                //fall through
            default:
                return;
        }
    }
    else if(0)
    {
        for(int x; x < 10; x++)
//      ^ keyword.control.lpc
//           ^ meta.parens.lpc storage.type.lpc
//                   ^ keyword.operator.comparison.lpc
//                          ^ keyword.operator.increment-decrement.lpc
        /* we don't match the for syntax at a deep level currently */
        {
            continue;
//          ^ keyword.control.lpc
        }
    }
    else
    {
        foreach(int i : ({1,2,3}))
//      ^ keyword.control.lpc
//               ^ meta.parens.lpc storage.type.lpc
//                      ^ punctuation.definition.array.begin.lpc
//                              ^ punctuation.definition.array.end.lpc
/*                    ^ we.need.something.better.than.operator.ternary.for.this*/
        /* we don't match the foreach syntax at a deep level currently */
        {
            tricky = i;
        }
    }
    while(tricky > 0)
//  ^ keyword.control.lpc
    {
        tricky--;
    }

    do
        /* we don't match the foreach syntax at a deep level currently */
    {
        if(catch(tricky++, tricky++; nolog))
//      ^ keyword.control.lpc
//          ^ meta.function-call.lpc support.function.efun.lpc
        /* we don't match the catch syntax at a deep level currently */
        {
            catch(tricky++, tricky++; publish);
            catch(tricky++, throw("oops"); reserve tricky*tricky);
        }
    } while(tricky < 10);
//      ^ keyword.control.lpc
}
