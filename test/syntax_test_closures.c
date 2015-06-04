// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
object efuns()
{
	this_object();
	efun::this_object();

	//this isn't detected properly, but not sure if I should fix; it's valid LPC, but it may be fine it it shows up as an error, since there's no assignment to make use of the closure; the minimal use case
	#'this_object;
	/* works fine here: */
	if(funcall(#'this_object))
	{
		return #'this_object;
	}

	object obj;
	obj = this_object();
	obj = efun::this_object();
	obj = #'this_object;
}

void reset(int arg)
{
	funcall(#'efuns); //implicit lfuns test
}

int foo(int x)
{
	return ((x*2) > 42);
}

closure factory (int arg)
{
	return function int (int val) { return val * arg; }; //TODO: this seems to leak scope
}

closure factory2 (int arg)
{
	return function int (int val) { return val * arg++; };
}

closure factory3 (int arg)
{
    return function int (int val) : int y, x = 2 * arg;
                                    int z
    	{ return val * x; };
}

/* documented closure examples (changed enough to get them compiling) */
void documented()
{
	funcall(#'write,"hello");
	filter(({ "bla","foo","bar" }),#'write);
	int * test = filter(({ 10,50,30,70 }),#'>,42);
	funcall(#'>,4,5);
	funcall(symbol_function("write"),"foobar");
	filter(({ 10,50,30,70 }),#'foo);
	filter(({ 10,50,30,70 }), (: ($1 * 2) > 42 :));
	filter(({ 10,50,30,70 }), (: return ($1 * 2) > 42; :));
	filter( ({ 10, 50, 30, 70 }),
		(:
			string *s;
			s = map(users(), (: $1->query_name() :));
            return s[random(sizeof(s))] + ($1 * 2);
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
    lambda(0, //TODO: argumentative oddity (and obviously a break in comment parsing)
    	({
    		(#'sizeof),
            quote(({ 10,50,30,70 }))
        })
    );
    lambda(0, //TODO: argumentative oddity (and obviously a break in comment parsing)
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
			({ (#'write),"hello world!" }),
			({ (#'say),"Foobar." })
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
              	({ (#'+=),'i,1 })    // increase i
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
			({ (#'write),"grin" })
			({ (#'?!),               // ifnot
				({ (#'random),10 }),  //       (random(10))
				({ (#'return),100 })  //   return 100;
			})
        })
    );
    lambda(0, ({ #'[, quote(({10,50,30,70})), 2}));
    lambda(0, ({ #'[, (["x":10;50, "y":30;70]), "x", 1}));
    lambda(0, ({ #'[..<], quote(({ 0,1,2,3,4,5,6,7 })), 2, 3}));
    lambda(0, ({ #'([, ({ "x",1,2,3 }), ({ "y",4,5,6 }) })); //TODO: indent problem caused here
   	lambda(0, ({ #'([, ({ 1, '({ 2 }) }) }) );

	closure f1 = factory(2);
	closure f2 = factory(3);
	funcall(f1, 3);
	funcall(f2, 3);

	closure f = factory2(2);
	funcall(f, 3);
	funcall(f, 3);

	sort_array(({5,1,4,2,3}), function { return $1 < $2; } ); //TODO: also leaks scope
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
		filter(map(users(), (:all_inventory(environment($1)):)), #'living),
		lambda(
			({ 'liv }),
			({'#, ,
				({#'=, 'hp,
					({#'call_other, 'liv, "QueryHP" })
				}),
				({#'?,
					({#'>, 'hp, 10 }),
					({#'call_other, 'liv, "SetHP",
						({#'-, 'hp, 10 })
					})
                })
          	})
        ) // of lambda()
    );
}
/*
closure test6a1 = (:"I hope so" + implode(test5g, test2g) + $1:);
closure test6a2 = #'this_player;
closure test6a3 = lambda( ({ 'x }), ({ #'environment, 'x }) );
closure test6a4 = function int (int val) : int x = 2 * arg { return val * x; };
test5f = map(
		filter(all_inventory(room), #'living),
		lambda(
			({ 'liv }),
			({'#, ,
				({#'=, 'hp,
					({#'call_other, 'liv, "QueryHP" })
				}),
				({#'?,
					({#'>, 'hp, 10 }),
					({#'call_other, 'liv, "SetHP",
						({#'-, 'hp, 10 })
					})
                })
          	})
        ) // of lambda()
    );
 */

private varargs struct StructTwo lets_get_post_structural(int * arg1a, struct NahStruct nah, varargs string * extra)
{
	/* efun/operator closures */
	closure test7a = #'[;
	closure test7a = #'[<;
	closure test7a = #'[..];
	closure test7a = #'[..<];
	closure test7a = #'[<..];
	closure test7a = #'[<..<];
	closure test7a = #'[<..;
	closure test7a = #'({;
	closure test7a = #'([;
	closure test7a = #'negate;
	closure test7a = #'efun::negate;
	closure test7a = #'sefun::negate;
	closure test7a = #'::negate;
	closure test7a = #'room::negate;
	closure test7a = #'room::negate;
	closure test7a = #',; 		//({#', <body> <result>})
	closure test7a = #'=;
	closure test7a = #'&;
	closure test7a = #'while; 	//({#'while <test> <result> <body>})
	closure test7a = #'do; 		//({#'do <body> <test> <result>})
	closure test7a = #'||; 		//({#'|| { test } })
	closure test7a = #'&&; 		//({#'&& { test } })
	closure test7a = #'?; 		//({#'? { <test> <result> } [ <result> ] })
	closure test7a = #'?!; 		//({#'?! { <test> <result> } [ <result> ] })
	closure test7a = #'(<; 		//({#'(<, (<Foo>), 1, ({ 2 }), (<Bar>) })
	closure test7a = #'->; 		//({#'->, struct-expression, 'one })
    closure test7a = #'->; 		//({#'->, struct-expression, "one" })
    closure test7a = #'test7a; 	//this is a variable closure, and there's probably no way to tell it apart from an lfun closure without doing more advanced code intel to keep track of available lfuns/vars
}
