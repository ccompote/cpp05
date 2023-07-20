#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	// std::cout << "Default constructor of PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "Default constructor of PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Destructor of PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm) : AForm("PresidentialPardonForm", 25, 5), _target(PresidentialPardonForm._target)
{
	// std::cout << "Copy constructor of PresidentialPardonForm is called" << std::endl;
	*this = PresidentialPardonForm;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &PresidentialPardonForm)
{
	// std::cout << "Copy assignment operator of PresidentialPardonForm is called" << std::endl;
	if (this == &PresidentialPardonForm)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getGradeExecute() && isSigned())
		informing(_target);
	else
		throw AForm::GradeTooLowException();
}

void PresidentialPardonForm::informing(std::string const &target) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}