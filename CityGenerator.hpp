#ifndef __CITY_GENERATOR__
#define __CITY_GENERATOR__

#include <vector>
#include <memory>

#define MIN_SIZE_BUILDING 3

struct S_Block {
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	std::vector<S_Block> subBlocks = {};
};

class CityGenerator {
	private:
	S_Block m_cityBlocks;

	void _split(S_Block &block);
	void _splitVertically(S_Block &block);
	void _splitHorizontally(S_Block &block);
	void _renderBlock(S_Block block);

	public:
	CityGenerator();
	void generate(int width, int height);
	void render();
};

#endif
