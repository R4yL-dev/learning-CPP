/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/01 16:48:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {

	std::cout << "-- SCAVTRAP CREATION --" << std::endl;
	ScavTrap st1("DEAD");
	ScavTrap st2("NO_ENERGY");
	ScavTrap st3("TEST");

	std::cout << "\n-- TEST TAKEDAMAGE --" << std::endl;
	for (int i = 0; i < 10; i++) {
		st1.takeDamage(10);
	}

	std::cout << "\n-- TEST ATTACK --" << std::endl;
	for (int i = 0; i < 50; i++) {
		st2.attack("Garogo");
	}

	std::cout << "\n-- TEST BEREPAIRED --" << std::endl;
	for (int i = 0; i < 3; i++) {
		st3.beRepaired(42);
	}

	std::cout << "\n-- TEST TAKEDAMAGE WHEN DEAD --" << std::endl;
	st1.takeDamage(1);

	std::cout << "\n-- TEST ATTACK WHEN DEAD --" << std::endl;
	st1.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN DEAD --" << std::endl;
	st1.beRepaired(1);

	std::cout << "\n-- TEST ATTACK WHEN NO ENERGY --" << std::endl;
	st2.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN NO ENERGY --" << std::endl;
	st2.beRepaired(1);

	std::cout << "\n-- TEST GUARDGATE --" << std::endl;
	st3.guardGate();

	std::cout << "\n-- TEST GUARDGATE WHEN DEAD --" << std::endl;
	st1.guardGate();

	std::cout << "\n-- SCAVTRAP DESTRUCTION --" << std::endl;
	return 0;
}
