#include "_Entity.hpp"

#pragma once
class Player : public Entity
{

public:
    Player();

    // functions
    void update(float time);

    void sInput();
};

Player::Player()
{

    tag = "Player";
    health = 5;

    sprite = new CSprite(m_textures["player.png"]);
    sprite->setOrigin(m_textures["player.png"].getSize().x / 2, m_textures["player.png"].getSize().y / 2);
    sprite->setPosition(sf::Vector2f(WINDOW_W/2, WINDOW_H/2));

    scale = 3;

    transform = new CTransform(350.f, 350.f);
    actionTag = "idle";
}

void Player::update(float time)
{

    deltaTime = time;
    sInput();
    sAnimate();

}

void Player::sInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite->getPosition().y - sprite->getGlobalBounds().getSize().y/2 > 0)
    {
        sprite->move(0, -transform->speedY * deltaTime);
        actionTag = (actionTag != "attack") ? "move" : "attack";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite->getPosition().y + sprite->getGlobalBounds().getSize().y/2 < WINDOW_H)
    {
        sprite->move(0, transform->speedY * deltaTime);
        actionTag = (actionTag != "attack") ? "move" : "attack";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite->getPosition().x - sprite->getGlobalBounds().getSize().x/2 > 0)
    {
        sprite->move(-transform->speedX * deltaTime, 0);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        direction = "right";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite->getPosition().x + sprite->getGlobalBounds().getSize().x/2< WINDOW_W)
    {
        sprite->move(transform->speedX * deltaTime, 0);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        direction = "left";
    }

}
