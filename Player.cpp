#include "Player.h"

Player::Player() {
	m_iNumber = NULL;
	m_sUsername = "";
	m_cSymbole = 'M';
	m_iScore = 0;
}

void Player::askConnection() {
	//
}

void Player::sendMove() {
	//
}

void Player::sendUsername() {
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