/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:48:56 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/05 13:49:03 by maaliber         ###   ########.fr       */
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
		int res = RPN::calculate(av[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return ( 0 );
}
