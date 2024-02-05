#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "CircleShape.h"
#include "CrossShape.h"
#include "GridShape.h"
#include "GameWindow.h"

char checkWin(const std::vector<char>& vGameGrid) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (vGameGrid[i * 3] != 'N' && vGameGrid[i * 3] == vGameGrid[i * 3 + 1] && vGameGrid[i * 3] == vGameGrid[i * 3 + 2]) {
            return vGameGrid[i * 3];
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (vGameGrid[i] != 'N' && vGameGrid[i] == vGameGrid[i + 3] && vGameGrid[i] == vGameGrid[i + 6]) {
            return vGameGrid[i];
        }
    }

    // Check diagonals
    if (vGameGrid[0] != 'N' && vGameGrid[0] == vGameGrid[4] && vGameGrid[0] == vGameGrid[8]) {
        return vGameGrid[0];
    }
    if (vGameGrid[2] != 'N' && vGameGrid[2] == vGameGrid[4] && vGameGrid[2] == vGameGrid[6]) {
        return vGameGrid[2];
    }

    // If no winner found
    return 'N';
}

int main()
{
    GameWindow oGameWindow;
    sf::Vector2f vWindowSize = sf::Vector2f(oGameWindow.getWidth(), oGameWindow.getHeight());

    std::vector<GameObject*> vAliveSymboles;

    std::vector<char> vGameGrid{'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};

    GridShape oGridShape(800.f, 20.f, sf::Color::Black);
    oGridShape.setGridPos((vWindowSize.x - oGridShape.m_fLinesSize) * 0.5, (vWindowSize.y - oGridShape.m_fLinesSize) * 0.5);

    bool bPlayerOneTurn = false;
    int iPlayerOneScore = 0;
    int iPlayerTwoScore = 0;

    sf::Font oDisplayFont;
    oDisplayFont.loadFromFile("assets/fonts/AmaticSC-Regular.ttf");

    sf::Text oTextOne;
    oTextOne.setPosition(sf::Vector2f(25, 25));
    oTextOne.setFont(oDisplayFont);
    oTextOne.setString("Player 1 : " + std::to_string(iPlayerOneScore));
    oTextOne.setCharacterSize(90);
    oTextOne.setFillColor(sf::Color::Black);
    oTextOne.setStyle(sf::Text::Bold);

    sf::Text oTextTwo;
    oTextTwo.setPosition(sf::Vector2f(vWindowSize.x - 310, 25));
    oTextTwo.setFont(oDisplayFont);
    oTextTwo.setString("Player 2 : " + std::to_string(iPlayerTwoScore));
    oTextTwo.setCharacterSize(90);
    oTextTwo.setFillColor(sf::Color::Black);
    oTextTwo.setStyle(sf::Text::Bold);

    while (oGameWindow.m_oWindow->isOpen()) {

        sf::Vector2f vWindowSize = sf::Vector2f(oGameWindow.getWidth(), oGameWindow.getHeight());

        sf::Event oEvent;
        while (oGameWindow.m_oWindow->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oGameWindow.m_oWindow->close();
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            // Get Mouse Position
            sf::Vector2i iMousePos = sf::Mouse::getPosition(*oGameWindow.m_oWindow);

            // 0,0
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[0] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[0] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[0] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 0,1
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[1] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[1] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[1] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 0,2
            if (iMousePos.x >= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[2] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[2] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[2] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 1,0
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[3] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5);
                            vGameGrid[3] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5);
                            vGameGrid[3] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 1,1
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[4] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5);
                            vGameGrid[4] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5);
                            vGameGrid[4] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 1,2
            if (iMousePos.x >= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 - oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[5] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5);
                            vGameGrid[5] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5);
                            vGameGrid[5] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 2,0
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[6] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[6] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[6] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 2,1
            if (iMousePos.x >= (vWindowSize.x * 0.5 - oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 - oGridShape.m_fLinesThickness * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[7] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[7] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[7] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }

            // 2,2
            if (iMousePos.x >= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.1666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.x <= (vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.5)) {
                if (iMousePos.y >= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.16666667 + oGridShape.m_fLinesThickness * 0.5) && iMousePos.y <= (vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.5 - oGridShape.m_fLinesThickness * 0.5)) {
                    if (vGameGrid[8] == 'N') {
                        if (bPlayerOneTurn) {
                            CrossShape* oShape = new CrossShape(250.f, 20.f, sf::Color(0, 97, 232));
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[8] = 'X';
                            vAliveSymboles.push_back(oShape);
                        }
                        else {
                            CircleShape* oShape = new CircleShape(85.f, 15.f, sf::Color::Red);
                            oShape->setPosition(vWindowSize.x * 0.5 + oGridShape.m_fLinesSize * 0.333, vWindowSize.y * 0.5 + oGridShape.m_fLinesSize * 0.333);
                            vGameGrid[8] = 'O';
                            vAliveSymboles.push_back(oShape);
                        }
                        bPlayerOneTurn = !bPlayerOneTurn;
                    }
                }
            }
        }

        // Check Win
        char cWinner = checkWin(vGameGrid);
        if (cWinner == 'X') {
            oGameWindow.m_oWindow->clear(sf::Color::Blue);
            vGameGrid.clear();
            vGameGrid.resize(9, 'N');
            vAliveSymboles.clear();
            iPlayerOneScore += 1;
            oTextOne.setString("Player 1 : " + std::to_string(iPlayerOneScore));
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        else if (cWinner == 'O') {
            oGameWindow.m_oWindow->clear(sf::Color::Red);
            vGameGrid.clear();
            vGameGrid.resize(9, 'N');
            vAliveSymboles.clear();
            iPlayerTwoScore += 1;
            oTextTwo.setString("Player 2 : " + std::to_string(iPlayerTwoScore));
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
        else {
            oGameWindow.m_oWindow->clear(sf::Color::White);
        }

        // Drawing
        oGameWindow.drawShape(oGridShape.m_vShapes);
        for (int i = 0; i < vAliveSymboles.size(); i++) {
            oGameWindow.drawShape(vAliveSymboles[i]->m_vShapes);
        }
        oGameWindow.m_oWindow->draw(oTextOne);
        oGameWindow.m_oWindow->draw(oTextTwo);

        // Display
        oGameWindow.display();
    }

    return 0;
}