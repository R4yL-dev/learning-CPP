/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:06 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 20:15:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "Test default form\n";
		Form form;
		std::cout << form << "\n";
	}
	catch (const std::exception& e){
		std::cout << e.what() << "\n";
	}

	try {
		std::cout << "Test parametrized form\n";
		Form form ("My test form", 84, 42);
		std::cout << form << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		std::cout << "Test grade too low\n";
		Form form ("My test form", 0, 42);
		std::cout << form << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		std::cout << "\nTest grade too high\n";
		Form form ("My test form", 151, 42);
		std::cout << form << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		std::cout << "\nTest Bureaucrat grade too low\n";
		Bureaucrat alice ("Alice", 100);
		std::cout << alice << " was successfully created" << std::endl;
		Form form ("My test form", 80, 20);
		std::cout << form << "\n";
		alice.signForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		std::cout << "\nTest Bureaucrat good grade\n";
		Bureaucrat alice ("Alice", 80);
		std::cout << alice << " was successfully created" << std::endl;
		Form form ("My test form", 80, 20);
		std::cout << form << "\n";
		alice.signForm(form);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
	return 0;
}
