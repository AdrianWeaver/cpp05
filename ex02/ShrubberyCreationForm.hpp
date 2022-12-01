/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:40:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 13:42:04 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors & Destructors
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& source);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const& rhs);
		ShrubberyCreationForm(std::string name, std::string target);
		ShrubberyCreationForm(std::string target);

		// Functions
		void	action(Bureaucrat const& executor) const;
	protected:
	private:
		// Variable
		const std::string _target;
};

#endif
