#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>

#include "bsc_vec.h"

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
glmVec4ScalarAdd( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 + valB;
    return v2;
}

bsc::vec4f
bscVec4ScalarAdd( const std::vector<float> & vals1, const float valB )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 = v1 + valB;
    return v2;
}

glm::vec4
glmVec4Vec4Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 + v2;
    return v3;
}

bsc::vec4f
bscVec4Vec4Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bsc::vec4f v3 = v1 + v2;
    return v3;
}

glm::vec4
glmVec4ScalarSub( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 - valB;
    return v2;
}

bsc::vec4f
bscVec4ScalarSub( const std::vector<float> & vals1, const float valB )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 = v1 - valB;
    return v2;
}

glm::vec4
glmVec4Vec4Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 - v2;
    return v3;
}

bsc::vec4f
bscVec4Vec4Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bsc::vec4f v3 = v1 - v2;
    return v3;
}

glm::vec4
glmVec4ScalarMul( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 * valB;
    return v2;
}

bsc::vec4f
bscVec4ScalarMul( const std::vector<float> & vals1, const float valB )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 = v1 * valB;
    return v2;
}

glm::vec4
glmVec4Vec4Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 * v2;
    return v3;
}

bsc::vec4f
bscVec4Vec4Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bsc::vec4f v3 = v1 * v2;
    return v3;
}

glm::vec4
glmVec4ScalarDiv( const std::vector<float> & vals1, const float valB )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 = v1 / valB;
    return v2;
}

bsc::vec4f
bscVec4ScalarDiv( const std::vector<float> & vals1, const float valB )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 = v1 / valB;
    return v2;
}

glm::vec4
glmVec4Vec4Div( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec4 v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::vec4 v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    glm::vec4 v3 = v1 / v2;
    return v3;
}

bsc::vec4f
bscVec4Vec4Div( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    bsc::vec4f v3 = v1 / v2;
    return v3;
}


// -------------------------------------------------------------------

glm::vec3
glmVec3ScalarAdd( const std::vector<float> & vals1, const float valB )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 = v1 + valB;
    return v2;
}

bsc::vec3f
bscVec3ScalarAdd( const std::vector<float> & vals1, const float valB )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 = v1 + valB;
    return v2;
}

glm::vec3
glmVec3Vec3Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 v3 = v1 + v2;
    return v3;
}

bsc::vec3f
bscVec3Vec3Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f v3 = v1 + v2;
    return v3;
}

glm::vec3
glmVec3ScalarSub( const std::vector<float> & vals1, const float valB )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 = v1 - valB;
    return v2;
}

bsc::vec3f
bscVec3ScalarSub( const std::vector<float> & vals1, const float valB )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 = v1 - valB;
    return v2;
}

glm::vec3
glmVec3Vec3Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 v3 = v1 - v2;
    return v3;
}

bsc::vec3f
bscVec3Vec3Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f v3 = v1 - v2;
    return v3;
}

glm::vec3
glmVec3ScalarMul( const std::vector<float> & vals1, const float valB )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 = v1 * valB;
    return v2;
}

bsc::vec3f
bscVec3ScalarMul( const std::vector<float> & vals1, const float valB )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 = v1 * valB;
    return v2;
}

glm::vec3
glmVec3Vec3Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 v3 = v1 * v2;
    return v3;
}

bsc::vec3f
bscVec3Vec3Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f v3 = v1 * v2;
    return v3;
}

glm::vec3
glmVec3ScalarDiv( const std::vector<float> & vals1, const float valB )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 = v1 / valB;
    return v2;
}

bsc::vec3f
bscVec3ScalarDiv( const std::vector<float> & vals1, const float valB )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 = v1 / valB;
    return v2;
}

glm::vec3
glmVec3Vec3Div( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::vec3 v1 ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 v2 ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 v3 = v1 / v2;
    return v3;
}

bsc::vec3f
bscVec3Vec3Div( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f v3 = v1 / v2;
    return v3;
}


