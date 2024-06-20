#pragma once

class GameEngine;
sf::RenderWindow window;
sf::View view;
sf::Clock Clock;
sf::Clock gameTime;
sf::Clock fpsClock;
sf::Sound sound;
sf::Music music;

//
std::string gameName = "Chime engine";

bool isRunning;
float gameSpeed=1;

int frames;
int shake;
int calculatedFPS;

int WINDOW_W=1080;
int WINDOW_H=720;

#include "entities/_Entity.hpp"

std::vector<Entity *> entities;
std::vector<Entity *> ui;
std::vector<Entity *> background;

#include "scenes/Scenes.hpp"

std::map<std::string, Scenes *> scenes;

Scenes *currentScene = NULL;
Scenes *nextScene = NULL;