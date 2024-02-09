#include "Player.h"


Player::Player() {
	m_iNumber = NULL;
	m_sUsername = "";
	m_cSymbole = 'M';
	m_iScore = 0;
	m_iID = "fyeNpM4iLTXQfKFmgUMXBS6YK31uXU";
}

void Player::askConnection(const std::string& sServerIP, int iPort) {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        // Handle initialization failure
        return;
    }

    // Set up server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(iPort);
    inet_pton(AF_INET, sServerIP.c_str(), &(serverAddress.sin_addr));

    // Create a socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        // Handle socket creation failure
        WSACleanup();
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        // Handle connection failure
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Connection successful, you can now send and receive data on 'sock'
    // Don't forget to close the socket and clean up Winsock when done
    closesocket(sock);
    WSACleanup();
}

void Player::sendMove(const std::string& sServerIP, int iPort, int x, int y) {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return;
    }

    // Set up server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(iPort);
    inet_pton(AF_INET, sServerIP.c_str(), &(serverAddress.sin_addr));

    // Create a socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Connection failed with error: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Connection successful, send the move to the server
    std::string move = std::to_string(x) + std::to_string(y) + m_iID;
    iResult = send(sock, move.c_str(), move.size(), 0);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Optional: Receive response from the server
    // You can implement this if the server sends back a response after receiving the move

    // Close the socket and clean up Winsock
    closesocket(sock);
    WSACleanup();
}

void Player::sendPlayerData() {
	//
}


void Player::setPlayer(int iNumber, char cSymbole) {
	m_iNumber = iNumber;
	m_cSymbole = cSymbole;
}

void Player::setUsername(std::string sUsername) {
	m_sUsername = sUsername;
}

void Player::setScore(int iScore) {
	m_iScore = iScore;
}

void Player::promptUsername() {
	//
}


int Player::getNumber() {
	return this->m_iNumber;
}

std::string	Player::getUsername() {
	return this->m_sUsername;
}

char Player::getSymbole() {
	return this->m_cSymbole;
}

int Player::getScore() {
	return this->m_iScore;
}

std::string Player::getID() {
    return this->m_iID;
}