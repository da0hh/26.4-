#include <iostream>
#include <vector>
#include <monitor.h>
#include <window.h>

Monitor::Monitor() : width(80), height(50)
{
}

int Monitor::getHeight() { return height; }
int Monitor::getWidth() { return width; }
