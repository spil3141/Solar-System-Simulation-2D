#include "Tiny.h"
#include "planet2_Pawn.h"

extern std::vector<Pawn*> planets;

void planet2_Pawn::BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass)
{
	Pawn::BeginPlay(texturefile, initposition, mass);

	sf::Vector2f InitVelocity = sf::Vector2f(100.0f, -100.0f);
	this->m_CurrentVelocity = InitVelocity;
}

void planet2_Pawn::Tick(float deltaTime)
{
	Pawn::Tick(deltaTime);

	//Apply force onself from all other objects
	//Calculate the distance between the two entities
	for (int j = 0; j < planets.size(); j++)
	{
		if (this != planets[j])
		{
			sf::Vector2f distance = this->getPosition() - planets[j]->getPosition();
			float magnitude = sqrt((pow(distance.x, 2) + pow(distance.y, 2)));

			//Calculate the direction of this entity position vector to that of the other
			sf::Vector2f direction = distance / magnitude;


			// calculate the G Force 
			float GForce = (this->GetMass() * planets[j]->GetMass()) / sqrt(magnitude) * this->m_G;

			//calculate the velocity 
			sf::Vector2f velocity = direction * GForce * deltaTime;

			if(magnitude > 20.0f)
				this->m_CurrentVelocity += velocity;


		}
	}
}

