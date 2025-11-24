#include <vector>
#include <string>
#pragma once

using namespace std;

class Monitor {
	int width;
	int height;
public:
	Monitor();

	int getHeight();
	int getWidth();

	void show_monitor();
};
