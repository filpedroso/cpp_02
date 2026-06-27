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

class Fixed
{
	private:

		int					_fixedNbr;
		static const int	_fracBits = 8;

	public:

		Fixed();
		Fixed(const Fixed& src );
		~Fixed();
		Fixed& operator=(const Fixed& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};



#endif
