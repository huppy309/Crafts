#include <iostream>

#include "Grid\grid.h"

using namespace crafts;

int main()
{
	Grid grid;
	grid.loadImage("Ref.png");
	grid.applySimpleGrid();
	grid.saveImage("test.png");
	grid.unloadImage();

	std::cin.get();
}