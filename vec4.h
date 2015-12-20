#pragma once

namespace bvu
{
    template <typename T>
    struct vec4
    {
        union
        {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T p, q, s, t; };
            T data[4];
        };

        vec4 ( void );
        vec4 ( T v );
        vec4 ( T x, T y, T z, T w );
        vec4 ( const vec4<T> &other );
        vec4 ( const vec2<T> &other, const T v );
        vec4 ( const vec2<T> &other, const T v1, const T v2 );
        vec4 ( const vec3<T> &other, const T v );
        vec4 ( const T v, const vec3<T> &other );

        vec4<T> & operator= ( const vec4<T> & v );

        void operator+=   ( const vec4<T> & other );
        void operator+=   ( const T constant );
        vec4<T> operator+ ( const vec4<T> & other ) const;
        vec4<T> operator+ ( const T constant ) const;

        void operator-=   ( const vec4<T> & other );
        void operator-=   ( const T constant );
        vec4<T> operator- ( const vec4<T> & other ) const;
        vec4<T> operator- ( const T constant ) const;
        vec4<T> operator- () const;

        void operator*=   ( const vec4<T> & other );
        void operator*=   ( const T constant );
        vec4<T> operator* ( const vec4<T> & other ) const;
        vec4<T> operator* ( const T constant ) const;

        void operator/=   ( const vec4<T> & other );
        void operator/=   ( const T constant );
        vec4<T> operator/ ( const vec4<T> & other ) const;
        vec4<T> operator/ ( const T constant ) const;

        bool operator== ( const vec4<T> & other ) const;
        bool operator!= ( const vec4<T> & other ) const;

        T operator[] ( unsigned int i ) const;
        T& operator[] ( unsigned int i );

        const constexpr int size() const { return 4; }
    };

    template <typename T>
    vec4<T> ::
    vec4 ( void ) : x( (T)0 ), y( (T)0 ), z( (T)0 ), w( (T)0 )
    {}

    template <typename T>
    vec4<T> ::
    vec4 ( T v ) : x( v ), y( v ), z( v ), w( v )
    {}

    template <typename T>
    vec4<T> ::
    vec4 ( T x, T y, T z, T w ) : x( x ), y( y ), z( z ), w( w )
    {}

    template <typename T>
    vec4<T> ::
    vec4 ( const vec4<T> &other ) : x( other.x ), y( other.y ), z( other.z ), w( other.w )
    {}

    template <typename T>
    vec4<T> ::
    vec4( const vec2<T> &other, const T v ) : x( other.x ), y( other.y ), z( v ), w( v )
    {}

    template <typename T>
    vec4<T> ::
    vec4 ( const vec2<T> &other, const T v1, const T v2 ) : x( other.x ), y( other.y ), z( v1 ), w( v2 )
    {}

    template <typename T>
    vec4<T> ::
    vec4 ( const vec3<T> &other, const T v ) : x( other.x ),y( other.y ), z( other.z ), w( v ) {}

    template <typename T>
    vec4<T> ::
    vec4 ( const T v, const vec3<T> &other ) : x( v ), y( other.x ), z( other.y ), w( other.z )
    {}

    template <typename T>
    inline vec4<T> & vec4<T> ::
    operator= ( const vec4<T> & v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
        return *this;
    }

    template <typename T>
    inline void vec4<T> ::
    operator+= ( const vec4<T> & other )
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;
    }

    template <typename T>
    inline void vec4<T> ::
    operator+= ( const T constant )
    {
        this->x += constant;
        this->y += constant;
        this->z += constant;
        this->w += constant;
    }

    template <typename T>
    inline vec4<T> vec4<T> ::
    operator+ ( const vec4<T> & other ) const
    {
        vec4<T> result( *this );
        result += other;
        return result;
    }

    template <typename T>
    inline vec4<T> vec4<T> ::
    operator+ ( const T constant ) const
    {
        vec4<T> result( *this );
        result += constant;
        return result;
    }


    template <typename T>
    inline void vec4<T> ::
    operator-= ( const vec4<T> & other )
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;
    }

    template <typename T>
    inline void vec4<T> ::
    operator-= ( const T constant )
    {
        this->x -= constant;
        this->y -= constant;
        this->z -= constant;
        this->w -= constant;
    }


    template <typename T>
    inline vec4<T> vec4<T> ::
    operator- ( const vec4<T> & other ) const
    {
        vec4<T> result( *this );
        result -= other;
        return result;
    }


    template <typename T>
    inline vec4<T> vec4<T> ::
    operator- ( const T constant ) const
    {
        vec4<T> result( *this );
        result -= constant;
        return result;
    }


    template <typename T>
    inline vec4<T> vec4<T> ::
    operator- () const
    {
        vec4<T> result;
        result.x = -this->x;
        result.y = -this->y;
        result.z = -this->z;
        result.w = -this->w;
        return result;
    }


    template <typename T>
    inline void vec4<T> ::
    operator*= ( const vec4<T> & other )
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;
        this->w *= other.w;
    }

    template <typename T>
    inline void vec4<T> ::
    operator*= ( const T constant )
    {
        this->x *= constant;
        this->y *= constant;
        this->z *= constant;
        this->w *= constant;
    }


    template <typename T>
    inline vec4<T> vec4<T> ::
    operator* ( const vec4<T> & other ) const
    {
        vec4<T> result( *this );
        result *= other;
        return result;
    }

    template <typename T>
    inline vec4<T> vec4<T> ::
    operator* ( const T constant ) const
    {
        vec4<T> result( *this );
        result *= constant;
        return result;
    }

    template <typename T>
    inline void vec4<T> ::
    operator/= ( const vec4<T> & other )
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;
        this->w /= other.w;
    }

    template <typename T>
    inline void vec4<T> ::
    operator/= ( const T constant )
    {
        T Invconstant = 1.0f / constant;
        this->x *= Invconstant;
        this->y *= Invconstant;
        this->z *= Invconstant;
        this->w *= Invconstant;
    }

    template <typename T>
    inline vec4<T> vec4<T> ::
    operator/ ( const vec4<T> & other ) const
    {
        vec4<T> result( *this );
        result /= other;
        return result;
    }

    template <typename T>
    inline vec4<T> vec4<T> ::
    operator/ ( const T constant ) const
    {
        vec4<T> result( *this );
        result *= ( 1.0f / constant );
        return result;
    }

    template <typename T>
    inline T vec4<T> ::
    operator[] ( unsigned int i ) const
    {
        return this->data[ i ];
    }

    template <typename T>
    inline T& vec4<T> ::
    operator[] ( unsigned int i )
    {
        return this->data[ i ];
    }

    template <typename T>
    inline bool vec4<T> ::
    operator== ( const vec4<T>& other ) const
    {
        if ( this->x == other.x &&
             this->y == other.y &&
             this->z == other.z &&
             this->w == other.z )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename T>
    inline bool vec4<T> ::
    operator!= ( const vec4<T>& other ) const
    {
        return !(*this == other);
    }
}


