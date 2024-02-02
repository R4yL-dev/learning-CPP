/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:11:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 23:06:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void emptyStorage(AMateria *materias[2]);

int	main(void)
{
	// Create Materias Storage
	AMateria *materias[2];
	materias[0] = new Ice();
	materias[1] = new Cure();

	// Create and set MateriaSource
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(materias[0]);
	src->learnMateria(materias[1]);

	// Clean the storage
	emptyStorage(materias);

	// Create Characters
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	// Create Materias
	materias[0] = src->createMateria("ice");
	materias[1] = src->createMateria("cure");

	// Should't do anything because me has no materia
	me->use(0, *bob);

	// Equip Materias
	me->equip(materias[0]);
	me->equip(materias[1]);

	// Should use both materias
	me->use(0, *bob);
	me->use(1, *bob);

	// Should't do anything me has no materia on slot 2
	me->use(2, *bob);

	// Should't do anything me has no materia on slot 1
	me->unequip(1);
	me->use(1, *bob);

	// Should't do anything bob has no materia
	bob->use(0, *me);

	delete bob;
	delete me;
	delete src;
	emptyStorage(materias);
	return 0;
}

static void emptyStorage(AMateria *materias[2])
{
	delete materias[0];
	delete materias[1];
}
