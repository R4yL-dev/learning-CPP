#include "Point.hpp"

#include <iostream>
#include <ostream>

#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(float const x, float const y) : _x(x), _y(y) {}
Point::Point(Point const &src) : _x(src._x), _y(src._y) {}
Point &Point::operator=(Point const &rhs) {
	(void)rhs;
	return *this;
}
Point::~Point(){};

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
std::ostream &operator<<(std::ostream &o, const Point &rhs) {
	o << "x: " << rhs.getX().toFloat() << " y: " << rhs.getY().toFloat();
	return o;
}
