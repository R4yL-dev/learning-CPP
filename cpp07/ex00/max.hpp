/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:38:15 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 20:20:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_HPP
#define MAX_HPP

template <typename T>
T const &max(T const &val1, T const &val2)
{
	return val1 > val2 ? val1 : val2;
}

#endif
