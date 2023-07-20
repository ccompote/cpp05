#include "Bureaucrat.hpp"

int main() 
{


	Bureaucrat  Tom("Tom", 50);
    Bureaucrat  Sam("Sam", 30);
    Form        application1("application1", 150, 100);
    Form        application2("application2", 20, 9);
    Form        application3("application3", 60, 80);

    Tom.signForm(application1);
    Tom.signForm(application2);
    Sam.signForm(application2);
    Sam.signForm(application3);
    return 0;
}