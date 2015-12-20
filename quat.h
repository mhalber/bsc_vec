#pragma once

namespace bvu
{
    template <typename T> struct quat;

    typedef quat<double> quatd;
    typedef quat<float>  quatf;
}

#include "quaternion.h"
#include "funct_quat.h"
