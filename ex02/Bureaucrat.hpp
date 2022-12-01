/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:57:53 by aweaver           #+#    #+#             */
/*   Updated: 2022/11/30 18:46:09 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;
class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& source);
		Bureaucrat & operator=(Bureaucrat const& rhs);

		std::string const&	getName(void) const;
		int const&			getGrade(void) const;
		void				increaseGrade(void);
		void				decreaseGrade(void);
		void				signForm(Form & toSign) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
	protected:
	private:
		std::string _name;
		int			_grade;

};

std::ostream&	operator<<(std::ostream & flow, Bureaucrat const& rhs);

# include "Form.hpp"
#endif
