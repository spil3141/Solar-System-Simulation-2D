#include "Tiny.h"
#include "planet2_Pawn.h"
#include "planet1_Pawn.h"



extern planet1_Pawn planet1;


void planet2_Pawn::BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass)
{
	Pawn::BeginPlay(texturefile, initposition, mass);


}

void planet2_Pawn::Tick(float deltaTime)
{
	Pawn::Tick(deltaTime);

	//Calculate the distance between the two entities
	sf::Vector2f distance = this->getPosition() - planet1.getPosition();
	float magnitude = sqrt((pow(distance.x, 2) + pow(distance.y, 2)));

	//Calculate the direction of this entity position vector to that of the other
	sf::Vector2f direction = distance / magnitude;


	// calculate the G Force 
	float GForce = (this->GetMass() * planet1.GetMass()) / sqrt(magnitude) * this->m_G;

	//calculate the velocity 
	sf::Vector2f velocity = direction * GForce * deltaTime;

	//Keep it in orbit
	if (velocity.x < 0.002 && velocity.y < 0.002)
	{
		sf::Vector2f m_InitVelocity = sf::Vector2f(0.003f, -0.0516f);
		velocity += m_InitVelocity;
	}

	this->m_CurrentVelocity -= sf::Vector2f(velocity.x, velocity.y) * deltaTime;

	//apply velocity to the position vector 

	sf::Vector2f newPos = this->getPosition();

	newPos += this->m_CurrentVelocity;

	this->setPosition(newPos);





	
	////Determine the distance between planet1 and platnet 2
	//float d = (CalculateMagitudeVec2f(getPosition().x, getPosition().y) - CalculateMagitudeVec2f(planet1.getPosition().x, planet1.getPosition().y));

	////Calculate the gravitational force on each object in relation to the other
	//float Force = ((GetMass() * planet1.GetMass()) / pow(d, 2)) * m_G;

	////printf("P2 -> distance b/w p1 and p2:  %.4f \n",d );
	//printf("Force Vector magnitude: %.4f \n", Force);

	//float newX = getPosition().x;
	//newX -= Force * deltaTime;
	//float newY = getPosition().y;
	//newY -= Force * deltaTime;
	//setPosition(sf::Vector2f(newX, newY));

}

