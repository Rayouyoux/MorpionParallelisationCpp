#pragma once

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

class GameWindow
{
private:

	// Private Attributes
	const char*		m_sName;
	float			m_fWidth;
	float			m_fHeight;
	sf::Image*		m_oIcon;

public:

	// Public Attributes
	sf::RenderWindow* m_oWindow;

	// Constructor
	GameWindow();

	// Destructor
	~GameWindow();

	// Main Methods
	void		display();
	void		clear();
	void		close();

	// Get Methods
	float		getWidth();
	float		getHeight();
	float		getMousePos();

	// Draw Method
	void		drawShape(std::vector<sf::Shape*> vShapes);
};