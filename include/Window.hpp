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
#include  <array>
#include  "InputHandler.hpp"
#include  "Player.hpp"
#include  "Enemy.hpp"
#include  "Settings.hpp"

namespace window {
  // An Alias to make things easier
  using sfWindow = sf::RenderWindow;
  using sfRectangle = sf::RectangleShape;
  using sfEvent = sf::Event;
  using sfClock = sf::Clock;
  using sfTime = sf::Time;

  const sstring ActorAsset =  "../assets/ship.png";
  const sstring EnemyRow1 =   "../assets/row_1.png";
  const sstring EnemyRow2 =   "../assets/row_2.png";
  const sstring EnemyRow3 =   "../assets/row_3.png";

  class Window {
    public:
      Window(event::InputHandler const &inputHandler, Settings const &settings);
      ~Window(void);
      const sfWindow &getWindow(void) const noexcept;
      bool getIsRunning(void) const noexcept;
      bool updateScreen(void) noexcept;
      void pollEvents(void) noexcept;
    private:
      sfWindow      _window;
      sfClock       _clock;
      bool          _isRunning;
      event::InputHandler _inputHandler;
      std::unique_ptr<actor::IActor>  _actor;
      std::unique_ptr<actor::IActor>  _enemy[3][11];
      model::Model                    _actorModel;
      std::array<model::Model*, 3>    _enemyModel;
  };
}

#endif // WINDOW_HPP_
