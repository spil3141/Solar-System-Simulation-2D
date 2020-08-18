#include "Player.h"
#include <iostream>




Player::Player()
{
	m_Mass = 0.0f;
	m_Grounded = false;
	m_JumpCount = 0;
	m_force = 0.0f;
}

Player::~Player()
{
}

/**
* Initialize the Player entity.
* 1. load texture
* 2. add texture to sprite
* 3. setposition and origin of sprite
* 4. assign member variables
*/
void Player::BeginPlay(std::string filepath, sf::Vector2f position, float mass)
{
	m_Texture.loadFromFile(filepath.c_str());
	m_Position = position;
	m_Mass = mass;
	m_Grounded = false;

	m_Sprite.setTexture(m_Texture, true);
	m_Sprite.setPosition(m_Position);
	m_Sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	m_Sprite.setOrigin(sf::Vector2f((float)m_Texture.getSize().x / 2, (float)m_Texture.getSize().y / 2));

}



/**
* This funciton is called every frame.
* 1. Calculate the gravitational force. 
* 2. apply gravity on the sprite by increasing the y value by the G force (mass * gravity * deltaTime); deltatime is for framerate independence.
* 3. check if the sprite reach the ground (72% of the height of the screen) and notify the instance of that. 
*/
void Player::Tick(float deltaTime)
{
	//Force of gravity
	m_force -= m_Mass * m_Gravity * deltaTime;

	//Gforce apply to the position of the sprite
	m_Position.y -= m_force * deltaTime;

	m_Sprite.setPosition(m_Position);

	//Ground "Collision"
	if (m_Position.y >= 800 * 0.84)
	{
		m_Position.y = 800 * 0.84;
		m_force = 0.0f;
		m_Grounded = true;
		m_JumpCount = 0;
	}
}

/**
* Player Jumping 
* 1. if the player jump count is less than 2, jump and increment the value. 
* 2. increase the player velocity 
*/
void Player::jump(float force)
{
	if (m_JumpCount < 1)
	{
		m_force = force;
		m_JumpCount++;
		m_Grounded = false;
	}

}

sf::Sprite Player::GetSprite()
{
	return m_Sprite;
}
