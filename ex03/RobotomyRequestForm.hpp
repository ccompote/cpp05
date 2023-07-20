#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
// class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
		void robotomize(std::string &target);

};