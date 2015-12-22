#pragma once

namespace bvu
{
    template <typename T>
    struct vec2
    {
        union
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T p, q; };
            T data[2];
        };

        vec2 ( void );
        vec2 ( T v );
        vec2 ( T x, T y );
        vec2 ( const vec2<T> &other );
        vec2 ( const vec3<T> &other );
        vec2 ( const vec4<T> &other );

        vec2<T> & operator=( const vec2<T> & other );

        void operator+=   ( const vec2<T> & other );
        void operator+=   ( const T constant );

        void operator-=   ( const vec2<T> & other );
        void operator-=   ( const T constant );

        void operator*=   ( const vec2<T> & other );
        void operator*=   ( const T constant );

        void operator/=   ( const vec2<T> & other );
        void operator/=   ( const T constant );

        bool operator== ( const vec2<T> & other ) const;
        bool operator!= ( const vec2<T> & other ) const;

        T operator[] ( unsigned int i ) const;
        T& operator[] ( unsigned int i );

        const constexpr int size() const  { return 2; }
    };

    template <typename T>
    vec2<T> ::
    vec2 ( void ) : x( (T) 0 ), y( (T) 0 )
    {}


    template <typename T>
    vec2<T> ::
    vec2 ( T v ) : x( v ), y( v )
    {}


    template <typename T>
    vec2<T> ::
    vec2 ( T x, T y ) : x( x ), y( y )
    {}


    template <typename T>
    vec2<T> ::
    vec2 ( const vec2<T> &other ) : x( other.x ), y( other.y )
    {}


    template <typename T>
    vec2<T> ::
    vec2 ( const vec3<T> &other ) : x( other.x ), y( other.y )
    {}


    template <typename T>
    vec2<T> ::
    vec2 ( const vec4<T> &other ) : x( other.x ), y( other.y )
    {}

    template <typename T>
    inline vec2<T> & vec2<T> ::
    operator= ( const vec2<T> & v)
    {
        this->x = v.x;
        this->y = v.y;
    }

    template <typename T>
    inline void vec2<T> ::
    operator+= ( const vec2<T> & other )
    {
        this->x += other.x;
        this->y += other.y;
    }


    template <typename T>
    inline void vec2<T> ::
    operator+= ( const T constant )
    {
        this->x += constant;
        this->y += constant;
    }


    template <typename T>
    inline vec2<T>
    operator+ ( const vec2<T> & v1, const vec2<T> & v2 )
    {
        vec2<T> result( v1.x + v2.x,
                        v1.y + v2.y );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator+ ( const vec2<T> & v, const T constant )
    {
        vec2<T> result( v.x + constant,
                        v.y + constant );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator+ ( const T constant, const vec2<T> & v )
    {
        vec2<T> result( v.x + constant,
                        v.y + constant );
        return result;
    }


    template <typename T>
    inline void vec2<T> ::
    operator-= ( const vec2<T> & other )
    {
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename T>
    inline void vec2<T> ::
    operator-= ( const T constant )
    {
        this->x -= constant;
        this->y -= constant;
    }


    template <typename T>
    inline vec2<T>
    operator- ( const vec2<T> & v1, const vec2<T> & v2 )
    {
        vec2<T> result( v1.x - v2.x,
                        v1.y - v2.y );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator- ( const vec2<T> & v, const T constant )
    {
        vec2<T> result( v.x - constant,
                        v.y - constant );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator- ( const T constant, const vec2<T> & v )
    {
        vec2<T> result( constant - v.x,
                        constant - v.y );
        return result;
    }


    template <typename T>
    inline vec2<T>
    operator- ( const vec2<T> & v )
    {
        vec2<T> result( -v.x,
                        -v.y );
        return result;
    }


    template <typename T>
    inline void vec2<T> ::
    operator*= ( const vec2<T> & other )
    {
        this->x *= other.x;
        this->y *= other.y;
    }

    template <typename T>
    inline void vec2<T> ::
    operator*= ( const T constant )
    {
        this->x *= constant;
        this->y *= constant;
    }


    template <typename T>
    inline vec2<T>
    operator* ( const vec2<T> & v1, const vec2<T> & v2 )
    {
        vec2<T> result( v1.x * v2.x,
                        v1.y * v2.y );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator* ( const vec2<T> & v, const T constant )
    {
        vec2<T> result( v.x * constant,
                        v.y * constant );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator* ( const T constant, const vec2<T> & v )
    {
        vec2<T> result( v.x * constant,
                        v.y * constant );
        return result;
    }

    template <typename T>
    inline void vec2<T> ::
    operator/= ( const vec2<T> & other )
    {
        this->x /= other.x;
        this->y /= other.y;
    }

    template <typename T>
    inline void vec2<T> ::
    operator/= ( const T constant )
    {
        T inv_constant = 1.0f / constant;
        this->x *= inv_constant;
        this->y *= inv_constant;
    }

    template <typename T>
    inline vec2<T>
    operator/ ( const vec2<T> & v1, const vec2<T> & v2 )
    {
        vec2<T> result( v1.x / v2.x,
                        v1.y / v2.y );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator/ ( const vec2<T> & v, const T constant )
    {
        vec2<T> result( v.x / constant,
                        v.y / constant );
        return result;
    }

    template <typename T>
    inline vec2<T>
    operator/ ( const T constant, const vec2<T> & v )
    {
        vec2<T> result( constant / v.x,
                        constant / v.y );
        return result;
    }


    template <typename T>
    inline T vec2<T> ::
    operator[] ( unsigned int i ) const
    {
        return this->data[ i ];
    }


    template <typename T>
    inline T& vec2<T> ::
    operator[] ( unsigned int i )
    {
        return this->data[ i ];
    }


    template <typename T>
    inline bool vec2<T> ::
    operator== ( const vec2<T>& other ) const
    {
        if ( this->x == other.x &&
             this->y == other.y )
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    template <typename T>
    inline bool vec2<T> ::
    operator!= (const vec2<T>& other) const
    {
        return !(*this == other);
    }
}
