/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:50 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:19:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
  std::cerr << "Cat default constructor called" << std::endl;
  brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
  std::cerr << "Cat copy constructor called" << std::endl;
  *this = copy;
  brain = new Brain(*copy.brain);
}

Cat::~Cat()
{
  std::cerr << "Cat destructor called" << std::endl;
  delete brain;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cerr << "Cat assignation operator called" << std::endl;
  if (this != &copy) {
    this->type = copy.type;
    delete brain;
    brain = new Brain(*copy.brain);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow Meow" << std::endl;
}
