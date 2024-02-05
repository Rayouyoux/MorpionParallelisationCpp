#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class CircleShape : public GameObject
{
public:

	// Public Attributes
	float					m_fRadius;
	float					m_fThickness;
	sf::Color				m_oColor;

	// Constructor
	CircleShape(float fRadius, float fThickness, sf::Color oColor);
};

