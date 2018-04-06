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
//

#ifndef   PLAYER_HPP_
# define  PLAYER_HPP_

#include "Actor.hpp"
#include "Model.hpp"

namespace actor {
  using IntRect = sf::IntRect;

  class Player : public IActor {
    public:
      Player(const int x, const int y, const int xMax, model::Model& model);
      ~Player(void);
      void FireCommand(void);
      void MoveRightCommand(void);
      void MoveLeftCommand(void);
      void UpdateSprite(void);
    private:
      model::Model &_model;
      IntRect      _rect;
  };
}

#endif // PLAYER_HPP_
