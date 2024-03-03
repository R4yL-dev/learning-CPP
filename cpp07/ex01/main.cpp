/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:17:45 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 20:57:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

static void showInt(int &val);
static void fillInt(int &val);
static void showFloat(float &val);
static void fillFloat(float &val);
static void showString(std::string &val);
static void fillString(std::string &val);

int main() {
	const size_t len = 6;
	{
		int arr[len] = {0};

		std::cout << "--- INT ---" << std::endl;
		std::cout << "iter(arr, len, showInt)" << std::endl;
		::iter(arr, len, showInt);
		std::cout << "iter(arr, len, fillInt)" << std::endl;
		::iter(arr, len, fillInt);
		std::cout << "iter(arr, len, showInt)" << std::endl;
		::iter(arr, len, showInt);
	}
	std::cout << std::endl;
	{
		float arr[len] = {0.0};

		std::cout << "--- FLOAT ---" << std::endl;
		std::cout << "iter(arr, len, showFloat)" << std::endl;
		::iter(arr, len, showFloat);
		std::cout << "iter(arr, len, fillFloat)" << std::endl;
		::iter(arr, len, fillFloat);
		std::cout << "iter(arr, len, showFloat)" << std::endl;
		::iter(arr, len, showFloat);
	}
	std::cout << std::endl;
	{
		std::string arr[len] = {""};

		std::cout << "--- STRING ---" << std::endl;
		std::cout << "iter(arr, len, showString)" << std::endl;
		::iter(arr, len, showString);
		std::cout << "iter(arr, len, fillString)" << std::endl;
		::iter(arr, len, fillString);
		std::cout << "iter(arr, len, showString)" << std::endl;
		::iter(arr, len, showString);
	}
	return 0;
}

static void showInt(int &val) {
	std::cout << "- " << val << std::endl;
}

static void fillInt(int &val) {
	val = 42;
}

static void showFloat(float &val) {
	std::cout << "- " << val << std::endl;
}

static void fillFloat(float &val) {
	val = 42.42;
}

static void showString(std::string &val) {
	std::cout << "- " << val << std::endl;
}

static void fillString(std::string &val) {
	val = "42 Lausanne";
}

