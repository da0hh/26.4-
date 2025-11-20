#include <iostream>
#include <vector>
#include <string>
#include <window.h>
#include <monitor.h>

class Window {
	int width = 80;
	int height = 50;
	vector<int>coordinates_left_top_angle;
public:
	int getHeight() { return height; }
	int getWidth() { return width; }

	void setHeight(int set_height) {
		if (set_height < 0) {
			cout << "Height must not be less than 0\n";
		}
		else if (set_height >= 0) {
			set_height = height;
		}
	}
	void setWidth(int set_width) {
		if (set_width < 0) {
			cout << "Height must not be less than 0\n";
		}
		else if (set_width >= 0) {
			set_width = width;
		}
	}

	void set_left_top_angle(int coordinatesX, int coordinatesY) {
		if ((coordinatesX > width || coordinatesX > height) || (coordinatesY > width || coordinatesY > height)) {
			cout << "Coordinates cannot be more than board of monitor\n";
		}
		else {
			coordinates_left_top_angle.push_back(coordinatesX);
			coordinates_left_top_angle.push_back(coordinatesY);
		}
	}

	int get_left_angle_y() {
		return coordinates_left_top_angle[1];
	}

	int get_left_angle_x() {
		
	}

	void move(vector<int>coorToMove) {
		set_left_top_angle(coorToMove[0], coorToMove[1]);
		cout << "Succesfuly pointed\n";
	}

	void resize(int new_width, int new_height) {
		setHeight(new_height);
		setWidth(new_width);
	}

	void display() {
		Monitor monitor;
		monitor.show_monitor();
	}

	void close() {
		Monitor monitor;
		cout << "Window was closed\n";

		for (size_t i = 0; i < monitor.getWidth(); i++) {
			cout << "0";
		}
		cout << endl;

		for (size_t i = 0; i < monitor.getHeight(); i++) {
			for (size_t x = 0; x < monitor.getWidth(); x++) {
				cout << "0";
			}
			cout << endl;
		}

		for (size_t i = 0; i < monitor.getWidth(); i++) {
			cout << "0";
		}
		cout << endl;
	}
};