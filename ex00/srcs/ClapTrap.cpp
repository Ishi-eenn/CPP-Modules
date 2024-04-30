/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:37 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/30 22:34:55 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("tsishika"), hitPoints(10), energyPoints(10), attackDamage(0)
{
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = copy;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
  std::cout << "ClapTrap assignation operator called" << std::endl;
  if (this != &copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
  }
  return *this;
}

void ClapTrap::attack(std::string const &target) {
  if (energyPoints == 0) {
    std::cout << "ClapTrap " << name << " cannot attack because it has no energy points." << std::endl;
  } else if (hitPoints == 0) {
    std::cout << "ClapTrap " << name << " cannot attack because it is already dead." << std::endl;
  } else {
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << "ClapTrap " << name << " cannot take damage because it is already dead." << std::endl;
  } else if (amount >= hitPoints) {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and dies!" << std::endl;
  } else {
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energyPoints == 0) {
    std::cout << "ClapTrap " << name << " cannot be repaired because it has no energy points." << std::endl;
  } else if (hitPoints == 0) {
    std::cout << "ClapTrap " << name << " cannot be repaired because it is already dead." << std::endl;
  } else {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " is repaired " << amount << " hit points." << std::endl;
  }
}
