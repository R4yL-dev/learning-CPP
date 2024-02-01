/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:24:48 by lray              #+#    #+#             */
/*   Updated: 2024/02/01 16:28:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(std::string const &name, uint const hitPoint, uint const energyPoint, uint const attackDamage);
	FragTrap(FragTrap const &src);
	FragTrap &operator=(FragTrap const &src);
	~FragTrap();

	void attack(std::string const &target);

	void highFivesGuys() const;
};

#endif
