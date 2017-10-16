#include "math.h"

namespace crafts {

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		a %= b;
		return gcd(b, a);
	}

}