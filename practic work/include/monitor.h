#include <iostream>
#include <vector>
#include <string>
#pragma once
using namespace std;

class Monitor {
	int width = 2560;
	int height = 1440;
public:
	int getHeight() { return height; }
	int getWidth() { return width; }

	void show_monitor() {}
};
