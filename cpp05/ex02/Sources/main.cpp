#include "UI.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test ShrubberyCreationForm" + RESET);

		//Default constructor
		ShrubberyCreationForm	Form1;
		std::cout << Form1 << std::endl;

		assert(Form1.getName() == "ShrubberyCreationForm");
		assert(Form1.getSigned() == false);
		assert(Form1.getGradeToSign() == SCDEFAULTGRADETOSIGN);
		assert(Form1.getGradeToExecute() == SCDEFAULTGRADETOEXEC);
		assert(Form1.getTarget().empty());

		//Target constructor
		ShrubberyCreationForm	Form2("test");
		std::cout << Form2 << std::endl;
		assert(Form2.getName() == "ShrubberyCreationForm");
		assert(Form2.getSigned() == false);
		assert(Form2.getGradeToSign() == SCDEFAULTGRADETOSIGN);
		assert(Form2.getGradeToExecute() == SCDEFAULTGRADETOEXEC);
		assert(Form2.getTarget() == "test");

		//Copy constructor
		ShrubberyCreationForm Form3(Form2);
		std::cout << Form3 << std::endl;
		assert(Form3.getName() == Form2.getName());
		assert(Form3.getSigned() == Form2.getSigned());
		assert(Form3.getGradeToSign() == Form2.getGradeToSign());
		assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());
		assert(Form3.getTarget() == Form2.getTarget());

		//Copy assingment operator
		ShrubberyCreationForm Form4;
		Form4 = Form2;
		std::cout << Form4 << std::endl;
		assert(Form4.getName() == Form1.getName());
		assert(Form4.getSigned() == Form1.getSigned());
		assert(Form4.getGradeToSign() == Form1.getGradeToSign());
		assert(Form4.getGradeToExecute() == Form1.getGradeToExecute());
		assert(Form4.getTarget() == Form2.getTarget());
	}
	UI::printLine("\n");
	{
		UI::printLine(RED + "Test RobotomyRequestForm" + RESET);

		//Default constructor
		RobotomyRequestForm	Form1;
		std::cout << Form1 << std::endl;

		assert(Form1.getName() == "RobotomyRequestForm");
		assert(Form1.getSigned() == false);
		assert(Form1.getGradeToSign() == RRDEFAULTGRADETOSIGN);
		assert(Form1.getGradeToExecute() == RRDEFAULTGRADETOEXEC);
		assert(Form1.getTarget().empty());

		//Target constructor
		RobotomyRequestForm	Form2("test");
		std::cout << Form2 << std::endl;
		assert(Form2.getName() == "RobotomyRequestForm");
		assert(Form2.getSigned() == false);
		assert(Form2.getGradeToSign() == RRDEFAULTGRADETOSIGN);
		assert(Form2.getGradeToExecute() == RRDEFAULTGRADETOEXEC);
		assert(Form2.getTarget() == "test");

		//Copy constructor
		RobotomyRequestForm Form3(Form2);
		std::cout << Form3 << std::endl;
		assert(Form3.getName() == Form2.getName());
		assert(Form3.getSigned() == Form2.getSigned());
		assert(Form3.getGradeToSign() == Form2.getGradeToSign());
		assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());
		assert(Form3.getTarget() == Form2.getTarget());

		//Copy assingment operator
		RobotomyRequestForm Form4;
		Form4 = Form2;
		std::cout << Form4 << std::endl;
		assert(Form4.getName() == Form1.getName());
		assert(Form4.getSigned() == Form1.getSigned());
		assert(Form4.getGradeToSign() == Form1.getGradeToSign());
		assert(Form4.getGradeToExecute() == Form1.getGradeToExecute());
		assert(Form4.getTarget() == Form2.getTarget());
	}
	UI::printLine("\n");
	{
		UI::printLine(RED + "Test PresidentialPardonForm" + RESET);

		//Default constructor
		PresidentialPardonForm	Form1;
		std::cout << Form1 << std::endl;

		assert(Form1.getName() == "PresidentialPardonForm");
		assert(Form1.getSigned() == false);
		assert(Form1.getGradeToSign() == PPDEFAULTGRADETOSIGN);
		assert(Form1.getGradeToExecute() == PPDEFAULTGRADETOEXEC);
		assert(Form1.getTarget().empty());

		//Target constructor
		PresidentialPardonForm	Form2("test");
		std::cout << Form2 << std::endl;
		assert(Form2.getName() == "PresidentialPardonForm");
		assert(Form2.getSigned() == false);
		assert(Form2.getGradeToSign() == PPDEFAULTGRADETOSIGN);
		assert(Form2.getGradeToExecute() == PPDEFAULTGRADETOEXEC);
		assert(Form2.getTarget() == "test");

		//Copy constructor
		PresidentialPardonForm Form3(Form2);
		std::cout << Form3 << std::endl;
		assert(Form3.getName() == Form2.getName());
		assert(Form3.getSigned() == Form2.getSigned());
		assert(Form3.getGradeToSign() == Form2.getGradeToSign());
		assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());
		assert(Form3.getTarget() == Form2.getTarget());

		//Copy assingment operator
		PresidentialPardonForm Form4;
		Form4 = Form2;
		std::cout << Form4 << std::endl;
		assert(Form4.getName() == Form1.getName());
		assert(Form4.getSigned() == Form1.getSigned());
		assert(Form4.getGradeToSign() == Form1.getGradeToSign());
		assert(Form4.getGradeToExecute() == Form1.getGradeToExecute());
		assert(Form4.getTarget() == Form2.getTarget());
	}
	UI::printLine("\n");
	{
		srand(time(NULL));
		UI::printLine(RED + "Test execute with signed forms and highest level Bureaucrat" + RESET);

		Bureaucrat				Bureaucrat1(1);
		ShrubberyCreationForm	Form1("test");
		RobotomyRequestForm		Form2("test2");
		PresidentialPardonForm	Form3("test3");

		Bureaucrat1.signForm(Form1);
		Bureaucrat1.signForm(Form2);
		Bureaucrat1.signForm(Form3);
		
		Form1.execute(Bureaucrat1);
		Form2.execute(Bureaucrat1);
		Form2.execute(Bureaucrat1);
		Form2.execute(Bureaucrat1);
		Form2.execute(Bureaucrat1);
		Form3.execute(Bureaucrat1);
	}
	UI::printLine("\n");
	{
		srand(time(NULL));
		UI::printLine(RED + "Test execute with unsigned form" + RESET);

		try {
			Bureaucrat				Bureaucrat1(1);
			ShrubberyCreationForm	Form1("test");

			Form1.execute(Bureaucrat1);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}
	UI::printLine("\n");
	{
		srand(time(NULL));
		UI::printLine(RED + "Test execute with a too weak Bureaucrat" + RESET);

		try {
			Bureaucrat				Bureaucrat1(SCDEFAULTGRADETOEXEC + 1);
			ShrubberyCreationForm	Form1("test");

			Bureaucrat1.signForm(Form1);
			Form1.execute(Bureaucrat1);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}
}