// -------------------------------------------------------------------



glm::vec4
glmNormalize( const std::vector<float> & vals )
{
    glm::vec4 v ( vals[0], vals[1], vals[2], vals[3] );
    v = glm::normalize( v );
    return v;
}

bsc::vec4f
bscNormalize( const std::vector<float> & vals )
{
    bsc::vec4f v( vals[0], vals[1], vals[2], vals[3] );
    v = bsc::normalize( v );
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
bscDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = bsc::dot( v1, v2 );
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
bscNorm( const std::vector<float> & vals )
{
    bsc::vec4f v ( vals[0], vals[1], vals[2], vals[3] );
    float f = bsc::norm( v );
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
bscNormSq( const std::vector<float> & vals )
{
    bsc::vec4f v ( vals[0], vals[1], vals[2], vals[3] );
    float f = bsc::normSq( v );
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
bscDistance( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec4f v1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::vec4f v2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    float f = bsc::distance( v1, v2 );
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

bsc::vec3f
bscCross( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::vec3f v1 ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f v2 ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f v3 = bsc::cross( v1, v2 );
    return v3;
}

glm::vec4
glmAbs( const std::vector<float> & vals )
{
    glm::vec4 v1 ( vals[0], vals[1], vals[2], vals[3] );
    glm::vec4 v2 = glm::abs( v1 );
    return v2;
}

bsc::vec4f
bscAbs( const std::vector<float> & vals )
{
    bsc::vec4f v1 ( vals[0], vals[1], vals[2], vals[3] );
    bsc::vec4f v2 = bsc::abs( v1 );
    return v2;
}

glm::vec4
glmClamp( const std::vector<float> & vals )
{
    glm::vec4 v1 ( vals[0], vals[1], vals[2], vals[3] );
    glm::vec4 v2 = glm::clamp( v1, 0.0f, 1.0f );
    return v2;
}

bsc::vec4f
bscClamp( const std::vector<float> & vals )
{
    bsc::vec4f v1 ( vals[0], vals[1], vals[2], vals[3] );
    bsc::vec4f v2 = bsc::clamp( v1, 0.0f, 1.0f );
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
glmMat4Mat4Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 + m2;
}

bsc::mat4f
bscMat4Mat4Add( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::mat4f m1 ( &vals1[0] );
    bsc::mat4f m2 ( &vals2[0] );
    return m1 + m2;
}

glm::mat4
glmMat4Mat4Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 - m2;
}

bsc::mat4f
bscMat4Mat4Sub( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::mat4f m1 ( &vals1[0] );
    bsc::mat4f m2 ( &vals2[0] );
    return m1 - m2;
}

glm::mat4
glmMat4Mat4Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m1 = InitGLMMat4( vals1 );
    glm::mat4 m2 = InitGLMMat4( vals2 );
    return m1 * m2;
}

bsc::mat4f
bscMat4Mat4Mul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::mat4f m1
     ( &vals1[0] );
    bsc::mat4f m2 ( &vals2[0] );
    return m1 * m2;
}

// ---------------------------------------------------------------------------

glm::mat4
glmMatInv( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::inverse(m);
}

bsc::mat4f
bscMatInv( const std::vector<float> & vals1 )
{
    bsc::mat4f m ( &vals1[0] );
    return bsc::inverse(m);
}

glm::mat4
glmMatTranspose( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::transpose( m );
}

bsc::mat4f
bscMatTranspose( const std::vector<float> & vals1 )
{
    bsc::mat4f m ( &vals1[0] );
    return bsc::transpose( m );
}

float
glmMatDeterminant( const std::vector<float> & vals1 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    return glm::determinant(m);
}

float
bscMatDeterminant( const std::vector<float> & vals1 )
{
    bsc::mat4f m ( &vals1[0] );
    return bsc::determinant(m);
}

glm::vec4
glmMatVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::mat4 m = InitGLMMat4( vals1 );
    glm::vec4 v ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return m * v;
}

