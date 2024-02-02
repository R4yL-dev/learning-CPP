/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:32:43 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:07:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const &src);
	~Ice();
	Ice &operator=(Ice const &rhs);

	Ice	*clone() const;
	void use(ICharacter &target);
};

#endif
