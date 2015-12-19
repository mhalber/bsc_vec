#pragma once

//---------------------------------------------------
// Interface
//---------------------------------------------------
namespace bvu
{

    template< typename T, template <typename Q> class vecX >
    T dot ( const vecX<T> & a, const vecX<T> & b );

    template< typename T, template <typename Q> class vecX >
    T normSq ( const vecX<T> & a );

    template< typename T, template <typename Q> class vecX >
    T norm ( const vecX<T> & a );

    template< typename T, template <typename Q> class vecX >
    T distance ( const vecX<T> & a, const vecX<T> & b );

    template< typename T, template <typename Q> class vecX >
    vecX<T> normalize ( const vecX<T> & a ); // this will only be called if the vector we are passing is const!

    template< typename T, template <typename Q> class vecX >
    vecX<T> abs ( const vecX<T> & a );

    template< typename T, template <typename Q> class vecX >
    vecX<T> clamp ( const vecX<T> & a, const T val_min = 0.0, const T val_max = 1.0 );

    template< typename T >
    vec3<T> cross ( const vec3<T> & a, const vec3<T> & b );

    template< typename T >
    T parallelogramArea ( const vec3<T> & a, const vec3<T> & b );

    template< typename T >
    T parallelogramArea ( const vec2<T> & a, const vec2<T> & b );

    template< typename T>
    T scalarTripleProduct( const vec3<T> & a, const vec3<T> & b, const vec3<T> & c );

    template< typename T>
    T parallelepipedVolume( const vec3<T> & a, const vec3<T> & b, const vec3<T> & c );

    template< typename T >
    int ccw ( const vec2<T> & a, const vec2<T> & b );

}

//---------------------------------------------------
// Implementation
//---------------------------------------------------

template< typename T, template <typename Q> class vecX >
inline T bvu ::
dot ( const vecX<T> & a, const vecX<T> & b )
{
    T dot_prod = 0.0;

    for ( int i = 0 ; i < a.size() ; ++i )
    {
        dot_prod += a[i] * b[i];
    }

    return dot_prod;
}

template< typename T, template <typename Q> class vecX >
inline T bvu ::
normSq ( const vecX<T> & a )
{
    return dot( a, a );
}

template< typename T, template <typename Q> class vecX >
inline T bvu ::
norm ( const vecX<T> & a )
{
    return std::sqrt( normSq( a ) );
}

template< typename T, template <typename Q> class vecX >
inline T bvu ::
distance ( const vecX<T> & a, const vecX<T> & b )
{
    return norm( a - b );
}

template< typename T, template <typename Q> class vecX >
inline vecX<T> bvu ::
normalize ( const vecX<T> & a )
{
    return a * ( (T)1.0 / std::sqrt( dot( a, a ) ) );
}


template< typename T, template <typename Q> class vecX >
inline vecX<T> bvu ::
abs ( const vecX<T> & a )
{
    vecX<T> b;
    for ( int i = 0 ; i < a.size() ; ++i )
    {
        b[i] = std::abs( a[i] );
    }
    return b;
}


template< typename T, template <typename Q> class vecX >
inline vecX<T> bvu ::
clamp ( const vecX<T> & a, const T val_min, const T val_max )
{
    vecX<T> b;
    for ( int i = 0 ; i < a.size() ; ++i )
    {
        if ( a[i] < val_min ) b[i]  = val_min;
        else if ( a[i] > val_max ) b[i]  = val_max;
        else b[i] = a[i];
    }
    return b;
}

template< typename T >
inline bvu::vec3<T> bvu ::
cross ( const vec3<T> & a, const vec3<T> & b )
{
    return vec3<T>( ( a.y * b.z - a.z * b.y ),
                    ( a.z * b.x - a.x * b.z ),
                    ( a.x * b.y - a.y * b.x ) );
}
template< typename T >
inline T bvu ::
parallelogramArea ( const vec3<T> & a, const vec3<T> & b )
{
    return norm( cross( a, b ) );
}

template< typename T >
inline T bvu ::
parallelogramArea ( const vec2<T> & a, const vec2<T> & b )
{
    return a.x * b.y - a.y * b.x;
}

template< typename T>
inline T bvu ::
scalarTripleProduct( const vec3<T> & a, const vec3<T> & b, const vec3<T> & c )
{
    return dot( a, cross( b, c ) );
}

template< typename T>
inline T bvu ::
parallelepipedVolume( const vec3<T> & a, const vec3<T> & b, const vec3<T> & c )
{
    return norm( scalarTripleProduct( a, b ) );
}

template< typename T >
inline int bvu ::
ccw ( const vec2<T> & a, const vec2<T> & b )
{
    T area = parallelogramArea( a, b );
    if ( area > 0 ) return 1;
    else if ( area < 0 ) return 0;
    else return 2;
}
