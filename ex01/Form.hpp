#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _grade_sign;
		const unsigned int _grade_execute;

	public:

		Form();
		Form(const std::string &name, unsigned int grade_sign, unsigned int grade_execute);
		Form(Form const &);
		Form &operator=(Form const &);
		virtual ~Form();

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
		int getGradeSign(void) const;
		int getGradeExecute(void) const;
		void beSigned(Bureaucrat *clerk);
};

		std::ostream &operator<<(std::ostream &os, Form const &);
		std::ostream &operator<<(std::ostream &os, Form const *);

#endif