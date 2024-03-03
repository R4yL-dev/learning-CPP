/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:31:01 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 22:34:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>

int main()
{
	{
		std::cout << "-- TEST CONSTRUCTOR --" << std::endl;

		std::cout << "- test default constructor" << std::endl;
		Array<float> arr1;
		std::cout << "arr1.size() = " << arr1.size() << std::endl;

		std::cout << "- test parametrize constructor" << std::endl;
		Array<float> arr2(8);
		std::cout << "arr2.size() = " << arr2.size() << std::endl;
		arr2[7] = 42.42;
		std::cout << "arr1[7] = " << arr2[7] << std::endl;

		std::cout << "- test copy constructor" << std::endl;
		Array<float> arr3(arr2);
		std::cout << "arr3.size() = " << arr3.size() << std::endl;
		std::cout << "arr3[7] = " << arr3[7] << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST OPERATOR --" << std::endl;
		Array<int> arr1(8);
		std::cout << "arr1.size() = " << arr1.size() << std::endl;
		for (unsigned int i = 0; i < arr1.size(); ++i)
		{
			arr1[i] = i * 2;
		}
		Array<int> arr2;
		std::cout << "arr2.size() = " << arr2.size() << std::endl;
		arr2 = arr1;
		std::cout << "arr2.size() = " << arr2.size() << std::endl;
		for (unsigned int i = 0; i < arr2.size(); ++i)
		{
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST OUT OF BOUNDS --" << std::endl;
		Array<std::string> arr1(8);
		std::cout << "arr1.size() = " << arr1.size() << std::endl;
		try
		{
			arr1[7] = "42";
			arr1[8] = "Lausanne";
		}
		catch (std::exception &err)
		{
			std::cerr << err.what() << std::endl;
		}
		std::cout << "arr1.size() = " << arr1.size() << std::endl;
		try
		{
			arr1[-1] = "42";
		}
		catch (std::exception &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	return 0;
}
