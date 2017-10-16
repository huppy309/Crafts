#include "grid.h"

#define DEBUG 1

namespace crafts {

	Grid::Grid() { }

	void Grid::loadImage(const char* file)
	{
		unloadImage();
		image = FreeImage_Load(FIF_PNG, file, PNG_DEFAULT);

#if DEBUG
		std::cout << "Image: " << file << std::endl;
		std::cout << "Width: " << FreeImage_GetWidth(image) << " Height: " << FreeImage_GetHeight(image) << std::endl;
#endif
	}

	void Grid::unloadImage()
	{
		if (image)
			FreeImage_Unload(image);
	}

	void Grid::saveImage(const char* outPath)
	{
		if (image && FreeImage_Save(FIF_PNG, image, outPath, 0)) { }
	}

	void Grid::applySimpleGrid()
	{
		
	}

}