/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:37:52 by lray              #+#    #+#             */
/*   Updated: 2024/02/14 20:01:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BUREAUCRAT_MIN_GRADE 150
#define BUREAUCRAT_MAX_GRADE 1

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(std::string const &name);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const &getName() const;
	int getGrade() const;
	void setGrade(int grade);
	void upGrade();
	void downGrade();

	void signForm(Form &form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	std::string const _name;
	int _grade;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref);

#endif
