#include "Player.h"

void Player::InitPlayer()
{
	this->name = "";
	this->surname = "";
	this->gender = ""; 
	this->nationality = "";
	this->sign = "";
	this->age = 0;
	this->health = Random::get(30, 80);
	this->happiness = 50;
	this->money = 0;
	this->intelligence.linguistic = Random::get(0.0, 10.0);
	this->intelligence.logical = Random::get(0.0, 10.0);
	this->intelligence.spatial = Random::get(0.0, 10.0);
	this->intelligence.bodily = Random::get(0.0, 10.0);
	this->intelligence.musical = Random::get(0.0, 10.0);
	this->intelligence.interpersonal = Random::get(0.0, 10.0);
	this->intelligence.intrapersonal = Random::get(0.0, 10.0);
	this->intelligence.naturalistic = Random::get(0.0, 10.0);
}

// Getter implementations
std::string Player::GetName() const { return name; }
std::string Player::GetSurname() const { return surname; }
std::string Player::GetGender() const { return gender; }
std::string Player::GetNationality() const { return nationality; }
std::string Player::GetSign() const { return sign; }
int Player::GetAge() const { return age; }
int Player::GetHealth() const { return health; }
int Player::GetHappiness() const { return happiness; }
double Player::GetMoney() const { return money; }
double Player::GetLinguisticIntelligence() const { return intelligence.linguistic; }
double Player::GetLogicalIntelligence() const { return intelligence.logical; }
double Player::GetSpatialIntelligence() const { return intelligence.spatial; }
double Player::GetBodilyIntelligence() const { return intelligence.bodily; }
double Player::GetMusicalIntelligence() const { return intelligence.musical; }
double Player::GetInterpersonalIntelligence() const { return intelligence.interpersonal; }
double Player::GetIntrapersonalIntelligence() const { return intelligence.intrapersonal; }
double Player::GetNaturalisticIntelligence() const { return intelligence.naturalistic; }

// Setter implementations
void Player::SetName(const std::string& newName) { name = newName; }
void Player::SetSurname(const std::string& newSurname) { surname = newSurname; }
void Player::SetGender(const std::string& newGender) { gender = newGender; }
void Player::SetNationality(const std::string& newNationality) { nationality = newNationality; }
void Player::SetSign(const std::string& newSign) { sign = newSign; }
void Player::SetAge(int newAge) { age = newAge; }
void Player::SetHealth(int newHealth) { health = newHealth; }
void Player::SetHappiness(int newHappiness) { happiness = newHappiness; }
void Player::SetMoney(double newMoney) { money = newMoney; }
void Player::SetLinguisticIntelligence(double value) { intelligence.linguistic = value; }
void Player::SetLogicalIntelligence(double value) { intelligence.logical = value; }
void Player::SetSpatialIntelligence(double value) { intelligence.spatial = value; }
void Player::SetBodilyIntelligence(double value) { intelligence.bodily = value; }
void Player::SetMusicalIntelligence(double value) { intelligence.musical = value; }
void Player::SetInterpersonalIntelligence(double value) { intelligence.interpersonal = value; }
void Player::SetIntrapersonalIntelligence(double value) { intelligence.intrapersonal = value; }
void Player::SetNaturalisticIntelligence(double value) { intelligence.naturalistic = value; }


std::string Player::GetRandomSign() const {
	switch (static_cast<Sign>(Random::get(0, 11))) {
		case aries: return "Aries";
		case taurus: return "Taurus";
		case gemini: return "Gemini";
		case cancer: return "Cancer";
		case leo: return "Leo";
		case virgo: return "Virgo";
		case libra: return "Libra";
		case scorpio: return "Scorpio";
		case sagittarius: return "Sagittarius";
		case capricorn: return "Capricorn";
		case aquarius: return "Aquarius";
		case pisces: return "Pisces";
	}
	return ""; // Fallback in case of an error
}