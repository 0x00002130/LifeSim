#pragma once
#include "Globals.h"

class Player
{
private:
    std::string name{};
    std::string surname{};
    std::string nationality{};
    int age{};
    int health{};
    int happiness{};
    double money{};
public:
    void InitPlayer();

    // Getter
    std::string GetName() const;
    std::string GetSurname() const;
    int GetAge() const;
    int GetHealth() const;
    int GetHappiness() const;
    double GetMoney() const;

    // Setter
    void SetName(const std::string& newName);
    void SetSurname(const std::string& newSurname);
    void SetAge(int newAge);
    void SetHealth(int newHealth);
    void SetHappiness(int newHappiness);
    void SetMoney(double newMoney);
};
