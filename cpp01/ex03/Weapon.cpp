/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:24:17 by lray              #+#    #+#             */
/*   Updated: 2024/01/23 11:21:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

const std::string& Weapon::getType() const
{
	return this->type;
}
void Weapon::setType(const std::string &type)
{
	this->type = type;
}
