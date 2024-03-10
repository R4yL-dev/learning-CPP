#include <ios>
#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	{
		std::cout << "-- TEST POINT --" << std::endl;
		Point p1;
		Point p2(3, 4);
		Point p3(p2);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
	}
	std::cout << "\n-- TEST BSP --" << std::endl;
	{
		std::cout << "- TEST BSP SIMPLE CASE -" << std::endl;
		Point p1(0, 0);
		Point p2(4, 0);
		Point p3(2, 4);
		Point point(2, 2);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
		std::cout << "point: " << point << "\n" << std::endl;
		std::cout << "Point is inside the triangle, expected resulte : true"
				  << std::endl;
		std::cout << "Result: " << std::boolalpha << bsp(p1, p2, p3, point)
				  << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "- TEST POINT IS A VERTEX -" << std::endl;
		Point p1(0, 0);
		Point p2(4, 0);
		Point p3(2, 4);
		Point point(0, 0);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
		std::cout << "point: " << point << "\n" << std::endl;
		std::cout << "Point is in a vertex, expected resulte : false"
				  << std::endl;
		std::cout << "Result: " << std::boolalpha << bsp(p1, p2, p3, point)
				  << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "- TEST POINT IS ON AN EDGE -" << std::endl;
		Point p1(0, 0);
		Point p2(4, 0);
		Point p3(2, 4);
		Point point(2, 0);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
		std::cout << "point: " << point << "\n" << std::endl;
		std::cout << "Point is in on an edge, expected resulte : false"
				  << std::endl;
		std::cout << "Result: " << std::boolalpha << bsp(p1, p2, p3, point)
				  << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "- TEST POINT IS OUTSIDE -" << std::endl;
		Point p1(0, 0);
		Point p2(4, 0);
		Point p3(2, 4);
		Point point(6, 2);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
		std::cout << "point: " << point << "\n" << std::endl;
		std::cout << "Point is outside, expected resulte : false" << std::endl;
		std::cout << "Result: " << std::boolalpha << bsp(p1, p2, p3, point)
				  << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "- TEST POINT FLOAT -" << std::endl;
		Point p1(0.0f, 0.0f);
		Point p2(4.42f, 0.0f);
		Point p3(2.12f, 4.420f);
		Point point(1.1f, 2.2f);
		std::cout << "p1: " << p1 << std::endl;
		std::cout << "p2: " << p2 << std::endl;
		std::cout << "p3: " << p3 << std::endl;
		std::cout << "point: " << point << "\n" << std::endl;
		std::cout << "Point is inside, expected resulte true" << std::endl;
		std::cout << "Result: " << std::boolalpha << bsp(p1, p2, p3, point)
				  << std::endl;
	}
	return 0;
}
