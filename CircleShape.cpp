#include "CircleShape.h"

/*
---------------------------------------------------------------------------------------------------------
|                                  Here is the circle shape constructor                                 |
---------------------------------------------------------------------------------------------------------
*/

CircleShape::CircleShape(float fRadius, float fThickness, sf::Color oColor) {
	m_fRadius = fRadius;
	m_fThickness = fThickness;
	m_oColor = oColor;

	sf::CircleShape* oCircle = new sf::CircleShape(m_fRadius);
	sf::Vector2f oPos = oCircle->getPosition();
	oCircle->setFillColor(sf::Color(255, 255, 255, 0));
	oCircle->setOutlineThickness(m_fThickness);
	oCircle->setOutlineColor(m_oColor);
	oCircle->setOrigin(sf::Vector2f(oPos.x + m_fRadius, oPos.y + m_fRadius));
	this->m_vShapes.push_back(oCircle);
}