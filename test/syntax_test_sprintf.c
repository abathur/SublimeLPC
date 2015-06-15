// SYNTAX TEST "Packages/SublimeLPC/LPC.sublime-syntax"
void reset(int arg)
{
    /* examples from sprintf docs */
    sprintf("decimal=%d, octal=%o, hexadecimal=%x\n", 7, 7, 7); /*TODO: something subtle may be going awry here scope-wise; enter doesn't auto-indent*/
//  ^ meta.function-call.lpc support.function.efun.lpc
//              ^ string.quoted.double.lpc
//                   ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                    ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//                     ^ string.quoted.double.lpc
//                             ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//                               ^ string.quoted.double.lpc
//                                             ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                                              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//                                               ^ string.quoted.double.lpc constant.character.escape.lpc

    sprintf("array=%O\n", ({1, 2, 3}));
//                 ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc

    sprintf("%-*#s\n", 80, implode(get_dir("/"), "\n"));

    sprintf("foo");                      /* returns "foo"*/

    sprintf("%s","foo");                 /* returns "foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%7s","foo");                /* returns "    foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%-7s","foo");               /* returns "foo    "*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%|7s","foo");               /* returns "  foo  "*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%7'.'s","foo");             /* returns "....foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.pad.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.pad.string.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%-7'+-'s","foo");           /* returns "foo+-+-"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.pad.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.pad.string.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%|9'-+'s","foo");           /* returns "-+-foo-+-"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.pad.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.pad.string.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%3s","foobarbloh");         /* returns "foobarbloh"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%3.6s","foobarbloh");       /* returns "foobar"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%6.3s","foobarbloh");       /* returns "   foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%:6s","foobarbloh");        /* returns "foobar"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc constant.other.placeholder.field.precision.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%:3s","foobarbloh");        /* returns "foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc constant.other.placeholder.field.precision.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%*.*s",-7,2,"foobarbloh");  /* returns "fo     "*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc

    sprintf("%=12s","this is a very long sentence\n");
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
                        /* returns "   this is a\n"*/
                        /*         "   very long\n"*/
                        /*         "    sentence\n"*/
    sprintf("%=-12s","this is a very long sentence\n");
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
                        /* returns "this is a\n"*/
                        /*         "very long\n"*/
                        /*         "sentence\n"*/
    sprintf("%=|12s","this is a very long sentence\n");
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
                        /* returns "  this is a\n"*/
                        /*         "  very long\n"*/
                        /*         "  sentence\n"*/
    sprintf("%=10.6s","this is a very long sentence\n");
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
                        /* returns "      this\n"*/
                        /*         "      is a\n"*/
                        /*         "      very\n"*/
                        /*         "      long\n"*/
                        /*         "    senten\n"*/
                        /*         "        ce\n"*/
    sprintf("%#-40.3s",
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
            "one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\nten\n");
                        /* returns "one          five         nine\n"*/
                        /*         "two          six          ten\n"*/
                        /*         "three        seven        \n"*/
                        /*         "four         eight        "*/
    sprintf("%#-40s",
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
            "one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\nten\n");
                        /* returns "one     three   five    seven   nine\n"*/
                        /*         "two     four    six     eight   ten"*/

    sprintf("%@-5s",({"foo","bar","bloh"})); /* returns "foo  bar  bloh "*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc

    sprintf("%d",123);                   /* returns "123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%7d",123);                  /* returns "    123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%-7d",123);                 /* returns "123" (yes, really)*/
    sprintf("%d/%d",123,-123);           /* returns "123/-123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("% d/% d",123,-123);         /* returns " 123/-123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%+d/%+d",123,-123);         /* returns "+123/-123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%+6d/%6d",123,123);         /* returns " +123/  123"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%|6d",123);                 /* returns "  123" (yes, really)*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%|10d",123);                /* returns "    123" (yes, really)*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%|10d%3s",123,"foo");       /* returns "    123   foo"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.modifier.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.lpc
//                 ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                  ^ string.quoted.double.lpc constant.other.placeholder.type.lpc

    sprintf("%o",16);                    /* returns "20"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%'0'3o",8);                 /* returns "010"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.pad.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.pad.string.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%x",123);                   /* returns "7b"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%X",123);                   /* returns "7B"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc

    sprintf("%f",123.5);                 /* returns "124"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%8.3f",123.5);              /* returns " 123.500"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%E",123.5);                 /* returns "1E+02"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%12.4e",123.5);             /* returns "  1.2350e+02"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//                ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%g",123.5);                 /* returns "124"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%8.3G",123.5);              /* returns "     124"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
    sprintf("%8.6g",123.5);              /* returns "   123.5"*/
//           ^ string.quoted.double.lpc constant.other.placeholder.lpc
//            ^ string.quoted.double.lpc constant.other.placeholder.field constant.other.placeholder.field.width.lpc
//             ^ string.quoted.double.lpc constant.other.placeholder.field.separator.lpc
//              ^ string.quoted.double.lpc constant.other.placeholder.field.precision.lpc
//               ^ string.quoted.double.lpc constant.other.placeholder.type.lpc
}
