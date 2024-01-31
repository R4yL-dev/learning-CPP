/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:05:58 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 12:59:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
	std::cout << this->_name << " was created" << std::endl;
}
HumanB::~HumanB()
{
	std::cout << this->_name << " was destroy" << std::endl;
}
void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
void HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}
