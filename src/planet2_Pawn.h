#pragma once

#include "Pawn.h"

class planet2_Pawn : public Pawn
{
public:
	void BeginPlay(std::string texturefile, sf::Vector2f initposition, float mass) override;
	void Tick(float deltaTime) override;
};

