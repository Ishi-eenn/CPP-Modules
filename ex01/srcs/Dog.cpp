/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:23:21 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
  std::cerr << "Dog default constructor called" << std::endl;
  brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
  std::cerr << "Dog copy constructor called" << std::endl;
  *this = copy;
  brain = new Brain(*copy.brain);
}

Dog::~Dog()
{
  std::cerr << "Dog destructor called" << std::endl;
  delete brain;
}

Dog &Dog::operator=(const Dog &copy) {
  std::cerr << "Dog assignation operator called" << std::endl;
  if (this != &copy) {
    this->type = copy.type;
    delete brain;
    brain = new Brain(*copy.brain);
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Woof Woof" << std::endl;
}
