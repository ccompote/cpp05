#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	// std::cout << "Default constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "Default constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Destructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm) : AForm("ShrubberyCreationForm", 145, 137), _target(ShrubberyCreationForm._target)
{
	// std::cout << "Copy constructor of ShrubberyCreationForm is called" << std::endl;
	*this = ShrubberyCreationForm;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ShrubberyCreationForm)
{
	// std::cout << "Copy assignment operator of ShrubberyCreationForm is called" << std::endl;
	if (this == &ShrubberyCreationForm)
		return (*this);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	else if (!isSigned())
		throw AForm::FormUnsignedException();
	else
		createFile(_target);
}


void ShrubberyCreationForm::createFile(std::string const &target) const
{
	std::string filename = target + "_shrubbery";
	std::ofstream outFile(filename.c_str());
	if (!outFile) 
	{
		std::cout << "Error opening the file." << std::endl;
	}

	outFile << "          /\\  " << std::endl;
	outFile << "         /__\\ " << std::endl;
	outFile << "        /    \\" << std::endl;
	outFile << "       /______\\" << std::endl;
	outFile << "      /\\      /\\" << std::endl;
	outFile << "     /__\\    /__\\" << std::endl;
	outFile << "    /    \\  /    \\" << std::endl;
	outFile << "   /______\\/______\\" << std::endl;
	outFile << "          ||" << std::endl;
	outFile << "          ||" << std::endl;
	outFile << "          ||" << std::endl;

	outFile.close();
}