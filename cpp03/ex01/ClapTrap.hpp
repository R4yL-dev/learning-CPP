/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:45 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:44:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(std::string const &name, unsigned int const hitPoint, unsigned int const energyPoint, unsigned int const attackDamage);
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string	_name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;

};

#endif
