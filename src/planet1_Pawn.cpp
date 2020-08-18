#include "planet1_Pawn.h"
#include "planet2_Pawn.h"
#include "planet3_Pawn.h"

extern planet1_Pawn planet1;
extern planet2_Pawn planet2;
extern planet3_Pawn planet3;

void planet1_Pawn::BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass)
{
	Pawn::BeginPlay(texturefile, initposition, mass);

}

void planet1_Pawn::Tick(float deltaTime)
{
	Pawn::Tick(deltaTime);

	//Determine the distance between planet1 and platnet 2
	float d = abs(CalculateMagitudeVec2f(getPosition().x, getPosition().y) - CalculateMagitudeVec2f(planet2.getPosition().x, planet2.getPosition().y));

	//Calculate the gravitational force on each object in relation to the other
	float Force = ((GetMass() * planet2.GetMass()) / pow(d, 2)) * m_G;

	//printf("P2 -> distance b/w p1 and p2:  %.4f \n",d );
	printf("Force Vector magnitude: %.4f \n", Force);

	float newX = getPosition().x;
	newX += Force * deltaTime;
	float newY = getPosition().y;
	newY += Force * deltaTime;
	setPosition(sf::Vector2f(newX, newY));

}
