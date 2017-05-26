#include "CityGenerator.hpp"
#include <stdlib.h>

CityGenerator::CityGenerator() : m_cityBlocks(S_Block()) {}

void CityGenerator::generate(int width, int height) {
	m_cityBlocks.width = width;
	m_cityBlocks.height = height;
	_split(m_cityBlocks);
}

void CityGenerator::_split(S_Block &block) {
	int remainingWidth = block.width;
	int remainingHeight = block.height;
	// split horizontally
	if (remainingWidth <= MIN_SIZE_BUILDING * 2 && remainingHeight > MIN_SIZE_BUILDING * 2) {
		_splitHorizontally(block);
		// select random number between MIN_SIZE_BUILDING and height -
		// MIN_SIZE_BUILDING - 1
	}
	// split vertically
	else if (remainingWidth > MIN_SIZE_BUILDING * 2 && remainingHeight <= MIN_SIZE_BUILDING * 2) {
		_splitVertically(block);
	}
	// split randomly
	else if (remainingWidth > MIN_SIZE_BUILDING && remainingHeight > MIN_SIZE_BUILDING * 2) {
		int way = rand() % 2;
		if (way == 1) {
			_splitHorizontally(block);
		}
		else {
			_splitVertically(block);
		}
	}
	// do not split
}

void CityGenerator::_splitVertically(S_Block &block) {
	// decide where to split
	int splitColumn = MIN_SIZE_BUILDING + rand() % (block.width - MIN_SIZE_BUILDING * 2);
	S_Block subBlock1, subBlock2;
	subBlock1.x = block.x;
	subBlock1.y = block.y;
	subBlock1.width = splitColumn;
	subBlock1.height = block.height;

	subBlock2.x = block.x + splitColumn + 1;
	subBlock2.y = block.y;
	subBlock2.width = block.width - splitColumn - 1;
	subBlock2.height = block.height;

	_split(subBlock1);
	_split(subBlock2);
	block.subBlocks.push_back(subBlock1);
	block.subBlocks.push_back(subBlock2);

}

void CityGenerator::_splitHorizontally(S_Block &block) {
	// decide where to split
	int splitRow = MIN_SIZE_BUILDING + rand() % (block.height - MIN_SIZE_BUILDING * 2);
	S_Block subBlock1, subBlock2;
	subBlock1.x = block.x;
	subBlock1.y = block.y;
	subBlock1.width = block.width;
	subBlock1.height = splitRow;

	subBlock2.x = block.x;
	subBlock2.y = block.y  + splitRow + 1;
	subBlock2.width = block.width;
	subBlock2.height = block.height  - splitRow - 1;

	_split(subBlock1);
	_split(subBlock2);
	block.subBlocks.push_back(subBlock1);
	block.subBlocks.push_back(subBlock2);
}

void CityGenerator::render() {
	_renderBlock(m_cityBlocks);
	refresh();
}
}
