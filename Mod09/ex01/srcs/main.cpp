/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:48:56 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/06 10:29:33 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2) {
		std::cerr << "Usage: ./RPN [reverse Polish notation expression]" << std::endl;
		return (1);
	}
	try {
		RPN rpn;
		std::string	str = av[1];
		int res = rpn.calculate(str);
		std::cout << res << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return ( 0 );
}
