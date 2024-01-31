/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:59:30 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 15:08:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main() {
	Harl harl;

	std::cout << "-- DEBUG MESSAGE --" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n-- INFO MESSAGE --" << std::endl;
	harl.complain("INFO");
	std::cout << "\n-- WARNING MESSAGE --" << std::endl;
	harl.complain("WARNING");
	std::cout << "\n-- ERROR MESSAGE --" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n-- INVALID MESSAGE --" << std::endl;
	harl.complain("TEST");
}
