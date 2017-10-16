#include "grid.h"

#define DEBUG 1

namespace crafts {

	Grid::Grid(const char* file)
	{
		m_File = file;
	}

	void Grid::applySimpleGrid(const char* outPath)
	{

		FIBITMAP* image = FreeImage_Load(FIF_PNG, m_File, PNG_DEFAULT);

#if DEBUG
		std::cout << "Image: " << m_File << std::endl;
		std::cout << "Width: " << FreeImage_GetWidth(image) << " Height: " << FreeImage_GetHeight(image) << std::endl;
#endif

		if (FreeImage_Save(FIF_PNG, image, outPath, 0))
			FreeImage_Unload(image);
	}

}