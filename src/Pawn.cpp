#include "Tiny.h"
#include "Pawn.h"

Pawn::Pawn()
{

	m_CurrentVelocity = sf::Vector2f(0.0f, 0.0f);
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
	this->setScale(sf::Vector2f(0.04f, 0.04f));
	//*m_Mass
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

