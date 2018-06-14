/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef UTIL_MATH_VEC2D_H_
#define UTIL_MATH_VEC2D_H_

#include <tuple>
//#include <cfloat>
//#include <climits>

namespace RL {
namespace Math {

template<class T>
class Vec2D {
public:
    T x;
    T y;

    Vec2D() :
            x(T(0)), y(T(0)) {
    }
    Vec2D(T const& vx, T const& vy) :
            x(vx), y(vy) {
    }

    Vec2D& operator+=(const Vec2D& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vec2D& operator-=(const Vec2D& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    Vec2D& operator*=(const Vec2D& v) {
        x *= v.x;
        y *= v.y;
        return *this;
    }
    Vec2D& operator/=(const Vec2D& v) {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    //Check if the Vectors have the same values (uses pairwise comparison of `std::tuple` on the x,y values of L and R.
    friend bool operator==(const Vec2D& L, const Vec2D& R) {
        return std::tie(L.x, L.y) == std::tie(R.x, R.y);
    }
    friend bool operator!=(const Vec2D& L, const Vec2D& R) {
        return !(L == R);
    }

    //Check if the Vectors have the same values (uses pairwise comparison of `std::tuple` on the x,y values of L and R.
    friend bool operator<(const Vec2D& L, const Vec2D& R) {
        return std::tie(L.x, L.y) < std::tie(R.x, R.y);
    }
    friend bool operator>=(const Vec2D& L, const Vec2D& R) {
        return !(L < R);
    }
    friend bool operator>(const Vec2D& L, const Vec2D& R) {
        return R < L;
    }
    friend bool operator<=(const Vec2D& L, const Vec2D& R) {
        return !(R < L);
    }

    //Negate both the x and y values.
    Vec2D operator-() const {
        return Vec2D(-x, -y);
    }

    //Apply scalar operations.
    Vec2D& operator*=(T const& s) {
        x *= s;
        y *= s;
        return *this;
    }
    Vec2D& operator/=(T const& s) {
        x /= s;
        y /= s;
        return *this;
    }
};

template<class T> Vec2D<T> operator+(const Vec2D<T>& L, const Vec2D<T>& R) {
    return Vec2D<T>(L) += R;
}
template<class T> Vec2D<T> operator-(const Vec2D<T>& L, const Vec2D<T>& R) {
    return Vec2D<T>(L) -= R;
}
template<class T> Vec2D<T> operator*(const Vec2D<T>& L, const Vec2D<T>& R) {
    return Vec2D<T>(L) *= R;
}
template<class T> Vec2D<T> operator/(const Vec2D<T>& L, const Vec2D<T>& R) {
    return Vec2D<T>(L) /= R;
}

template<class T> Vec2D<T> operator*(const T& s, const Vec2D<T>& v) {
    return Vec2D<T>(v) *= s;
}
template<class T> Vec2D<T> operator*(const Vec2D<T>& v, const T& s) {
    return Vec2D<T>(v) *= s;
}
template<class T> Vec2D<T> operator/(const T& s, const Vec2D<T>& v) {
    return Vec2D<T>(v) /= s;
}
template<class T> Vec2D<T> operator/(const Vec2D<T>& v, const T& s) {
    return Vec2D<T>(v) /= s;
}

} /* namespace Math */
} /* namespace RL */


#endif /* UTIL_MATH_VEC2D_H_ */
