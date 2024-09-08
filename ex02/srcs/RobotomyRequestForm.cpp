/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:05:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 19:40:28 by dbarrene         ###   ########.fr       */
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
	static int i = 0;
	if (checkPrivs(executor))
	{
		std:: cout << "*drilling noises*" << std::endl;
		if (i % 2)
			std::cout << m_target << " has been robotomized" << std::endl;
		else
			std::cout << m_target << "'s robotomy has failed :( " << std::endl;
	}
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	m_target = other.m_target;
	return *this;
}
