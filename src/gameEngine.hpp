#include "global.hpp"
#include "particles.hpp"
#include "scenes/Scenes.hpp"

#include "scenes/Scene_default.hpp"

class GameEngine
{

public:
    sf::Event event;
    sf::Image icon;

    AssetManager assets;

    GameEngine();

    // functions
    void run();
};

GameEngine::GameEngine()
{

    window.create(sf::VideoMode(WINDOW_W, WINDOW_H), gameName, sf::Style::Default);

    // USE THIS INCASE OF WINDOW SIZE CHANGES
    // WINDOW_W = window.getSize().x;
    // WINDOW_H = window.getSize().y;


    //load icon
    if(!icon.loadFromFile("./assets/icon.png")) {
        std::cout<<"ICON: NOT FOUND";
    }

    assets.addTexture("player.png");

    assets.addFont("hack.ttf");
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    scenes["default"] = new Scene_default;

    currentScene = scenes["default"];
    window.setFramerateLimit(144);
    isRunning = true;
    totalFrames = 0;

    view.setCenter(sf::Vector2f(WINDOW_W / 2, WINDOW_H / 2));
    view.setSize(sf::Vector2f(WINDOW_W, WINDOW_H));
    window.setView(view);

    // MUSIC - BACKGROUND
    // if (!music.openFromFile("./assets/dos88.ogg"))
    // {
    //     std::cout << "ASSET: DOS88 NOT FOUND\n";
    // }
    // music.setVolume(50);
    // music.setLoop(true);
    // music.play();
}

void GameEngine::run()
{
    currentScene->init();

    while (isRunning)
    {

        sf::Time time = Clock.restart();
        totalFrames++;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.create(sf::VideoMode::getDesktopMode(), gameName);
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
        {
            window.create(sf::VideoMode::getDesktopMode(), gameName, sf::Style::Fullscreen);
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        }

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
                window.close();
            }
        }

        currentScene->run(time.asSeconds());
    }
}