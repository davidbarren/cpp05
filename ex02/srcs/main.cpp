/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 13:47:37 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	AForm *shrub = new ShrubberyCreationForm("dir");
	Bureaucrat chad;
	Bureaucrat gigachad("gigachad", 1);

	chad.signForm(*shrub);
	chad.executeForm(*shrub);
	gigachad.signForm(*shrub);
	gigachad.executeForm(*shrub);
	delete shrub;

	AForm* pardon = new PresidentialPardonForm("baboonius");
	chad.signForm(*pardon);
	chad.executeForm(*pardon);
	gigachad.signForm(*pardon);
	gigachad.executeForm(*pardon);
	delete pardon;

	AForm* robotomy = new RobotomyRequestForm("bender");
	chad.signForm(*robotomy);
	chad.executeForm(*robotomy);
	gigachad.signForm(*robotomy);
	gigachad.executeForm(*robotomy);
	chad = gigachad;
	chad.executeForm(*robotomy);
	delete robotomy;
}
