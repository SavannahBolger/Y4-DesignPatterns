#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include <SFML/Graphics.hpp>

static std::vector<std::string> output;
int z = 0;
int x = 0;

class Command
{
public:
	Command() {}
	virtual ~Command() {}
	virtual void add() = 0;
	virtual void increase() = 0;
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class MacroCommand : public Command
{
public:
	MacroCommand() { };
	virtual ~MacroCommand() {}
	 void add() { if(z < x) z++; };
	 void increase() { z++; x++; };
	 void undo() { if (z > 0)z--; };
	 void execute() {
		 system("cls");

		for(int i = 0; i < z ;i++)
		{
			std::cout << output[i];
		}
	};
private:
	
};

class InputHandler
{
public:
	void handleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) == true)
		{
			output.push_back("q");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true)
		{
			output.push_back("w");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true)
		{
			output.push_back("e");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) == true)
		{
			output.push_back("r");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) == true)
		{
			output.push_back("t");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) == true)
		{
			output.push_back("y");
			button->increase();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) == true)
		{
			button->add();
			button->execute();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true)
		{
			button->undo();
			button->execute();
		}
	};

private:
	Command* button = new MacroCommand();
};

int main()
{
	bool start = true;

	while (start)
	{
		InputHandler input;
		input.handleInput();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			start = false;
		}
	}
	system("pause");
	return 0;
}