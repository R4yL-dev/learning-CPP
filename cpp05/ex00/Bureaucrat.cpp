/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:56:34 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 18:12:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Default"),
	_grade(BUREAUCRAT_MIN_GRADE) {}
Bureaucrat::Bureaucrat(std::string const &name) :
	_name(name),
	_grade(BUREAUCRAT_MIN_GRADE) {}
Bureaucrat::Bureaucrat(std::string const &name, int grade) :
	_name(name) {
	setGrade(grade);
}
Bureaucrat::Bureaucrat(Bureaucrat const &src) :
	_name(src.getName()),
	_grade(src.getGrade()) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

std::string const &Bureaucrat::getName() const {
	return _name;
}
int Bureaucrat::getGrade() const {
	return _grade;
}
void Bureaucrat::setGrade(int grade) {
	if (grade > BUREAUCRAT_MIN_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < BUREAUCRAT_MAX_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else
	_grade = grade;
}
void Bureaucrat::upGrade() {
	this->setGrade(getGrade() - 1);
}
void Bureaucrat::downGrade() {
	this->setGrade(getGrade() + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade cannot be higher than 1";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade cannot be lower thant 150";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return os;
}
