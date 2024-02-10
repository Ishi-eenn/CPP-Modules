/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:10:25 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/10 16:48:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::initCurrentIndex(){
	this->currentIndex = 0;
}

int PhoneBook::getCurrentIndex() {
	return (this->currentIndex);
}

void PhoneBook::printHeader(){
	std::cout << "|";
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << "Index" << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << "First Name" << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << "Last Name" << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << "Nickname" << '|';
	std::cout << std::endl;
}

std::string PhoneBook::truncateAndAppendEllipsis(std::string str)
{
	if (str.length() > PhoneBook::COLUMN_WIDTH)
		str = str.substr(0, PhoneBook::COLUMN_WIDTH - 1) + ".";
	return (str);
}

void PhoneBook::printSearchListRow(const Contact& contact, const int i) const
{
	std::cout << "|";
	std::cout <<  std::setw(PhoneBook::COLUMN_WIDTH) << i;
	std::cout << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << PhoneBook::truncateAndAppendEllipsis(contact.getFirstName());
	std::cout << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << PhoneBook::truncateAndAppendEllipsis(contact.getLastName());
	std::cout << '|';
	std::cout << std::setw(PhoneBook::COLUMN_WIDTH) << std::right << PhoneBook::truncateAndAppendEllipsis(contact.getNickname());
	std::cout << '|' << std::endl;
}

void PhoneBook::printSearchList(){
	std::cout << "---------------------------------------------" << std::endl;
	PhoneBook::printHeader();
	std::cout << "---------------------------------------------" << std::endl;
	for (size_t i = 0; i < PhoneBook::MAX_CONTACT; i++)
		PhoneBook::printSearchListRow(this->contacts[i], i + 1);
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::printContactInfo(const Contact& contact) const
{
	const int COLUMN_WIDTH = 15;

	std::cout << std::setw(COLUMN_WIDTH) << std::left << "First Name";
	std::cout << ": " << contact.getFirstName() << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << std::left << "Last Name";
	std::cout << ": " << contact.getLastName() << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << std::left << "Nickname";
	std::cout << ": " << contact.getNickname() << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << std::left << "Phone Number";
	std::cout << ": " << contact.getPhoneNumber() << std::endl;
	std::cout << std::setw(COLUMN_WIDTH) << std::left << "Darkest Secret";
	std::cout << ": " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::printContactAtIndex(const int i){
	if (i - 1 < 0 || PhoneBook::MAX_CONTACT <= i - 1)
		std::cerr << "Error: Index out of range" << std::endl;
	else if (this->contacts[i - 1].getFirstName().empty())
		std::cerr << "Error: No contact information at that index" << std::endl;
	else printContactInfo(this->contacts[i - 1]);
}
