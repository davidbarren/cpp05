/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:57:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/11 15:07:09 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

AForm* Intern::makeForm(std::string formname, std::string target)
{
	std::string forms[3] { "robotomy request", "shrubbery creation", "presidential pardon"};
	for(int i = 0; i < 3; i++)
	{
		if (formname == forms[i])
		{
			switch (i)
			{
				case 0:
					return new RobotomyRequestForm(target);
				case 1:
					return new ShrubberyCreationForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	return nullptr;
}
