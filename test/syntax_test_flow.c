// SYNTAX TEST "Packages/C/C.sublime-syntax"
//demonstrate flow-control keywords and some related concepts

void flow()
{
	mixed tricky;
	if(1)
	{
		switch(10)
		{
			case 0:
				break;
			case 1:
				break;
			case 2..22:
				//fall through
			default:
				return;
		}
		switch("ten")
		{
			case 0:
				break;
			case "one":
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
		{
			continue;
		}
	}
	else
	{
		foreach(int i : ({1,2,3}))
		{
			tricky = i;
		}
	}
	while(tricky > 0)
	{
		tricky--;
	}

	do
	{
		if(catch(tricky++, tricky++; nolog))
		{
			catch(tricky++, tricky++; publish);
			catch(tricky++, throw("oops"); reserve tricky*tricky);
		}
	} while(tricky < 10);
}
