#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "\033[32mTest valid constructions\033[0m" << std::endl << std::endl;

    try 
	{
        Bureaucrat bureaucrat("John", 1);
		bureaucrat.decrement();
        std::cout << bureaucrat << std::endl;
    } 
	catch (const Bureaucrat::GradeTooHighException& ex) 
	{
        std::cout << "Caught GradeTooHighException: " << ex.what() << std::endl;
    } 
	catch (const Bureaucrat::GradeTooLowException& ex) 
	{
        std::cout << "Caught GradeTooLowException: " << ex.what() << std::endl;
    }

	std::cout << "\033[32mTest invalid constructions\033[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat invalidBureaucrat("Jane", 160);
	}
	catch (const Bureaucrat::GradeTooHighException& ex) 
	{
        std::cout << "Caught GradeTooHighException: " << ex.what() << std::endl;
    } 
	catch (const Bureaucrat::GradeTooLowException& ex) 
	{
        std::cout << "Caught GradeTooLowException: " << ex.what() << std::endl;
    }

	std::cout << "\033[32mTest over incremention\033[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat Tom("Tom", 1);
		Tom.increment();
	}
	catch (const Bureaucrat::GradeTooHighException& ex) 
	{
        std::cout << "Caught GradeTooHighException: " << ex.what() << std::endl;
    } 
	catch (const Bureaucrat::GradeTooLowException& ex) 
	{
        std::cout << "Caught GradeTooLowException: " << ex.what() << std::endl;
    }
    return 0;
}