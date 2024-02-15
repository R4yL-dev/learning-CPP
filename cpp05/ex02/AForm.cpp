/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:12:04 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 22:19:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	_name("Default"),
	_isSigned(false),
	_gradeToSign(FORM_DEFAULT_SIGN_GRADE),
	_gradeToExecute(FORM_DEFAILT_EXEC_GRADE),
	_target("") {}
AForm::AForm(std::string const &name) :
	_name(name),
	_isSigned(false),
	_gradeToSign(FORM_DEFAULT_SIGN_GRADE),
	_gradeToExecute(FORM_DEFAILT_EXEC_GRADE),
	_target("") {}
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_target("") {
	if (gradeToSign > FORM_MIN_GRADE || gradeToExecute > FORM_MIN_GRADE)
		throw(AForm::GradeTooLowException());
	if (gradeToSign < FORM_MAX_GRADE || gradeToExecute < FORM_MAX_GRADE)
		throw(AForm::GradeTooHighException());
}
AForm::AForm(AForm const &src) :
	_name(src.getName()),
	_isSigned(false),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute()),
	_target(src.getTarget()) {}
AForm::~AForm() {}

AForm &AForm::operator=(AForm const &rhs) {
	if (this != &rhs) {
		_isSigned = rhs.getIsSigned();
		_target = rhs.getTarget();
	}
	return *this;
}

std::string const &AForm::getName() const {
	return _name;
}
bool AForm::getIsSigned() const {
	return _isSigned;
}
int AForm::getGradeToSign() const {
	return _gradeToSign;
}
int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}
std::string const &AForm::getTarget() const {
	return _target;
}
void AForm::setIsSigned(bool const sign) {
	_isSigned = sign;
}
void AForm::setTarget(std::string const &target) {
	_target = target;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw(AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade cannot be higher than 1";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade cannot be lower than 150 Or bureaucrat grade is too low to sign this form";
}
const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &os, AForm const &ref) {
	std::string isSigned = ref.getIsSigned() ? "true" : "false";
	os << "Form name: " << ref.getName() << "\n";
	os << "Form is signed: " << isSigned << "\n";
	os << "Form grade to sign: " << ref.getGradeToSign() << "\n";
	os << "Form grade to exec: " << ref.getGradeToExecute() << std::endl;
	return os;
}
