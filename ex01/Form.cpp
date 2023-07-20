#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _grade_sign(75), _grade_execute(75)
{
	// std::cout << "Default constructor of Form is called" << std::endl;
}

Form::Form(const std::string &name, unsigned int grade_sign, unsigned int grade_execute) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	// std::cout << "Constructor with type of Form is called" << std::endl;
	if (_grade_sign < 1 || _grade_execute < 1)
		throw Form::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	// std::cout << "Destructor of Form is called" << std::endl;
}

Form::Form(Form const &Form) : _name(Form._name), _grade_sign(Form._grade_sign), _grade_execute(Form._grade_execute)
{
	// std::cout << "Copy constructor of Form is called" << std::endl;
	*this = Form;
}

Form &Form::operator=(Form const &Form)
{
	// std::cout << "Copy assignment operator of Form is called" << std::endl;
	if (this == &Form)
		return (*this);
	_signed = Form._signed;
	return (*this);
}

std::string Form::getName(void) const
{
	return (_name);
}

int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int Form::getGradeExecute(void) const
{
	return (_grade_execute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Form::beSigned(Bureaucrat *clerk)
{
	if (clerk->getGrade() < 1)
		throw Form::GradeTooHighException();
	else if (clerk->getGrade() > _grade_sign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form const &obj)
{
	os << obj.getName() << " Form has  " << obj.getGradeSign() << " grade to be signed and " << obj.getGradeExecute() << " grade to be executed.";
	return (os);
}

std::ostream &operator<<(std::ostream &os, Form const *obj)
{
	os << obj->getName() << " Form has  " << obj->getGradeSign() << " grade to be signed and " << obj->getGradeExecute() << " grade to be executed.";
	return (os);
}