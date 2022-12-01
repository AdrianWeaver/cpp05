/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:37:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 14:19:08 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	}
	std::cout << std::endl << "Trying to execute a signed form:" << std::endl;
	{
		try
		{
			Bureaucrat			papa("Daddy", 10);
			ShrubberyCreationForm wesh("jardin");
			std::cout << "grade exe: " << wesh.getGradeRequiredToExe()
				<< "grade sign: " << wesh.getGradeRequired() << std::endl;
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
	}
	{
	}
	return (0);
}
