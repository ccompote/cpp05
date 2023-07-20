#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	std::string str = "loch";
	Bureaucrat  *Tom = new Bureaucrat("Tom", 137);
	Bureaucrat  *Jerry = new Bureaucrat("Jerry", 138);
    Bureaucrat  *Sam = new Bureaucrat("Sam", 4);
    AForm        *Shrub = new ShrubberyCreationForm(str);
	AForm        *Shrub2 = new ShrubberyCreationForm(str);
	AForm 		*Shrub3 = new ShrubberyCreationForm();
	*Shrub3 = *Shrub;
	AForm        *Pres = new PresidentialPardonForm(str);
	AForm        *Rob = new RobotomyRequestForm(str);
    Tom->signForm(*Shrub);
    Tom->executeForm(*Shrub);
	delete Shrub;
	Tom->executeForm(*Shrub3);
	Tom->signForm(*Shrub3);
	Tom->executeForm(*Shrub3);
	Jerry->executeForm(*Shrub2);
	Sam->signForm(*Pres);
    Sam->executeForm(*Pres);
	Sam->signForm(*Rob);
    Sam->executeForm(*Rob);
	Sam->executeForm(*Rob);
	delete Tom;
	delete Jerry;
	delete Sam;
	delete Shrub2;
	delete Shrub3;
	delete Pres;
	delete Rob;
    return 0;
}