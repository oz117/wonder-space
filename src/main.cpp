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

#include  <iostream>
#include  <vector>
#include  <fstream>

#include "window.hpp"
#include  "Settings.hpp"

using sfEvent = sf::Event;

std::string getConfigFilePath() {
  static const std::vector<std::string> files = {"/tmp/wonder.settings",
                                               "./wonder.settings"};

  for (auto file : files) {
      if (std::ifstream(file).good()) {
          return file;
      }
  }
  return std::string("");
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char const *argv[]) {
  std::string configFile;
  bool            isRunning;

  configFile = getConfigFilePath();
  // For now I will only do a simple check and exit if no file is found.
  // Later on I will probably create the config file with a default one.
  if (configFile == "") {
    std::cerr << "Config file not found."
              << "Create one in the current directory or /tmp/"
              << std::endl;
  }
  std::cout << "Found config file: " << configFile << std::endl;
  Settings *settings = Settings::getInstance(configFile);
  if (settings == nullptr)
    return 1;

  window::Window  mainWindow;
  isRunning = true;
  while (isRunning) {
    sfEvent event;
    // FIXME: This is ugly. Handle events in a proper class or in window class.
    while (mainWindow.getWindow().pollEvent(event)) {
      if (event.type == sfEvent::Closed){
        isRunning = false;
        mainWindow.getWindow().close();
      }
    }
    // Intercept inputs and update screen
    mainWindow.updateScreen();
  }
  return 0;
}
