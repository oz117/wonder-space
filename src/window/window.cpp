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
#include  "Settings.hpp"

using namespace window;
using vec2f = sf::Vector2f;

// Creates the window by setting it s title and size
// Also setting up a few other things just to improve play experience
// FIXME: Add an icon to the app
// FIXME: All the cast are temporary. It is only for now and for the tests
Window::Window(event::InputHandler &inputHandler) {
  Settings *settings = Settings::getInstance();
  unsigned int width = (unsigned int) settings->getWidth();
  unsigned int height = (unsigned int) settings->getHeight();

  this->_window.create(sf::VideoMode(width, height), settings->getTitle());
  this->_window.setVerticalSyncEnabled(true);
  this->_window.setKeyRepeatEnabled(true);
  this->_isRunning = true;
  this->_inputHandler = inputHandler;
  this->_actor = new actor::Player(0, (int)height, (int)width);
}

Window::~Window(void) {
}

bool Window::getIsRunning() noexcept {
  return this->_isRunning;
}

sfWindow &Window::getWindow(void) noexcept {
  return this->_window;
}

bool Window::updateScreen(void) noexcept{
  this->_window.clear();
  this->_window.draw(this->_actor->getSprite());
  this->_window.display();

  return true;
}

void Window::pollEvents(void) noexcept {
  sfEvent event;

  while (this->_window.pollEvent(event)) {
    if (event.type == sfEvent::Closed){
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
