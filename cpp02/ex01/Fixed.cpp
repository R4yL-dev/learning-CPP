/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:34:45 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 18:11:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	int value = n;
	for (int i = this->_bits; i > 0; i--) {
		value *= 2;
	}
	this->_value = value;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	float value = n;
	for (int i = this->_bits; i > 0; i--) {
		value *= 2;
	}
	this->_value = round(value);
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat() const {
	float value = this->_value;

	for (int i = this->_bits; i > 0; i--) {
		value /= 2;
	}
	return value;
}

int Fixed::toInt() const {
	int value = this->_value;

	for (int i = this->_bits; i > 0; i--) {
		value /= 2;
	}
	return value;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return o;
}
