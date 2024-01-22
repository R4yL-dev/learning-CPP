/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:29:54 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 20:45:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void setName(std::string &name);
	void announce(void);
private:
	std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
