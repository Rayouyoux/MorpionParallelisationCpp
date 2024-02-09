#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>

#include <iostream>
#include <string>

class Player
{
public:

	// Main Attributes
	int				m_iNumber;
	std::string		m_sUsername;
	char			m_cSymbole;
	int				m_iScore;
	std::string		m_iID;

	// Constructor
	Player();

	// Server Methods
	void			askConnection(const std::string& sServerIP, int iPort);
	void			sendMove(const std::string& serverIP, int port, int x, int y);
	void			sendPlayerData();

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
	std::string		getID();
};