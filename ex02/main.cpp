/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:37:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 16:19:06 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "Trying to execute a form that has not been signed:" << std::endl;
	{
		try
		{
			Bureaucrat			papa("Daddy", 10);
			ShrubberyCreationForm wesh("jardin");
			papa.executeForm(wesh);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Trying to execute a signed form:" << std::endl;
	{
		try
		{
			Bureaucrat			papa("Daddy", 10);
			ShrubberyCreationForm wesh("jardin");
			wesh.beSigned(papa);
			papa.executeForm(wesh);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Trying to execute an unsigned RobotomyForm:" << std::endl;
	{
		try
		{
			Bureaucrat				afaure("Auguste", 10);
			Bureaucrat				aweaver("aweaver", 42);
			RobotomyRequestForm		adventofcode("adventofcode", "aweaver");
			aweaver.executeForm(adventofcode);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Trying to execute a signed RobotomyForm:" << std::endl;
	{
		try
		{
			Bureaucrat				afaure("Auguste", 10);
			Bureaucrat				aweaver("aweaver", 42);
			RobotomyRequestForm		adventofcode("adventofcode", "aweaver");
			adventofcode.beSigned(afaure);
			aweaver.executeForm(adventofcode);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Trying to execute a signed PresidentialPardon with a low grade:" << std::endl;
	{
		try
		{
			Bureaucrat				calamity("calamity the almighty", 1);
			Bureaucrat				bsavinel("bsavinel the weak", 150);
			PresidentialPardonForm	immunity("cookie", "aweaver");
			immunity.beSigned(calamity);
			bsavinel.executeForm(immunity);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Trying to execute a signed PresidentialPardon with a proper grade:" << std::endl;
	{
		try
		{
			Bureaucrat				calamity("calamity the almighty", 1);
			PresidentialPardonForm	immunity("cookie", "aweaver");
			immunity.beSigned(calamity);
			calamity.executeForm(immunity);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	return (0);
}
