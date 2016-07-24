#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "basicWindow.h"
#include "colorWindow.h"

using namespace std;

int main(int argc, char** argv) {
	//he, wi, stx, sty
	//BasicWindow bw = BasicWindow(20, 80, 0, 0);

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 		* everty thing to me 		*/
	keypad(stdscr, TRUE);
	start_color();

	ColorWindow cw = ColorWindow(20, 80, 0, 0);

	//WINDOW* container;
	/*
	container = bw.createNewContainer();
	bw.writeString(0, 10, "Hello Everyone!!");
	bw.refreshContainer();

	sleep(2);
	bw.~BasicWindow();
	//endwin();*/

	cw.createNewContainer();
	///int pair = cw.addColorPair(COLOR_RED, COLOR_BLACK);
	bool success = cw.writeStringWithColor(10, 0, "Hello everyone in color!!", 1);
	if(!success)
		cw.writeString(10, 3, "Write with color failed :(");
	success = cw.writeNumberWithColor(10, 1, 0.598702145646454684123, 2);
	if(!success)
		cw.writeString(10, 4, "Write with color (number) failed :(");
	cw.refreshContainer();
	sleep(2);
	cw.~ColorWindow();
	endwin();

	return 0;
}