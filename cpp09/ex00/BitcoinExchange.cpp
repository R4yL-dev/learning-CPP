/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:07 by lray              #+#    #+#             */
/*   Updated: 2024/03/05 20:37:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string const &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("cannot open database");
	std::cout << CYAN << "[?] database has been successfully opened" << RESET << std::endl;

	std::string line;
	std::getline(file, line);
	int i = 2;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;

		if (!getline(ss, date, ',') || !(ss >> value))
		{
			std::cerr << RED << "[!] line: " << i << RESET << std::endl;
			throw std::runtime_error("invalide entry in database");
		}
		++i;
		this->_mapData[date] = value;
	}
	std::cout << CYAN << "[?] database has been successfully loaded | total entry: " << this->_mapData.size() << RESET << std::endl;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	this->_mapData = src._mapData;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs)
		this->_mapData = rhs._mapData;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::getExchangeRate(std::string const &date, float value) const
{
	_isValid(date);
	_isValid(value);
	std::map<std::string, float>::const_iterator it = this->_mapData.lower_bound(date);
	if (it != this->_mapData.begin() && (it == this->_mapData.end() || it->first != date))
		--it;
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

void BitcoinExchange::_isValid(std::string const &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("invalid date format");

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1000 || year > 9999)
		throw std::runtime_error("year must be between 1000 and 9999");

	if (month < 1 || month > 12)
		throw std::runtime_error("month must be between 01 and 12");

	if (day < 1 || day > 31)
		throw std::runtime_error("day must be between 01 and 31");

	// Checks for months with less than 31 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::runtime_error("this month cannot have more than 30 days");

	// February
	if (month == 2)
	{
		// Check for leap year
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > 29 || (!isLeapYear && day > 28))
			throw std::runtime_error("February cannot have more than 29 days, except in leap years when it cannot have more than 28 days.");
	}
}

void BitcoinExchange::_isValid(float value) const
{
	if (value < 0.0 || value > 1000.0)
		throw std::runtime_error("value must be between 0 and 1000");
}
