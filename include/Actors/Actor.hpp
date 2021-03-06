// COPYRIGHT (c) 2016 Andre Paulos
//
// BSD ISC License
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all cpoies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#ifndef   ACTOR_HPP_
# define  ACTOR_HPP_

#include  <SFML/Graphics.hpp>

namespace actor {
  using Texture = sf::Texture;
  using Sprite = sf::Sprite;
  using Vector2i = sf::Vector2i;
  enum SpriteSize {
    Start,
    Middle,
    Over
  };

  class IActor {
    public:
      virtual ~IActor(void) {};
      virtual void FireCommand(void) = 0;
      virtual void MoveRightCommand(void) = 0;
      virtual void MoveLeftCommand(void) = 0;
      virtual void UpdateSprite(void) = 0;
      const Sprite& getSprite(void) { return this->_sprite; };
      void setPosition(const int x, const int y) { this->_sprite.setPosition(x, y); };
      void setPosition(void) { this->_sprite.setPosition(this->_x, this->_y); };
    protected:
      int _x;
      int _y;
      int _xMax;
      SpriteSize    _currentSize;
      int      _size[3] = {
        0,
        104,
        208
      };
      Texture       _texture;
      Sprite        _sprite;
  };
}

#endif // ACTOR_HPP_
