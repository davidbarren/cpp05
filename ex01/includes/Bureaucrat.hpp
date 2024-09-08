/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:54:33 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 16:57:30 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
class Form;
class Bureaucrat
{
	private:
		const std::string m_name;
		int32_t m_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string &name, int32_t grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);
		const std::string getName() const;
		int32_t getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);
		class GradeTooHighException : public std::exception
		{
			const char*	what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			const char*	what() const noexcept;
		};
};
std::ostream& operator<<(std::ostream& str, Bureaucrat& ref);


#endif
