#pragma once

#include "SFML/graphics.hpp"


class Pawn : public sf::Sprite
{	
protected:
	float m_Mass;
	const float m_G = 9.8f;
	sf::Texture m_Texture;
	sf::Vector2f InitPosition;
public:
	Pawn();
	~Pawn();
	virtual void BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass);
	virtual void Tick(float deltaTime);
	virtual float CalculateMagitudeVec2f(float x, float y);
	float GetMass();
};

