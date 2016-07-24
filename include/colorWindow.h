#ifndef _COLOR_WINDOW_H
#define _COLOR_WINDOW_H

#include <map>
#include <utility>
#include "basicWindow.h"

class ColorWindow : public BasicWindow {
	private:
		int npairs;
		bool canColor;
		map<int,pair<int, int>> parejas_color;
		void initializePairs();

	public:
		ColorWindow();
		ColorWindow(int he, int wi, int stx, int sty);
		ColorWindow(const ColorWindow& cw);
		~ColorWindow();
		ColorWindow& operator=(const ColorWindow& cw);

		int addColorPair(int foreground, int background);
		bool writeStringWithColor(int x, int y, const char* message, int pair);
		bool writeNumberWithColor(int x, int y, int message, int pair);
		bool writeNumberWithColor(int x, int y, long message, int pair);
		bool writeNumberWithColor(int x, int y, double message, int pair);
		bool writeNumberWithColor(int x, int y,float message, int pair);
		bool writeNumberWithColor(int x, int y, long double message, int pair);
		bool changeColor(int color, int r, int g, int b);

};

#endif