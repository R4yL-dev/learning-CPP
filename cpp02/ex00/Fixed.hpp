/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:26:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 17:53:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed& operator=(Fixed const &rhs);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int	_value;
	static const int _bits = 8;
};

#endif
