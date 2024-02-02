/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:18:20 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 13:22:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "-- BUILD GOOD INSTANCES --" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n-- BUILD WRONG INSTANCES --" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n-- GETTYPE GOOD --" << std::endl;
	std::cout << "Meta type: ";
	std::cout << meta->getType() << std::endl;
	std::cout << "Dog type: ";
	std::cout << dog->getType() << std::endl;
	std::cout << "Cat type: ";
	std::cout << cat->getType() << std::endl;

	std::cout << "\n-- GETTYPE WRONG --" << std::endl;
	std::cout << "Wrong meta type: ";
	std::cout << wrongMeta->getType() << std::endl;
	std::cout << "Wrong dog type: ";
	std::cout << wrongDog->getType() << std::endl;
	std::cout << "Wrong cat type: ";
	std::cout << wrongCat->getType() << std::endl;

	std::cout << "\n-- MAKESOUND GOOD --" << std::endl;
	std::cout << "Meta sound: ";
	meta->makeSound();
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();

	std::cout << "\n-- MAKESOUND WRONG --" << std::endl;
	std::cout << "Wrong meta sound: ";
	wrongMeta->makeSound();
	std::cout << "Wrong dog sound: ";
	wrongDog->makeSound();
	std::cout << "Wrong cat sound: ";
	wrongCat->makeSound();

	std::cout << "\n-- DESTRUCTION WRONG INSTANCES --" << std::endl;
	delete wrongCat;
	delete wrongDog;
	delete wrongMeta;

	std::cout << "\n-- DESTRUCTION GOOD INSTANCES --" << std::endl;
	delete cat;
	delete dog;
	delete meta;
	return 0;
}
