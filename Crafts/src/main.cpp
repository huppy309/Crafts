#include <iostream>

#include "Grid\grid.h"

using namespace crafts;

int main()
{
	Grid grid("Ref.png");
	grid.applySimpleGrid("test.png");

	std::cin.get();
}