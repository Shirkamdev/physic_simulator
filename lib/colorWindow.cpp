#include "colorWindow.h"

/* BASIC OBJECT METHODS*/
ColorWindow::ColorWindow() {
	if(has_colors()) {
		initializePairs();
		this->canColor = true;
	}
	else {
		this->canColor = false;
	}
}

ColorWindow::ColorWindow(int he, int wi, int stx, int sty) : BasicWindow(he, wi, stx, sty) {
	if(has_colors()) {
		initializePairs();
		this->canColor = true;
	}
	else {
		this->canColor = false;
	}
}

ColorWindow::ColorWindow(const ColorWindow& cw) : BasicWindow((BasicWindow) cw){
	npairs = cw.npairs;
	this->canColor = cw.canColor;
	if(this->canColor) {
		initializePairs();
	}
}

ColorWindow::~ColorWindow() {}

ColorWindow& ColorWindow::operator=(const ColorWindow& cw) {
	npairs = cw.npairs;
	this->canColor = cw.canColor;
	if(this->canColor) {
		initializePairs();
	}

	return *this;
}

/* PUBLIC METHODS */
int ColorWindow::addColorPair(int foreground, int background) {
	if(foreground < 0 || foreground > 7 
		|| background < 0 || background > 7)
		return -1;

	init_pair(npairs, foreground, background);
	npairs++;

	return npairs-1;
}

bool ColorWindow::writeStringWithColor(int x, int y,const char* message, int pair) {
	if(!isInLimits(x, y))
		return false;

	if(pair >= npairs) 
		return false;

	if(canColor)
		return false;

	/*
	short* f;
	short f_aux;
	short* b;
	pair_content(pair, f, b);
	f_aux = *f;
	writeNumber(0, 0, f_aux);
	writeNumber(0, 2, *b);*/

	//init_pair(2, COLOR_GREEN, COLOR_BLACK);
	wattron(getContainer(), COLOR_PAIR(pair));
	mvwprintw(getContainer(), x, y, message);
	wattroff(getContainer(), COLOR_PAIR(7));
}


/* PRIVATE FUNCTIONS */
void ColorWindow::initializePairs() {
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	npairs = 8;
}

bool ColorWindow::changeColor(int color, int r, int g, int b) {
	if(!can_change_color())
		return false;
	if(color < 0 || color > 7 || r < 0 || r > 1000 
		|| g < 0 || g > 1000 || b < 0 || b > 1000)
		return false;

	init_color(color, r, g, b);

	return true;
}