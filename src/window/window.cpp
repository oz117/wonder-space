// COPYRIGHT (c) 2016 Andre Paulos
//
// BSD ISC License
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

// USing this for lols as of feature/create_main_window
// Will Probably remove thie later. Will see :)
#include  <iostream>
#include  <vector>

#include  "Window.hpp"

using namespace window;
using vec2f = sf::Vector2f;

// Creates the window by setting it s title and size
// Also setting up a few other things just to improve play experience
// FIXME: Add an icon to the app
// FIXME: All the cast are temporary. It is only for now and for the tests
Window::Window(event::InputHandler const &inputHandler, Settings const &settings)
  : _actorModel(ActorAsset) {
  auto width = (unsigned int) settings.getWidth();
  auto height = (unsigned int) settings.getHeight();

  this->_window.create(sf::VideoMode(width, height), settings.getTitle());
  this->_window.setVerticalSyncEnabled(true);
  this->_window.setKeyRepeatEnabled(true);
  this->_window.setFramerateLimit(144);
  this->_isRunning = true;
  this->_inputHandler = inputHandler;
  this->_enemyModel[0] = new model::Model(EnemyRow1);
  this->_enemyModel[1] = new model::Model(EnemyRow2);
  this->_enemyModel[2] = new model::Model(EnemyRow3);
  this->_actor
    = std::unique_ptr<actor::Player>(
      new actor::Player(0, (int)height, (int)width, this->_actorModel)
    );
  for(size_t i = 0; i < 3; i++)
  {
    auto y = 160 * (int)i;

    for(auto j = 0; j < 11; j++) {
        this->_enemy[i][j]
          = std::unique_ptr<actor::Enemy>(
            new actor::Enemy(j * 104, y, (int)width, *(this->_enemyModel.at(i)))
          );
    }
  }
}

Window::~Window(void) {
  std::for_each(
    this->_enemyModel.begin(),
    this->_enemyModel.begin(),
    [](model::Model *model) { delete model; }
  );
}

bool Window::getIsRunning() const noexcept {
  return this->_isRunning;
}

const sfWindow &Window::getWindow(void) const noexcept {
  return this->_window;
}

bool Window::updateScreen(void) noexcept {
  sfTime elapsed = this->_clock.getElapsedTime();

  this->_window.clear();
  this->_window.draw(this->_actor->getSprite());
  for(auto i = 0; i < 3; i++)
  {
    for(auto j = 0; j < 11; j++) {
      if (elapsed.asSeconds() >= 0.4) {
        this->_enemy[i][j]->UpdateSprite();
        this->_clock.restart();
      }
      this->_window.draw(this->_enemy[i][j]->getSprite());
    }
  }
  this->_window.display();

  return true;
}

void Window::pollEvents(void) noexcept {
  sfEvent event;

  while (this->_window.pollEvent(event)) {
    if (event.type == sfEvent::Closed) {
      this->_isRunning = false;
      this->_window.close();
    }
    else if (event.type == sfEvent::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        this->_isRunning = false;
        this->_window.close();
      }
      else if (event.key.code == sf::Keyboard::Space) {
          this->_actor->FireCommand();
      }
      else if (event.key.code == sf::Keyboard::Right) {
          this->_actor->MoveRightCommand();
      }
      else if (event.key.code == sf::Keyboard::Left) {
          this->_actor->MoveLeftCommand();
      }
    }
  }
}
