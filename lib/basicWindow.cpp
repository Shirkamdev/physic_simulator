#include "basicWindow.h"


/*
	BASIC OBJECT OPERATORS
*/
BasicWindow::BasicWindow() {
	this->height = 20;
	this->width = 84;
	this->starty = (LINES - height) / 2;	/* Calculating for a center placement */
	this->startx = (COLS - width) / 2;
}

BasicWindow::BasicWindow(int he, int wi, int stx, int sty) {
	this->height = he;
	this->width = wi;
	this->starty = sty;
	this->startx = stx;
}

BasicWindow::BasicWindow(const BasicWindow &bw) {
	this->height = bw.height;
	this->width = bw.width;
	this->starty = bw.starty;
	this->startx = bw.startx;
}

BasicWindow::~BasicWindow() {}

BasicWindow& BasicWindow::operator=(const BasicWindow& bw){
	this->height = bw.height;
	this->width = bw.width;
	this->starty = bw.starty;
	this->startx = bw.startx;

	return *this;
}


/*
	WINDOW MANAGEMENT OPERATORS
*/
WINDOW* BasicWindow::createNewContainer() {
	this->container = newwin(height, width, starty, startx);
	/*box(this->container, 0 , 0);		/* 0, 0 gives default characters 
					 					* for the vertical and horizontal
					 					* lines			*/
	wrefresh(this->container);		/* Show that box 		*/

	return getContainer();
}

WINDOW* BasicWindow::getContainer() {
	return this->container;
}

void BasicWindow::refreshContainer() {
	refresh();
	wrefresh(this->container);		/* Show that box 		*/
}

void BasicWindow::destroyWindow() {
	wborder(this->container, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(this->container);
	delwin(this->container);
}

bool BasicWindow::writeString(int x, int y, const char* message) {
	//mvwprintw(container, 0, 10, "Hello everyone!!");
	if(!isInLimits(x, y))
		return false;

	mvwprintw(this->container, x, y, message);
}

bool BasicWindow::writeNumber(int x, int y, int message) {
	writeNumber(x, y, (long) message);
}

bool BasicWindow::writeNumber(int x, int y, double message) {
	writeNumber(x, y, (long double) message);
}

bool BasicWindow::writeNumber(int x, int y,float message) {
	writeNumber(x, y, (long double) message);
}

bool BasicWindow::writeNumber(int x, int y, long message) {
	ostringstream convert;
	string Result;

	convert << message;

	Result = convert.str();

	return writeString(x, y, Result.c_str());
}

bool BasicWindow::writeNumber(int x, int y, long double message) {
	ostringstream convert;
	string Result;

	convert << message;

	Result = convert.str();

	return writeString(x, y, Result.c_str());
}

bool BasicWindow::isInLimits(int x, int y) {
	if(x < 0 || x >= this->width-1) {
		return false;
	}
	if(y < 0 || y >= this->height-1) {
		return false;
	}

	return true;
}
