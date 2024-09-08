/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 17:42:07 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try{
		Form testcase;
		std::cout << testcase << std::endl;
		Bureaucrat worker("loser", 69);

		testcase.beSigned(worker);}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try{
		Form myform("bestformever" , 150, 42);
		std:: cout << myform << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
