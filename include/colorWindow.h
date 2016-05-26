#ifndef _COLOR_WINDOW_H
#define _COLOR_WINDOW_H

#include "basicWindow.h"

class ColorWindow : public BasicWindow {
	private:
		int npairs;
		bool canColor;
		void initializePairs();

	public:
		ColorWindow();
		ColorWindow(int he, int wi, int stx, int sty);
		ColorWindow(const ColorWindow& cw);
		~ColorWindow();
		ColorWindow& operator=(const ColorWindow& cw);

		int addColorPair(int foreground, int background);
		bool writeStringWithColor(int x, int y, const char* message, int pair);
		bool changeColor(int color, int r, int g, int b);

};

#endif