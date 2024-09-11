/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:45 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/11 14:41:18 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "Forms and shit" << std::endl;
	AForm *shrub = new ShrubberyCreationForm("dir");
	std::cout << *shrub << std::endl;
	Bureaucrat chad;

	 
	std::cout << chad << std::endl;
	shrub->beSigned(chad);
	shrub->execute(chad);
	std::cout << *shrub << std::endl;
}
