/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:42:20 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:50:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &rhs);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const &type);

private:
	AMateria *_storage[4];
};

#endif
