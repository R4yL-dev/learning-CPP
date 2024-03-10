#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

#include "Fixed.hpp"

class Point {
   public:
	Point();
	Point(float const x, float const y);
	Point(Point const &src);
	Point &operator=(Point const &rhs);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

   private:
	Fixed const _x;
	Fixed const _y;
};
std::ostream &operator<<(std::ostream &o, const Point &rhs);
#endif
