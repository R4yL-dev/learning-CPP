/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:50:13 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 17:10:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(
	const std::string &firstName,
	const std::string &lastName,
	const std::string &nickName,
	const std::string &phoneNumber,
	const std::string &secret
)
{
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setPhoneNumber(phoneNumber);
	setSecret(secret);
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string &firstName)
{
	if (validateField(firstName))
		m_firstName = firstName;
}
void Contact::setLastName(const std::string &lastName)
{
	if (validateField(lastName))
		m_lastName = lastName;
}
void Contact::setNickName(const std::string &nickName)
{
	if (validateField(nickName))
		m_nickName = nickName;
}
void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	if (validateField(phoneNumber))
		m_phoneNumber = phoneNumber;
}
void Contact::setSecret(const std::string &secret)
{
	if (validateField(secret))
		m_secret = secret;
}

std::string	Contact::getFirstName() const
{
	return m_firstName;
}
std::string	Contact::getLastName() const
{
	return m_lastName;
}
std::string	Contact::getNickName() const
{
	return m_nickName;
}
std::string	Contact::getPhoneNumber() const
{
	return m_phoneNumber;
}
std::string	Contact::getSecret() const
{
	return m_secret;
}

void Contact::print() const
{
	std::cout << std::left << std::setw(15) << "First name: " << m_firstName << "\n";
	std::cout << std::left << std::setw(15) << "Last name: " << m_lastName << "\n";
	std::cout << std::left << std::setw(15) << "Nickname: " << m_nickName << "\n";
	std::cout << std::left << std::setw(15) << "Phone number: " << m_phoneNumber << "\n";
	std::cout << std::left << std::setw(15) << "Secret: " << m_secret << std::endl;
}

void Contact::fillContactInfo()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (!validateField(firstName))
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
	}
	setFirstName(firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (!validateField(lastName))
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
	}
	setLastName(lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	while (!validateField(nickName))
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickName);
	}
	setNickName(nickName);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (!validateField(phoneNumber))
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	}
	setPhoneNumber(phoneNumber);

	std::cout << "Enter secret: ";
	std::getline(std::cin, secret);
	while (!validateField(secret))
	{
		std::cout << "Enter the secret: ";
		std::getline(std::cin, secret);
	}
	setSecret(secret);
}

bool Contact::validateField(const std::string &data) const
{
	if (data.empty())
		return false;
	return true;
}
