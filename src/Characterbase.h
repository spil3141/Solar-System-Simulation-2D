#pragma once

#include "SFML/graphics.hpp"


class CharacterBase : public sf::Sprite
{
public:
	void BeginPlay(sf::Texture texture, sf::Vector2f initposition, float mass);
	void Tick(float deltaTime);

};

