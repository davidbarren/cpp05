/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 01:03:45 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Testing copy constructor -------" << std::endl;
	Bureaucrat cog("rotta", 420);
	Bureaucrat shitter(cog);
	Bureaucrat machine;

	std::cout << shitter << std::endl;
	std::cout << cog << std::endl;

	std::cout << "Testing copy assignment operator ---------------" << std::endl;
	std::cout << machine << std::endl;
	cog = machine;
	std::cout << cog << std::endl;
//	shitter = cog;
//	std::cout << shitter << std::endl;
}
