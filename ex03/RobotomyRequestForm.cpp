#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	// std::cout << "Default constructor of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "Default constructor of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Destructor of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm) : AForm("RobotomyRequestForm", 72, 45), _target(RobotomyRequestForm._target)
{
	// std::cout << "Copy constructor of RobotomyRequestForm is called" << std::endl;
	*this = RobotomyRequestForm;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &RobotomyRequestForm)
{
	// std::cout << "Copy assignment operator of RobotomyRequestForm is called" << std::endl;
	if (this == &RobotomyRequestForm)
		return (*this);
	return (*this);
}

static int success_robotomize = 0;

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!isSigned())
		throw AForm::FormUnsignedException();
	else
	{
		std::cout << "bzzzzzzzzzzzzzzzzzzzzz!" << std::endl;
		if (success_robotomize++ % 2)
			std::cout << _target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;
	}

}
