/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/11/30 18:50:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("unkown"), _signed(0), _gradeRequired(150), _gradeRequiredForExecution(150)
{
	std::cout << "Default Form constructor" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Default Form destructor" << std::endl;
	return ;
}

Form::Form(Form const& source) : _name(source.getName()),
	_signed(source.getSigned()),
	_gradeRequired(source.getGradeRequired()),
	_gradeRequiredForExecution(source.getGradeRequiredToExe())
{
	if (_gradeRequired < 1 || _gradeRequiredForExecution < 1)
		throw Form::GradeTooHighException();
	else if (_gradeRequired > 150 || _gradeRequiredForExecution > 150)
		throw Form::GradeTooLowException();
	std::cout << "Copy Form Constructor" << std::endl;
	*this = source;
	return ;
}

Form::Form(std::string name, int gradeRequired, int gradeRequiredForExecution) :
				_name(name),
				_signed(0),
				_gradeRequired(gradeRequired),
				_gradeRequiredForExecution(gradeRequiredForExecution)
{
	if (_gradeRequired < 1 || _gradeRequiredForExecution < 1)
		throw Form::GradeTooHighException();
	else if (_gradeRequired > 150 || _gradeRequiredForExecution > 150)
		throw Form::GradeTooLowException();
	std::cout << "Complete Form Constructor" << std::endl;
}

Form & Form::operator=(Form const& rhs)
{
	std::cout << "Assignment Operator" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream& flow, Form const& rhs)
{
	flow << rhs.getName() << ", is";
	if (rhs.getSigned() == 0)
		flow << " unsigned, grade required: ";
	else
		flow << " signed, grade required: ";
	flow << rhs.getGradeRequired() << ", grade required for execution: ";
	flow << rhs.getGradeRequiredToExe() << std::endl;
	return (flow);
}

std::string const& Form::getName(void) const
{
	return (this->_name);
}

const bool& Form::getSigned(void) const
{
	return (this->_signed);
}

const int& Form::getGradeRequired(void) const
{
	return (this->_gradeRequired);
}

const int& Form::getGradeRequiredToExe(void) const
{
	return (this->_gradeRequiredForExecution);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

void	Form::beSigned(Bureaucrat const& admin)
{
	if (admin.getGrade() <= this->_gradeRequired)
	{
		this->_signed = 1;
	}
	else
		throw Form::GradeTooLowException();
	admin.signForm(*this);
}
