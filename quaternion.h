#pragma once

// TODO : conversions!
// TODO : rotation from euler angles / angle axis
namespace bvu
{
    template <typename T> struct quat;

    typedef quat<double> quatd;
    typedef quat<float>  quatf;
}

#include "quat.h"
#include "funct_quaternion.h"
