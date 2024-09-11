/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:42:27 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/09 13:31:06 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): m_name("default form"), m_is_signed(false),
	m_sign_req(42), m_exec_req(42)
{
}

Form::Form(std::string name, int32_t signreq, int32_t execreq): m_name(name),
	m_is_signed(false), m_sign_req(signreq), m_exec_req(execreq)
{
	if (m_sign_req > 150 || m_exec_req > 150)
		throw GradeTooLowException();
	if (m_sign_req < 0 || m_exec_req < 0)
		throw GradeTooHighException();
}

Form::Form(const Form& other):m_name(other.m_name), 
	m_is_signed(other.m_is_signed), m_sign_req(other.m_sign_req), m_exec_req(other.m_exec_req)
{
}

Form& Form::operator=(const Form& other)
{
	m_is_signed = other.m_is_signed;
		return (*this);
}

Form::~Form(){}

const std::string Form::getName() const
{
	return m_name;
}
bool	Form::getSignage() const
{
	return m_is_signed;
}

int32_t Form::getSignReq() const
{
	return m_sign_req;
}

int32_t Form::getExecReq() const
{
	return m_exec_req;
}

void	Form::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() <= m_sign_req)
		m_is_signed = true;
	else
		throw GradeTooLowException();

}

const char*	Form::GradeTooHighException::what() const noexcept
{
	return "Forms grade is too high!";
}

const char*	Form::GradeTooLowException::what() const noexcept
{
	return "Form's grade is too low!";
}

std::ostream& operator<<(std::ostream& str, Form& ref)
{
	str << "Form name: " << ref.getName() << std::endl;
	str << "Form signage status: " << ref.getSignage() << std::endl;
	str << "Form signage requirement: " << ref.getSignReq() << std::endl;
	str << "Form execution requirement: " << ref.getExecReq() << std::endl;
	return str;
}
