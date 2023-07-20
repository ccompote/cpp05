#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		
		const std::string _name;
		unsigned int _grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat &operator=(Bureaucrat const &);
		virtual ~Bureaucrat();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void setGrade(int grade);
		void increment(void);
		void decrement(void);
		void signForm(AForm &form);
		void executeForm(AForm const & form);

};
		std::ostream &operator<<(std::ostream &os, Bureaucrat const &);
		std::ostream &operator<<(std::ostream &os, Bureaucrat const *);
		