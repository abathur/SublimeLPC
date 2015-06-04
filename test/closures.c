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
