/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:17:10 by lray              #+#    #+#             */
/*   Updated: 2024/02/15 13:37:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef struct	s_list
{
	std::string	name;
	AForm	*form;
}	t_list;

class Intern {

public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &nameForm, std::string const &target) const;

	class UnknownFormException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif
