/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 10:51:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm & operator=(AForm const& rhs);

		void				beSigned(Bureaucrat const& adm);
		std::string const&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getGradeRequired(void) const;
		const int&			getGradeRequiredToExe(void) const;

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
		AForm(void);
		~AForm(void);
		AForm(AForm const& source);
		AForm(std::string name, int gradeRequired, int gradeRequiredForExecution);
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeRequired;
		const int			_gradeRequiredForExecution;
};

std::ostream & operator<<(std::ostream & flow, AForm const& rhs);

#endif
