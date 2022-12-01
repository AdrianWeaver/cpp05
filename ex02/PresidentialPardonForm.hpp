/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:23:26 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 15:35:53 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors & Destructors
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& source);
		PresidentialPardonForm & operator=(PresidentialPardonForm const& rhs);
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(std::string target);

		// Functions
		void	action(Bureaucrat const& executor) const;
	protected:
	private:
		// Variable
		const std::string _target;
};

#endif
