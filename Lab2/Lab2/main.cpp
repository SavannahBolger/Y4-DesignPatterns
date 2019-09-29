#include <iostream>
#include <SFML/Graphics.hpp>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command() {}
};

class MacroCommand : public Command
{
public:
	MacroCommand() {}
	virtual ~MacroCommand() {}
	virtual void add(int x) { if(z<x) z++; };
	virtual void undo(int x) { if (z > 0)z--; };
	virtual void execute(int x) {
		for(int i = 0; i < z ;i++)
		{
			system("cls");
			std::cout << output[i];
		}
	};
	std::vector<std::string> command() { return output; };
private:
	std::vector<std::string> output;
	int z;
};

class InputHandler
{
public:
	int x = -1;
	void handleInput(std::vector<std::string> output)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			output.push_back("q");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			output.push_back("w");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			output.push_back("e");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			output.push_back("r");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			output.push_back("t");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			output.push_back("y");
			x++;
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			button->add(x);
			button->execute(x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			button->undo(x);
			button->execute(x);
		}
	};

private:
	MacroCommand* button;
};

int main()
{
	InputHandler input;
	MacroCommand* button;
	input.handleInput(button->command());

	system("pause");
	return 0;
}