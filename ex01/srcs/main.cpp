/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 14:32:47 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form myform("myform", 42, 42);
	try
	{
		Form badform("trashform", 160, 42);
	}
	catch (std::exception &e)
	{
		std::cout << "caught exception: " << e.what() << std::endl;
	}
	Bureaucrat gigachad("gigachad", 3);
	Bureaucrat loser;

	std::cout << myform << std::endl;
	std::cout << gigachad << std::endl;
	std::cout << loser << std::endl;
	loser.signForm(myform);
	gigachad.signForm(myform);
	loser = gigachad;
	loser.signForm(myform);
	std::cout << myform << std::endl;
}
