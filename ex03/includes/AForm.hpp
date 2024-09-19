/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:32:54 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 12:35:25 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string m_name;
		bool			m_is_signed;
		const int32_t	m_sign_req;
		const int32_t	m_exec_req;
	public:
		AForm();
		AForm(std::string name, int32_t signreq, int32_t execreq);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		const std::string getName() const;
		bool			getSignage() const;
		int32_t	getSignReq() const;
		int32_t getExecReq() const;
		void	beSigned(Bureaucrat signer);
		bool	checkSignPrivs(Bureaucrat const &executor) const;
		bool	checkExecPrivs(Bureaucrat const &executor) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception
		{
		const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
		const char* what() const noexcept;
		};
		class FormNotSignedException : public std::exception
		{
		const char* what() const noexcept;
		};
};
std::ostream& operator<<(std::ostream& str, AForm& ref);

#endif
