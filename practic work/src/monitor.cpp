#include <iostream>
#include <vector>
#include <string>
#include <monitor.h>
#include <window.h>

Monitor::Monitor() : width(2560), height(1440)
{
}

int Monitor::getHeight() { return height; }
int Monitor::getWidth() { return width; }

void Monitor::show_monitor() {
	Window window;
	int start_x = window.get_left_angle_x();
	int start_y = window.get_left_angle_y();
	bool find = false;
	vector<int>windowsWidth;
	vector<int>windowsHeight;
	int counter = 0;
	cout << "Monitor width: " << width << "\nMonitor height: " << height << endl;

	for (size_t i = 0; i < width; i++) {
		if (i == start_x && 1 == start_y) {
			cout << "1";
			find = true;

			for (size_t q = 0; q < window.getWidth(); q++) {
				int numWidth = start_x + q + 1;
				windowsWidth.push_back(numWidth);
			}

			for (size_t y = 0; y < window.getHeight(); y++) {
				int numHeight = start_y + y + 1;
				windowsHeight.push_back(numHeight);
			}
		}
		cout << "0";
	}

	cout << endl;
	counter++;

	if (find) {
		for (size_t y = 0; y < height; y++) {
			for (size_t x = 0; x < width; x++) {
				if (windowsWidth[x] == x && windowsHeight[y + 2] == y + 2) {
					cout << "1";
				}
				else
					cout << "0";
			}
			cout << endl;
			counter++;
		}
	}
	else {
		for (size_t y = 0; y < height; y++) {
			for (size_t x = 0; x < width; x++) {
				if (x == start_x && y == start_y + 2) {
					cout << "1";
					find = true;

					for (size_t q = 0; q < window.getWidth(); q++) {
						int numWidth = start_x + q + 2;
						windowsWidth.push_back(numWidth);
					}

					for (size_t y = 0; y < window.getHeight(); y++) {
						int numHeight = start_y + y + 2;
						windowsHeight.push_back(numHeight);
					}
				}
				else
					cout << "0";

				if (find && windowsHeight[y] == y && windowsWidth[x] == x) {
					cout << "1";
				}
				else
					cout << "0";
			}
			cout << endl;
			counter++;
		}
	}

	if (!find) {
		for (size_t i = 0; i < width; i++) {
			cout << "0";
		}
		cout << "\n\nWindow wasn't found!";
	}
	else {
		for (size_t x = 0; x < width; x++) {
			if (windowsWidth[x] == x && windowsHeight[-1] == counter + 1) {
				cout << "1";
			}
			else
				cout << "0";
		}
	}
}

