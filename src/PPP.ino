/* -*- mode: c++ -*-
 * PPP -- Perpetual Parenting Platform, a game for two.
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-Macros.h>

enum {
  BABY_JUMP,
  BABY_POOP,
  BABY_PAUSE,
  BABY_CHEER,

  PARENT_JUMP,
  PARENT_DRINK,
  PARENT_PAUSE,
  PARENT_FEED,
};

#define P(action) M(PARENT_ ## action)
#define B(action) M(BABY_ ## action)

const Key keymaps[][ROWS][COLS] PROGMEM = {
  [0] = KEYMAP_STACKED (
       XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

      ,P(PAUSE) ,XXX ,P(DRINK) ,P(JUMP)
      ,P(FEED)

      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
           ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

      ,B(JUMP) ,B(POOP) ,XXX ,B(PAUSE)
      ,B(CHEER)
  ),
};

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  return MACRO_NONE;
}

void setup() {
  Serial.begin(9600);

  Kaleidoscope.setup();

  Kaleidoscope.use(&LEDControl,
                   &Macros);
}

void loop() {
  Kaleidoscope.loop();
}