bsc::vec4f
bscMatVecMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::mat4f m ( &vals1[0] );
    bsc::vec4f v ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return m * v;
}

glm::mat4
glmTranslate( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals )
{
    glm::mat4 m = InitGLMMat4( mat_vals );
    glm::vec3 v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return glm::translate( m, v );
}

bsc::mat4f
bscTranslate( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals )
{
    bsc::mat4f m ( &mat_vals[0] );
    bsc::vec3f v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return bsc::translate( m, v );
}

glm::mat4
glmScale( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals )
{
    glm::mat4 m = InitGLMMat4( mat_vals );
    glm::vec3 v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return glm::scale( m, v );
}

bsc::mat4f
bscScale( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals )
{
    bsc::mat4f m ( &mat_vals[0] );
    bsc::vec3f v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return bsc::scale( m, v );
}

glm::mat4
glmRotate( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals, float angle )
{
    glm::mat4 m = InitGLMMat4( mat_vals );
    glm::vec3 v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return glm::rotate( m, angle, v );
}

bsc::mat4f
bscRotate ( const std::vector<float> & mat_vals, const std::vector<float> & vec_vals, float angle )
{
    bsc::mat4f m ( &mat_vals[0] );
    bsc::vec3f v ( vec_vals[0], vec_vals[1], vec_vals[2] );
    return bsc::rotate( m, bsc::deg2rad(angle), v );
}

glm::mat4
glmLookAt ( const std::vector<float> & vals1, const std::vector<float> & vals2, const std::vector<float> & vals3 )
{
    glm::vec3 eye ( vals1[0], vals1[1], vals1[2] );
    glm::vec3 center ( vals2[0], vals2[1], vals2[2] );
    glm::vec3 up ( vals3[0], vals3[1], vals3[2] );
    return glm::lookAt( eye, center, up );
}

bsc::mat4f
bscLookAt ( const std::vector<float> & vals1, const std::vector<float> & vals2, const std::vector<float> & vals3 )
{
    bsc::vec3f eye ( vals1[0], vals1[1], vals1[2] );
    bsc::vec3f center ( vals2[0], vals2[1], vals2[2] );
    bsc::vec3f up ( vals3[0], vals3[1], vals3[2] );
    return bsc::lookAt( eye, center, up );
}

glm::mat4
glmPerspective ( const float fovy, const float aspect, const float z_near, const float z_far )
{
    return glm::perspective( fovy, aspect, z_near, z_far );
}

bsc::mat4f
bscPerspective ( const float fovy, const float aspect, const float z_near, const float z_far )
{
    return bsc::perspective( bsc::deg2rad(fovy), aspect, z_near, z_far );
}


glm::mat4
glmFrustum ( const float left, const float right, const float bottom, const float top, const float z_near, const float z_far )
{
    return glm::frustum( left, right, bottom, top, z_near, z_far );
}

bsc::mat4f
bscFrustum ( const float left, const float right, const float bottom, const float top, const float z_near, const float z_far )
{
    return bsc::frustum( left, right, bottom, top, z_near, z_far );
}

glm::mat4
glmOrtho ( const float left, const float right, const float bottom, const float top, const float z_near, const float z_far )
{
    return glm::ortho( left, right, bottom, top, z_near, z_far );
}

bsc::mat4f
bscOrtho ( const float left, const float right, const float bottom, const float top, const float z_near, const float z_far )
{
    return bsc::ortho( left, right, bottom, top, z_near, z_far );
}

glm::vec3
glmProject ()
{
    glm::vec3 w( 10.0f, 10.0f, 10.0f);
    glm::mat4 proj = glm::perspective( 45.0f, 1.3f, 0.01f, 100.0f);
    glm::mat4 view = glm::lookAt( glm::vec3( 0.0, 0.0, -3.0 ), glm::vec3( 0.0, 0.0, 0.0 ), glm::vec3( 0.0, 1.0, 0.0 ) );
    glm::vec4 viewport (0, 0, 640, 480);
    return glm::project( w, view, proj, viewport );
}

