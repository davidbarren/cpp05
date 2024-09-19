/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:42:27 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 12:47:02 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): m_name("default form"), m_is_signed(false),
	m_sign_req(42), m_exec_req(42)
{
}

AForm::AForm(std::string name, int32_t signreq, int32_t execreq): m_name(name),
	m_is_signed(false), m_sign_req(signreq), m_exec_req(execreq)
{
	if (m_sign_req > 150 || m_exec_req > 150)
		throw GradeTooLowException();
	if (m_sign_req < 0 || m_exec_req < 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other):m_name(other.m_name), 
	m_is_signed(other.m_is_signed), m_sign_req(other.m_sign_req), m_exec_req(other.m_exec_req)
{
}

AForm& AForm::operator=(const AForm& other)
{
	m_is_signed = other.m_is_signed;
		return (*this);
}

AForm::~AForm(){}

const std::string AForm::getName() const
{
	return m_name;
}
bool	AForm::getSignage() const
{
	return m_is_signed;
}

int32_t AForm::getSignReq() const
{
	return m_sign_req;
}

int32_t AForm::getExecReq() const
{
	return m_exec_req;
}

void	AForm::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() <= m_sign_req)
		m_is_signed = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return "AForm's grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return "AForm's grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "This form is not signed!";
}

bool	AForm::checkSignPrivs(Bureaucrat const &executor) const
{
	if (executor.getGrade() > m_sign_req)
		throw GradeTooLowException();
	return true;
}

bool	AForm::checkExecPrivs(Bureaucrat const &executor) const
{
	if (executor.getGrade() > m_exec_req)
		throw GradeTooLowException();
	return true;
}

std::ostream& operator<<(std::ostream& str, AForm& ref)
{
	str << "AForm name: " << ref.getName() << std::endl;
	str << "AForm signage status: " << ref.getSignage() << std::endl;
	str << "AForm signage requirement: " << ref.getSignReq() << std::endl;
	str << "AForm execution requirement: " << ref.getExecReq() << std::endl;
	return str;
}

