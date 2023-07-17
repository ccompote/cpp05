#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		
		const std::string _name;
		unsigned int _grade;

	public:

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too low");
				}
		};

		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat &operator=(Bureaucrat const &);
		virtual ~Bureaucrat();

		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void increment(void);
		void decrement(void);

};
		std::ostream &operator<<(std::ostream &os, Bureaucrat const &);
		std::ostream &operator<<(std::ostream &os, Bureaucrat const *);
#endif