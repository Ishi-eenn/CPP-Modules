/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 12:23:03 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
  std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
  std::cerr << "Dog copy constructor called" << std::endl;
  *this = copy;
}

Dog::~Dog()
{
  std::cerr << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
  if (this != &copy)
    this->type = copy.type;
  std::cerr << "Dog assignation operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Woof Woof" << std::endl;
}
