/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/01 16:50:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {

	std::cout << "-- CLAPTRAP CREATION --" << std::endl;
	ClapTrap ct1("DEAD");
	ClapTrap ct2("NO_ENERGY");
	ClapTrap ct3("TEST");

	std::cout << "\n-- TEST TAKEDAMAGE --" << std::endl;
	for (int i = 0; i < 10; i++) {
		ct1.takeDamage(1);
	}
	std::cout << "\n-- TEST ATTACK --" << std::endl;
	for (int i = 0; i < 10; i++) {
		ct2.attack("Garogo");
	}

	std::cout << "\n-- TEST BEREPAIRED --" << std::endl;
	for (int i = 0; i < 10; i++) {
		ct3.beRepaired(1);
	}
	std::cout << "\n-- TEST TAKEDAMAGE WHEN DEAD --" << std::endl;
	ct1.takeDamage(1);

	std::cout << "\n-- TEST ATTACK WHEN DEAD --" << std::endl;
	ct1.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN DEAD --" << std::endl;
	ct1.beRepaired(1);

	std::cout << "\n-- TEST ATTACK WHEN NO ENERGY --" << std::endl;
	ct2.attack("Garogo");

	std::cout << "\n-- TEST BEREPAIRED WHEN NO ENERGY --" << std::endl;
	ct2.beRepaired(1);

	std::cout << "\n-- CLAPTRAP DESTRUCTION --" << std::endl;
	return 0;
}
