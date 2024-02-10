#ifndef UTILS_H
# define UTILS_H

# include <string>
# include <iostream>

void displayAvailableCommandsTitle(){
	std::cout << "The available commands are EXIT, ADD and SEARCH." << std::endl;
}

void displayErrorAndExit(std::string string, bool isNewlineNeeded){
	if(isNewlineNeeded)
		std::cout << std::endl;
	std::cerr << string << std::endl;
	exit(1);
}

void displayAndExit(std::string string){
	std::cout << string << std::endl;
	exit(0);
}

#endif
