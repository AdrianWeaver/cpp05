/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:29:52 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 15:21:37 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("unspecified target")
{
	std::cout << "Default RobotomyRequestForm constructor" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Default RobotomyRequestForm destructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& source) : AForm("Robotomy request", 72, 45), _target("unspecified target")
{
	std::cout << "Copy RobotomyRequestForm constructor" << std::endl;
	*this = source;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 72, 45), _target(target)
{
	std::cout << "Nominative RobotomyRequestForm constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", 72, 45), _target(target)
{
	std::cout << "Explicit RobotomyRequestForm constructor" << std::endl;
	return ;
}

void	RobotomyRequestForm::action(Bureaucrat const& executor) const
{
	std::cout << executor.getName() << " picks up the drill." << std::endl;
	std::cout << "ZZZzzzziiiooooiiiuuuuuuurrrrg" << std::endl << this->_target;
	if (rand() % 2 == 0)
		std::cout << " has been robotomized!" << std::endl;
	else
		std::cout << " could not be robotomized." << std::endl;
}
