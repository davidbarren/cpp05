/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:05:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 20:10:03 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	m_target = target;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	m_target = other.m_target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::string filename;

	filename = m_target + "_shrubbery";
	std::cout << filename << std::endl;
	if (checkPrivs(executor))
	{
		std::cout << "shrubbadubdub" << std::endl;
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	m_target = other.m_target;
	return *this;
}
