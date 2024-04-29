/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:50 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 12:21:09 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
  std::cerr << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
  std::cerr << "Cat copy constructor called" << std::endl;
  *this = copy;
}

Cat::~Cat()
{
  std::cerr << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
  if (this != &copy)
    this->type = copy.type;
  std::cerr << "Cat assignation operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow Meow" << std::endl;
}
