#pragma once

namespace bsc
{
    template <typename T> struct mat2;
    template <typename T> struct mat3;
    template <typename T> struct mat4;

    typedef mat2<r64> mat2d;
    typedef mat2<r32> mat2f;
    typedef mat2<i32> mat2i;

    typedef mat3<r64> mat3d;
    typedef mat3<r32> mat3f;
    typedef mat3<i32> mat3i;

    typedef mat4<r64> mat4d;
    typedef mat4<r32> mat4f;
    typedef mat4<i32> mat4i;
}

#include "mat2.h"
#include "mat3.h"
#include "mat4.h"

#include "funct_mat.h"
