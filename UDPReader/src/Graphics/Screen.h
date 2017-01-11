/*
 * Screen.h
 *
 *  Created on: Jan 7, 2017
 *      Author: rlam1
 */

#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

namespace RL {
namespace Graphics {

/* Screen
 * ----------------------------------------------
 * Class wrapper around an ALLEGRO_SCREEN and any
 * other Allegro system that is directly part of it */
class Screen {
public:
    Screen();
    virtual ~Screen();
};

} /* namespace Graphics */
} /* namespace RL */

#endif /* GRAPHICS_SCREEN_H_ */
