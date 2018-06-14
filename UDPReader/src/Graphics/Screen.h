/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include "Util/Math/Vec2D.h"

#include <string>
#include <algorithm>

#include <Poco/Exception.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

namespace RL {
namespace Graphics {

constexpr int screenW = 800;
constexpr int screenH = 480;

/* Screen
 * ----------------------------------------------
 * Class wrapper around an ALLEGRO_SCREEN and any
 * other Allegro system that is directly part of it.
 *
 * Currently this class holds the real screen and a
 * virtual, internal one where all the real drawing
 * is made. All drawing commands are routed to the
 * virtual screen at all times. A call to flipScreen
 * is the only way to present the buffer to the real
 * screen attached to the display.*/
class Screen {
public:
    Screen();
    virtual ~Screen();

    /* WORK IN PROGRESS!
     * Eventually this function will accept a generic
     * object that contains information on how to
     * draw itself. Hence the name of the function.
     * Each object will be a drawing command.*/
    void processCommands(RL::Math::Vec2D<float> pos, const std::string &value) const;

    /* Draws whatever is currently present in the
     * virtual screen to the actual display.
     *
     * Clears the display buffer and the virtual
     * screen (in that order) after the image is
     * presented in the display.*/
    void flipScreen() const;

    /* Restarts the display in the opposite video mode
     * from the last one selected.
     * */
    void toggleFullscreenMode();

private:
    void calculateScreenScalingFactor();

    ALLEGRO_DISPLAY *display;
    ALLEGRO_BITMAP *screen;
    ALLEGRO_FONT *systemFont;

    bool fullscreen;

    double scaleW;
    double scaleH;
    double scaleX;
    double scaleY;
};

POCO_DECLARE_EXCEPTION(/**/,GraphicsSystemNotAvailableException,
        Poco::Exception);

} /* namespace Graphics */
} /* namespace RL */

#endif /* GRAPHICS_SCREEN_H_ */
