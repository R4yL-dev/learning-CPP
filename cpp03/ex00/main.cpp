/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/01 13:59:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {

	std::cout << "-- CLAPTRAP CREATION --" << std::endl;
	ClapTrap ct;
	ClapTrap ct2("TEST");
	ClapTrap ct3(ct2);
	ct = ct3;

	std::cout << "\n-- TEST ATTACK --" << std::endl;
	for (int i = 0; i < 11; i++) {
		ct3.attack("Garogo");
	}
	std::cout << "\n-- TEST TAKEDAMAGE --" << std::endl;
	for (int i = 0; i < 11; i++) {
		ct.takeDamage(1);
	}

	std::cout << "\n-- TEST BEREPAIRED --" << std::endl;
	for (int i = 0; i < 11; i++) {
		ct2.beRepaired(1);
	}

	std::cout << "\n-- CLAPTRAP DESTRUCTION --" << std::endl;
	return 0;
}
