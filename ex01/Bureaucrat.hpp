#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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
		void increment(void);
		void decrement(void);
		void signForm(Form &form);

};
		std::ostream &operator<<(std::ostream &os, Bureaucrat const &);
		std::ostream &operator<<(std::ostream &os, Bureaucrat const *);
#endif