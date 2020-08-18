#include "Pawn.h"
#include <cmath>

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}

void Pawn::BeginPlay(std::string texturefile,sf::Vector2f initposition, float mass)
{
	m_Mass = mass;
	m_Texture.loadFromFile(texturefile);
	this->setTexture(m_Texture);
	this->setOrigin(sf::Vector2f((float) m_Texture.getSize().x/2, (float) m_Texture.getSize().y/2));
	this->setPosition(initposition);
	this->setScale(sf::Vector2f(0.001f * m_Mass, 0.001f * m_Mass));
}

void Pawn::Tick(float deltaTime)
{
}

float Pawn::CalculateMagitudeVec2f(float x, float y)
{
	return sqrt(pow(x,2) + pow(y,2));
}

float Pawn::GetMass()
{
	return m_Mass;
}

