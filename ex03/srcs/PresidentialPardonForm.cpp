/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:05:49 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 19:36:43 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	m_target = target;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	m_target = other.m_target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (checkPrivs(executor))
		std:: cout<< m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	m_target = other.m_target;
	return *this;
}
