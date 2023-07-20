#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <cctype>

class Intern
{
	private:
		AForm *createPresidentialPardonForm(std::string const &target);	
		AForm *createRobotomyRequestForm(std::string const &target);
		AForm *createShrubberyCreationForm(std::string const &target);

	public:

		Intern();
		Intern(Intern const &);
		Intern &operator=(Intern const &);
		virtual ~Intern();

		class CannotCreateFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		AForm *makeForm(std::string const &name, std::string const &target);

};