/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:53:11 by mcombeau          #+#    #+#             */
/*   Updated: 2023/11/30 15:14:05 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
		std::cout << "Invalid number of arguments:\n [Usage] : ./btc [filename]." << std::endl;
	
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
		std::cout << "Invalid file name." << std::endl;
	
	std::string line;
	while (getline(ifs, line)) {
		
	}
}
