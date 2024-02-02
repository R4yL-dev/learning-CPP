/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:37:40 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:40:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
