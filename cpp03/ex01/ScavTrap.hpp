/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:17:51 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:45:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(std::string const &name, unsigned int const hitPoint, unsigned int const energyPoint, unsigned int const attackDamage);
	ScavTrap(ScavTrap const &src);
	ScavTrap &operator=(ScavTrap const &src);
	~ScavTrap();

	void attack(std::string const &target);

	void guardGate() const;
};

#endif
