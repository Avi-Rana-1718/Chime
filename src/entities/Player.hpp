#include "_Entity.hpp"

#pragma once
class Player : public Entity
{

public:
    Player();

    // functions
    void update(float time);

    void sInput();
    void sAttack();
};

Player::Player()
{

    tag = "Player";
    health = 5;

    animationMap["idle"].push_back(m_textures["player_idle"]);
    animationMap["move"].push_back(m_textures["player_move0"]);
    animationMap["move"].push_back(m_textures["player_move1"]);
    animationMap["move"].push_back(m_textures["player_move2"]);
    animationMap["move"].push_back(m_textures["player_move3"]);
    animationMap["move"].push_back(m_textures["player_move4"]);
    animationMap["move"].push_back(m_textures["player_move5"]);
    animationMap["attack"].push_back(m_textures["player_attack1"]);
    animationMap["attack"].push_back(m_textures["player_attack1"]);
    animationMap["attack"].push_back(m_textures["player_attack2"]);
    animationMap["attack"].push_back(m_textures["player_attack3"]);
    animationMap["attack"].push_back(m_textures["player_attack4"]);
    animationMap["attack"].push_back(m_textures["player_attack5"]);

    
    sprite = new CSprite(m_textures["player_idle"]);
    sprite->setOrigin(m_textures["player_idle"].getSize().x / 2, m_textures["player_idle"].getSize().y / 2);
    sprite->setPosition(sf::Vector2f(WINDOW_W/2, WINDOW_H/2));

    scale = 1;

    currentFrame=0;
    frameDelay=0.15;

    transform = new CTransform(350.f, 350.f);
    actionTag = "idle";
}

void Player::update(float time)
{

    deltaTime = time;
    sInput();
    sAnimate();
    sAttack();

}

void Player::sInput()
{
    bool moving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite->getPosition().y - sprite->getGlobalBounds().getSize().y/2 > 0)
    {
        sprite->move(0, -transform->speedY * deltaTime);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        moving=true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite->getPosition().y + sprite->getGlobalBounds().getSize().y/2 < WINDOW_H)
    {
        sprite->move(0, transform->speedY * deltaTime);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        moving=true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite->getPosition().x - sprite->getGlobalBounds().getSize().x/2 > 0)
    {
        sprite->move(-transform->speedX * deltaTime, 0);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        direction = -1;
        moving=true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite->getPosition().x + sprite->getGlobalBounds().getSize().x/2< WINDOW_W)
    {
        sprite->move(transform->speedX * deltaTime, 0);
        actionTag = (actionTag != "attack") ? "move" : "attack";
        direction = 1;
        moving=true;
    }

    if(moving==false && actionTag!="attack") {
        actionTag="idle";
    }

}

void Player::sAttack() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        actionTag="attack";
    }
}