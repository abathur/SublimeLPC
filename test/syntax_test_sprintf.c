// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
void reset(int arg)
{
	sprintf("decimal=%d, octal=%o, hexadecimal=%x\n", 7, 7, 7);

	sprintf("array=%O\n", ({1, 2, 3}));

	sprintf("%-*#s\n", 80, implode(get_dir("/"), "\n"));

	sprintf("foo");                      // returns "foo"

	sprintf("%s","foo");                 // returns "foo"
	sprintf("%7s","foo");                // returns "    foo"
	sprintf("%-7s","foo");               // returns "foo    "
	sprintf("%|7s","foo");               // returns "  foo  "
	sprintf("%7'.'s","foo");             // returns "....foo"
	sprintf("%-7'+-'s","foo");           // returns "foo+-+-"
	sprintf("%|9'-+'s","foo");           // returns "-+-foo-+-"
	sprintf("%3s","foobarbloh");         // returns "foobarbloh"
	sprintf("%3.6s","foobarbloh");       // returns "foobar"
	sprintf("%6.3s","foobarbloh");       // returns "   foo"
	sprintf("%:6s","foobarbloh");        // returns "foobar"
	sprintf("%:3s","foobarbloh");        // returns "foo"
	sprintf("%*.*s",-7,2,"foobarbloh");  // returns "fo     "

	sprintf("%=12s","this is a very long sentence\n");
						// returns "   this is a\n"
						//         "   very long\n"
						//         "    sentence\n"
	sprintf("%=-12s","this is a very long sentence\n");
						// returns "this is a\n"
						//         "very long\n"
						//         "sentence\n"
	sprintf("%=|12s","this is a very long sentence\n");
						// returns "  this is a\n"
						//         "  very long\n"
						//         "  sentence\n"
	sprintf("%=10.6s","this is a very long sentence\n");
						// returns "      this\n"
						//         "      is a\n"
						//         "      very\n"
						//         "      long\n"
						//         "    senten\n"
						//         "        ce\n"
	sprintf("%#-40.3s",
			"one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\nten\n");
						// returns "one          five         nine\n"
						//         "two          six          ten\n"
						//         "three        seven        \n"
						//         "four         eight        "
	sprintf("%#-40s",
			"one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\nten\n");
						// returns "one     three   five    seven   nine\n"
						//         "two     four    six     eight   ten"

	sprintf("%@-5s",({"foo","bar","bloh"})); // returns "foo  bar  bloh "

	sprintf("%d",123);                   // returns "123"
	sprintf("%7d",123);                  // returns "    123"
	sprintf("%-7d",123);                 // returns "123" (yes, really)
	sprintf("%d/%d",123,-123);           // returns "123/-123"
	sprintf("% d/% d",123,-123);         // returns " 123/-123"
	sprintf("%+d/%+d",123,-123);         // returns "+123/-123"
	sprintf("%+6d/%6d",123,123);         // returns " +123/  123"
	sprintf("%|6d",123);                 // returns "  123" (yes, really)
	sprintf("%|10d",123);                // returns "    123" (yes, really)
	sprintf("%|10d%3s",123,"foo");       // returns "    123   foo"

	sprintf("%o",16);                    // returns "20"
	sprintf("%'0'3o",8);                 // returns "010"
	sprintf("%x",123);                   // returns "7b"
	sprintf("%X",123);                   // returns "7B"

	sprintf("%f",123.5);                 // returns "124"
	sprintf("%8.3f",123.5);              // returns " 123.500"
	sprintf("%E",123.5);                 // returns "1E+02"
	sprintf("%12.4e",123.5);             // returns "  1.2350e+02"
	sprintf("%g",123.5);                 // returns "124"
	sprintf("%8.3G",123.5);              // returns "     124"
	sprintf("%8.6g",123.5);              // returns "   123.5"
}
