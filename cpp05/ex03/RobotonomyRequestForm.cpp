/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotonomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:38:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 00:56:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(
	"RobotomyRequestForm",
	72,
	45
){
	this->setTarget("Default");
}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(
	"RobotomyRequestForm",
	72,
	45
){
	this->setTarget(target);
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(
	"RobotomyRequestForm",
	72,
	45
){
	this->setTarget(src.getTarget());
}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::srand(std::time(0));
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());

	std::cout << "Making some drilling noises...\n";
	if (std::rand() % 2)
		std::cout << "Robotomization of "<< this->getTarget() << " success !\n";
	else
		std::cout << "Robotomization of " << this->getTarget() << " failed...\n";
}
