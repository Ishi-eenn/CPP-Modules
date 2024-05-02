/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:37:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 01:47:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap Default constructor" << std::endl;
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  std::cout << "DiamondTrap Name constructor" << std::endl;
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
  std::cout << "DiamondTrap Copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
  if (this != &copy) {
    ClapTrap::operator=(copy);
    ScavTrap::operator=(copy);
    FragTrap::operator=(copy);
  }
  return *this;
}

void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "My name is " << name << " and my DiamondTrap name is " << ClapTrap::name << std::endl;
}