// Debug Prints
// inline void
// print ( const vec2f & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f\n", v.x, v.y );
// }

// inline void
// print ( const vec2d & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f\n", v.x, v.y );
// }

// inline void
// print ( const vec2i & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5d %5d\n", v.x, v.y );
// }



// inline void
// print ( const vec3f & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f %5.3f\n", v.x, v.y, v.z );
// }

// inline void
// print( const vec3d & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f %5.3f\n", v.x, v.y, v.z );
// }

// inline void
// print( const vec3i & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5d %5d %5d \n", v.x, v.y, v.z );
// }



// inline void
// print( const vec4f & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", v.x, v.y, v.z, v.w );
// }

// inline void
// print( const vec4d & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5.3f %5.3f %5.3f %5.3f\n", v.x, v.y, v.z, v.w );
// }

// inline void
// print( const vec4i & v, FILE * stream = stdout ) {
//     fprintf ( stream, "%5d %5d %5d %5d\n", v.x, v.y, v.z, v.w );
// }

////////////////////////////////////////////////////////////////////////////////
// Old SSE code for possible future reference
////////////////////////////////////////////////////////////////////////////////

/*
//calculating Norm
    __m128 divisor = _mm_Mul_ps(this->test, this->test);
    divisor = _mm_hAdd_ps(divisor, divisor);
    divisor = _mm_hAdd_ps(divisor, divisor);
// calculating 1/Norm
    divisor = _mm_rsqrt_ps( divisor );
// Normalizing the vector
    this->vec4 = _mm_Mul_ps( this->vec4, divisor );
*/

/*
void
printSSEVec( const __m128 vec,  FILE * stream = stdout ) {
    float res[4];
    _mm_store_ps( res, vec );
    fprintf( stream, "%f %f %f %f\n", res[0], res[1], res[2], res[3] );
}
*/
