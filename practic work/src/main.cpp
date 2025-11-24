#include <window.h>
#include <monitor.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Window window;
	string command;
	
	while (true) {
		cout << "Enter command: "; cin >> command;

		if (command == "close") {
			cout << "Window was closed\n";
			return 0;
		}
		else if (command == "move") {
			vector<int> coor;
		
			cout << "Enter 2 coordinates x and y for move window\n";
			int x, y;
			cout << "Enter x and y: "; cin >> x >> y;

			coor.push_back(x);
			coor.push_back(y);
			window.move(coor);

		}
		else if (command == "resize") {
			int width, height;
			cout << "Enter new width and new height for window: "; cin >> width >> height;
			window.resize(width, height);
		}
		else if (command == "display") {
			window.display();
		}
		else {
			cout << "Invalid command\nTry again\n";
		}
	}
}