/*
 * Rect.h
 *
 *  Created on: Jan 7, 2017
 *      Author: rlam1
 */

#ifndef UTIL_MATH_RECT_H_
#define UTIL_MATH_RECT_H_

#include "Math/Vec2D.h"

namespace RL {
namespace Math {

template<class T>
class Vec2D;

template<class T>
class Rect {
public:
    Vec2D<T> position;

    Rect() {
    }
    Rect(Vec2D<T> const& MyPosition, Vec2D<T> const& MySize) :
            position(MyPosition), WH(MySize) {
    }
    Rect(const Rect<T> &other) :
            position(other.position), WH(other.GetSize()) {
    }

    const Vec2D<T> GetCenter() const {
        T x, y;

        x = (position.x + WH.x) / T(2);
        y = (position.y + WH.y) / T(2);

        return Vec2D<T>(x, y);
    }

    const Vec2D<T> GetSize() const {
        return WH;
    }

    bool Intersects(const Rect<T>& other) const { // https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
        Vec2D<T> aPos = position;
        Vec2D<T> aSize = WH;
        Vec2D<T> bPos = other.position;
        Vec2D<T> bSize = other.GetSize();

        if (aPos.x < bPos.x + bSize.x && aPos.x + aSize.x > bPos.x && aPos.y < bPos.y + bSize.y && aPos.y + aSize.y > bPos.y) {
            return true; // Collision detected
        }

        return false; // no collision
    }

private:
    Vec2D<T> WH;
};

} /* namespace Math */
} /* namespace RL */

#endif /* UTIL_MATH_RECT_H_ */
