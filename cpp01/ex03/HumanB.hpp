/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:28:48 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 12:57:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack() const;

private:
	std::string _name;
	Weapon* _weapon;
};

#endif
