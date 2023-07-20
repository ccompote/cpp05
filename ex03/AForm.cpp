#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _grade_sign(75), _grade_execute(75)
{
	// std::cout << "Default constructor of AForm is called" << std::endl;
}

AForm::AForm(const std::string &name, unsigned int grade_sign, unsigned int grade_execute) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	// std::cout << "Constructor with type of AForm is called" << std::endl;
	if (_grade_sign < 1 || _grade_execute < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	// std::cout << "Destructor of AForm is called" << std::endl;
}

AForm::AForm(AForm const &AForm) : _name(AForm._name), _signed(false), _grade_sign(AForm._grade_sign), _grade_execute(AForm._grade_execute)
{
	// std::cout << "Copy constructor of AForm is called" << std::endl;
	*this = AForm;
}

AForm &AForm::operator=(AForm const &AForm)
{
	// std::cout << "Copy assignment operator of AForm is called" << std::endl;
	if (this == &AForm)
		return (*this);
	return (*this);
}

std::string AForm::getName(void) const
{
	return (_name);
}

unsigned int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

bool AForm::isSigned(void) const
{
	return (_signed);
}

unsigned int AForm::getGradeExecute(void) const
{
	return (_grade_execute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormUnsignedException::what() const throw()
{
	return ("Form must be signed before executing.");
}

void AForm::beSigned(Bureaucrat *clerk)
{
	if (clerk->getGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (clerk->getGrade() > _grade_sign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

std::ostream &operator<<(std::ostream &os, AForm const &obj)
{
	os << obj.getName() << " AForm has  " << obj.getGradeSign() << " grade to be signed and " << obj.getGradeExecute() << " grade to be executed.";
	return (os);
}

std::ostream &operator<<(std::ostream &os, AForm const *obj)
{
	os << obj->getName() << " AForm has  " << obj->getGradeSign() << " grade to be signed and " << obj->getGradeExecute() << " grade to be executed.";
	return (os);
}