#include <iostream>
#include <SFML/Graphics.hpp>

class Command
{
public:
	Command() {}
	virtual ~Command() {}
	virtual void execute() {};
};

class InputHandler
{
public:
	InputHandler();

private:
	Command* button;
};

int main()
{
	std::string i;
	std::cin >> i;
	std::cout << i << std::endl;

	system("pause");
	return 0;
}