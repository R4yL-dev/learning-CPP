/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:12:44 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 18:30:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
#define AMATERIA

#include "ICharacter.hpp"
#include <iostream>

class	ICharacter;

class AMateria {

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	AMateria &operator=(AMateria const &rhs);
	~AMateria();

	std::string const &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
protected:
	std::string _type;

};

#endif
