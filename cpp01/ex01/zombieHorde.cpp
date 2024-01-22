/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:59:28 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 21:15:36 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *horde = NULL;
	try
	{
		horde = new Zombie[n];
		for (int i = 0; i < n; ++i)
		{
			horde[i].setName(name);
		}
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << '\n';
		return NULL;
	}
	return horde;
}
