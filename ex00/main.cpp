/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:22:31 by mjung             #+#    #+#             */
/*   Updated: 2021/12/22 02:23:20 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "scalarConversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "The number of argument values is not correct." << std::endl;
		return(1);
	}

	std::cout << std::fixed;
	std::cout.precision(1);

	char *target = argv[1];
	scalarConversion convert(target);

	convert.toChar();
	convert.toInt();
	convert.toFloat();
	convert.toDouble();
	
	return (0);
}
