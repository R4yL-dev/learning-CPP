#include "Point.hpp"

static float area(Point const &p1, Point const &p2, Point const &p3);
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float d0, d1, d2, d3;
	bool ret = false;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, c, a);

	if (d1 == 0 || d2 == 0 || d3 == 0) {
		ret = false;
	} else if (d1 + d2 + d3 == d0) {
		ret = true;
	}
	return ret;
}

static float area(Point const &p1, Point const &p2, Point const &p3) {
	float area;

	area =
		((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
		 (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
		 (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) /
		2;
	if (area >= 0) {
		return area;
	} else {
		return area * -1;
	}
}
