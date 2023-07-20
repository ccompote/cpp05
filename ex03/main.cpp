#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void checkleaks(void)
// {
// 	system("leaks three");
// }

int main() 
{
	// atexit(checkleaks);
	std::cout << "\033[32mTest valid file creation\033[0m" << std::endl << std::endl;
	Bureaucrat  *Tom = new Bureaucrat("Tom", 6);
	Intern someRandomIntern;
	try
	{
		AForm* ppf;
		AForm* rrf;
		AForm* scf;
		ppf = someRandomIntern.makeForm("presidential Pardon", "Bender");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
		Tom->signForm(*ppf);
    	Tom->executeForm(*ppf);
		Tom->signForm(*rrf);
    	Tom->executeForm(*rrf);
		Tom->signForm(*scf);
    	Tom->executeForm(*scf);
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch(Intern::CannotCreateFormException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[32mTest wrong file name\033[0m" << std::endl << std::endl;
	try
	{
		AForm *notrealform;
		notrealform = someRandomIntern.makeForm("weird form", "Bender");
		delete notrealform;
	}
	catch(Intern::CannotCreateFormException& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete Tom;
}