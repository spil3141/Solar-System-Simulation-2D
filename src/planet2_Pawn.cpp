#include "planet2_Pawn.h"
#include "planet1_Pawn.h"
#include "planet3_Pawn.h"
extern planet1_Pawn planet1;
extern planet2_Pawn planet2;
extern planet3_Pawn planet3;


void planet2_Pawn::BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass)
{
	Pawn::BeginPlay(texturefile, initposition, mass);


}

void planet2_Pawn::Tick(float deltaTime)
{
	Pawn::Tick(deltaTime);
	
	//Determine the distance between planet1 and platnet 2
	float d = (CalculateMagitudeVec2f(getPosition().x, getPosition().y) - CalculateMagitudeVec2f(planet1.getPosition().x, planet1.getPosition().y));

	//Calculate the gravitational force on each object in relation to the other
	float Force = ((GetMass() * planet1.GetMass()) / pow(d, 2)) * m_G;

	//printf("P2 -> distance b/w p1 and p2:  %.4f \n",d );
	printf("Force Vector magnitude: %.4f \n", Force);

	float newX = getPosition().x;
	newX -= Force * deltaTime;
	float newY = getPosition().y;
	newY -= Force * deltaTime;
	setPosition(sf::Vector2f(newX, newY));

}
