#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>

#include "bvu.h"

// TODO Tests for transformation functions
// TODO Tests for quaternions

template< typename T = float, typename F, typename G, typename ...Args>
bool CompareResults( F functionA, G functionB, Args&&... arguments )
{
    // get results of both functions
    auto result1 = functionA( std::forward<Args>(arguments)... );
    auto result2 = functionB( std::forward<Args>(arguments)... );

    // make sure that both functions return results of same size
    assert( sizeof(result1) == sizeof(result2) );

    // compare the results!
    T * ptr1 = (T*)&result1;
    T * ptr2 = (T*)&result2;

    for ( int i = 0 ; i < sizeof( result1 ) / sizeof( T ) ; ++i )
    {
        T val1 = *ptr1;
        T val2 = *ptr2;
        if ( std::abs( val1 - val2 ) > 1e-3 ) { return false; }
        ptr1++;
        ptr2++;
    }

    return true;
}


glm::vec4
glmVecScalarAdd( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 + valB;
    return v2;
}

bvu::vec4f
bvuVecScalarAdd( const std::vector<float> & vals1, const float valB )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 = v1 + valB;
    return v2;
}

glm::vec4
glmVecVecAdd( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 + v2;
    return v3;
}

bvu::vec4f
bvuVecVecAdd( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bvu::vec4f v3 = v1 + v2;
    return v3;
}

glm::vec4
glmVecScalarSub( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 - valB;
    return v2;
}

bvu::vec4f
bvuVecScalarSub( const std::vector<float> & vals1, const float valB )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 = v1 - valB;
    return v2;
}

glm::vec4
glmVecVecSub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 - v2;
    return v3;
}

bvu::vec4f
bvuVecVecSub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bvu::vec4f v3 = v1 - v2;
    return v3;
}

glm::vec4
glmVecScalarMul( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 * valB;
    return v2;
}

bvu::vec4f
bvuVecScalarMul( const std::vector<float> & vals1, const float valB )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 = v1 * valB;
    return v2;
}

glm::vec4
glmVecVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 * v2;
    return v3;
}

bvu::vec4f
bvuVecVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bvu::vec4f v3 = v1 * v2;
    return v3;
}

glm::vec4
glmVecScalarDiv( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 / valB;
    return v2;
}

bvu::vec4f
bvuVecScalarDiv( const std::vector<float> & vals1, const float valB )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 = v1 / valB;
    return v2;
}

glm::vec4
glmVecVecDiv( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 / v2;
    return v3;
}

bvu::vec4f
bvuVecVecDiv( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bvu::vec4f v3 = v1 / v2;
    return v3;
}


glm::vec4
glmNormalize( const std::vector<float> & vals )
{
    glm::vec4 v ( vals[0], vals[1], vals[2], vals[3] );
    v = glm::normalize( v );
    return v;
}

bvu::vec4f
bvuNormalize( const std::vector<float> & vals )
{
    bvu::vec4f v( vals[0], vals[1], vals[2], vals[3] );
    v = bvu::normalize( v );
    return v;
}

float
glmDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = glm::dot( v1, v2 );
    return f;
}

float
bvuDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = bvu::dot( v1, v2 );
    return f;
}

float
glmNorm( const std::vector<float> & vals )
{
    glm::vec4 v( vals[0], vals[1], vals[2], vals[3] );
    float f = glm::length( v );
    return f;
}

float
bvuNorm( const std::vector<float> & vals )
{
    bvu::vec4f v ( vals[0], vals[1], vals[2], vals[3] );
    float f = bvu::norm( v );
    return f;
}

float
glmNormSq( const std::vector<float> & vals )
{
    glm::vec4 v( vals[0], vals[1], vals[2], vals[3] );
    float f = glm::length2(v);
    return f;
}

float
bvuNormSq( const std::vector<float> & vals )
{
    bvu::vec4f v ( vals[0], vals[1], vals[2], vals[3] );
    float f = bvu::normSq( v );
    return f;
}

float
glmDistance( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = glm::distance( v1, v2 );
    return f;
}

