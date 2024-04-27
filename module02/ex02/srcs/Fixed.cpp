/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:19:21 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/25 18:46:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::kFractionalBits = 8;

Fixed::Fixed() : _fixed_point_number(0) {
  std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
  std::cerr << "Int constructor called" << std::endl;
  SetRawBits(integer << Fixed::kFractionalBits);
}

Fixed::Fixed(const float floating_point_number) {
  std::cerr << "Float constructor called" << std::endl;
  float shifted = floating_point_number * static_cast<float>(1 << Fixed::kFractionalBits);
  SetRawBits(static_cast<int>(roundf(shifted)));
}

Fixed::Fixed(const Fixed &obj) {
  std::cerr << "Copy constructor called" << std::endl;
  *this = obj;
}

bool Fixed::operator>(const Fixed &obj) const {
  return GetRawBits() > obj.GetRawBits();
}

bool Fixed::operator<(const Fixed &obj) const {
  return GetRawBits() < obj.GetRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const {
  return GetRawBits() >= obj.GetRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const {
  return GetRawBits() <= obj.GetRawBits();
}

bool Fixed::operator==(const Fixed &obj) const {
  return GetRawBits() == obj.GetRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const {
  return GetRawBits() != obj.GetRawBits();
}

Fixed Fixed::operator+(Fixed obj) const {
  obj.SetRawBits(GetRawBits() + obj.GetRawBits());
  return obj;
}

Fixed Fixed::operator-(Fixed obj) const {
  obj.SetRawBits(GetRawBits() - obj.GetRawBits());
  return obj;
}

Fixed Fixed::operator*(Fixed obj) const {
  obj.SetRawBits(static_cast<int>((static_cast<long int>(GetRawBits()) * obj.GetRawBits()) >> Fixed::kFractionalBits));
  return obj;
}

Fixed Fixed::operator/(Fixed obj) const {
  obj.SetRawBits((GetRawBits() / obj.GetRawBits()) << Fixed::kFractionalBits);
  return obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
  std::cerr << "Copy assignment operator called" << std::endl;
  SetRawBits(obj.GetRawBits());
  return *this;
}

Fixed &Fixed::operator++() {
  SetRawBits(GetRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  operator++();
  return temp;
}

Fixed &Fixed::operator--() {
  SetRawBits(GetRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  operator--();
  return temp;
}

Fixed::~Fixed() {
  std::cerr << "Destructor called" << std::endl;
}

int Fixed::GetRawBits() const {
  return _fixed_point_number;
}

void Fixed::SetRawBits(const int row) {
  _fixed_point_number = row;
}

int Fixed::ToInt() const {
  return GetRawBits() >> Fixed::kFractionalBits;
}

float Fixed::ToFloat() const {
  return static_cast<float>(GetRawBits()) / (1 << Fixed::kFractionalBits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  if (f1 <= f2)
	return f1;
  return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  if (f1 <= f2)
	return f1;
  return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  if (f1 >= f2)
	return f1;
  return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  if (f1 >= f2)
	return f1;
  return f2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.ToFloat();
  return os;
}
