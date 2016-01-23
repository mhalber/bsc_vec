#pragma once

namespace bsc
{
    template <typename T>
    struct vec3
    {
        union
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T p, q, s; };
            T data[3];
        };

        vec3<T> ( void );
        vec3<T> ( T v );
        vec3<T> ( T x, T y, T z );
        vec3<T> ( const vec3<T> & other );
        vec3<T> ( const T v, const vec2<T> & other );
        vec3<T> ( const vec2<T> & other, const T v );
        vec3<T> ( const vec4<T> & other );

        vec3<T> & operator= ( const vec3<T> & other );

        void operator+=   ( const vec3<T> & other );
        void operator+=   ( const T constant );

        void operator-=   ( const vec3<T> & other );
        void operator-=   ( const T constant );

        void operator*=   ( const vec3<T> & other );
        void operator*=   ( const T constant );

        void operator/=   ( const vec3<T> & other );
        void operator/=   ( const T constant );

        bool operator== ( const vec3<T> & other ) const;
        bool operator!= ( const vec3<T> & other ) const;

        T operator[] ( unsigned int i ) const;
        T& operator[] ( unsigned int i );

        const constexpr int size() const  { return 3; }
    };

    template <typename T>
    vec3<T> ::
    vec3 ( void ) : x( (T)0 ), y( (T)0 ), z( (T)0 )
    {}

    template <typename T>
    vec3<T> ::
    vec3 ( T v ) : x( v ), y( v ), z( v )
    {}

    template <typename T>
    vec3<T> ::
    vec3( T x, T y, T z ) : x( x ), y( y ), z( z )
    {
    }

    template <typename T>
    vec3<T> ::
    vec3 ( const vec3<T> &other ) : x( other.x ), y( other.y ), z( other.z )
    {
    }

    template <typename T>
    vec3<T> ::
    vec3 ( const T v, const vec2<T> &other ) : x( v ), y( other.x ), z( other.y )
    {}

    template <typename T>
    vec3<T> ::
    vec3 ( const vec2<T> &other, const T v ) : x( other.x ), y( other.y ), z( v )
    {}

    template <typename T>
    vec3<T> ::
    vec3 ( const vec4<T> &other ) : x( other.x ), y( other.y ), z( other.z )
    {}

    template <typename T>
    inline vec3<T> &  vec3<T> ::
    operator=( const vec3<T> & other )
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        return *this;
    }

    template <typename T>
    inline void vec3<T> ::
    operator+= ( const vec3<T> & other )
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
    }


    template <typename T>
    inline void vec3<T> ::
    operator+= ( const T constant )
    {
        this->x += constant;
        this->y += constant;
        this->z += constant;
    }


    template <typename T>
    inline vec3<T>
    operator+ ( const vec3<T> & v1, const vec3<T> & v2 )
    {
        vec3<T> result( v1.x + v2.x,
                        v1.y + v2.y,
                        v1.z + v2.z );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator+ ( const vec3<T> & v, const T constant )
    {
        vec3<T> result( v.x + constant,
                        v.y + constant,
                        v.z + constant );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator+ ( const T constant, const vec3<T> & v )
    {
        vec3<T> result( v.x + constant,
                        v.y + constant,
                        v.z + constant );
        return result;
    }


    template <typename T>
    inline void vec3<T> ::
    operator-= ( const vec3<T> & other )
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
    }

    template <typename T>
    inline void vec3<T> ::
    operator-= ( const T constant )
    {
        this->x -= constant;
        this->y -= constant;
        this->z -= constant;
    }


    template <typename T>
    inline vec3<T>
    operator- ( const vec3<T> & v1, const vec3<T> & v2 )
    {
        vec3<T> result( v1.x - v2.x,
                        v1.y - v2.y,
                        v1.z - v2.z );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator- ( const vec3<T> & v, const T constant )
    {
        vec3<T> result( v.x - constant,
                        v.y - constant,
                        v.z - constant );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator- ( const T constant, const vec3<T> & v )
    {
        vec3<T> result( constant - v.x,
                        constant - v.y,
                        constant - v.z );
        return result;
    }


    template <typename T>
    inline vec3<T>
    operator- ( const vec3<T> & v )
    {
        vec3<T> result( -v.x,
                        -v.y,
                        -v.z );
        return result;
    }


    template <typename T>
    inline void vec3<T> ::
    operator*= ( const vec3<T> & other )
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;
    }

    template <typename T>
    inline void vec3<T> ::
    operator*= ( const T constant )
    {
        this->x *= constant;
        this->y *= constant;
        this->z *= constant;
    }


    template <typename T>
    inline vec3<T>
    operator* ( const vec3<T> & v1, const vec3<T> & v2 )
    {
        vec3<T> result( v1.x * v2.x,
                        v1.y * v2.y,
                        v1.z * v2.z );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator* ( const vec3<T> & v, const T constant )
    {
        vec3<T> result( v.x * constant,
                        v.y * constant,
                        v.z * constant );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator* ( const T constant, const vec3<T> & v )
    {
        vec3<T> result( v.x * constant,
                        v.y * constant,
                        v.z * constant );
        return result;
    }

    template <typename T>
    inline void vec3<T> ::
    operator/= ( const vec3<T> & other )
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;
    }

    template <typename T>
    inline void vec3<T> ::
    operator/= ( const T constant )
    {
        T inv_constant = 1.0f / constant;
        this->x *= inv_constant;
        this->y *= inv_constant;
        this->z *= inv_constant;
    }

    template <typename T>
    inline vec3<T>
    operator/ ( const vec3<T> & v1, const vec3<T> & v2 )
    {
        vec3<T> result( v1.x / v2.x,
                        v1.y / v2.y,
                        v1.z / v2.z );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator/ ( const vec3<T> & v, const T constant )
    {
        vec3<T> result( v.x / constant,
                        v.y / constant,
                        v.z / constant );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator/ ( const T constant, const vec3<T> & v )
    {
        vec3<T> result( constant / v.x,
                        constant / v.y,
                        constant / v.z );
        return result;
    }

    template <typename T>
    inline T vec3<T> ::
    operator[] ( unsigned int i ) const
    {
        return this->data[ i ];
    }


    template <typename T>
    inline T& vec3<T> ::
    operator[] ( unsigned int i )
    {
        return this->data[ i ];
    }


    template <typename T>
    inline bool vec3<T> ::
    operator== ( const vec3<T>& other ) const
    {
        if ( this->x == other.x &&
             this->y == other.y &&
             this->z == other.z )
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    template <typename T>
    inline bool vec3<T> ::
    operator!= ( const vec3<T>& other ) const
    {
        return !(*this == other);
    }
}
