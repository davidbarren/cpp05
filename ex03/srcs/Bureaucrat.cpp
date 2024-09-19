/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:04:36 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 14:39:14 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream& operator<<(std::ostream& str, Bureaucrat& ref)
{
	str << ref.getName() << ", bureaucrat grade " << +ref.getGrade();
	return str;
}

Bureaucrat::Bureaucrat(): m_name("loser"), m_grade(69)
{
};

Bureaucrat::Bureaucrat(const std::string &name, int32_t grade) : m_name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	m_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade)
{
};

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		m_grade = other.m_grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return m_name;
}

int32_t Bureaucrat::getGrade() const
{
	return m_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < 1)
		throw GradeTooHighException();
	m_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > 150)
		throw GradeTooLowException();
	m_grade += 1;
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "This grade is too low!";
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "This grade is too high!";
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.checkSignPrivs(*this);
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << m_name << " couldnt sign " << form.getName();
		std::cout << " because of a skill issue (grade too low)" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{	
		form.execute(*this);
		std::cout << m_name << " has executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << m_name << " failed to execute " << form.getName();
		std::cout << " because of exception: " << e.what() << std::endl;
	}
}
