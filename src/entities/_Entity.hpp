#include "../Components.hpp"
#include "../assetManager.hpp"
#include "../particles.hpp"
#include "_Animated.hpp"

#pragma once

int totalEntities = 0;

class Entity : public Animated
{

public:
    std::map<std::string, std::vector<sf::Texture>> animationMap;

    std::string tag;
    int id;
    int layer;

    float health;

    float lastActionFrame;
    float scale;

    bool hatesPlayer;
    bool isProjectile;
    bool honour;
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

    direction = "";
    health = 1;
    actionTag = "idle";
    rotate=1;

    hatesPlayer=false;
    isProjectile = false;
    honour=false;
    isInvulnerable=false;

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

    if(direction=="right") {
        rotate=1;
    } else if(direction=="left") {
        rotate=-1;
    }

    
}
