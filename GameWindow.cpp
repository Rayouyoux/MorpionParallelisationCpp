#include "GameWindow.h"

#include <iostream>
#include <SFML/Graphics.hpp>


/*
---------------------------------------------------------------------------------------------------------
|                                        Here is the constructor                                        |
---------------------------------------------------------------------------------------------------------
*/

GameWindow::GameWindow() {

	m_sName = "Morpion Parallélisation";
	m_fWidth = 1920.f;
	m_fHeight = 1080.f;

	m_oWindow = new sf::RenderWindow(sf::VideoMode((unsigned int)m_fWidth, (unsigned int)m_fHeight), m_sName);
	sf::View *oView = new sf::View(sf::Vector2f(960, 540), sf::Vector2f(1920, 1080));
	m_oWindow->setView(*oView);

	m_oIcon = new sf::Image();
	if (!m_oIcon->loadFromFile("assets/icons/icon_1.png"))
	{
		std::cout << "Error loading icon" << std::endl;
		exit(1);
	}
	m_oWindow->setIcon(m_oIcon->getSize().x, m_oIcon->getSize().y, m_oIcon->getPixelsPtr());
}

/*
---------------------------------------------------------------------------------------------------------
|                                       Here are the main methods                                       |
---------------------------------------------------------------------------------------------------------
*/

void GameWindow::display() {
	m_oWindow->display();
}

void GameWindow::clear() {
	m_oWindow->clear();
}

void GameWindow::close() {
	m_oWindow->close();
	exit(0);
}

/*
---------------------------------------------------------------------------------------------------------
|                                       Here are the get methods                                        |
---------------------------------------------------------------------------------------------------------
*/

float GameWindow::getWidth() {
	return (float)m_fWidth;
}

float GameWindow::getHeight() {
	return (float)m_fHeight;
}

/*
---------------------------------------------------------------------------------------------------------
|                                       Here is the draw methods                                        |
---------------------------------------------------------------------------------------------------------
*/

void GameWindow::drawShape(std::vector<sf::Shape*> vShapes) {
	for (int i = 0; i < vShapes.size(); i++) {
		m_oWindow->draw(*vShapes[i]);
	}
}

/*
---------------------------------------------------------------------------------------------------------
|                                        Here is the destructor                                         |
---------------------------------------------------------------------------------------------------------
*/

GameWindow::~GameWindow() {
	delete m_oIcon;
	delete m_oWindow;
}