float
bvuDistance( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = bvu::distance( v1, v2 );
    return f;
}

glm::vec3
glmCross( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 v3 = glm::cross( v1, v2 );
    return v3;
}

bvu::vec3f
bvuCross( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bvu::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bvu::vec3f v3 = bvu::cross( v1, v2 );
    return v3;
}

glm::vec4
glmAbs( const std::vector<float> & vals )
{
    glm::vec4 v1 ( vals[0], vals[1], vals[2], vals[3] );
    glm::vec4 v2 = glm::abs( v1 );
    return v2;
}

bvu::vec4f
bvuAbs( const std::vector<float> & vals )
{
    bvu::vec4f v1 ( vals[0], vals[1], vals[2], vals[3] );
    bvu::vec4f v2 = bvu::abs( v1 );
    return v2;
}

glm::vec4
glmClamp( const std::vector<float> & vals )
{
    glm::vec4 v1 ( vals[0], vals[1], vals[2], vals[3] );
    glm::vec4 v2 = glm::clamp( v1, 0.0f, 1.0f );
    return v2;
}

bvu::vec4f
bvuClamp( const std::vector<float> & vals )
{
    bvu::vec4f v1 ( vals[0], vals[1], vals[2], vals[3] );
    bvu::vec4f v2 = bvu::clamp( v1, 0.0f, 1.0f );
    return v2;
}

glm::mat4 InitGLMMat4( const std::vector<float> & vals )
{
    return glm::mat4 ( vals[ 0], vals[ 1], vals[ 2], vals[ 3],
                       vals[ 4], vals[ 5], vals[ 6], vals[ 7],
                       vals[ 8], vals[ 9], vals[10], vals[11],
                       vals[12], vals[13], vals[14], vals[15] );
}

glm::mat4
glmMatMatAdd( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 + m2;
}

bvu::mat4f
bvuMatMatAdd( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::mat4f m1 ( &vals1[0] );
    bvu::mat4f m2 ( &vals2[0] );
    return m1 + m2;
}

glm::mat4
glmMatMatSub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 - m2;
}

bvu::mat4f
bvuMatMatSub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::mat4f m1 ( &vals1[0] );
    bvu::mat4f m2 ( &vals2[0] );
    return m1 - m2;
}

glm::mat4
glmMatMatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 * m2;
}

bvu::mat4f
bvuMatMatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::mat4f m1
     ( &vals1[0] );
    bvu::mat4f m2 ( &vals2[0] );
    return m1 * m2;
}

glm::mat4
glmMatInv( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::inverse(m);
}

bvu::mat4f
bvuMatInv( const std::vector<float> & vals1 )
{
    bvu::mat4f m ( &vals1[0] );
    return bvu::inverse(m);
}

glm::mat4
glmMatTranspose( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::transpose( m );
}

bvu::mat4f
bvuMatTranspose( const std::vector<float> & vals1 )
{
    bvu::mat4f m ( &vals1[0] );
    return bvu::transpose( m );
}

float
glmMatDeterminant( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::determinant(m);
}

float
bvuMatDeterminant( const std::vector<float> & vals1 )
{
    bvu::mat4f m ( &vals1[0] );
    return bvu::determinant(m);
}

glm::vec4
glmMatVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    glm::vec4 v ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return m * v;
}

bvu::vec4f
bvuMatVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::mat4f m ( &vals1[0] );
    bvu::vec4f v ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return m * v;
}

glm::quat
glmQuatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::quat q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::quat q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return q1 * q2;
}

bvu::quatf
bvuQuatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::quatf q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::quatf q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return q1 * q2;
}

glm::quat
glmQuatConjugate( const std::vector<float> & vals1 )
{
    glm::quat q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return glm::conjugate( q );
}

bvu::quatf
bvuQuatConjugate( const std::vector<float> & vals1 )
{
    bvu::quatf q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return bvu::conjugate( q );
}

glm::quat
glmQuatInverse( const std::vector<float> & vals1 )
{
    glm::quat q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return glm::inverse( q );
}

