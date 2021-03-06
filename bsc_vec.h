
// basic vector utilities v0.1
// by Maciej Halber

// This is a small and simple library for basic vector operation, hence the inventive name of basic vector utilities

// It implements 2d, 3d and 4d vector and matrix types, alongside with quaternions.
// Most of the functions can be found in bvu_impl/funct_mat.h, bvu_impl/funct_vec.h and bvu_impl/funct_quat.h, and hopefully are pretty
// self-explanatory. Besides standard inverse transpose, it also has implementations of useful glu functions ( https://en.wikipedia.org/wiki/OpenGL_Utility_Library )

// This code is in public domain. I'd appreciate contribution, but none is required.
// This project has been written for educational purposes, and because I wanted to have my own library for vectors and matrices. It is
// heavily inspired by glm( http://glm.g-truc.net/0.9.7/index.html ) in terms of overall api design.
// In its current version it is not battle hardened and most likely contains many bugs.
// Feel free to contact me with any comments or suggestions for improvement.

#include "bsc_vec_impl/common.h"
#include "bsc_vec_impl/vec.h"
#include "bsc_vec_impl/mat.h"
#include "bsc_vec_impl/quat.h"
#include "bsc_vec_impl/funct_debug.h"
