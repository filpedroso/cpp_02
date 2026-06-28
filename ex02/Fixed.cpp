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


// ****** CANONICAL RITES ******

// Default constructor
Fixed::Fixed() : _fixedNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
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

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



// ****** ALTERNATIVE CONSTRUCTORS ******

Fixed::Fixed(const int n) : _fixedNbr(n << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixedNbr(static_cast<int>(roundf(f * (1 << _fracBits))))
{
	std::cout << "Float constructor called" << std::endl;
}



// ****** COMPARISON OPERATOR OVERLOADS ******

bool	Fixed::operator>( const Fixed& rhs) const
{
	return this->_fixedNbr > rhs._fixedNbr;
}

bool	Fixed::operator<( const Fixed& rhs) const
{
	return this->_fixedNbr < rhs._fixedNbr;
}

bool	Fixed::operator>=( const Fixed& rhs) const
{
	return this->_fixedNbr >= rhs._fixedNbr;
}

bool	Fixed::operator<=( const Fixed& rhs) const
{
	return this->_fixedNbr <= rhs._fixedNbr;
}

bool	Fixed::operator==( const Fixed& rhs) const
{
	return this->_fixedNbr == rhs._fixedNbr;
}

bool	Fixed::operator!=( const Fixed& rhs) const
{
	return this->_fixedNbr != rhs._fixedNbr;
}



// ****** ARITHMETIC OPERATOR OVERLOADS ******

Fixed	Fixed::operator+( const Fixed& rhs)
{
	return Fixed( this->_fixedNbr + rhs._fixedNbr );
}

Fixed	Fixed::operator-( const Fixed& rhs)
{
	return Fixed( this->_fixedNbr - rhs._fixedNbr );
}

Fixed	Fixed::operator*( const Fixed& rhs)
{
	Fixed result;
	result.setRawBits((this->_fixedNbr * rhs._fixedNbr) >> this->_fracBits);
	return result;
}

Fixed	Fixed::operator/( const Fixed& rhs)
{
	Fixed result;
	result.setRawBits((this->_fixedNbr << this->_fracBits) / rhs._fixedNbr);
	return result;
}



// ****** INCR/DECR OPERATOR OVERLOADS ******

Fixed&	Fixed::operator++( void )
{
	this->_fixedNbr += 1;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	this->_fixedNbr -= 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);
	this->_fixedNbr += 1;
	return (tmp);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);
	this->_fixedNbr -= 1;
	return (tmp);
}



// ****** INSERTION OPERATOR OVERLOAD ******

std::ostream&	operator<<( std::ostream& o, const Fixed& rhs )
{
	o << rhs.toFloat();
	return (o);
}



// ****** MEMBER FUNCTIONS ******

// Getter / Setter
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


// Conversion
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedNbr / (1 << this->_fracBits));
}

int	Fixed::toInt( void ) const
{
	return ( this->_fixedNbr >> this->_fracBits );
}


// Comparison
Fixed&	Fixed::min( Fixed& n1, Fixed& n2 )
{
	return ( (n1 < n2) ? n1 : n2);
}

Fixed&	Fixed::max( Fixed& n1, Fixed& n2 )
{
	return ( (n1 > n2) ? n1 : n2);
}

const Fixed&	Fixed::min( const Fixed& n1, const Fixed& n2 )
{
	return ( (n1 < n2) ? n1 : n2);
}

const Fixed&	Fixed::max( const Fixed& n1, const Fixed& n2 )
{
	return ( (n1 > n2) ? n1 : n2);
}
