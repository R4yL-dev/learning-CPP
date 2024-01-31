/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:28:48 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 12:55:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack() const;

private:
	std::string _name;
	Weapon& _weapon;
};

#endif
