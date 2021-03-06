#ifndef MATH_VEC3_H
#define MATH_VEC3_H


#include <iostream>
#include <cmath>
#include <math/constants.h>
#include <math/vecmath.h>


template <typename T>
struct vec3 {
    T x, y, z;
    vec3() : x(0), y(0), z(0) {}
    vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    vec3(T *ptr): x(ptr[0]), y(ptr[1]), z(ptr[2]) {}
    vec3(vec3<T> b, vec3<T> e) : x(e.x - b.x), y(e.y - b.y), z(e.z - b.z) {};
    T dot(const vec3<T> &v) const;
    vec3<T> crs(const vec3<T> &v) const;
    T sdot(const vec3<T> &v) const;
    T sqlen() const;
    void resize(const float s);
    void rotate(const float s, const float t=0, const float a=0);
    void floor(const float s);
    operator vec3f();
};

typedef vec3<long long int> vec3ll;
typedef vec3<double> vec3d;

template <class T>
vec3<T> operator+(const vec3<T> &a, const vec3<T> &b) {
    return vec3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}

template <class T>
vec3<T> operator-(const vec3<T> &a, const vec3<T> &b) {
    return vec3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template <class T>
vec3<T> operator*(T x, const vec3<T> &v) {
    return vec3<T>(x * v.x, x * v.y, x * v.z);
}

template <class T>
vec3<T> operator/(const vec3<T> &v, T x) {
    return vec3<T>(v.x / x, v.y / x, v.z / x);
}

template <class T>
bool operator ==(const vec3<T> one, const vec3<T> second) {
    return one.x == second.x and one.y == second.y and one.z == second.z;
}
template <class T>
T vec3<T>::dot(const vec3<T> &v) const {
    return x * v.x + y * v.y + z * v.z;
}

template <class T>
vec3<T> vec3<T>::crs(const vec3<T> &v) const {
    return vec3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

template <class T>
void vec3<T>::floor(const float s) {
    x /= s;
    y /= s;
    z /= s;
    x -= x / 1000;
    y -= y / 1000;
    z -= z / 1000;
}
/*
template <class T>
int vec3<T>::sdot(const vec3<T> &v) const {
    return sgn(dot(v));
}
*/
template <class T>
T vec3<T>::sqlen() const {
    return x * x + y * y + z * z;
}

template <class T>

void vec3<T>::resize(const float s) {
    float vlen = sqrt(this->sqlen());
    x /= vlen;
    y /= vlen;
    z /= vlen;
    (*this) = s * (*this);
}
template <class T>
void vec3<T>::rotate(const float s, const float t, const float a) { // xz xy yz
    T new_x, new_y, new_z;
    float cosf, sinf;
    if (s != 0) {
    cosf = cos(std::min((float)(2 * M_PI - s), s));
    if (-M_PI < 2 * s and 2 * s <= M_PI)
        sinf = sin(s);
    else if (2 * s > 3 * M_PI)
        sinf = -sin(2 * M_PI - s);
    else
        sinf = -sin(s - M_PI);
    new_x = cosf * x - sinf * z;
    new_z = sinf * x + cosf * z;
    x = new_x;
    z = new_z;
    } if (t != 0) {
        cosf = cos(std::min((2 * M_PI - fabs(t)), fabs(t)));
        if (-M_PI < 2 * t and 2 * t <= M_PI)
            sinf = sin(t);
        else if (2 * t > 3 * M_PI)
            sinf = -sin(2 * M_PI - t);
        else
            sinf = -sin(t - M_PI);
        new_x = cosf * x - sinf * y;
        new_y = sinf * x + cosf * y;
        x = new_x;
        y = new_y;
    } if (a != 0) {
        cosf = cos(std::min((2 * M_PI - fabs(a)), fabs(a)));
        if (-M_PI < 2 * a and 2 * a <= M_PI)
            sinf = sin(a);
        else if (2 * a > 3 * M_PI)
            sinf = -sin(2 * M_PI - a);
        else
            sinf = -sin(a - M_PI);
        new_y = cosf * y - sinf * z;
        new_z = sinf * y + cosf * z;
        y = new_y;
        z = new_z;

    }
}

template <class T>
std::ostream &operator<<(std::ostream &out, const vec3<T> &v) {
    return out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


#endif // MATH_VEC3_H