bsc::vec3f
bscProject ()
{
    bsc::vec4f w ( 10.0f, 10.0f, 10.0f, 1.0f);
    bsc::mat4f proj = bsc::perspective( bsc::deg2rad(45.0f), 1.3f, 0.01f, 100.0f);
    bsc::mat4f view = bsc::lookAt( bsc::vec3f( 0.0, 0.0, -3.0 ), bsc::vec3f( 0.0, 0.0, 0.0 ), bsc::vec3f( 0.0, 1.0, 0.0 ) );
    bsc::vec4f viewport (0, 0, 640, 480);
    return bsc::project( w, view, proj, viewport );
}

glm::vec4
glmUnProject ()
{
    glm::vec3 w( -137.129, 685.701, 0.999 );
    glm::mat4 proj = glm::perspective( 45.0f, 1.3f, 0.01f, 100.0f);
    glm::mat4 view = glm::lookAt( glm::vec3( 0.0, 0.0, -3.0 ), glm::vec3( 0.0, 0.0, 0.0 ), glm::vec3( 0.0, 1.0, 0.0 ) );
    glm::vec4 viewport (0, 0, 640, 480);
    return glm::vec4( glm::unProject( w, view, proj, viewport ), 1.0 );
}

bsc::vec4f
bscUnProject ()
{
    bsc::vec3f w ( -137.129, 685.701, 0.999 );
    bsc::mat4f proj = bsc::perspective( bsc::deg2rad(45.0f), 1.3f, 0.01f, 100.0f);
    bsc::mat4f view = bsc::lookAt( bsc::vec3f( 0.0, 0.0, -3.0 ), bsc::vec3f( 0.0, 0.0, 0.0 ), bsc::vec3f( 0.0, 1.0, 0.0 ) );
    bsc::vec4f viewport (0, 0, 640, 480);
    return bsc::unproject( w, view, proj, viewport );
}

glm::quat
glmQuatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::quat q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::quat q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return q1 * q2;
}

bsc::quatf
bscQuatMul( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::quatf q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::quatf q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return q1 * q2;
}

glm::quat
glmQuatConjugate( const std::vector<float> & vals1 )
{
    glm::quat q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return glm::conjugate( q );
}

bsc::quatf
bscQuatConjugate( const std::vector<float> & vals1 )
{
    bsc::quatf q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return bsc::conjugate( q );
}

glm::quat
glmQuatInverse( const std::vector<float> & vals1 )
{
    glm::quat q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return glm::inverse( q );
}

bsc::quatf
bscQuatInverse( const std::vector<float> & vals1 )
{
    bsc::quatf q ( vals1[0], vals1[1], vals1[2], vals1[3] );
    return bsc::inverse( q );
}

float
glmQuatDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    glm::quat q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    glm::quat q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return glm::dot( q1, q2 );
}

float
bscQuatDot( const std::vector<float> & vals1, const std::vector<float> & vals2 )
{
    bsc::quatf q1 ( vals1[0], vals1[1], vals1[2], vals1[3] );
    bsc::quatf q2 ( vals2[0], vals2[1], vals2[2], vals2[3] );
    return bsc::dot( q1, q2 );
}

glm::quat
glmMatToQuat( const std::vector<float> & mat_vals )
{
    glm::mat4 m = InitGLMMat4( mat_vals );
    return glm::quat_cast( m );
}

bsc::quatf
bscMatToQuat( const std::vector<float> & mat_vals )
{
    bsc::mat4f m( &mat_vals[0] );
    return bsc::to_quat( m );
}

glm::mat4
glmQuatToMat( const std::vector<float> & vals1 )
{
    glm::vec3 v ( vals1[0], vals1[1], vals1[2] );
    glm::quat q ( vals1[3], v );
    return glm::mat4_cast( q );
}

