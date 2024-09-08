/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:57:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/08 18:13:08 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		void	execute(Bureaucrat const& executor) const;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
	private:
		std::string m_target;
};
#endif
