#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class CrossShape : public GameObject
{
public:

	// Public Attributes
	float					m_fLinesSize;
	float					m_fLinesThickness;
	sf::Color				m_oColor;

	// Constructor
	CrossShape(float fLinesSize, float fLinesThickness, sf::Color oColor);
};

