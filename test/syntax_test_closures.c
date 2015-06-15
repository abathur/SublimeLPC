// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
closure efuns()
{
    //this isn't detected properly, but not sure if I should fix; it's valid LPC, but it may be fine it it shows up as an error, since there's no assignment to make use of the closure; the minimal use case (though treating this as an error implies a single variable reference alone on a line should effectively also be an error.)
    #'this_object;  //test
    //
    /* works fine here: */
    if(funcall(#'this_object))
//             ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//              ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//               ^ meta.closure.simple.lpc support.function.efun.lpc
    {
        return #'this_object;
//             ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//              ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//               ^ meta.closure.simple.lpc support.function.efun.lpc
    }

    object obj;
    obj = funcall(#'this_object);
//                ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                 ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                  ^ meta.closure.simple.lpc support.function.efun.lpc
    if(obj)
    {
        return #'efun::this_object;
//             ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//              ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//               ^ meta.closure.simple.lpc meta.function-call.super.lpc
//                   ^ keyword.operator.super.lpc
//                     ^ meta.closure.simple.lpc support.function.efun.lpc
    }
}

int foo(int x)
{
    return ((x*2) > 42);
}

closure factory (int arg)
{
    return function int (int val) { return val * arg; };
//         ^ meta.closure.inline.verbose.lpc keyword.other.closure.inline.verbose.lpc
//                  ^ meta.closure.inline.verbose.lpc storage.type.lpc
}

closure factory2 (int arg)
{
    return function int (int val) : int ignore_me = 1 { return val * arg++; };
//         ^ meta.closure.inline.verbose.lpc keyword.other.closure.inline.verbose.lpc
//                  ^ meta.closure.inline.verbose.lpc storage.type.lpc
//                                 ^ meta.closure.inline.verbose.lpc meta.closure.inline.verbose.context.lpc
}

closure factory3 (int arg)
{
    return function int (int val) : int y, x = 2 * arg; //test
//         ^ meta.closure.inline.verbose.lpc keyword.other.closure.inline.verbose.lpc
//                  ^ meta.closure.inline.verbose.lpc storage.type.lpc
//                                 ^ meta.closure.inline.verbose.lpc meta.closure.inline.verbose.context.lpc
                                    int z   //test
//                                 ^ meta.closure.inline.verbose.lpc meta.closure.inline.verbose.context.lpc
        { return val * x; }; //test
// <-                                meta.closure.inline.verbose.lpc meta.closure.inline.verbose.context.lpc
}

/* documented closure examples (changed enough to get them compiling) */
void documented_complex()
{
    funcall(#'write,"hello");
//          ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//           ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//            ^ meta.closure.simple.lpc support.function.efun.lpc
    filter(({ "bla","foo","bar" }),#'write);
//                                 ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                                  ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                                   ^ meta.closure.simple.lpc support.function.efun.lpc
    int * test = filter(({ 10,50,30,70 }),#'>,42);
//                                        ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                                         ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                                          ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    funcall(#'>,4,5);
//          ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//           ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//            ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    funcall(symbol_function("write"),"foobar");
    filter(({ 10,50,30,70 }), #'foo);
//                            ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                             ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                              ^ meta.closure.simple.lpc meta.closure.simple.lfun.lpc
    filter(({ 10,50,30,70 }), (: ($1 * 2) > 42 :)); /* TODO indentation issue, check for scope problems */
//                            ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.begin.lpc
//                                ^ meta.closure.inline.literal.lpc meta.closure.inline.literal.parameter.lpc
//                                              ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.end.lpc
    filter(({ 10,50,30,70 }), (: return ($1 * 2) > 42; :));
//                            ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.begin.lpc
//                                       ^ meta.closure.inline.literal.lpc meta.closure.inline.literal.parameter.lpc
//                                                      ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.end.lpc
    filter( ({ 10, 50, 30, 70 }),
        (:
//      ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.begin.lpc
            string *s;  //test
            s = map(users(), (: $1->query_name() :)); //test
//                            ^ meta.closure.inline.literal.lpc meta.function-call.lpc meta.parens.lpc meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.begin.lpc
//                                               ^ meta.closure.inline.literal.lpc meta.function-call.lpc meta.parens.lpc meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.end.lpc
            return s[random(sizeof(s))] + ($1 * 2); //test
        :)
//      ^ meta.closure.inline.literal.lpc punctuation.definition.closure.inline.literal.end.lpc
    );
    lambda(
        ({ 'x }),
//<- meta.closure.lambda.lpc
//        ^ meta.closure.lambda.arguments.lpc
//         ^ meta.symbol.lpc punctuation.definition.symbol.lpc
//          ^ meta.symbol.lpc variable.other.symbol.lpc
        ({
//<- meta.closure.lambda.lpc
//        ^ meta.closure.lambda.function.lpc
            (#'>),
//           ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//            ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//             ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
            ({ (#'*),'x,2 }),
//           ^ punctuation.definition.array.begin.lpc
//              ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//               ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                   ^ meta.symbol.lpc punctuation.definition.symbol.lpc
//                    ^ meta.symbol.lpc variable.other.symbol.lpc
//                      ^ constant.numeric.integer.lpc
//                        ^ punctuation.definition.array.end.lpc
            42
//          ^ meta.closure.lambda.function.lpc constant.numeric.integer.lpc
        })
//<- meta.closure.lambda.lpc meta.closure.lambda.function.lpc
    );
    lambda(0, //test
//         ^ meta.closure.lambda.lpc meta.closure.lambda.arguments.lpc
//             ^ meta.closure.lambda.lpc comment.line.double-slash.lpc punctuation.definition.comment.lpc
        ({  //test
//<- meta.closure.lambda.lpc
//        ^ meta.closure.lambda.function.lpc
//           ^ meta.closure.lambda.function.lpc comment.line.double-slash.lpc punctuation.definition.comment.lpc
            (#'sizeof), //test
//                       ^ meta.closure.lambda.function.lpc comment.line.double-slash.lpc punctuation.definition.comment.lpc
            quote(({ 10,50,30,70 })) //test
//                                    ^ meta.closure.lambda.function.lpc comment.line.double-slash.lpc punctuation.definition.comment.lpc
        }) //test
//          ^ meta.closure.lambda.lpc comment.line.double-slash.lpc punctuation.definition.comment.lpc
    );  //test
    lambda(0,
        ({
            (#'sizeof),
            '({ 10,50,30,70 })
        })
    );
    lambda(
        ({ 'x }),
        ({ (#'?),             // if
            ({ (#'>),'x,5 }),  //    (x > 5)
            ({ (#'*),'x,2 }),  //       result is x * 2;
            ({ (#'<),'x,-5 }), // else if (x < -5)
            ({ (#'/),'x,2 }),  //    result is x/2;
            'x                 // else result is x;
        })
    );
    lambda(
        ({ 'x }),
        ({
            (#',),  // two commas necessary!
            // one for the closure and one as
            // delimiter in the array
            ({ (#'write), "hello world!" }),
            ({ (#'say), "Foobar." })
        })
    );
    lambda(
        0,
        ({
            (#',),            // several things to do ...
            ({ (#'=),'i,0 }),    // i is a local variable of this
                               // lambda-closure and is
                               // initialized with 0 now.
            ({
                (#'while),
                ({ (#'<),'i,10 }),   // condition: i < 10
                42,                  // result is not interesting,
                                  // but we must give one
                ({ (#'write),'i }),  // give out i
                ({ (#'+=),'i,1 })    // increase i
            })
        })
    );
    lambda(
        0,
        ({
            (#',),          // several things to do ...
            ({ (#'=),'i,0 }),  // i is a local variable of this
                              // lambda-closure and is initialized
                              // with 0 now.
            ({
                (#'do),
                ({ (#'write),'i }),  // give out i
                ({ (#'+=),'i,1 }),    // increase i
                ({ (#'<),'i,10 }),   // condition: i < 10
                42                   // result is not interesting
            })
        })
    );
    lambda(
        0,
        ({
            (#'while),// loop
            1,        // condition is 1 ==> endles loop
            42,       // return value (which will never be used)
            ({ (#'write),"grin" }),
            ({ (#'?!),               // ifnot
                ({ (#'random),10 }),  //       (random(10))
                ({ (#'return),100 })  //   return 100;
            })
        })
    );
    lambda(0, ({ #'[, quote(({10,50,30,70})), 2}));
    lambda(0, ({ #'[, (["x":10;50, "y":30;70]), "x", 1}));
    lambda(0, ({ #'[..<], quote(({ 0,1,2,3,4,5,6,7 })), 2, 3}));

    lambda(0, ({ #'([, ({ "x",1,2,3 }), ({ "y",4,5,6 }) }));

    lambda(0, ({ #'([, ({ 1, '({ 2 }) }) }) );

    closure f1 = factory(2);
    closure f2 = factory(3);
    funcall(f1, 3);
    funcall(f2, 3);

    closure f = factory2(2);
    funcall(f, 3);
    funcall(f, 3);

    sort_array(({5,1,4,2,3}), function { return $1 < $2; } );
    sort_array(({5,1,4,2,3}), (: $1 < $2 :) );

    closure timer = lambda(0, ({#'-, ({ #'time }), time() }) );
    int wizards = sizeof(filter(users(), lambda(
        ({'x,}),
        ({#'>=,
            ({#'call_other, 'x, "query_wiz_level",}),
            21
        })
    )));
    map(
        flatten_array(map(users(), (:filter(all_inventory(environment($1)), #'living):))),
        lambda(
            ({ 'liv }),
            ({#', ,
                ({#'=,
                    'hp,
                    ({#'call_other, 'liv, "query_hp" })

                }),
                ({#'?,
                    ({#'>, 'hp, 10 }),
                    ({#'call_other, 'liv, "set_hp",
                        ({#'-, 'hp, 10 })
                    })
                })
            })
        ) // of lambda()
    );
}

int global_var;
void documented_simple()
{
    closure simple_closure;
    /* efun/operator closures */
    simple_closure = #'[;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[<;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[..];
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                        ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[..<];
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                         ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[<..];
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                         ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[<..<];
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                          ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[<..;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                        ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'[,];
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                       ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'({;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'([;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'negate;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc support.function.efun.lpc
    simple_closure = #'efun::negate;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.function-call.super.lpc
//                         ^ meta.closure.simple.lpc keyword.operator.super.lpc
//                           ^ meta.closure.simple.lpc support.function.efun.lpc
    simple_closure = #',;       //({#', <body> <result>})
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'=;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'&;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'while;   //({#'while <test> <result> <body>})
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'do;      //({#'do <body> <test> <result>})
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'||;      //({#'|| { test } })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'&&;      //({#'&& { test } })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'?;       //({#'? { <test> <result> } [ <result> ] })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'?!;      //({#'?! { <test> <result> } [ <result> ] })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'(<;      //({#'(<, (<Foo>), 1, ({ 2 }), (<Bar>) })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'->;      //({#'->, struct-expression, 'one|"one" })
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'+;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'-;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'>;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'<;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'*;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'/;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'++;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'--;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                     ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
//                      ^ meta.closure.simple.lpc meta.closure.simple.operator.lpc
    simple_closure = #'break;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'continue;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'default;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'foreach;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'return;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'sscanf;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc support.function.efun.lpc
    simple_closure = #'switch;
//                   ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                    ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//                      ^ meta.closure.simple.lpc keyword.control.lpc
    simple_closure = #'global_var; //can't syntactically distinguish this from an lfun
}

void reset(int arg)
{
    funcall(#'efuns); //implicit lfuns test
//          ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//           ^ meta.closure.simple.lpc punctuation.definition.closure.simple.lpc
//            ^ meta.closure.simple.lpc meta.closure.simple.lfun.lpc
    documented_simple();
    documented_complex();
}
