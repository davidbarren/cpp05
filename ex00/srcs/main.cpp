/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 13:25:35 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Testing copy constructor -------" << std::endl;
	Bureaucrat cog("cog", 42);
	Bureaucrat worker(cog);
	Bureaucrat machine;

	std::cout << worker << std::endl;
	std::cout << cog << std::endl;

	std::cout << "Testing copy assignment operator ---------------" << std::endl;
	std::cout << machine << std::endl;
	cog = machine;
	std::cout << cog << std::endl;

	std::cout << "Exception handling -----------" << std::endl;


	std::cout << "Decrementing low grade: -------" << std::endl;
	try{
		Bureaucrat peon("peon", 150);
		peon.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl << std::endl;
	}

	std::cout << "Incrementing high grade: -----------" << std::endl;
	try{
		Bureaucrat genius("genius", 1);
		genius.incrementGrade();
		genius.incrementGrade();
		std::cout << genius << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl << std::endl;
	}

	std::cout << "Initializing too high grade: -----------" << std::endl;
	try{
		Bureaucrat smart("smart", -42);
		std::cout << smart << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl << std::endl;
	}

	std::cout << "Initializing too low grade: -----------" << std::endl;
	try{
		Bureaucrat simpleton("simpleton", 153);
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl << std::endl;
	}

}
