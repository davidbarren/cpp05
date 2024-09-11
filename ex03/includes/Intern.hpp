/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:55:02 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/11 14:59:04 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other) = delete;
		Intern& operator=(const Intern& other) = delete;
		~Intern();
		AForm* makeForm(std::string formname, std::string target);

};
#endif
