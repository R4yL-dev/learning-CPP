/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:37:48 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 20:20:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_HPP
#define MIN_HPP

template <typename T>
T const &min(T const &val1, T const &val2)
{
	return val1 < val2 ? val1 : val2;
}

#endif
