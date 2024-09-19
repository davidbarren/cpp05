/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:05:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 13:00:37 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	m_target = target;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	m_target = other.m_target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSignage())
		throw FormNotSignedException();
	if (checkExecPrivs(executor))
	{
		std::srand(std::time(nullptr));
		int random = std::rand();
		std:: cout << "*drilling noises*" << std::endl;
		if (random % 2)
			std::cout << m_target << " has been robotomized" << std::endl;
		else
			std::cout << m_target << "'s robotomy has failed :( " << std::endl;
	}
	else
		throw GradeTooLowException();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	m_target = other.m_target;
	return *this;
}
