/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:13 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/10 16:48:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		static const int MAX_CONTACT = 8;
		static const int COLUMN_WIDTH = 10;
		int currentIndex;
		Contact contacts[MAX_CONTACT];

	private:
		static std::string truncateAndAppendEllipsis(std::string str);
		int getCurrentIndex();
		void printContactInfo(const Contact& contact) const;
		void printHeader();
		void printSearchListRow(const Contact& contact, const int) const;

	public:
		void initCurrentIndex();
		void printSearchList();
		void printContactAtIndex(int idx);
};

#endif
