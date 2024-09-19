/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:05:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 13:01:58 by dbarrene         ###   ########.fr       */
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
	std::string tree;
	std::ofstream strm;

	tree = "  *  \n *** \n*****\n  |  \n";
	if (!getSignage())
		throw FormNotSignedException();
	if (checkExecPrivs(executor))
	{
		strm.open(m_target + "_shrubbery");
		if (strm.is_open())
		{
			strm << tree;
			strm.close();
		}
	}
	else
		throw GradeTooLowException();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	m_target = other.m_target;
	return *this;
}
