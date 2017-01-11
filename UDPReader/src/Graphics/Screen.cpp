/*
 * Screen.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: rlam1
 */

#include "Graphics/Screen.h"

#include <typeinfo>

namespace RL {
namespace Graphics {

Screen::Screen() {
    display = nullptr;
    screen = nullptr;
    systemFont = nullptr;
    scaleW = 1.0;
    scaleH = 1.0;
    scaleX = 1.0;
    scaleY = 1.0;

    if (al_is_system_installed() != true) {
        throw GraphicsSystemNotAvailableException("Allegro is not initialized");
    }

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    display = al_create_display(screenW, screenH);

    screen = al_create_bitmap(screenW, screenH);

    systemFont = al_create_builtin_font();

    if (display == nullptr || screen == nullptr || systemFont == nullptr) {
        throw Poco::ApplicationException("Invalid graphics state encountered");
    }

    calculateScreenScalingFactor();

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    al_set_target_bitmap(screen);
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

Screen::~Screen() {
    al_destroy_display(display);
    al_destroy_bitmap(screen);
    al_destroy_font(systemFont);
}

void Screen::processCommands(RL::Math::Vec2D<float> pos,
        const std::string& value) {
    al_draw_text(systemFont, al_map_rgb(255, 255, 255), pos.x, pos.y, 0,
            value.c_str());
}

void Screen::flipScreen() {
    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(screen, 0, 0, screenW, screenH, scaleX, scaleY,
            scaleW, scaleH, 0);
    al_flip_display();

    al_set_target_bitmap(screen);
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Screen::calculateScreenScalingFactor() {
    int displayW = al_get_display_width(display);
    int displayH = al_get_display_height(display);
    // calculate scaling factor
    double sx = (double) displayW / (double) screenW;
    double sy = (double) displayH / (double) screenH;
    double scale = (std::min)(sx, sy); // minwindef.h interferes with std::min and std::max because of a macro definition :/
    // calculate how much the buffer should be scaled
    scaleW = (double) screenW * scale;
    scaleH = (double) screenH * scale;
    scaleX = ((double) displayW - scaleW) / 2.0;
    scaleY = ((double) displayH - scaleH) / 2.0;
}

POCO_IMPLEMENT_EXCEPTION(GraphicsSystemNotAvailableException, Poco::Exception,
        "RL::Graphics::Screen Error");

} /* namespace Graphics */
} /* namespace RL */
