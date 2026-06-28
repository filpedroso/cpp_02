/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 23:19:49 by fpedroso          #+#    #+#             */
/*   Updated: 2026/06/25 23:19:49 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int					_fixedNbr;
		static const int	_fracBits = 8;

	public:
		// Canonical
		Fixed();
		Fixed(const Fixed& src );
		Fixed&	operator=(const Fixed& rhs);
		~Fixed();

		// Alt Constructors
		Fixed( const int );
		Fixed( const float );

		// Overloads - comparison
		bool	operator>( const Fixed& rhs) const;
		bool	operator<( const Fixed& rhs) const;
		bool	operator>=( const Fixed& rhs) const;
		bool	operator<=( const Fixed& rhs) const;
		bool	operator==( const Fixed& rhs) const;
		bool	operator!=( const Fixed& rhs) const;

		// Overloads -  arithmetic
		Fixed	operator+( const Fixed& rhs);
		Fixed	operator-( const Fixed& rhs);
		Fixed	operator*( const Fixed& rhs);
		Fixed	operator/( const Fixed& rhs);

		// Overloads - increment | decrement
		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		//Member functions
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static Fixed&		min( Fixed& n1, Fixed& n2 );
		static Fixed&		max( Fixed& n1, Fixed& n2 );
		static const Fixed&	min( const Fixed& n1, const Fixed& n2 );
		static const Fixed&	max( const Fixed& n1, const Fixed& n2 );
};

std::ostream&	operator<<( std::ostream& o, const Fixed& rhs );



#endif
