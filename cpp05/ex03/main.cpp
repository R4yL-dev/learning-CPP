/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:06 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 14:12:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

static void cleanList(AForm *list[]);

int main() {
	AForm* listForm[4];
	for (int i = 0; i < 4; ++i) {
		listForm[i] = NULL;
	}

	{
		std::cout << "-- CREATION OF FORMS BY INTERN --\n";
		Intern someRandomIntern;

		try {
			listForm[0] = someRandomIntern.makeForm("shrubbery creation", "Leela");
			std::cout << *listForm[0];
			std::cout << "Form target: " << listForm[0]->getTarget() << "\n";

			listForm[1] = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *listForm[1];
			std::cout << "Form target: " << listForm[1]->getTarget() << "\n";

			listForm[2] = someRandomIntern.makeForm("presidential pardon", "Philip");
			std::cout << *listForm[2];
			std::cout << "Form target: " << listForm[2]->getTarget() << "\n";

			listForm[3] = someRandomIntern.makeForm("unknown form", "lray");
			std::cout << *listForm[3];
			std::cout << "Form target: " << listForm[3]->getTarget() << "\n";
		} catch(const std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}

	{
		std::cout << "\n-- LRAY SIGN ALL FORMS --\n";
		Bureaucrat lray("Lray", 5);

		for (int i = 0; i < 4; ++i) {
			if (listForm[i]) {
				lray.signForm(*listForm[i]);
				std::cout << *listForm[i] << "\n";
			}
		}
	}

	{
		std::cout << "\n-- BOSS EXEC ALL FORMS --\n";
		Bureaucrat boss("boss", 1);

		for (int i = 0; i < 4; ++i) {
			if (listForm[i]) {
				boss.executeForm(*listForm[i]);
				std::cout << "\n";
			}
		}
	}
	cleanList(listForm);
	return 0;
}


static void cleanList(AForm *list[]) {
	for (int i = 0; i < 4; ++i) {
		if (list[i])
			delete (list[i]);
	}
}
