/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:06 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 01:40:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	{
		std::cout << "-- ShrubberyCreationForm --\n";
		Bureaucrat boss("Boss", 137);
		Bureaucrat subBoss("Sub Boss", 146);
		ShrubberyCreationForm newForm("Leela");

		std::cout << newForm << "\n";
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		subBoss.upGrade();
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
		boss.downGrade();
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
	}

	{
		std::cout << "-- RobotomyRequestForm --\n";
		Bureaucrat boss("Boss", 45);
		Bureaucrat subBoss("Sub Boss", 73);
		RobotomyRequestForm newForm("Bender");

		std::cout << newForm << "\n";
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		subBoss.upGrade();
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
		boss.downGrade();
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
	}

	{
		std::cout << "-- PresidentialPardonForm --\n";
		Bureaucrat boss("Boss", 5);
		Bureaucrat subBoss("Sub Boss", 26);
		PresidentialPardonForm newForm("Philip");

		std::cout << newForm << "\n";
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		subBoss.upGrade();
		subBoss.signForm(newForm);
		std::cout << newForm << "\n";
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
		boss.downGrade();
		boss.executeForm(newForm);
		std::cout << newForm << "\n";
	}
	return 0;
}
