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

#include "Enemy.hpp"
#include "Settings.hpp"

using namespace actor;

Enemy::Enemy(
  const int x,
  const int y,
  const int xMax,
  model::Model& model) : _model(model) {
  sf::Vector2i position(0, 0);
  sf::Vector2i size(104, 64);

  this->_currentSize = SpriteSize::Start;
  this->_x = x;
  this->_y = y;
  this->_xMax = xMax;
  this->_rect.left = position.x;
  this->_rect.top = position.y;
  this->_rect.width = size.x;
  this->_rect.height = size.y;
  this->_sprite.setTexture(this->_model.getTexture());
  this->_sprite.setTextureRect(this->_rect);
  this->_xMax = (int)((unsigned int)xMax - 104);
  this->setPosition();
  this->_moveFunction = [=](void) {
    this->MoveRightCommand();
  };
}

Enemy::~Enemy(void) {

}

void Enemy::FireCommand() {
  std::cout << "Fire !!" << std::endl;
};

void Enemy::MoveRightCommand(void) {
  if ((this->_x + 10 < this->_xMax)) {
    this->_x += 10;
  }
  else {
    this->_x = this->_xMax;
    this->_y += 84;
    this->_moveFunction = [=](void) {
      this->MoveLeftCommand();
    };
  }
  this->setPosition();
};

void Enemy::MoveLeftCommand() {
  if ((this->_x - 10 >= 0)) {
    this->_x -= 10;
  }
  else {
    this->_x = 0;
    this->_y += 84;
    this->_moveFunction = [=](void) {
      this->MoveRightCommand();
    };
  }
  this->setPosition();
};

void Enemy::UpdateSprite(void) {
  if (this->_currentSize == SpriteSize::Over){
    return;
  }
  this->_currentSize =
    this->_currentSize == SpriteSize::Start ? SpriteSize::Middle : SpriteSize::Start;
  this->_rect.left = this->_size[this->_currentSize];
  this->_sprite.setTextureRect(this->_rect);
  this->_moveFunction();
}
