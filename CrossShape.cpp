#include "CrossShape.h"

/*
---------------------------------------------------------------------------------------------------------
|                                  Here is the cross shape constructor                                  |
---------------------------------------------------------------------------------------------------------
*/

CrossShape::CrossShape(float fLinesSize, float fLinesThickness, sf::Color oColor) {
	m_fLinesSize = fLinesSize;
	m_fLinesThickness = fLinesThickness;
	m_oColor = oColor;
	m_vOrigin = sf::Vector2f(m_fLinesSize * 0.5, m_fLinesSize * 0.5);

	sf::RectangleShape* oLineOne = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosOne = oLineOne->getPosition();
	oLineOne->setFillColor(oColor);
	oLineOne->setOrigin(sf::Vector2f(oPosOne.x + m_fLinesSize * 0.5, oPosOne.y + m_fLinesThickness * 0.5));
	oLineOne->rotate(45);
	this->m_vShapes.push_back(oLineOne);

	sf::RectangleShape* oLineTwo = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosTwo = oLineTwo->getPosition();
	oLineTwo->setFillColor(oColor);
	oLineTwo->setOrigin(sf::Vector2f(oPosTwo.x + m_fLinesSize * 0.5, oPosTwo.y + m_fLinesThickness * 0.5));
	oLineTwo->rotate(135);
	this->m_vShapes.push_back(oLineTwo);
}