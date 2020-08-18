#pragma once

#include "SFML/Graphics.hpp" // sf::Texture sf::Sprite sf::Vector2f


class Player
{
private:
	sf::Texture m_Texture;
	sf::Vector2f m_Position;
	int m_JumpCount;
	float m_Mass;
	float m_force;
	const float m_Gravity = 9.8f;
	bool m_Grounded;
public:
	sf::Sprite m_Sprite;
public:
	Player();
	~Player();
	void BeginPlay(std::string filepath, sf::Vector2f position, float mass);
	void Tick(float deltaTime);
	void jump(float velocity);
	sf::Sprite GetSprite();

};

