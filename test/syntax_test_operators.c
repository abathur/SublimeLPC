// SYNTAX TEST "Packages/User/LPC/LPC.sublime-syntax"
public int operators()
{
	int operators_a = 10;
	float operators_b;
	return 2, 3;
	return 2 , 3;
	operators_a = 3;
	operators_a += 4;
	operators_a -= 1;
	operators_a &= 4;
	operators_a |= 1;
	operators_a ^= 4;
	operators_a <<= 1;
	operators_a >>= 4;
	operators_a >>>= 1;
	operators_a *= 4;
	operators_a %= 1;
	operators_a /= 4;
	operators_a &&= 1;
	operators_a ||= 4;
	operators_a -= 3 || 4 != 4 && 5 == 7 ? (3 | 5 ^ 6 & 7) : (4);
	operators_a += 3 || 4 >= 4 && 5 << 7 ? (3 | 5 ^ 6 & 7) : (4>>>3);
	operators_a = ~4;
	operators_b = (float) operators_a;
	operators_a++;
	operators_a--;

	int * operators_c = ({1, 2, 3});
	operators_c[0] = operators_c[<1];
	operators_c[0..1] = operators_c[<1..<2];

	mapping operators_d;
	operators_d = ([1:2;3, "one":"two";operators_a]);
	operators_d[1, 1] = operators_d["one", 1];

	// test5e = operators_f->query_name(operators_d);
	// test5e = (struct NahStruct) operators_h->name;
	// test6h = (<NahStruct> nah: 1, bro: "ok");
	implode(({({"one", "two"}), "three"})...); //TODO: flatten operator
}
// <- meta.preprocessor.lpc.include
// ^ keyword.other.preprocessor.include.lpc
