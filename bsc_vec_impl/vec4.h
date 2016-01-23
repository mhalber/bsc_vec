#pragma once

namespace bsc
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

        void operator-=   ( const vec4<T> & other );
        void operator-=   ( const T constant );

        void operator*=   ( const vec4<T> & other );
        void operator*=   ( const T constant );

        void operator/=   ( const vec4<T> & other );
        void operator/=   ( const T constant );

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
    inline vec4<T>
    operator+ ( const vec4<T> & v1, const vec4<T> & v2 )
    {
        vec4<T> result( v1.x + v2.x,
                        v1.y + v2.y,
                        v1.z + v2.z,
                        v1.w + v2.w );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator+ ( const vec4<T> & v, const T constant )
    {
        vec4<T> result( v.x + constant,
                        v.y + constant,
                        v.z + constant,
                        v.w + constant );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator+ ( const T constant, const vec4<T> & v )
    {
        vec4<T> result( v.x + constant,
                        v.y + constant,
                        v.z + constant,
                        v.w + constant );
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
    inline vec4<T>
    operator- ( const vec4<T> & v1, const vec4<T> & v2 )
    {
        vec4<T> result( v1.x - v2.x,
                        v1.y - v2.y,
                        v1.z - v2.z,
                        v1.w - v2.w );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator- ( const vec4<T> & v, const T constant )
    {
        vec4<T> result( v.x - constant,
                        v.y - constant,
                        v.z - constant,
                        v.w - constant );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator- ( const T constant, const vec4<T> & v )
    {
        vec4<T> result( constant - v.x,
                        constant - v.y,
                        constant - v.z,
                        constant - v.w );
        return result;
    }


    template <typename T>
    inline vec4<T>
    operator- ( const vec4<T> & v )
    {
        vec4<T> result( -v.x,
                        -v.y,
                        -v.z,
                        -v.w );
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
    inline vec4<T>
    operator* ( const vec4<T> & v1, const vec4<T> & v2 )
    {
        vec4<T> result( v1.x * v2.x,
                        v1.y * v2.y,
                        v1.z * v2.z,
                        v1.w * v2.w );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator* ( const vec4<T> & v, const T constant )
    {
        vec4<T> result( v.x * constant,
                        v.y * constant,
                        v.z * constant,
                        v.w * constant );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator* ( const T constant, const vec4<T> & v )
    {
        vec4<T> result( v.x * constant,
                        v.y * constant,
                        v.z * constant,
                        v.w * constant );
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
        T inv_constant = 1.0f / constant;
        this->x *= inv_constant;
        this->y *= inv_constant;
        this->z *= inv_constant;
        this->w *= inv_constant;
    }

    template <typename T>
    inline vec4<T>
    operator/ ( const vec4<T> & v1, const vec4<T> & v2 )
    {
        vec4<T> result( v1.x / v2.x,
                        v1.y / v2.y,
                        v1.z / v2.z,
                        v1.w / v2.w );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator/ ( const vec4<T> & v, const T constant )
    {
        vec4<T> result( v.x / constant,
                        v.y / constant,
                        v.z / constant,
                        v.w / constant );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator/ ( const T constant, const vec4<T> & v )
    {
        vec4<T> result( constant / v.x,
                        constant / v.y,
                        constant / v.z,
                        constant / v.w );
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
