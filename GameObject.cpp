#include "GameObject.h"

/*
---------------------------------------------------------------------------------------------------------
|                                        Here is the constructor                                        |
---------------------------------------------------------------------------------------------------------
*/

GameObject::GameObject() {
	m_vPosition.x = NULL;
	m_vPosition.y = NULL;
}

/*
---------------------------------------------------------------------------------------------------------
|                                        Here are the get Methods                                       |
---------------------------------------------------------------------------------------------------------
*/

sf::Vector2f GameObject::getPosition() {
	sf::Vector2f vPosition(m_vPosition.x, m_vPosition.y);
	return vPosition;
}

/*
---------------------------------------------------------------------------------------------------------
|                                        Here are the set Methods                                       |
---------------------------------------------------------------------------------------------------------
*/

void GameObject::setPosition(float x, float y) {
	m_vPosition.x = x;
	m_vPosition.y = y;
	for (int i = 0; i < m_vShapes.size(); i++) {
		m_vShapes[i]->setPosition(sf::Vector2f(m_vPosition.x, m_vPosition.y));
	}
}

void GameObject::setGridPos(float x, float y) {
	for (int i = 0; i < m_vShapes.size(); i++) {
		sf::Vector2f oPos = m_vShapes[i]->getPosition();
		m_vShapes[i]->setPosition(sf::Vector2f(oPos.x + x, oPos.y + y));
	}
}
