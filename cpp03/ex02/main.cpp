/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/01 16:44:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {

	std::cout << "-- FRAGTRAP CREATION --" << std::endl;
	FragTrap ft1("DEAD");
	FragTrap ft2("NO_ENERGY");
	FragTrap ft3("TEST");

	std::cout << "\n-- TEST TAKEDAMAGE --" << std::endl;
	for (int i = 0; i < 10; i++) {
		ft1.takeDamage(10);
	}

	std::cout << "\n-- TEST ATTACK --" << std::endl;
	for (int i = 0; i < 100; i++) {
		ft2.attack("Garogo");
	}

	std::cout << "\n-- TEST BEREPAIRED --" << std::endl;
	for (int i = 0; i < 3; i++) {
		ft3.beRepaired(42);
	}

	std::cout << "\n-- TEST TAKEDAMAGE WHEN DEAD --" << std::endl;
	ft1.takeDamage(1);

	std::cout << "\n-- TEST ATTACK WHEN DEAD --" << std::endl;
	ft1.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN DEAD --" << std::endl;
	ft1.beRepaired(1);

	std::cout << "\n-- TEST ATTACK WHEN NO ENERGY --" << std::endl;
	ft2.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN NO ENERGY --" << std::endl;
	ft2.beRepaired(1);

	std::cout << "\n-- TEST HIGHFIVESGUYS --" << std::endl;
	ft3.highFivesGuys();

	std::cout << "\n-- TEST HIGHFIVESGUYS WHEN DEAD --" << std::endl;
	ft1.highFivesGuys();

	std::cout << "\n-- FRAGTRAP DESTRUCTION --" << std::endl;
	return 0;
}
