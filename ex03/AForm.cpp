/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 11:38:25 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("unkown"), _signed(0), _gradeRequired(150), _gradeRequiredForExecution(150)
{
	std::cout << "Default AForm constructor" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "Default AForm destructor" << std::endl;
	return ;
}

AForm::AForm(AForm const& source) : _name(source.getName()),
	_signed(source.getSigned()),
	_gradeRequired(source.getGradeRequired()),
	_gradeRequiredForExecution(source.getGradeRequiredToExe())
{
	if (_gradeRequired < 1 || _gradeRequiredForExecution < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeRequired > 150 || _gradeRequiredForExecution > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Copy AForm Constructor" << std::endl;
	*this = source;
	return ;
}

AForm::AForm(std::string name, int gradeRequired, int gradeRequiredForExecution) :
				_name(name),
				_signed(0),
				_gradeRequired(gradeRequired),
				_gradeRequiredForExecution(gradeRequiredForExecution)
{
	if (_gradeRequired < 1 || _gradeRequiredForExecution < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeRequired > 150 || _gradeRequiredForExecution > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Complete AForm Constructor" << std::endl;
}

AForm & AForm::operator=(AForm const& rhs)
{
	std::cout << "Assignment Operator" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream& flow, AForm const& rhs)
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

std::string const& AForm::getName(void) const
{
	return (this->_name);
}

const bool& AForm::getSigned(void) const
{
	return (this->_signed);
}

const int& AForm::getGradeRequired(void) const
{
	return (this->_gradeRequired);
}

const int& AForm::getGradeRequiredToExe(void) const
{
	return (this->_gradeRequiredForExecution);
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

void	AForm::beSigned(Bureaucrat const& admin)
{
	if (admin.getGrade() <= this->_gradeRequired)
	{
		this->_signed = 1;
	}
	else
		throw AForm::GradeTooLowException();
	admin.signAForm(*this);
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() <= this->_gradeRequiredForExecution)
	{
		if (this->_signed == 0)
			throw AForm::FormNotSignedException();
		this->action(executor);
		return ;
	}
	else
		throw AForm::GradeTooLowException();
}

void	AForm::action(Bureaucrat const& executor) const
{
	std::cout << "Default AForm action called by " << executor.getName() << std::endl;
}
