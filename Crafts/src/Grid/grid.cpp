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
		RGBQUAD color;
		color.rgbRed = 255;
		color.rgbGreen = 255;
		color.rgbBlue = 255;

		int width = FreeImage_GetWidth(image);
		int height = FreeImage_GetHeight(image);

		width = (width / 10) * 10;
		height = (height / 10) * 10;

		int divisor = gcd(width, height);
		int boxLength = std::min((width / divisor), (height / divisor));
		
		for (int i = 0; i < width; i++)
			for (int j = boxLength; j < height; j += boxLength)
				FreeImage_SetPixelColor(image, i, j, &color);

		for (int i = boxLength; i < width; i += boxLength)
			for (int j = 0; j < height; j++)
				FreeImage_SetPixelColor(image, i, j, &color);

	}

}