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

		Fixed();
		Fixed( const int );
		Fixed( const float );
		Fixed(const Fixed& src );
		~Fixed();

		Fixed&	operator=(const Fixed& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& o, const Fixed& rhs );



#endif
