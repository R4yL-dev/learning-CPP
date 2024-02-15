/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:03:15 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 01:17:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(
	"ShrubberyCreationForm",
	145,
	137
){
	this->setTarget("Default");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(
	"ShrubberyCreationForm",
	145,
	137
){
	this->setTarget(target);
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(
	"ShrubberyCreationForm",
	145,
	137
){
	this->setTarget(src.getTarget());
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	if (this->getGradeToExecute() < executor.getGrade())
		throw (AForm::GradeTooLowException());
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file) {
		std::cerr << "Failed to open the file: " << fileName << std::endl;
		return;
	}
	file << ASCII_TREE << std::endl;
}
