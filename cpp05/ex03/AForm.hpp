/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:55:42 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 13:43:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define FORM_MIN_GRADE 150
#define FORM_MAX_GRADE 1
#define FORM_DEFAULT_SIGN_GRADE 100
#define FORM_DEFAILT_EXEC_GRADE 50

#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm {

public:
	AForm();
	AForm(std::string const &name);
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &src);
	virtual ~AForm();

	AForm &operator=(AForm const &rhs);

	std::string const &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string const &getTarget() const;
	void setIsSigned(bool const sign);
	void setTarget(std::string const &target);

	virtual void execute(Bureaucrat const &executor) const = 0;
	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
	std::string _target;
};

std::ostream &operator<<(std::ostream &os, AForm const &ref);

#endif
