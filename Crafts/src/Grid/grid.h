#pragma once

#include <iostream>
#include <FreeImage.h>

namespace crafts {

	class Grid
	{
	private:
		const char* m_File;
	public:
		Grid(const char* file);
		void applySimpleGrid(const char* outPath);
	};

}