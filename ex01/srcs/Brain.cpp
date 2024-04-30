/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:57:52 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/01 02:07:49 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
  std::cerr << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
  std::cerr << "Brain copy constructor called" << std::endl;
  *this = copy;
}

Brain::~Brain()
{
  std::cerr << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
  std::cerr << "Brain assignation operator called" << std::endl;
  if (this != &copy) {
    for (int i = 0; i < ideasCount; i++)
      ideas[i] = copy.ideas[i];
  }
  return *this;
}
