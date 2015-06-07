// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
closure efuns()
{
	this_object();
	efun::this_object();

	//this isn't detected properly, but not sure if I should fix; it's valid LPC, but it may be fine it it shows up as an error, since there's no assignment to make use of the closure; the minimal use case (though treating this as an error implies a single variable reference alone on a line should effectively also be an error.)
	#'this_object;	//test
	/* works fine here: */
	if(funcall(#'this_object))
	{
		return #'this_object;
	}

	object obj;
	obj = this_object();
	obj = efun::this_object();
	obj = funcall(#'this_object);
}

int foo(int x)
{
	return ((x*2) > 42);
}

closure factory (int arg)
{
	return function int (int val) { return val * arg; };
}

closure factory2 (int arg)
{
	return function int (int val) { return val * arg++; };
}

closure factory3 (int arg)
{
    return function int (int val) : int y, x = 2 * arg; //test
                                    int z	//test
    	{ return val * x; }; //test
}

/* documented closure examples (changed enough to get them compiling) */
void documented_complex()
{
	funcall(#'write,"hello");
	filter(({ "bla","foo","bar" }),#'write);
	int * test = filter(({ 10,50,30,70 }),#'>,42);
	funcall(#'>,4,5);
	funcall(symbol_function("write"),"foobar");
	filter(({ 10,50,30,70 }), #'foo);
	filter(({ 10,50,30,70 }), (: ($1 * 2) > 42 :));
	filter(({ 10,50,30,70 }), (: return ($1 * 2) > 42; :));
	filter( ({ 10, 50, 30, 70 }),
		(:
			string *s;	//test
			s = map(users(), (: $1->query_name() :)); //test
            return s[random(sizeof(s))] + ($1 * 2);	//test
        :)
    );
    lambda(
    	({ 'x }),
    	({
    		(#'>),
            ({ (#'*),'x,2 }),
            42
        })
    );
    lambda(0, //test
    	({	//test
    		(#'sizeof), //test
            quote(({ 10,50,30,70 })) //test
        }) //test
    );	//test
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
	simple_closure = #'[<;
	simple_closure = #'[..];
	simple_closure = #'[..<];
	simple_closure = #'[<..];
	simple_closure = #'[<..<];
	simple_closure = #'[<..;
	simple_closure = #'[,];
	simple_closure = #'({;
	simple_closure = #'([;
	simple_closure = #'negate;
	simple_closure = #'efun::negate;
	simple_closure = #'negate;
	simple_closure = #',; 		//({#', <body> <result>})
	simple_closure = #'=;
	simple_closure = #'&;
	simple_closure = #'while; 	//({#'while <test> <result> <body>})
	simple_closure = #'do; 		//({#'do <body> <test> <result>})
	simple_closure = #'||; 		//({#'|| { test } })
	simple_closure = #'&&; 		//({#'&& { test } })
	simple_closure = #'?; 		//({#'? { <test> <result> } [ <result> ] })
	simple_closure = #'?!; 		//({#'?! { <test> <result> } [ <result> ] })
	simple_closure = #'(<; 		//({#'(<, (<Foo>), 1, ({ 2 }), (<Bar>) })
	simple_closure = #'->; 		//({#'->, struct-expression, 'one|"one" })
	simple_closure = #'+;
	simple_closure = #'-;
	simple_closure = #'>;
	simple_closure = #'<;
	simple_closure = #'*;
	simple_closure = #'/;
	simple_closure = #'++;
	simple_closure = #'--;
	simple_closure = #'break;
	simple_closure = #'continue;
	simple_closure = #'default;
	simple_closure = #'foreach;
	simple_closure = #'return;
	simple_closure = #'sscanf;
	simple_closure = #'switch;
	simple_closure = #'global_var; //can't syntactically distinguish this from an lfun
}

void reset(int arg)
{
	funcall(#'efuns); //implicit lfuns test
	documented_simple();
	documented_complex();
}
