#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(1)
{
	// std::cout << "Default constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name)
{
	// std::cout << "Constructor with type of Bureaucrat is called" << std::endl;

	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Construction of " << _name << " failed because " << e.what() << ". The grade was set to 1." << std::endl;
		setGrade(1);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Construction of " << _name << " failed because " << e.what() << ". The grade was set to 1." << std::endl;
		setGrade(150);
	}
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor of Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat)
{
	// std::cout << "Copy constructor of Bureaucrat is called" << std::endl;
	*this = Bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &Bureaucrat)
{
	// std::cout << "Copy assignment operator of Bureaucrat is called" << std::endl;
	_grade = Bureaucrat._grade;
	return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment(void)
{
	if ((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrement(void)
{
	if ((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooHighException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout <<_name << " couldn't execute the command because " << e.what() << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const *obj)
{
	os << obj->getName() << ", bureaucrat grade " << obj->getGrade() << ".";
	return (os);
}