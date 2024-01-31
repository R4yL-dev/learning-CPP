/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:59:30 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 15:49:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl harl;
	std::string filter;

	if (argc == 1)
		filter = "DEBUG";
	if (argc == 2)
		filter = argv[1];
	harl.complain("DEBUG", filter);
	harl.complain("INFO", filter);
	harl.complain("WARNING", filter);
	harl.complain("ERROR", filter);
	return 0;
}
