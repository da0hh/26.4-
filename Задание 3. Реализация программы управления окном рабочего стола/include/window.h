#pragma once

class Window {
	int width = 80;
	int height = 50;
	vector<int>coordinates_left_top_angle;
public:
	int getHeight() { return height; }
	int getWidth() { return width; }

	void setHeight(int set_height) {}
	void set_left_top_angle(int coordinatesX, int coordinatesY) {}

	int get_left_angle_y() { return coordinates_left_top_angle[1]; }

	int get_left_angle_x() { return coordinates_left_top_angle[0]; }

	void move(vector<int>coorToMove) {}

	void resize(int new_width, int new_height) {}

	void display() {}

	void close() {
	}
};