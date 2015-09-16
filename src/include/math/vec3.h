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
    vec3(vec3<T> b, vec3<T> e) : x(e.x - b.x), y(e.y - b.y), z(e.z - b.z) {};
    T dot(const vec3<T> &v) const;
    vec3<T> crs(const vec3<T> &v) const;
    T sdot(const vec3<T> &v) const;
    T sqlen() const;
    void resize(const float s);
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
T vec3<T>::dot(const vec3<T> &v) const {
    return x * v.x + y * v.y + z * v.z;
}

template <class T>
vec3<T> vec3<T>::crs(const vec3<T> &v) const {
    return vec3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
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
std::ostream &operator<<(std::ostream &out, const vec3<T> &v) {
    return out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


#endif // MATH_VEC3_H

