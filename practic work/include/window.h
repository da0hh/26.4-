#include <vector>
#pragma once

class Window {
	int width;
	int height;
	std::vector<int> coordinates_left_top_angle;
public:
	int getHeight();
	int getWidth();

	void setHeight(int set_height);
	void setWidth(int set_width);
	void set_left_top_angle(int coordinatesX, int coordinatesY);

	int get_left_angle_y();

	int get_left_angle_x();

	void move(const std::vector<int>& new_coords);

	void resize(int new_width, int new_height);

	void display();

	void close();
};