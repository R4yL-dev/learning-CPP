/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:46:00 by lray              #+#    #+#             */
/*   Updated: 2024/03/02 17:03:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data data = {42, "http://42lausanne.ch"};

	std::cout << "Data before serialization: " << data.index << " | " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Raw data: " << raw << std::endl;

	Data* final = {0};

	final = Serializer::deserialize(raw);

	std::cout << "Data after serialization: " << final->index << " | " << final->value << std::endl;

	return 0;
}
