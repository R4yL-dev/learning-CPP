/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:11:04 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 01:38:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(
	"PresidentialPardonForm",
	25,
	5
){
	this->setTarget("Default");
}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(
	"PresidentialPardonForm",
	25,
	5
){
	this->setTarget(target);
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(
	"PresidentialPardonForm",
	25,
	5
){
	this->setTarget(src.getTarget());
}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebox\n";
}

