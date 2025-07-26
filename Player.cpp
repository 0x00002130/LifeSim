#include "Player.h"

void Player::InitPlayer()
{
	this->name = "";
	this->surname = "";
	this->nationality = "";
	this->age = 0;
	this->health = Random::get(30, 80);
	this->happiness = 50;
	this->money = 0;
}

// Getter implementations
std::string Player::GetName() const { return name; }
std::string Player::GetSurname() const { return surname; }
std::string Player::GetNationality() const { return nationality; }
int Player::GetAge() const { return age; }
int Player::GetHealth() const { return health; }
int Player::GetHappiness() const { return happiness; }
double Player::GetMoney() const { return money; }

// Setter implementations
void Player::SetName(const std::string& newName) { name = newName; }
void Player::SetSurname(const std::string& newSurname) { surname = newSurname; }
void Player::SetNationality(const std::string& newNationality) { nationality = newNationality; }
void Player::SetAge(int newAge) { age = newAge; }
void Player::SetHealth(int newHealth) { health = newHealth; }
void Player::SetHappiness(int newHappiness) { happiness = newHappiness; }
void Player::SetMoney(double newMoney) { money = newMoney; }
