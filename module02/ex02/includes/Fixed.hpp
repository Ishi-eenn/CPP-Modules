/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:19:18 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/25 18:46:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(int integer);
  Fixed(float floating_point_number);
  Fixed(const Fixed &obj);
  bool operator>(const Fixed &obj) const;
  bool operator<(const Fixed &obj) const;
  bool operator>=(const Fixed &obj) const;
  bool operator<=(const Fixed &obj) const;
  bool operator==(const Fixed &obj) const;
  bool operator!=(const Fixed &obj) const;
  Fixed operator+(Fixed obj) const;
  Fixed operator-(Fixed obj) const;
  Fixed operator*(Fixed obj) const;
  Fixed operator/(Fixed obj) const;
  Fixed &operator=(const Fixed &obj);
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  ~Fixed();
  int GetRawBits() const;
  void SetRawBits(int row);
  int ToInt() const;
  float ToFloat() const;
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);

 private:
  int _fixed_point_number;
  static const int kFractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
