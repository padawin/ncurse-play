#include "CityGenerator.hpp"

void CityGenerator::generate(int width, int height) {
	m_cityBlocks.width = width;
	m_cityBlocks.height = height;
	_split(m_cityBlocks);
}

void CityGenerator::_split(S_Block block) {

}
