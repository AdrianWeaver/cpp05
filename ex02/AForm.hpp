/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 15:43:44 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	public:
		virtual ~AForm(void);

		// Functions
		void				beSigned(Bureaucrat const& adm);
		std::string const&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getGradeRequired(void) const;
		const int&			getGradeRequiredToExe(void) const;
		int					execute(Bureaucrat const& executor) const;
		virtual void		action(Bureaucrat const& executor) const;

		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	protected:
		// Constructors
		AForm(void);
		AForm(AForm const& source);
		AForm(std::string name, int gradeRequired, int gradeRequiredForExecution);
		AForm & operator=(AForm const& rhs);

		// Variables
		const std::string	_name;
		bool				_signed;
		const int			_gradeRequired;
		const int			_gradeRequiredForExecution;
	private:
};

std::ostream & operator<<(std::ostream & flow, AForm const& rhs);

#endif
