/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/11/30 18:31:58 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		~Form(void);
		Form(Form const& source);
		Form(std::string name, int gradeRequired, int gradeRequiredForExecution);
		Form & operator=(Form const& rhs);

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
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeRequired;
		const int			_gradeRequiredForExecution;
};

std::ostream & operator<<(std::ostream & flow, Form const& rhs);

#endif
