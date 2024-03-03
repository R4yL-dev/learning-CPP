/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:38:49 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 20:21:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T>
void swap(T &val1, T &val2)
{
	T tmp = val1;
	val1 = val2;
	val2 = tmp;
}

#endif
