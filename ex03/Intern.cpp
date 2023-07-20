#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Default constructor of Intern is called" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Destructor of Intern is called" << std::endl;
}

Intern::Intern(Intern const &Intern)
{
	// std::cout << "Copy constructor of Intern is called" << std::endl;
	*this = Intern;
}

Intern &Intern::operator=(Intern const &Intern)
{
	// std::cout << "Copy assignment operator of Intern is called" << std::endl;
	if (this == &Intern)
		return (*this);
	return (*this);
}

const char *Intern::CannotCreateFormException::what() const throw()
{
	return ("Such form doesn't exist");
}

AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string str[3];
	str[0] = "shrubbery creation";
	str[1] = "robotomy request";
	str[2] = "presidential pardon";
	std::string newname = name;
	AForm *(Intern::*functions[])(std::string const &target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	for (std::size_t i = 0; i < newname.length(); i++)
	{
        if (std::isupper(newname[i])) {
            newname[i] = std::tolower(newname[i]);
        }
    }
	for (int i = 0; i < 3; i++)
	{
		if (newname == str[i])
			return((this->*functions[i])(target));
	}
	throw CannotCreateFormException();
}