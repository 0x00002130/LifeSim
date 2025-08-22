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
    std::string job{};
    int age{};
    int health{};
    int happiness{};
    double money{};

    struct Intelligence {
		double linguistic{};
		double logical{};
		double spatial{};
		double bodily{};
		double musical{};
		double interpersonal{};
		double intrapersonal{};
		double naturalistic{};
    };

	Intelligence intelligence{};

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
	std::string GetJob() const;
    int GetAge() const;
    int GetHealth() const;
    int GetHappiness() const;
    double GetMoney() const;
    double GetLinguisticIntelligence() const;
    double GetLogicalIntelligence() const;
    double GetSpatialIntelligence() const;
    double GetBodilyIntelligence() const;
    double GetMusicalIntelligence() const;
    double GetInterpersonalIntelligence() const;
    double GetIntrapersonalIntelligence() const;
    double GetNaturalisticIntelligence() const;


    // Setter
    void SetName(const std::string& newName);
    void SetSurname(const std::string& newSurname);
	void SetGender(const std::string& newGender);
	void SetNationality(const std::string& newNationality);
    void SetSign(const std::string& newSign);
	void SetJob(const std::string& newJob);
    void SetAge(int newAge);
    void SetHealth(int newHealth);
    void SetHappiness(int newHappiness);
    void SetMoney(double newMoney);
    void SetLinguisticIntelligence(double value);
    void SetLogicalIntelligence(double value);
    void SetSpatialIntelligence(double value);
    void SetBodilyIntelligence(double value);
    void SetMusicalIntelligence(double value);
    void SetInterpersonalIntelligence(double value);
    void SetIntrapersonalIntelligence(double value);
    void SetNaturalisticIntelligence(double value);

};
