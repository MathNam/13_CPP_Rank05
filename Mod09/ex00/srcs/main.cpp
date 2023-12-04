/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnam <matnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:53:11 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/01 15:12:40 by matnam           ###   ########.fr       */
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

	BitcoinExchange btc;
	btc.fillData(av[1]);
	btc.processFile(ifs);
	return 0;
}
