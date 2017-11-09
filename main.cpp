#include "CityGenerator.hpp"
#include <ncurses.h>
#include <time.h>

void _initNCurses();

int main() {
	srand((unsigned) time(NULL));
	_initNCurses();
	CityGenerator gen;
	gen.generate(80, 50);
	gen.render();
	refresh();
	getch();
	endwin(); // Restore normal terminal behavior
	return 0;
}

void _initNCurses() {
	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	curs_set(FALSE); // Don't display a cursor
}
