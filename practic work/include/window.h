#include <vector>
#include <string>
#pragma once

class Window {
	int width;
	int height;
	std::vector<int> coordinates_left_top_angle;
public:
	Window();

	int getHeight();
	int getWidth();

	void setHeight(int set_height);
	void setWidth(int set_width);
	void set_left_top_angle(int coordinatesX, int coordinatesY);

	int get_left_angle_y();

	int get_left_angle_x();

	void move(int x, int y);

	void resize(int new_width, int new_height);

	void display();
};