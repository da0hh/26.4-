#include <iostream>
#include <vector>
#include <window.h>
#include <monitor.h>

Window::Window () : width(10), height (5)
{
	coordinates_left_top_angle.push_back(0);
	coordinates_left_top_angle.push_back(0);
}

int Window::getHeight() { return height; }
int Window::getWidth() { return width; }

void Window::setHeight(int set_height) {
	if (set_height < 0) {
		cout << "Height must not be less than 0\n";
	}
	else if (set_height >= 0) {
		height = set_height;
	}
}

void Window::setWidth(int set_width) {
	if (set_width < 0) {
		cout << "Width must not be less than 0\n";
	}
	else if (set_width >= 0) {
		width = set_width;
	}
}

void Window::set_left_top_angle(int coordinatesX, int coordinatesY) {
	Monitor monitor;
	if ((coordinatesX > monitor.getWidth() || coordinatesX < 0) || 
		(coordinatesY > monitor.getWidth() || coordinatesY < 0)) {
		cout << "Coordinates cannot be more than board of monitor\n";
	}
	else {
		coordinates_left_top_angle[0] = coordinatesX;
		coordinates_left_top_angle[1] = coordinatesY;
	}
}

int Window::get_left_angle_y() {
	return coordinates_left_top_angle[1];

}
int Window::get_left_angle_x() {
	return coordinates_left_top_angle[0];
}

void Window::move(int x, int y) {
	Monitor monitor;
	if (x < 0 || x > monitor.getWidth() || y < 0 || y > monitor.getHeight()) {
		cout << "Coordinates cannot be outside monitor bounds\n";
	}
	else {
		coordinates_left_top_angle[0] = x;
		coordinates_left_top_angle[1] = y;
		cout << "Succesfuly moved to (" << x << ":" << y << ")" << endl;
	}
}

void Window::resize(int new_width, int new_height) {
	if (new_width < 0 || new_height < 0) {
		cout << "Width and height cannot be negative\n";
	}
	else {
		Monitor monitor;
		if (coordinates_left_top_angle[0] + new_width > monitor.getWidth() ||
			coordinates_left_top_angle[1] + new_height > monitor.getHeight()) {
			cout << "Coordinates cannot be outside monitor bounds\n";
		}
		else {
			width = new_width;
			height = new_height;
			cout << "Successfully resized to " << width << "x" << height << "\n";
		}
	}
}

void Window::display() {
	Monitor monitor;

    int monitor_width = monitor.getWidth();
    int monitor_height = monitor.getHeight();

    int start_x = get_left_angle_x();
    int start_y = get_left_angle_y();

    int window_width = getWidth();
    int window_height = getHeight();

	const int scale = 10;

    for (int y = 0; y < monitor_height; y++) {
        for (int x = 0; x < monitor_width; x++) {
			if (x >= coordinates_left_top_angle[0] &&
				x < coordinates_left_top_angle[0] + width &&
				y >= coordinates_left_top_angle[1] &&
				y < coordinates_left_top_angle[1] + height) {
				std::cout << '1';
			}
			else {
				std::cout << '0';
			}
        }
        std::cout << std::endl;
    }
}
