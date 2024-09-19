/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 14:40:16 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "Forms and shit" << std::endl;
	AForm *shrub = new ShrubberyCreationForm("dir");
	std::cout << *shrub << std::endl;
	Bureaucrat chad("gigachad", 1);
	Intern baboon;
	Bureaucrat loser("rotta", 150);
	AForm *putchar = baboon.makeForm("robotomy request", "trees");
	std::cout << *putchar << std::endl;
	std::cout << chad << std::endl;
	loser.signForm(*putchar);
	chad.executeForm(*putchar);
	chad.signForm(*putchar);
	loser.executeForm(*putchar);
	chad.executeForm(*putchar);
	chad.signForm(*shrub);
	chad.executeForm(*shrub);
	std::cout << *putchar << std::endl;
	std::cout << *shrub << std::endl;
	delete putchar;
	delete shrub;
}
