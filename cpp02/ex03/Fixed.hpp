/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:26:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 18:39:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
   public:
	Fixed();
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);
	bool operator>(const Fixed &src) const;
	bool operator<(const Fixed &src) const;
	bool operator>=(const Fixed &src) const;
	bool operator<=(const Fixed &src) const;
	bool operator==(const Fixed &src) const;
	bool operator!=(const Fixed &src) const;
	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;
	Fixed &operator++();
	Fixed operator++(int n);
	Fixed &operator--();
	Fixed operator--(int n);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	static Fixed &min(Fixed &src1, Fixed &src2);
	static const Fixed &min(const Fixed &src1, const Fixed &src2);
	static Fixed &max(Fixed &src1, Fixed &src2);
	static const Fixed &max(Fixed const &src1, Fixed const &src2);

   private:
	int _value;
	static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif
