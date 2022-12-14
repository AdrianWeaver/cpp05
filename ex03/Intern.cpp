/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:29:14 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 11:52:14 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern(void)
{
	std::cout << "Default victim constructor." << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Default victim destructor." << std::endl;
	return ;
}

Intern::Intern(Intern const& source)
{
	*this = source;
	return ;
}

Intern & Intern::operator=(Intern const& rhs)
{
	if (&rhs != this)
	{
	}
	return (*this);
}

const char* Intern::WrongFormException::what(void) const throw()
{
	return ("This form name does not exist!");
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	return (this->filter(formName, formTarget));
}


AForm*	Intern::filter(std::string formName, std::string formTarget)
{
	int	i;
	std::string category[] = { "robotomy request", "shrubbery creation", "presidential pardon" };
	AForm	*ret;
	for (i = 0; i < 3; i++)
		if (formName == category[i])
			break;
	switch (i)
	{
		case 0:
			ret = new RobotomyRequestForm(formTarget);
			std::cout << "Intern creates " << formName << "." << std::endl;
			break;
		case 1:
			ret = new ShrubberyCreationForm(formTarget);
			std::cout << "Intern creates " << formName << "." << std::endl;
			break ;
		case 2:
			ret = new PresidentialPardonForm(formTarget);
			std::cout << "Intern creates " << formName << "." << std::endl;
			break ;
		default:
			throw Intern::WrongFormException();
	}
	return (ret);
}
