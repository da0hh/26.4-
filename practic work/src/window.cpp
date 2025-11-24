#include <iostream>
#include <vector>
#include <window.h>
#include <monitor.h>

Window::Window () : width(80), height (50)
{
}
int Window::getHeight() { return height; }
int Window::getWidth() { return width; }

void Window::setHeight(int set_height) {
	if (set_height < 0) {
		cout << "Height must not be less than 0\n";
	}
	else if (set_height >= 0) {
		set_height = height;
	}
}
void Window::setWidth(int set_width) {
	if (set_width < 0) {
		cout << "Height must not be less than 0\n";
	}
	else if (set_width >= 0) {
		set_width = width;
	}
}

void Window::set_left_top_angle(int coordinatesX, int coordinatesY) {
	if ((coordinatesX > width || coordinatesX > height) || (coordinatesY > width || coordinatesY > height)) {
		cout << "Coordinates cannot be more than board of monitor\n";
	}
	else {
		coordinates_left_top_angle.push_back(coordinatesX);
		coordinates_left_top_angle.push_back(coordinatesY);
	}
}

int Window::get_left_angle_y() {
	return coordinates_left_top_angle[1];
}

int Window::get_left_angle_x() {
	return coordinates_left_top_angle[0];
}

void Window::move(const vector<int>& new_coords) {
	coordinates_left_top_angle = new_coords;
	cout << "Succesfuly pointed\n";
}

void Window::resize(int new_width, int new_height) {
	setHeight(new_height);
	setWidth(new_width);
}

void Window::display() {
	Monitor monitor;
	monitor.show_monitor();
}