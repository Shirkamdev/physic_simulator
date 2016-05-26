#ifndef _BASIC_WINDOW_H
#define _BASIC_WINDOW_H

#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;
/*Default window class
* From here, we will develope our own windows
*/

class BasicWindow {
	private:
		WINDOW* container;
		int startx, starty, height, width;

	public:
		BasicWindow();
		BasicWindow(int he, int wi, int stx, int sty);
		BasicWindow(const BasicWindow &bw);
		~BasicWindow();
		BasicWindow& operator=(const BasicWindow& bw);

		WINDOW* createNewContainer();
		WINDOW* getContainer();
		bool writeNumber(int x, int y, int message);
		bool writeNumber(int x, int y, long message);
		bool writeNumber(int x, int y, double message);
		bool writeNumber(int x, int y,float message);
		bool writeNumber(int x, int y, long double message);
		bool writeString(int x, int y, const char* message);
		void refreshContainer();
		void destroyWindow();
		bool isInLimits(int x, int y);
};

#endif
