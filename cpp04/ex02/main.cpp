/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:18:20 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 17:02:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	AAnimal *animals[4];

	std::cout << "-- CREATION OF 2 CATS" << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << "- Cat N° " << i+1 << " -" << std::endl;
		animals[i] = new Cat();
	}

	std::cout << "\n-- CREATION OF 2 DOGS" << std::endl;
	for (int i = 2; i < 4; i++) {
		std::cout << "- Dog N° " << i+1 << " -" << std::endl;
		animals[i] = new Dog();
	}

	std::cout << "\n-- TEST ALL ANIMALS --" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "Type: " << animals[i]->getType() << " Sound: ";
		animals[i]->makeSound();
	}

	std::cout << "\n-- DESTRUCTION OF 2 CATS" << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << "- Cat N° " << i+1 << " -" << std::endl;
		delete animals[i];
	}

	std::cout << "\n-- DESTRUCTION OF 2 DOGS" << std::endl;
	for (int i = 2; i < 4; i++) {
		std::cout << "- Dog N° " << i+1 << " -" << std::endl;
		delete animals[i];
	}

	return 0;
}
