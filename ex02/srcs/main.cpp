/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:25:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;//should not create a leak
  delete i;

  return 0;
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor()
{
  system("leaks -q a.out");
}

#endif
