#include "Tiny.h"
#include "planet1_Pawn.h"
#include "planet2_Pawn.h"

extern planet2_Pawn planet2;

void planet1_Pawn::BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass)
{
	Pawn::BeginPlay(texturefile, initposition, mass);

}

void planet1_Pawn::Tick(float deltaTime)
{
	Pawn::Tick(deltaTime);

	//Calculate the distance between the two entities
	sf::Vector2f distance = this->getPosition() - planet2.getPosition();
	float magnitude = sqrt((pow(distance.x, 2) + pow(distance.y, 2)));


	//Calculate the direction of this entity position vector to that of the other
	sf::Vector2f direction = distance / magnitude;


	// calculate the G Force 
	float GForce = (this->GetMass() * planet2.GetMass()) / sqrt(magnitude) * this->m_G;

	//calculate the velocity 
	sf::Vector2f velocity = direction * GForce * deltaTime;
	sf::Vector2f m_InitVelocity = sf::Vector2f(0.0f, 0.0f);
	velocity += m_InitVelocity;

	//apply velocity to the position vector 

	sf::Vector2f newPos = this->getPosition();

	newPos -= sf::Vector2f(velocity.x, velocity.y) * deltaTime;
	this->setPosition(newPos);
}
