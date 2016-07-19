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

#include  "window.hpp"
#include  "Settings.hpp"

using namespace window;
using vec2f = sf::Vector2f;

// Creates the window by setting it s title and size
// Also setting up a few other things just to improve play experience
// FIXME: Add an icon to the app
// FIXME: All the cast are temporary. It is only for now and for the tests
Window::Window(void) {
  Settings *settings = Settings::getInstance();
  unsigned int width = (unsigned int) settings->getWidth();
  unsigned int height = (unsigned int) settings->getHeight();

  this->_window.create(sf::VideoMode(width, height), settings->getTitle());
  this->_window.setVerticalSyncEnabled(true);
  this->_window.setKeyRepeatEnabled(true);
  this->_rectangleForLols.setSize(vec2f{(float) width, (float) height});
  this->_rectangleForLols.setFillColor(sf::Color::Red);
}

Window::~Window(void) {
}

sfWindow &Window::getWindow(void) noexcept {
  return this->_window;
}

bool Window::updateScreen(void) noexcept{
  this->_window.clear();
  this->_window.draw(this->_rectangleForLols);
  this->_window.display();

  return true;
}
