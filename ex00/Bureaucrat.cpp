#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(1)
{
	// std::cout << "Default constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name)
{
	// std::cout << "Constructor with type of Bureaucrat is called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
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
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrement(void)
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	else
		_grade++;
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