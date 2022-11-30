/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:57:54 by aweaver           #+#    #+#             */
/*   Updated: 2022/11/30 14:18:50 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
{
	this->_name = "unknown";
	this->_grade = 150;
	std::cout << "Default bureaucrat constructor." << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default bureaucrat destructor." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Common bureaucrat constructor." << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	this->_name = name;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const& source)
{
	*this = source;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (&rhs != this)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string const& Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const& Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

std::ostream&	operator<<(std::ostream & flow, Bureaucrat const& rhs)
{
	flow << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (flow);
}
