/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:20:06 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 12:51:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon(const std::string& type);
	~Weapon();

	const std::string& getType() const;
	void setType(const std::string &type);
private:
	std::string _type;
};

#endif
