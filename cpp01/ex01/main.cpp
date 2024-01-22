/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:39:54 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 21:20:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 42;
	Zombie* horde = zombieHorde(n, "Alice");
	if (horde != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << "id: " << i << " - ";
			horde[i].announce();
		}
		delete[] horde;
	}
	return 0;
}
