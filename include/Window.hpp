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

#ifndef   WINDOW_HPP_
# define  WINDOW_HPP_

#include  <SFML/Graphics.hpp>
#include  "InputHandler.hpp"
#include  "Player.hpp"
#include  "Enemy.hpp"

namespace window {
  // An Alias to make things easier
  using sfWindow = sf::RenderWindow;
  using sfRectangle = sf::RectangleShape;
  using sfEvent = sf::Event;
  using sfClock = sf::Clock;
  using sfTime = sf::Time;

  class Window {
    public:
      Window(event::InputHandler &inputHandler);
      ~Window(void);
      bool getIsRunning(void) noexcept;
      sfWindow &getWindow(void) noexcept;
      bool updateScreen(void) noexcept;
      void pollEvents(void) noexcept;
    private:
      sfWindow      _window;
      sfClock       _clock;
      bool          _isRunning;
      event::InputHandler _inputHandler;
      actor::IActor       *_actor;
      actor::IActor       *_enemy[3][11];
      model::Model        *_actorModel;
      model::Model        *_enemyModel[3];
  };
}

#endif // WINDOW_HPP_
