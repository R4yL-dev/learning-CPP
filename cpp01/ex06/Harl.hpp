/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:03:18 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 15:48:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
public:
	void	complain(const std::string &level) const;
	void	complain(const std::string &level, const std::string &filter) const;

private:
	void	debug() const;
	void	info() const;
	void	warning() const;
	void	error() const;
};

int	get_level(const std::string &level);

#endif
