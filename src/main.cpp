#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "basicWindow.h"
#include "colorWindow.h"

using namespace std;

int main(int argc, char** argv) {
	//he, wi, stx, sty
	BasicWindow bw = BasicWindow(20, 80, 0, 0);
	ColorWindow cw = ColorWindow(20, 80, 0, 0);


	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 		* everty thing to me 		*/
	keypad(stdscr, TRUE);
	start_color();

	WINDOW* container;
	/*
	container = bw.createNewContainer();
	bw.writeString(0, 10, "Hello Everyone!!");
	bw.refreshContainer();

	sleep(2);
	bw.~BasicWindow();
	//endwin();*/

	container = cw.createNewContainer();
	int pair = cw.addColorPair(5, 7);
	cw.writeStringWithColor(0, 10, "Hello everyone in color!!", pair);
	cw.refreshContainer();
	sleep(2);
	cw.~ColorWindow();
	endwin();

	return 0;
}