#pragma once

namespace bvu
{
    template <typename T> struct vec2;
    template <typename T> struct vec3;
    template <typename T> struct vec4;

    typedef vec2<r64> vec2d;
    typedef vec2<r32> vec2f;
    typedef vec2<i32> vec2i;

    typedef vec3<r64> vec3d;
    typedef vec3<r32> vec3f;
    typedef vec3<i32> vec3i;

    typedef vec4<r64> vec4d;
    typedef vec4<r32> vec4f;
    typedef vec4<i32> vec4i;
}

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "funct_vec.h"
