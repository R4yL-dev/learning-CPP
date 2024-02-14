/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:06 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 18:22:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	// Test grade too low
	try {
		std::cout << "Creation of Alice\n";
		Bureaucrat alice ("Alice");
		std::cout << alice << " was successfully created" << std::endl;
		alice.downGrade();
		std::cout << alice << std::endl;
		alice.upGrade();
		std::cout << alice << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test grade too high
	try {
		std::cout << "\nCreation of Bob\n";
		Bureaucrat bob ("Bob", 1);
		std::cout << bob << " was successfully created" << std::endl;
		bob.upGrade();
		std::cout << bob << std::endl;
		bob.downGrade();
		std::cout << bob << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test grade
	try {
		std::cout << "\nCreation of Carmen\n";
		Bureaucrat carmen ("Carmen", 2);
		std::cout << carmen << " was successfully created" << std::endl;
		carmen.downGrade();
		std::cout << carmen << std::endl;
		carmen.upGrade();
		carmen.upGrade();
		std::cout << carmen << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test creation to low
	try {
		std::cout << "\nCreation of David\n";
		Bureaucrat david ("David", 151);
		std::cout << david << " was successfully created" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test creation to high
	try {
		std::cout << "\nCreation of David the second\n";
		Bureaucrat david ("David the second", 0);
		std::cout << david << " was successfully created" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