bsc::mat4f
bscQuatToMat( const std::vector<float> & vals1 )
{
    bsc::vec3f v ( vals1[0], vals1[1], vals1[2] );
    bsc::quatf q ( vals1[3], v );
    return bsc::to_mat4( q );
}



void
RunTests()
{
    // data
    std::vector<float> data_vec3_A = { 1.0f, 2.0f, 3.0f };
    std::vector<float> data_vec3_B = { -1.20f, 3.6f, -3.8f };
    std::vector<float> data_vec3_C = { 0.0f, 0.0f, 1.0f };

    std::vector<float> data_vec4_A = { 1.0f, 2.0f, 3.0f, 4.0f };
    std::vector<float> data_quat_A = { 0.0f, 1.0f, 0.0f, M_PI };
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

    // Vector4 operators

    if ( CompareResults( glmVec4ScalarAdd, bscVec4ScalarAdd, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vec4-Scalar Addition");
    else                                                                        printf("%-40s- failed!\n", "Vec4-Scalar Addition" );

    if ( CompareResults( glmVec4Vec4Add, bscVec4Vec4Add, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vec4-Vec4 Addition");
    else                                                                          printf("%-40s- failed!\n", "Vec4-Vec4 Addition");

    if ( CompareResults( glmVec4ScalarSub, bscVec4ScalarSub, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vec4-Scalar Substraction");
    else                                                                        printf("%-40s- failed!\n", "Vec4-Scalar Substraction");

    if ( CompareResults( glmVec4Vec4Sub, bscVec4Vec4Sub, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vec4-Vec4 Substraction");
    else                                                                          printf("%-40s- failed!\n", "Vec4-Vec4 Substraction");

    if ( CompareResults( glmVec4ScalarMul, bscVec4ScalarMul, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vec4-Scalar Multiplication");
    else                                                                        printf("%-40s- failed!\n", "Vec4-Scalar Multiplication");

    if ( CompareResults( glmVec4Vec4Mul, bscVec4Vec4Mul,data_vec4_A,data_vec4_B ) ) printf("%-40s- passed!\n","Vec4-Vec4 Multiplication");
    else                                                                       printf("%-40s- failed!\n","Vec4-Vec4 Multiplication");

    if ( CompareResults( glmVec4ScalarDiv, bscVec4ScalarDiv, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vec4-Scalar Division");
    else                                                                        printf("%-40s- failed!\n", "Vec4-Scalar Division");

    if ( CompareResults( glmVec4Vec4Div, bscVec4Vec4Div, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vec4-Vec4 Division");
    else                                                                          printf("%-40s- failed!\n", "Vec4-Vec4 Division");

    // Vector3 operators

    if ( CompareResults( glmVec3ScalarAdd, bscVec3ScalarAdd, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vector3-Scalar Addition");
    else                                                                        printf("%-40s- failed!\n", "Vector3-Scalar Addition" );

    if ( CompareResults( glmVec3Vec3Add, bscVec3Vec3Add, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector3-Vec3 Addition");
    else                                                                          printf("%-40s- failed!\n", "Vector3-Vec3 Addition");

    if ( CompareResults( glmVec3ScalarSub, bscVec3ScalarSub, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vector3-Scalar Substraction");
    else                                                                        printf("%-40s- failed!\n", "Vector3-Scalar Substraction");

    if ( CompareResults( glmVec3Vec3Sub, bscVec3Vec3Sub, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector3-Vector3 Substraction");
    else                                                                          printf("%-40s- failed!\n", "Vector3-Vector3 Substraction");

    if ( CompareResults( glmVec3ScalarMul, bscVec3ScalarMul, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vector3-Scalar Multiplication");
    else                                                                        printf("%-40s- failed!\n", "Vector3-Scalar Multiplication");

    if ( CompareResults( glmVec3Vec3Mul, bscVec3Vec3Mul,data_vec4_A,data_vec4_B ) ) printf("%-40s- passed!\n","Vector3-Vector3 Multiplication");
    else                                                                       printf("%-40s- failed!\n","Vector3-Vector3 Multiplication");

    if ( CompareResults( glmVec3ScalarDiv, bscVec3ScalarDiv, data_vec4_A, 3.2 ) ) printf("%-40s- passed!\n", "Vector3-Scalar Division");
    else                                                                        printf("%-40s- failed!\n", "Vector3-Scalar Division");

    if ( CompareResults( glmVec3Vec3Div, bscVec3Vec3Div, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector3-Vector3 Division");
    else                                                                          printf("%-40s- failed!\n", "Vector3-Vector3 Division");





    // Vector functions

    if ( CompareResults( glmNormalize, bscNormalize, data_vec4_A ) ) printf("%-40s- passed!\n", "Vector Normalization");
    else                                                             printf("%-40s- failed!\n", "Vector Normalization");

    if ( CompareResults( glmDot, bscDot, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector Dot Product");
    else                                                              printf("%-40s- failed!\n", "Vector Dot Product");

    if ( CompareResults( glmNorm, bscNorm, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector Norm");
    else                                                   printf("%-40s- failed!\n", "Vector Norm");

    if ( CompareResults( glmNormSq, bscNormSq, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector Norm Squared");
    else                                                       printf("%-40s- failed!\n", "Vector Norm Squared");

    if ( CompareResults( glmDistance, bscDistance, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n","Vector Distance");
    else                                                                        printf("%-40s- failed!\n","Vector Distance");

    if ( CompareResults( glmAbs, bscAbs, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector Absolute Value" );
    else                                                 printf("%-40s- failed!\n", "Vector Absolute Value" );

    if ( CompareResults( glmClamp, bscClamp, data_vec4_B ) ) printf("%-40s- passed!\n", "Vector Clamp");
    else                                                     printf("%-40s- failed!\n", "Vector Clamp");

    if ( CompareResults( glmCross, bscCross, data_vec3_A, data_vec3_B ) ) printf("%-40s- passed!\n", "Vector Cross");
    else                                                                  printf("%-40s- failed!\n", "Vector Cross");

    // Matrix operators

    if ( CompareResults( glmMat4Mat4Add, bscMat4Mat4Add, data_mat4_A, data_mat4_B ) ) printf("%-40s- passed!\n", "Matrix-Matrix Addition");
    else                                                                          printf("%-40s- failed!\n", "Matrix-Matrix Addition");

    if ( CompareResults( glmMat4Mat4Sub, bscMat4Mat4Sub, data_mat4_A, data_mat4_B ) ) printf("%-40s- passed!\n", "Matrix-Matrix Substraction");
    else                                                                          printf("%-40s- failed!\n", "Matrix-Matrix Substraction");

    if ( CompareResults( glmMat4Mat4Mul, bscMat4Mat4Mul, data_mat4_A, data_mat4_B ) ) printf("%-40s- passed!\n", "Matrix-Matrix Mult");
    else                                                                          printf("%-40s- failed!\n", "Matrix-Matrix Mult");


    // Matrix functions

    if ( CompareResults( glmMatInv, bscMatInv, data_mat4_C ) ) printf("%-40s- passed!\n", "Matrix Inverse");
    else                                                       printf("%-40s- failed!\n", "Matrix Inverse");

    if ( CompareResults( glmMatDeterminant, bscMatDeterminant, data_mat4_C ) ) printf("%-40s- passed!\n", "Matrix Determinant" );
    else                                                                       printf("%-40s- failed!\n", "Matrix Determinant" );

    if ( CompareResults( glmMatTranspose, bscMatTranspose, data_mat4_C ) ) printf("%-40s- passed!\n", "Matrix Transpose" );
    else                                                                   printf("%-40s- failed!\n", "Matrix Transpose" );



    // Vector Matrix Multiplicaton
    if ( CompareResults( glmMatVecMul, bscMatVecMul, data_mat4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Matrix-Vector Mult");
    else                                                                          printf("%-40s- failed!\n", "Matrix-Vector Mult");


    // Quaternions
    if ( CompareResults( glmQuatMul, bscQuatMul, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Quaternion Mult");
    else                                                                      printf("%-40s- failed!\n", "Quaternion Mult");

    if ( CompareResults( glmQuatConjugate, bscQuatConjugate, data_vec4_A ) ) printf("%-40s- passed!\n", "Quaternion Conjugate");
    else                                                                     printf("%-40s- failed!\n", "Quaternion Conjugate");

    if ( CompareResults( glmQuatDot, bscQuatDot, data_vec4_A, data_vec4_B ) ) printf("%-40s- passed!\n", "Quaternion Dot Prod.");
    else                                                                     printf("%-40s- failed!\n", "Quaternion Dot Prod.");

    if ( CompareResults( glmQuatInverse, bscQuatInverse, data_vec4_A ) ) printf("%-40s- passed!\n", "Quaternion Inverse");
    else                                                                 printf("%-40s- failed!\n", "Quaternion Inverse");

    if ( CompareResults( glmQuatToMat, bscQuatToMat, data_quat_A ) ) printf("%-40s- passed!\n", "Quaternion To Matrix");
    else                                                             printf("%-40s- failed!\n", "Quaternion To Matrix");


    if ( CompareResults( glmMatToQuat, bscMatToQuat, data_mat4_A ) ) printf("%-40s- passed!\n", "Matrix To Quaternion");
    else                                                             printf("%-40s- failed!\n", "Matrix To Quaternion");

    // Glu functions
    if ( CompareResults( glmLookAt, bscLookAt, data_vec3_A, data_vec3_B, data_vec3_C ) ) printf("%-40s- passed!\n", "Look At Matrix");
    else                                                                                 printf("%-40s- failed!\n", "Look At Matrix");

    if ( CompareResults( glmPerspective, bscPerspective, 45.0f, 1.3f, 0.01f, 100.0f ) ) printf("%-40s- passed!\n", "Perspective Matrix");
    else                                                                                printf("%-40s- failed!\n", "Perspective Matrix");

    if ( CompareResults( glmFrustum, bscFrustum, -0.5f, 0.5f, -0.5f, 0.5f, 0.01f, 100.0f ) ) printf("%-40s- passed!\n", "Frustum Matrix");
    else                                                                                     printf("%-40s- failed!\n", "Frustum Matrix");

    if ( CompareResults( glmOrtho, bscOrtho, -0.5f, 0.5f, -0.5f, 0.5f, 0.01f, 100.0f ) ) printf("%-40s- passed!\n", "Ortho Matrix");
    else                                                                                 printf("%-40s- failed!\n", "Ortho Matrix");

    if ( CompareResults( glmProject, bscProject ) ) printf("%-40s- passed!\n", "Project Function");
    else                                            printf("%-40s- failed!\n", "Project Function");

    if ( CompareResults( glmUnProject, bscUnProject ) ) printf("%-40s- passed!\n", "Unproject Function");
    else                                                printf("%-40s- failed!\n", "Unproject Function");


    // Transforms
    if ( CompareResults( glmTranslate, bscTranslate, data_mat4_A, data_vec4_A ) ) printf("%-40s- passed!\n", "Translation Matrix");
    else                                                                          printf("%-40s- failed!\n", "Translation Matrix");

    if ( CompareResults( glmScale, bscScale, data_mat4_A, data_vec4_A ) ) printf("%-40s- passed!\n", "Scaling Matrix");
    else                                                                  printf("%-40s- failed!\n", "Scaling Matrix");

    if ( CompareResults( glmRotate, bscRotate, data_mat4_A, data_vec4_A, 45.0 ) ) printf("%-40s- passed!\n", "Rotation Matrix");
    else                                                                          printf("%-40s- failed!\n", "Rotation Matrix");


}
