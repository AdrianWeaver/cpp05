/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:37:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/11/30 14:19:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat toto("Toto", 150);
		Bureaucrat dumb("Krolo", 151);
		std::cout << toto << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat zaza("Zaza", 1);
		std::cout << zaza << std::endl;
		zaza.increaseGrade();
		std::cout << zaza << std::endl;
		Bureaucrat dumb("Krolo", -1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat boris("Boris", 42);
		// get ready for big promotion
		for (int i = 0; i < 200; i--)
		{
			std::cout << boris << std::endl;
			boris.increaseGrade();
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught exception: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught exception: " << e.what();
	}
	std::cout << "heh" << std::endl;
	return (0);
}
