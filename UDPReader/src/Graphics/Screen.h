/*
 * Screen.h
 *
 *  Created on: Jan 7, 2017
 *      Author: rlam1
 */

#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include "Util/Math/Vec2D.h"

#include <string>

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
 * other Allegro system that is directly part of it */
class Screen {
public:
    Screen();
    virtual ~Screen();

    void processCommands(RL::Math::Vec2D<float> pos, const std::string &value);
    void flipScreen();

private:
    void calculateScreenScalingFactor();

    ALLEGRO_DISPLAY *display;
    ALLEGRO_BITMAP *screen;
    ALLEGRO_FONT *systemFont;

    double scaleW;
    double scaleH;
    double scaleX;
    double scaleY;
};

POCO_DECLARE_EXCEPTION(, GraphicsSystemNotAvailableException, Poco::Exception);

} /* namespace Graphics */
} /* namespace RL */

#endif /* GRAPHICS_SCREEN_H_ */
