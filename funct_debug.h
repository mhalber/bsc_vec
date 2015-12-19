#pragma once

namespace bvu
{
    template<typename T>
    inline void
    printMat4( const T& mat, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", mat[0][0], mat[1][0], mat[2][0], mat[3][0] );
        fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", mat[0][1], mat[1][1], mat[2][1], mat[3][1] );
        fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", mat[0][2], mat[1][2], mat[2][2], mat[3][2] );
        fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", mat[0][3], mat[1][3], mat[2][3], mat[3][3] );
        fprintf ( stream, "\n" );
    }

    template<typename T>
    inline void
    printMat3( const T& mat, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f %5.3f\n", mat[0][0], mat[1][0], mat[2][0] );
        fprintf ( stream, "%5.3f %5.3f %5.3f\n", mat[0][1], mat[1][1], mat[2][1] );
        fprintf ( stream, "%5.3f %5.3f %5.3f\n", mat[0][2], mat[1][2], mat[2][2] );
        fprintf ( stream, "\n" );
    }

    template<typename T>
    inline void
    printMat2( const T& mat, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f\n", mat[0][0], mat[1][0] );
        fprintf ( stream, "%5.3f %5.3f\n", mat[0][1], mat[1][1] );
        fprintf ( stream, "\n" );
    }

    template<typename T>
    inline void
    printVec4( const T& vec, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", vec.x, vec.y, vec.z, vec.w );
    }

    template<typename T>
    inline void
    printVec3( const T& vec, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f %5.3f\n", vec.x, vec.y, vec.z );
    }

    template<typename T>
    inline void
    printVec2( const T& vec, FILE * stream = stdout )
    {
        fprintf ( stream, "%5.3f %5.3f\n", vec.x, vec.y );
    }
}
