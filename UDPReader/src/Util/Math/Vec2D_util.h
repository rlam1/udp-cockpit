/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef UTIL_MATH_VEC2D_UTIL_H_
#define UTIL_MATH_VEC2D_UTIL_H_

#include "Vec2D.h"

namespace RL {
namespace Math {

//Product functions
template<class T> T DotProduct(const Vec2D<T>& a, const Vec2D<T>& b) {
    return ((a.x * b.x) + (a.y * b.y));
}
template<class T> T CrossProduct(const Vec2D<T>& a, const Vec2D<T>& b) {
    return ((a.x * b.y) - (a.y * b.x));
}

//Returns the length of the vector from the origin.
template<class T> T EuclideanNorm(const Vec2D<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

//Return the unit vector of the input
template<class T> Vec2D<T> Normal(const Vec2D<T>& v) {
    T magnitude = EuclideanNorm<T>(v);
    return Vec2D<T>(v.x / magnitude, v.y / magnitude);
}

//Return a vector perpendicular to the left.
template<class T> Vec2D<T> Perpendicular(const Vec2D<T>& v) {
    return Vec2D<T>(v.y, -v.x);
}

//Return true if two line segments intersect.
template<class T> bool Intersect(const Vec2D<T>& aa, const Vec2D<T>& ab,
        const Vec2D<T>& ba, const Vec2D<T>& bb) {
    auto p = aa;
    auto r = ab - aa;
    auto q = ba;
    auto s = bb - ba;

    T t = CrossProduct<T>((q - p), s) / CrossProduct<T>(r, s);
    T u = CrossProduct<T>((q - p), r) / CrossProduct<T>(r, s);

    return (0.0 <= t && t <= 1.0) && (0.0 <= u && u <= 1.0);
}

//Return the point where two lines intersect.
template<class T> Vec2D<T> GetIntersect(const Vec2D<T>& aa, const Vec2D<T>& ab,
        const Vec2D<T>& ba, const Vec2D<T>& bb) {
    T pX =
            (aa.x * ab.y - aa.y * ab.x) * (ba.x - bb.x) - (ba.x * bb.y - ba.y * bb.x) * (aa.x - ab.x);
    T pY =
            (aa.x * ab.y - aa.y * ab.x) * (ba.y - bb.y) - (ba.x * bb.y - ba.y * bb.x) * (aa.y - ab.y);
    T denominator =
            (aa.x - ab.x) * (ba.y - bb.y) - (aa.y - ab.y) * (ba.x - bb.x);

    return Vec2D<T>(pX / denominator, pY / denominator);
}

} /* namespace Math */
} /* namespace RL */

#endif /* UTIL_MATH_VEC2D_UTIL_H_ */
