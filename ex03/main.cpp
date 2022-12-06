/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:37:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/06 16:41:21 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm	*immunity = NULL;
	AForm	*wesh = NULL;
	AForm	*adventofcode = NULL;
	std::cout << "Trying to execute a form that has not been signed:" << std::endl;
	{
		try
		{
			Bureaucrat			papa("Daddy", 10);
			Intern				stagiaire;
			wesh = stagiaire.makeForm("shrubbery creation", "jardin");
			papa.executeForm(*wesh);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete wesh;
		wesh = NULL;
	}
	std::cout << std::endl << "Trying to execute a signed form:" << std::endl;
	{
		try
		{
			Bureaucrat			papa("Daddy", 10);
			Intern				stagiaire;
			wesh = stagiaire.makeForm("shrubbery creation", "jardin");
			(*wesh).beSigned(papa);
			papa.executeForm(*wesh);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete wesh;
		wesh = NULL;
	}
	std::cout << std::endl << "Trying to execute an unsigned RobotomyForm:" << std::endl;
	{
		try
		{
			Bureaucrat				afaure("Auguste", 10);
			Bureaucrat				aweaver("aweaver", 42);
			Intern					stagiaire;
			adventofcode = stagiaire.makeForm("robotomy request", "aweaver");
			aweaver.executeForm(*adventofcode);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete adventofcode;
		adventofcode = NULL;
	}
	std::cout << std::endl << "Trying to execute a signed RobotomyForm:" << std::endl;
	{
		try
		{
			Bureaucrat				afaure("Auguste", 10);
			Bureaucrat				aweaver("aweaver", 42);
			Intern					stagiaire;
			adventofcode = stagiaire.makeForm("robotomy request", "aweaver");
			(*adventofcode).beSigned(afaure);
			aweaver.executeForm(*adventofcode);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete adventofcode;
		adventofcode = NULL;
	}
	std::cout << std::endl << "Trying to execute a signed PresidentialPardon with a low grade:" << std::endl;
	{
		try
		{
			Bureaucrat				calamity("calamity the almighty", 1);
			Bureaucrat				bsavinel("bsavinel the weak", 150);
			Intern					stagiaire;
			immunity = stagiaire.makeForm("presidential pardon", "aweaver");
			(*immunity).beSigned(calamity);
			bsavinel.executeForm(*immunity);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete immunity;
		immunity = NULL;
	}
	std::cout << std::endl << "Trying to execute a signed PresidentialPardon with a proper grade:" << std::endl;
	{
		try
		{
			Bureaucrat				calamity("calamity the almighty", 1);
			Intern					stagiaire;
			immunity = stagiaire.makeForm("presidential pardon", "aweaver");
			(*immunity).beSigned(calamity);
			calamity.executeForm(*immunity);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught: " << e.what() << std::endl;
		}
		delete immunity;
		immunity = NULL;
	}
	std::cout << std::endl << "Tryin to create an invalid form:" << std::endl;
	{
		try
		{
			Bureaucrat				calamity("calamity the almighty", 1);
			Intern					stagiaire;
			immunity = stagiaire.makeForm("prepare the codingame fall challenge", "aweaver");
			(*immunity).beSigned(calamity);
			calamity.executeForm(*immunity);
		}
		catch (std::bad_alloc &e)
		{
			std::cout << "allocation error: " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught" << e.what() << std::endl;
		}
			delete immunity;
			immunity = NULL;
	}
	return (0);
}
