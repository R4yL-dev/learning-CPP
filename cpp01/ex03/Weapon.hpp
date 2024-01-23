/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:20:06 by lray              #+#    #+#             */
/*   Updated: 2024/01/23 11:21:24 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
public:
	Weapon(const std::string& type);

	const std::string& getType() const;
	void setType(const std::string &type);
private:
	std::string type;
};

#endif
