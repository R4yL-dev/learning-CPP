/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:34 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 16:27:04 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

#define NAME_MIN_LEN 3
#define NAME_MAX_LEN 50
#define PHONE_MIN_LEN 3
#define PHONE_MAX_LEN 12
#define SECRET_MIN_LEN 3
#define SECRET_MAX_LEN 255

class Contact
{
public:
	Contact(
		const std::string &firstName = "",
		const std::string &lastName = "",
		const std::string &nickName = "",
		const std::string &phoneNumber = "",
		const std::string &secret = ""
	);
	~Contact();
	void		setFirstName(const std::string &firstName);
	void		setLastName(const std::string &lastName);
	void		setNickName(const std::string &nickName);
	void		setPhoneNumber(const std::string &phoneNumber);
	void		setSecret(const std::string &secret);
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getSecret() const;
	void		print() const;
	void		fillContactInfo();
private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickName;
	std::string	m_phoneNumber;
	std::string	m_secret;

	bool		validateField(const std::string &data) const;
};

#endif
