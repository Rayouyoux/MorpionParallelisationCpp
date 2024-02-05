#pragma once

#include "SFML/Graphics.hpp"

class GameObject
{
public:

	// Public Attributes
	sf::Vector2f			m_vPosition;
	std::vector<sf::Shape*>	m_vShapes;
	sf::Vector2f			m_vOrigin;

	// Constructor
	GameObject();

	// Get Methods
	sf::Vector2f	getPosition();

	// Set Methods
	void	setPosition(float x, float y);
	void	setGridPos(float x, float y);
};

