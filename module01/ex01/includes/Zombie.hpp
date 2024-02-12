/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:49:08 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 15:10:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(const std::string &name);
};

Zombie *zombieHorde(int, std::string);

#endif
