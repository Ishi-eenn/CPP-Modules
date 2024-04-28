/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 00:04:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  // ClapTrap clapTrap("tsishika");

  // clapTrap.attack("enemy");
  // clapTrap.takeDamage(5);
  // clapTrap.beRepaired(5);

  ClapTrap human1("tsishika");
  ClapTrap human2("yamada");

  human1.attack("yamada");

  human1.attack("yayamada");
  human2.takeDamage(10);
  human1.takeDamage(5);
  human2.beRepaired(10);
  human1.beRepaired(6);
  human1.beRepaired(3);

  ClapTrap human4(human1);
  human4.beRepaired(2);
  human4.beRepaired(3);
  human1.beRepaired(1);

std::cout << "====================" << std::endl;
// ClapTrap human1("yamada");
//   ClapTrap human2("yayamada");
//   ClapTrap human3;

  return 0;
}
