#pragma once

#include <3ds.h>     // ctrulib libraries

#include <time.h>    // Time since epoch used as seed
#include <stdlib.h>  // Didn't need last time for some reason
#include <iostream>
#include <string>

// ANSI escape codes, use as you like, they work in most consoles
const std::string RED       = "\x1b[41;31m";
const std::string GREEN     = "\x1b[42;32m";
const std::string YELLOW    = "\x1b[43;33m";
const std::string BLUE      = "\x1b[44;34m";
const std::string MAGENTA   = "\x1b[45;35m";
const std::string CYAN      = "\x1b[46;36m";
const std::string CLEAR     = "\x1b[0m";

const u8 TWIDTH = 50;
const u8 BWIDTH = 40;
const u8 HEIGHT = 30;

u8 getRand(u8 num);

void printToConsole(u8 x, u8 y, std::string color, std::string sentence = " ");

void drawBackground(u8 width, u8 height, std::string color);
