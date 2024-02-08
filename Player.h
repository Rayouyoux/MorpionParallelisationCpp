#pragma once

#include <iostream>

class Player
{
public:

	// Main Attributes
	int				m_iNumber;
	std::string		m_sUsername;
	char			m_cSymbole;
	int				m_iScore;

	// Constructor
	Player();

	// Server Methods
	void			askConnection();
	void			sendMove();
	void			sendUsername();

	// Set Methods
	void			setPlayer(int iNumber, char cSymbole);
	void			setUsername(std::string sUsername);
	void			setScore(int iScore);
	void			promptUsername();

	// Get Methods
	int				getNumber();
	std::string		getUsername();
	char			getSymbole();
	int				getScore();

};

