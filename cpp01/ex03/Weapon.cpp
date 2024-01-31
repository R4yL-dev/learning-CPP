/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:24:17 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 12:55:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
	std::cout << "A weapon has been created" << std::endl;
}
Weapon::~Weapon()
{
	std::cout << "A weapon was destroyed" << std::endl;
}

const std::string& Weapon::getType() const
{
	return this->_type;
}
void Weapon::setType(const std::string &type)
{
	this->_type = type;
}
