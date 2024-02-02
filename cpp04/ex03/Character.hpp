/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:17 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:44:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter {
public:
	Character();
	Character(std::string const &name);
	Character(Character const &src);
	~Character();
	Character &operator=(Character const &rhs);

	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	AMateria *_inventory[4];
	std::string _name;
};

#endif
