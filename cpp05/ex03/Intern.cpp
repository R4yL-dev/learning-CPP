/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:21:11 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 13:51:22 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}
Intern::Intern(Intern const &src) {
	(void)src;
}
Intern::~Intern() {}
Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(std::string const &nameForm, std::string const &target) const {
	AForm *newForm = NULL;

	t_list formList[3] = {
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}
	};

	for (int i = 0; i < 3; ++i) {
		if (formList[i].name == nameForm)
			newForm = formList[i].form;
		else
			delete (formList[i].form);
	}

	if (!newForm)
		throw(UnknownFormException());
	std::cout << "Intern creates " << newForm->getName();
	return newForm;
}

const char *Intern::UnknownFormException::what() const throw() {
	return "Form is unknown";
}
