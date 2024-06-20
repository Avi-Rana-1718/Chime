#pragma once

class Animated {
    public:
    float frameDelay;
    float animationTimer;
    int currentFrame;

    int direction;

    std::map<std::string, std::vector<sf::Texture>> animationMap;
};