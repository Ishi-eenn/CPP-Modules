/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:04:44 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 01:22:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = copy;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  std::cout << "FragTrap assignation operator called" << std::endl;
  if (this != &copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
  }
  return *this;
}

void FragTrap::attack(std::string const &target) {
  if (energyPoints == 0) {
    std::cout << "FragTrap " << name << " cannot attack because it has no energy points." << std::endl;
  } else if (hitPoints == 0) {
    std::cout << "FragTrap " << name << " cannot attack because it is already dead." << std::endl;
  } else {
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
  }
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << " requests a high five." << std::endl;
}
