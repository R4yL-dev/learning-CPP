#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "Default constructor of DiamondTrap was called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) {
	std::cout << "Parametrize constructor of DiamonTrap was called"
			  << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::_hitPoint = 100;
	this->ScavTrap::_energyPoint = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
	: ClapTrap(src), FragTrap(src), ScavTrap(src) {
	std::cout << "Copy constructor of DiamondTrap was called" << std::endl;
	this->_name = src._name;
	this->ClapTrap::_name = src.ClapTrap::_name;
	this->FragTrap::_hitPoint = src.FragTrap::_hitPoint;
	this->ScavTrap::_energyPoint = src.ScavTrap::_energyPoint;
	this->FragTrap::_attackDamage = src.FragTrap::_hitPoint;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->FragTrap::_hitPoint = rhs.FragTrap::_hitPoint;
		this->ScavTrap::_energyPoint = rhs.ScavTrap::_energyPoint;
		this->FragTrap::_attackDamage = rhs.FragTrap::_attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondClap was called" << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoiam() {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
