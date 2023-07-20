#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
// class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
		void informing(std::string const &target) const;
};
