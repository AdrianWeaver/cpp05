/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:37:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 10:25:43 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		Bureaucrat	toto("Toto", 50);
		Form		poleEmploi("Pole emploi", 150, 50);
		std::cout << poleEmploi << std::endl;
		poleEmploi.beSigned(toto);
		std::cout << poleEmploi << std::endl;
	}
	{
		try
		{
			Bureaucrat	toto("Toto", 50);
			Form		poleEmploi("Pole emploi", 152, 50);
			std::cout << poleEmploi << std::endl;
			poleEmploi.beSigned(toto);
			std::cout << poleEmploi << std::endl;
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	toto("Toto", 150);
			Form		poleEmploi("Pole emploi", 1, 50);
			std::cout << poleEmploi << std::endl;
			poleEmploi.beSigned(toto);
			std::cout << poleEmploi << std::endl;
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
