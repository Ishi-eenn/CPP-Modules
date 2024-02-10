/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:10:36 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/10 17:04:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.h"

void interactivePhoneBook(){
	PhoneBook book;
	std::string input;

	book.initCurrentIndex();

	while(true){
		displayAvailableCommandsTitle();
		std::cout << "$> ";

		std::getline(std::cin, input);

		if(std::cin.eof())
			displayErrorAndExit("Error: End of input", true);
		if(std::cin.fail())
			displayErrorAndExit("Error: Input failure", true);
		if (input.compare("EXIT") == 0)
			displayAndExit("Exiting the program. Goodbye!");

		if (input == "ADD")
			std::cout << "ADD handler" << std::endl;
		else if (input == "SEARCH")
			std::cout << "SEARCH handler" << std::endl;
		else
			input.empty() ? (std::cerr << "Error: Empty input" << std::endl) : (std::cerr << "Error: Invalid command" << std::endl);
	}
}

int main(int argc, char **argv){
	(void)argv;
	if(1 < argc)
		displayErrorAndExit("Error: Too many arguments", false);
	interactivePhoneBook();
}
