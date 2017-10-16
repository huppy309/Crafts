#pragma once

#include <iostream>
#include <algorithm>
#include <FreeImage.h>

#include "../Utils/math.h"

namespace crafts {

	class Grid
	{
	private:
		FIBITMAP* image;
	public:
		Grid();
		void loadImage(const char* file);
		void unloadImage();
		void saveImage(const char* outPath);

		void applySimpleGrid();
	};

}