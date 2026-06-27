/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 23:19:52 by fpedroso          #+#    #+#             */
/*   Updated: 2026/06/25 23:19:52 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed() : _fixedNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedNbr(n << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixedNbr(static_cast<int>(roundf(f * (1 << _fracBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _fixedNbr(other._fixedNbr)
{
	std::cout << "Copy constructor called" << std::endl;
}


// Copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_fixedNbr = rhs._fixedNbr;
	return (*this);
}

// Insertion operator overload
std::ostream&	operator<<( std::ostream& o, const Fixed& rhs )
{
	o << rhs.toFloat();
	return (o);
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// Member functions
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNbr);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNbr = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedNbr / (1 << this->_fracBits));
}

int	Fixed::toInt( void ) const
{
	return ( this->_fixedNbr >> this->_fracBits );
}
