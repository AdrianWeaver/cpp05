/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:23:27 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 15:49:08 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("ShrubberyForm", 25, 5), _target("unspecified target")
{
	std::cout << "Default PresidentialPardonForm constructor" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Default PresidentialPardonForm destructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& source) : AForm("ShrubberyForm", 25, 5), _target("unspecified target")
{
	std::cout << "Copy PresidentialPardonForm constructor" << std::endl;
	*this = source;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : AForm(name, 25, 5), _target(target)
{
	std::cout << "Nominative PresidentialPardonForm constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("ShrubberyForm", 25, 5), _target(target)
{
	std::cout << "Explicit PresidentialPardonForm constructor" << std::endl;
	return ;
}

void	PresidentialPardonForm::action(Bureaucrat const& executor) const
{
	std::cout << "Thanks to " << executor.getName() << std::endl;
	std::cout << "Zapod Beeblebrox granted presidential grace to "
		<< this->_target << std::endl;
}
