/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:55:42 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 20:01:46 by lray             ###   ########.fr       */
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

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const &name);
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &src);
	~Form();

	Form &operator=(Form const &rhs);

	std::string const &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, Form const &ref);

#endif