bvu::quatf
bvuQuatInverse( const std::vector<float> & vals1 )
{
    bvu::quatf q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return bvu::inverse( q );
}

float
glmQuatDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::quat q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::quat q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return glm::dot( q1, q2 );
}

float
bvuQuatDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bvu::quatf q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bvu::quatf q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return bvu::dot( q1, q2 );
}

void
RunTests()
{
    // data
    std::vector<float> data_vec3_A = { 1.0f, 2.0f, 3.0f };
    std::vector<float> data_vec3_B = { -1.20f, 3.6f, -3.8f };

    std::vector<float> data_vec4_A = { 1.0f, 2.0f, 3.0f, 4.0f };
    std::vector<float> data_vec4_B = { -11.20f, 12.2f, -13.0f, 12.321f };

    std::vector<float> data_mat4_A = { 1.0f, 0.0f, 2.0f, 0.0f,
                                       0.0f, 1.0f, 3.0f, 0.0f,
                                       0.0f, 0.0f, 1.0f, 0.0f,
                                       0.0f, 0.0f, 0.0f, 1.0f };

    std::vector<float> data_mat4_B = { 1.0f, 0.0f, 0.0f, 8.0f,
                                       0.0f, 3.0f, 0.0f, 1.0f,
                                       0.0f, 0.5f, 1.0f, 0.0f,
                                       0.0f, 0.0f, 0.0f, 1.0f };

    std::vector<float> data_mat4_C = { 2.5647f, 1.8781f, 1.9452f, 1.0231,
                                       1.8781f, 2.0246f, 1.4695f, 1.0652,
                                       1.9452f, 1.4695f, 1.7409f, 1.1118,
                                       1.0231f, 1.0652f, 1.1118f, 0.9585 };

    // Vector operators

    if ( CompareResults( glmVecScalarAdd, bvuVecScalarAdd, data_vec4_A, 3.2 ) ) printf("%-30s- passed!\n", "Vector-Scalar Addition");
    else                                                                        printf("%-30s- failed!\n", "Vector-Scalar Addition" );

    if ( CompareResults( glmVecVecAdd, bvuVecVecAdd, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector-Scalar Addition");
    else                                                                          printf("%-30s- failed!\n", "Vector-Scalar Addition");

    if ( CompareResults( glmVecScalarSub, bvuVecScalarSub, data_vec4_A, 3.2 ) ) printf("%-30s- passed!\n", "Vector-Scalar Addition");
    else                                                                        printf("%-30s- failed!\n", "Vector-Scalar Addition");

    if ( CompareResults( glmVecVecSub, bvuVecVecSub, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector-Scalar Addition");
    else                                                                          printf("%-30s- failed!\n", "Vector-Scalar Addition");

    if ( CompareResults( glmVecScalarMul, bvuVecScalarMul, data_vec4_A, 3.2 ) ) printf("%-30s- passed!\n", "Vector-Scalar Multiplication");
    else                                                                        printf("%-30s- failed!\n", "Vector-Scalar Multiplication");

    if ( CompareResults( glmVecVecMul,bvuVecVecMul,data_vec4_A,data_vec4_B ) ) printf("%-30s- passed!\n","Vector-Vector Multiplication");
    else                                                                       printf("%-30s- failed!\n","Vector-Vector Multiplication");

    if ( CompareResults( glmVecScalarDiv, bvuVecScalarDiv, data_vec4_A, 3.2 ) ) printf("%-30s- passed!\n", "Vector-Scalar Division");
    else                                                                        printf("%-30s- failed!\n", "Vector-Scalar Division");

    if ( CompareResults( glmVecVecDiv, bvuVecVecDiv, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector-Vector Division");
    else                                                                          printf("%-30s- failed!\n", "Vector-Vector Division");

    // Vector functions

    if ( CompareResults( glmNormalize, bvuNormalize, data_vec4_A ) ) printf("%-30s- passed!\n", "Vector Normalization");
    else                                                             printf("%-30s- failed!\n", "Vector Normalization");

    if ( CompareResults( glmDot, bvuDot, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector Dot Product");
    else                                                              printf("%-30s- failed!\n", "Vector Dot Product");

    if ( CompareResults( glmNorm, bvuNorm, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector Norm");
    else                                                   printf("%-30s- failed!\n", "Vector Norm");

    if ( CompareResults( glmNormSq, bvuNormSq, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector Norm Squared");
    else                                                       printf("%-30s- failed!\n", "Vector Norm Squared");

    if ( CompareResults( glmDistance, bvuDistance, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n","Vector Distance");
    else                                                                        printf("%-30s- failed!\n","Vector Distance");

    if ( CompareResults( glmAbs, bvuAbs, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector Absolute Value" );
    else                                                 printf("%-30s- failed!\n", "Vector Absolute Value" );

    if ( CompareResults( glmClamp, bvuClamp, data_vec4_B ) ) printf("%-30s- passed!\n", "Vector Clamp");
    else                                                     printf("%-30s- failed!\n", "Vector Clamp");

    if ( CompareResults( glmCross, bvuCross, data_vec3_A, data_vec3_B ) ) printf("%-30s- passed!\n", "Vector Cross");
    else                                                                  printf("%-30s- failed!\n", "Vector Cross");

    // Matrix operators

    if ( CompareResults( glmMatMatAdd, bvuMatMatAdd, data_mat4_A, data_mat4_B ) ) printf("%-30s- passed!\n", "Matrix-Matrix Addition");
    else                                                                          printf("%-30s- failed!\n", "Matrix-Matrix Addition");

    if ( CompareResults( glmMatMatSub, bvuMatMatSub, data_mat4_A, data_mat4_B ) ) printf("%-30s- passed!\n", "Matrix-Matrix Substraction");
    else                                                                          printf("%-30s- failed!\n", "Matrix-Matrix Substraction");

    if ( CompareResults( glmMatMatMul, bvuMatMatMul, data_mat4_A, data_mat4_B ) ) printf("%-30s- passed!\n", "Matrix-Matrix Mult");
    else                                                                          printf("%-30s- failed!\n", "Matrix-Matrix Mult");


    // Matrix functions

    if ( CompareResults( glmMatInv, bvuMatInv, data_mat4_C ) ) printf("%-30s- passed!\n", "Matrix Inverse");
    else                                                       printf("%-30s- failed!\n", "Matrix Inverse");

    if ( CompareResults( glmMatDeterminant, bvuMatDeterminant, data_mat4_C ) ) printf("%-30s- passed!\n", "Matrix Determinant" );
    else                                                                       printf("%-30s- failed!\n", "Matrix Determinant" );

    if ( CompareResults( glmMatTranspose, bvuMatTranspose, data_mat4_C ) ) printf("%-30s- passed!\n", "Matrix Transpose" );
    else                                                                   printf("%-30s- failed!\n", "Matrix Transpose" );



    // Vector Matrix Multiplicaton
    if ( CompareResults( glmMatVecMul, bvuMatVecMul, data_mat4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Matrix-Vector Mult");
    else                                                                          printf("%-30s- failed!\n", "Matrix-Vector Mult");


    // Quaternions
    if ( CompareResults( glmQuatMul, bvuQuatMul, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Quaternion Mult");
    else                                                                      printf("%-30s- failed!\n", "Quaternion Mult");

    if ( CompareResults( glmQuatConjugate, bvuQuatConjugate, data_vec4_A ) ) printf("%-30s- passed!\n", "Quaternion Conjugate");
    else                                                                     printf("%-30s- failed!\n", "Quaternion Conjugate");

    if ( CompareResults( glmQuatDot, bvuQuatDot, data_vec4_A, data_vec4_B ) ) printf("%-30s- passed!\n", "Quaternion Dot Prod.");
    else                                                                     printf("%-30s- failed!\n", "Quaternion Dot Prod.");

    if ( CompareResults( glmQuatInverse, bvuQuatInverse, data_vec4_A ) ) printf("%-30s- passed!\n", "Quaternion Inverse");
    else                                                                 printf("%-30s- failed!\n", "Quaternion Inverse");


    // glu functions

}
