#include "../Components.hpp"
#include "../assetManager.hpp"
#include "../particles.hpp"
#include "_Animated.hpp"

#pragma once

int totalEntities = 0;

class Entity : public Animated
{

public:

    std::string tag;
    int id;
    int layer;

    float health;

    float lastActionFrame;
    float scale;

    bool hatesPlayer;
    bool isProjectile;
    bool isInvulnerable;

    CSprite *sprite = NULL;
    CTransform *transform = NULL;
    sf::Text *text = NULL;
    sf::RectangleShape *shape = NULL;
    ParticleSystem *particles = NULL;


    float deltaTime;
    std::string actionTag;
    

    // functions
    Entity();
    ~Entity();

    virtual void update(float time);
    virtual void sAnimate();

};

Entity::Entity()
{
    id = totalEntities++;
    layer = 1;

    direction = 1;
    health = 1;
    actionTag = "idle";

    hatesPlayer=false;
    isProjectile = false;
    isInvulnerable=false;

    currentFrame=0;

    scale=1;

    lastActionFrame=gameTime.getElapsedTime().asSeconds();
}
Entity::~Entity()
{
    delete sprite;
    delete transform;
    delete text;
    delete shape;
    delete particles;
}

void Entity::update(float time)
{
    //
}

void Entity::sAnimate()
{
    sprite->setScale(sf::Vector2f(direction * scale, scale));  

    // std::cout<<actionTag<<std::endl;

    if (currentFrame < animationMap[actionTag].size() && gameTime.getElapsedTime().asSeconds() > animationTimer + frameDelay)
    {
        sprite->setTexture(animationMap[actionTag][currentFrame++]);
        animationTimer = gameTime.getElapsedTime().asSeconds();
        return;
    }
    else if (currentFrame >= animationMap[actionTag].size())
    {
        animationTimer = gameTime.getElapsedTime().asSeconds();
        currentFrame = 0;
        actionTag = "idle";
    }
}
