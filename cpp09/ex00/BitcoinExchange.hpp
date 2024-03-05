/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:13:15 by lray              #+#    #+#             */
/*   Updated: 2024/03/05 20:38:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"

class BitcoinExchange {
public:
	BitcoinExchange(std::string const &path);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();

	void getExchangeRate(std::string const &date, float value) const;

private:
	std::map<std::string, float> _mapData;

	BitcoinExchange();
	void _initMapData(std::string const &path);
	void _isValid(std::string const &date) const;
	void _isValid(float value) const;
};

#endif
