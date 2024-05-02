/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:29 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:58:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *brain;

  public:
    Dog();
    Dog(const Dog &copy);
    Dog &operator=(const Dog &copy);
    ~Dog();

    void makeSound() const;
};

#endif
