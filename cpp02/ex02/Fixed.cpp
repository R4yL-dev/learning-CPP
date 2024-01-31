/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:34:45 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 18:43:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(int const n) {
	int value = n;
	for (int i = this->_bits; i > 0; i--) {
		value *= 2;
	}
	this->_value = value;
}

Fixed::Fixed(float const n) {
	float value = n;
	for (int i = this->_bits; i > 0; i--) {
		value *= 2;
	}
	this->_value = round(value);
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

bool Fixed::operator>(const Fixed &src) const {
	return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(const Fixed &src) const {
	return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(const Fixed &src) const {
	return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(const Fixed &src) const {
	return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(const Fixed &src) const {
	return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(const Fixed &src) const {
	return this->toFloat() != src.toFloat();
}

Fixed Fixed::operator+(const Fixed &src) const {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const {
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int n) {
	Fixed value = *this;
	this->setRawBits(this->getRawBits() + 1);
	return value;
}

Fixed &Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int n) {
	Fixed value = *this;
	this->setRawBits(this->getRawBits() - 1);
	return value;
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

Fixed &Fixed::min(Fixed &src1, Fixed &src2) {
	if (src1 < src2)
		return src1;
	return src2;
}

const Fixed &Fixed::min(const Fixed &src1, const Fixed &src2) {
	if (src1 < src2)
		return src1;
	return src2;
}

Fixed &Fixed::max(Fixed &src1, Fixed &src2) {
	if (src1 > src2)
		return src1;
	return src2;
}

const Fixed &Fixed::max(Fixed const &src1, Fixed const &src2) {
	if (src1 > src2)
		return src1;
	return src2;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return o;
}
