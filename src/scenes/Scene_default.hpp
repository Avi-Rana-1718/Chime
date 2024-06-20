#include "Scenes.hpp"
#include "../entities/Player.hpp"

class Scene_default : public Scenes {
    
  Entity* player=NULL;
  Entity *playerCORDS = NULL, *console = NULL;

    public:
    void init();
    void run(float time);
    void update();

};

void Scene_default::init() {
  player=new Player;
  entities.push_back(player);

  playerCORDS = new Entity;
  playerCORDS->text = new sf::Text;
  playerCORDS->text->setFont(m_fonts["hack.ttf"]);
  playerCORDS->text->setString("100, 100");
  playerCORDS->text->setCharacterSize(18);
  playerCORDS->text->setFillColor(sf::Color::Black);
  playerCORDS->text->setPosition(sf::Vector2f(10, WINDOW_H-playerCORDS->text->getGlobalBounds().getSize().y-10));
  ui.push_back(playerCORDS);

  Entity* temp = new Entity;
  temp->text = new sf::Text;
  temp->text->setString("Chime demo!");
  temp->text->setFont(m_fonts["hack.ttf"]);
  temp->text->setCharacterSize(20);
  temp->text->setFillColor(sf::Color::Black);
  temp->text->setPosition(sf::Vector2f(10, 10));
  ui.push_back(temp);

  console = new Entity;
  console->text = new sf::Text;
  console->text->setString("Window: " + std::to_string(WINDOW_W) + "x" + std::to_string(WINDOW_H) + "\nTotal entities: " + std::to_string(entities.size()) + "\nTotal UI elements: " + std::to_string(ui.size()) + "\nFPS: " + std::to_string(calculatedFPS));
  console->text->setFont(m_fonts["hack.ttf"]);
  console->text->setCharacterSize(20);
  console->text->setFillColor(sf::Color::Black);
  console->text->setPosition(sf::Vector2f(WINDOW_W-console->text->getGlobalBounds().getSize().x-10, 10));
  ui.push_back(console);
}

void Scene_default::run(float time) {
  deltaTime=time;
  sRender();
  update();
}

void Scene_default::update() {
  for(auto &entity : entities) {
    entity->update(deltaTime);
  }

  playerCORDS->text->setString(std::to_string(player->sprite->getPosition().x) + ", " + std::to_string(player->sprite->getPosition().y));
  console->text->setString("Window: " + std::to_string(WINDOW_W) + "x" + std::to_string(WINDOW_H) + "\nTotal entities: " + std::to_string(entities.size()) + "\nTotal UI elements: " + std::to_string(ui.size()) + "\nFPS: " + std::to_string(calculatedFPS));

}
