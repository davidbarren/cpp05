/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:32:54 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/19 13:49:03 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string m_name;
		bool			m_is_signed;
		const int32_t	m_sign_req;
		const int32_t	m_exec_req;
	public:
		Form();
		Form(std::string name, int32_t signreq, int32_t execreq);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();
		const std::string getName() const;
		bool			getSignage() const;
		int32_t	getSignReq() const;
		int32_t getExecReq() const;
		void	beSigned(Bureaucrat signer);
		bool	checkSignPrivs(Bureaucrat const &executor) const;
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
std::ostream& operator<<(std::ostream& str, Form& ref);

#endif
