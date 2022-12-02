/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:29:13 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 11:32:58 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <exception>

class AForm;

class Intern
{
	public:
		// Constructors & Destructors
		Intern(void);
		~Intern(void);
		Intern(Intern const& source);
		Intern & operator=(Intern const& rhs);

		// Functions
		AForm*		makeForm(std::string formName, std::string formTarget);

		class WrongFormException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
	protected:
	private:
		AForm* filter(std::string formName, std::string formTarget);

};

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

#endif
