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

#include <iostream>

#include "Player.hpp"
#include "Settings.hpp"

using namespace actor;

Player::Player(
  const int x,
  const int y,
  const int xMax,
  model::Model const &model) : _model(model) {
  this->_x = x;
  this->_y = y - 200;
  this->_sprite.setTexture(this->_model.getTexture());
  this->_xMax = (int)((unsigned int)xMax - this->_model.getTexture().getSize().x);
  this->_sprite.setPosition(x, this->_y);
}

Player::~Player(void) {
}

void Player::FireCommand() {
  std::cout << "Fire !!" << std::endl;
};

void Player::MoveRightCommand() {
  if ((this->_x + 15 < this->_xMax)) {
    this->_x += 15;
  }
  else {
    this->_x = this->_xMax;
  }
  this->setPosition();
};

void Player::MoveLeftCommand() {
  if ((this->_x - 10 >= 0)) {
    this->_x -= 10;
  }
  else {
    this->_x = 0;
  }
  this->setPosition();
};

void Player::UpdateSprite(void) {

}
