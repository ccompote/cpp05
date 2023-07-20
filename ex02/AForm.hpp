#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _grade_sign;
		const unsigned int _grade_execute;

	public:

		AForm();
		AForm(const std::string &name, unsigned int grade_sign, unsigned int grade_execute);
		AForm(AForm const &);
		AForm &operator=(AForm const &);
		virtual ~AForm();

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
		class FormUnsignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string getName(void) const;
		unsigned int getGradeSign(void) const;
		unsigned int getGradeExecute(void) const;
		void beSigned(Bureaucrat *clerk);
		bool isSigned(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

		std::ostream &operator<<(std::ostream &os, AForm const &);
		std::ostream &operator<<(std::ostream &os, AForm const *);
