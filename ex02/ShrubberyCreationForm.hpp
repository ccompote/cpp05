#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;
// class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);
		virtual ~ShrubberyCreationForm();

		void createFile(std::string const &target) const;
		void execute(Bureaucrat const & executor) const;
};
