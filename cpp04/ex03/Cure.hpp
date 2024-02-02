/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:47:20 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:17:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const &src);
	~Cure();
	Cure &operator=(Cure const &rhs);

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif
