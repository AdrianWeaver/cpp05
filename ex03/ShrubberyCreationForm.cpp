/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:40:34 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 14:15:30 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyForm", 145, 137), _target("unspecified target")
{
	std::cout << "Default ShrubberyCreationForm constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Default ShrubberyCreationForm destructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& source) : AForm("ShrubberyForm", 145, 137), _target("unspecified target")
{
	std::cout << "Copy ShrubberyCreationForm constructor" << std::endl;
	*this = source;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 145, 137), _target(target)
{
	std::cout << "Nominative ShrubberyCreationForm constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << "Explicit ShrubberyCreationForm constructor" << std::endl;
	return ;
}

void	ShrubberyCreationForm::action(Bureaucrat const& executor) const
{
	std::ofstream	outfile;
	std::string		filename;

	filename = this->_target + ("_shrubbery");
	std::cout << executor.getName() << " planted a tree in "
		<< this->_target << std::endl;
	outfile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	outfile << std::endl
			<< "            ~.%,  .*`-" << std::endl
			<< "          &&& &&  & &&" << std::endl
			<< "      && &\\/&\\|& ()|/ @, && " << std::endl
			<< "      &\\/(/&/&||/& /_/)_&/_& " << std::endl
			<< "   &() &\\/&|()|/&\\/ '%\" & () " << std::endl
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& && " << std::endl
			<< "&&   && & &| &| /& & % ()& /&& " << std::endl
			<< " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl
			<< "     &&     \\||| " << std::endl
			<< "             ||| " << std::endl
			<< "             ||| " << std::endl
			<< "             ||| " << std::endl
			<< "       , -=-~  .-^- _ " << std::endl
			<< "              `; " << std::endl;
	outfile.close();
}
