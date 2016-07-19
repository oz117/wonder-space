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

#include  <fstream>
#include  <iostream>

#include  "Settings.hpp"

// @description Using singleton parttern.
// @param std::string path to configuration file
// @return Settings* instance on object if success.
// nullptr if config file is malformed.
Settings *Settings::getInstance(const sstring& path) {
  static Settings *instance = nullptr;

  if (instance == nullptr) {
    instance = new Settings(path);
    if (instance->_errors != 0 || instance->_readLines == 0) {
      // This will be replaced y a logger later on :)
      std::cerr << "Configuration file is broken" << std::endl;
      instance = nullptr;
    }
  }
  return instance;
}

Settings::Settings(const sstring& path): _errors(0), _readLines(0) {
  loadFile(path);
}

Settings::~Settings(void) {}

// @description Read the configuration file line by line
// @param std::string path to configuration file
void Settings::loadFile(const sstring& path) {
  std::ifstream file(path);
  sstring       line;

  while (!file.eof()) {
    std::getline(file, line);
    if (line.size() != 0)
      setConfiguration(line);
    line.clear();
  }
}

// @description Inits the different parts of the Configuration
// @param std::string path to configuration file
// Check of file existence in main file
void Settings::setConfiguration(const sstring& line) noexcept {
  size_t  pos;

  this->_readLines++;
  pos = line.find("= ") + 2;
  if (!line.compare(0, 5, "title"))
    this->_title = line.substr(pos);
  else if (!line.compare(0, 10, "resolution"))
    extractResolution(line.substr(pos));
  else
    this->_errors = 1;
}

// @description Parses the resolution
// @param std::string line containing the resolution
// @return int 0 if success. Test object->_errors for errors
int Settings::extractResolution(const sstring& line) noexcept {
  size_t  pos;

  if ((pos = line.find(" ")) == sstring::npos)
    return (this->_errors = 1);
  try {
    this->_height = stoi(line.substr(0, pos));
    this->_width = stoi(line.substr(pos + 1));
  } catch (std::exception e) {
    return (this->_errors = 1);
  }
  return (0);
}

const std::string&  Settings::getTitle(void) const noexcept {
  return this->_title;
}

int   Settings::getWidth(void) const noexcept {
  return this->_width;
}

int   Settings::getHeight(void) const noexcept {
  return this->_height;
}
