/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:20:17 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/01 15:16:33 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& source);
		RobotomyRequestForm & operator=(RobotomyRequestForm const& rhs);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(std::string target);

		// Functions
		void		action(Bureaucrat const& executor) const;
	protected:
	private:
		const std::string _target;
};

#endif
