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
	this->canColor = cw.canColor;
	if(this->canColor) {
		initializePairs();
	}
}

ColorWindow::~ColorWindow() {}

ColorWindow& ColorWindow::operator=(const ColorWindow& cw) {
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

	//init_pair(foreground, background);
	npairs++;

	return npairs-1;
}

bool ColorWindow::writeStringWithColor(int x, int y,const char* message, int pair) {
	if(!isInLimits(x, y)) {
		writeString(3, 5, "Sorry, bounds out of limits.");
		return false;
	}

	if(pair >= npairs) {
		writeString(3, 5, "Sorry, pair not yet added.");
		return false;
	}

	if(!canColor) {
		writeString(3, 5, "Sorry, your term can't show colors.");
		return false;
	}

	/*
	init_pair(2, COLOR_RED, COLOR_BLACK);
	wattron(getContainer(), COLOR_PAIR(2));
	writeString(x, y, message);
	wattroff(getContainer(), COLOR_PAIR(pair));
	*/
	
	if(this->parejas_color.find(pair) != this->parejas_color.end()) {
		std::pair<int, int> aux = this->parejas_color.at(pair);

		init_pair(pair, aux.first, aux.second);
		
		wattron(getContainer(), COLOR_PAIR(pair));
		writeString(x, y, message);
		wattroff(getContainer(), COLOR_PAIR(pair));
	}
	else {
		writeString(x, y, message);
		return false;
	}
	
	return true;
}

bool ColorWindow::writeNumberWithColor(int x, int y, int message, int pair) {
	return writeNumberWithColor(x, y, (long) message, pair);
}

bool ColorWindow::writeNumberWithColor(int x, int y, long message, int pair) {
	ostringstream convert;
	string Result;

	convert << message;

	Result = convert.str();

	return writeStringWithColor(x, y, Result.c_str(), pair);
}

bool ColorWindow::writeNumberWithColor(int x, int y, double message, int pair) {
	return writeNumberWithColor(x, y, (long double) message, pair);
}

bool ColorWindow::writeNumberWithColor(int x, int y,float message, int pair) {
	return writeNumberWithColor(x, y, (long double) message, pair);
}

bool ColorWindow::writeNumberWithColor(int x, int y, long double message, int pair) {
	ostringstream convert;
	string Result;

	convert << message;

	Result = convert.str();

	return writeStringWithColor(x, y, Result.c_str(), pair);
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


/* PRIVATE FUNCTIONS */
void ColorWindow::initializePairs() {
	//start_color();

	/*
	map<int,pair<int, int>>
	pair<string, InformacionTerminoPregunta> aux(token, i);
	this->indicePregunta.insert(aux);
	*/
	pair<int, int> colors(COLOR_RED, COLOR_BLACK);
	pair<int, pair<int, int>> aux (1, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_GREEN, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(2, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_YELLOW, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(3, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_BLUE, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(4, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_MAGENTA, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(5, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_CYAN, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(6, colors);
	this->parejas_color.insert(aux);

	colors = pair<int, int>(COLOR_WHITE, COLOR_BLACK);
	aux = pair<int, pair<int, int>>(7, colors);
	this->parejas_color.insert(aux);

	/*init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	*/

	npairs = 8;
}