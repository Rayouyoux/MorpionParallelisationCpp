#include "GridShape.h"

/*
---------------------------------------------------------------------------------------------------------
|                                  Here is the grid shape constructor                                   |
---------------------------------------------------------------------------------------------------------
*/

GridShape::GridShape(float fLinesSize, float fLinesThickness, sf::Color oColor) {
	m_fLinesSize = fLinesSize;
	m_fLinesThickness = fLinesThickness;
	m_oColor = oColor;
	m_vOrigin = sf::Vector2f(fLinesSize * 0.5, fLinesSize * 0.5);

	sf::RectangleShape* oLineOne = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosOne = oLineOne->getPosition();
	oLineOne->setFillColor(oColor);
	oLineOne->setOrigin(sf::Vector2f(oPosOne.x, oPosOne.y + m_fLinesThickness * 0.5));
	oLineOne->setPosition(sf::Vector2f(oPosOne.x, oPosOne.y + m_fLinesSize * 0.33333));
	this->m_vShapes.push_back(oLineOne);

	sf::RectangleShape* oLineTwo = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosTwo = oLineTwo->getPosition();
	oLineTwo->setFillColor(oColor);
	oLineTwo->setOrigin(sf::Vector2f(oPosTwo.x, oPosTwo.y + m_fLinesThickness * 0.5));
	oLineTwo->setPosition(sf::Vector2f(oPosTwo.x, oPosTwo.y + m_fLinesSize * 0.66667));
	this->m_vShapes.push_back(oLineTwo);

	sf::RectangleShape* oLineThree = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosThree = oLineThree->getPosition();
	oLineThree->setFillColor(oColor);
	oLineThree->setOrigin(sf::Vector2f(oPosThree.x, oPosThree.y + m_fLinesThickness * 0.5));
	oLineThree->rotate(90);
	oLineThree->setPosition(sf::Vector2f(oPosThree.x + m_fLinesSize * 0.33333, oPosThree.y - m_fLinesThickness * 0.5));
	this->m_vShapes.push_back(oLineThree);

	sf::RectangleShape* oLineFour = new sf::RectangleShape(sf::Vector2f(m_fLinesSize, m_fLinesThickness));
	sf::Vector2f oPosFour = oLineFour->getPosition();
	oLineFour->setFillColor(oColor);
	oLineFour->setOrigin(sf::Vector2f(oPosFour.x, oPosFour.y + m_fLinesThickness * 0.5));
	oLineFour->rotate(90);
	oLineFour->setPosition(sf::Vector2f(oPosFour.x + m_fLinesSize * 0.66667, oPosFour.y - m_fLinesThickness * 0.5));
	this->m_vShapes.push_back(oLineFour);
}