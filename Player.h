#pragma once
#include "Globals.h"

class Player
{
private:
    std::string name{};
    std::string surname{};
	std::string gender{};
    std::string nationality{};
	std::string sign{};
    int age{};
    int health{};
    int happiness{};
    double money{};

    enum Sign {
        aries,
        taurus,
        gemini,
        cancer,
        leo,
        virgo,
        libra,
        scorpio,
        sagittarius,
        capricorn,
        aquarius,
        pisces
    };
public:
    void InitPlayer();

    // Getter
    std::string GetName() const;
    std::string GetSurname() const;
	std::string GetGender() const;
	std::string GetNationality() const;
    std::string GetSign() const;
    std::string GetRandomSign() const;
    int GetAge() const;
    int GetHealth() const;
    int GetHappiness() const;
    double GetMoney() const;

    // Setter
    void SetName(const std::string& newName);
    void SetSurname(const std::string& newSurname);
	void SetGender(const std::string& newGender);
	void SetNationality(const std::string& newNationality);
    void SetSign(const std::string& newSign);
    void SetAge(int newAge);
    void SetHealth(int newHealth);
    void SetHappiness(int newHappiness);
    void SetMoney(double newMoney);
};
