#ifndef __CITY_GENERATOR__
#define __CITY_GENERATOR__

#include <vector>

#define MIN_SIZE_BUILDING 5
#define MAX_SIZE_BUILDING 8

struct S_Block {
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
};

class CityGenerator {
	private:
	S_Block m_cityBlocks;

	void _split(S_Block block);

	public:
	void generate(int width, int height);
};

#endif
