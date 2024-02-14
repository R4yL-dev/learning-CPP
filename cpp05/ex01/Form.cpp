/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:12:04 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 20:02:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	_name("Default"),
	_isSigned(false),
	_gradeToSign(FORM_DEFAULT_SIGN_GRADE),
	_gradeToExecute(FORM_DEFAILT_EXEC_GRADE) {}
Form::Form(std::string const &name) :
	_name(name),
	_isSigned(false),
	_gradeToSign(FORM_DEFAULT_SIGN_GRADE),
	_gradeToExecute(FORM_DEFAILT_EXEC_GRADE) {}
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign > FORM_MIN_GRADE || gradeToExecute > FORM_MIN_GRADE)
		throw(Form::GradeTooLowException());
	if (gradeToSign < FORM_MAX_GRADE || gradeToExecute < FORM_MAX_GRADE)
		throw(Form::GradeTooHighException());
}
Form::Form(Form const &src) :
	_name(src.getName()),
	_isSigned(false),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute()) {}
Form::~Form() {}

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs)
		_isSigned = rhs.getIsSigned();
	return *this;
}

std::string const &Form::getName() const {
	return _name;
}
bool Form::getIsSigned() const {
	return _isSigned;
}
int Form::getGradeToSign() const {
	return _gradeToSign;
}
int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw(Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade cannot be higher than 1";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade cannot be lower than 150 Or bureaucrat grade is too low to sign this form";
}

std::ostream &operator<<(std::ostream &os, Form const &ref) {
	std::string isSigned = ref.getIsSigned() ? "true" : "false";
	os << "Form name: " << ref.getName() << "\n";
	os << "Form is signed: " << isSigned << "\n";
	os << "Form grade to sign: " << ref.getGradeToSign() << "\n";
	os << "Form grade to exec: " << ref.getGradeToExecute() << std::endl;
	return os;
}
