/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:28:48 by lray              #+#    #+#             */
/*   Updated: 2024/01/23 11:15:59 by lray             ###   ########.fr       */
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
	void attack() const;

private:
	std::string name;
	Weapon& weapon;
};

#endif
