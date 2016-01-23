#pragma once

namespace bsc
{
    template <typename T>
    struct quat
    {
        union
        {
            struct { T x, y, z, w; };
            struct { vec3<T> im; T re; };
        };


        quat();
        quat( const T re );
        quat( const vec3<T> & im );
        quat( const T re, const vec3<T> & im );
        quat( const T w, const T x, const T y, const T z );
        quat( const quat<T> & other );

        void operator+=( const quat<T> & other );
        void operator+=( const T constant );
        quat<T> operator+( const quat<T> & other ) const;
        quat<T> operator+( const T constant ) const;

        void operator-=( const quat<T> & other );
        void operator-=( const T constant );
        void operator- ( void );
        quat<T> operator-( const quat<T> & other ) const;
        quat<T> operator-( const T constant ) const;

        void operator*=( const quat<T> & other );
        void operator*=( const T constant );
        quat<T> operator*( const quat<T> & other ) const;
        quat<T> operator*( const T constant ) const;

        void operator/=( const quat<T> & other );
        void operator/=( const T constant );
        quat<T> operator/( const quat<T> & other ) const;
        quat<T> operator/( const T constant ) const;

        bool operator==( const quat<T> & other ) const;
        bool operator!=( const quat<T> & other ) const;

        T operator[] ( unsigned int i ) const;
        T& operator[] ( unsigned int i );
    };


    template <typename T>
    quat<T>::
    quat ()
    {
        this->re      = 0;
        this->im = vec3<T>();
    }

    template <typename T>
    quat<T>::
    quat ( const T re )
    {
        this->re = re;
        this->im = vec3<T>();
    }

    template <typename T>
    quat<T>::
    quat ( const vec3<T> & im )
    {
        this->re = (T)0;
        this->im = im;
    }

    template <typename T>
    quat<T>::
    quat ( const T re, const vec3<T> & im )
    {
        this->re = re;
        this->im = im;
    }

    template <typename T>
    quat<T>::
    quat ( const T w, const T x, const T y, const T z )
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    template <typename T>
    quat<T>::
    quat ( const quat<T> & other )
    {
        this->re = other.re;
        this->im = other.im;
    }

    template <typename T>
    inline void quat<T>::
    operator+=( const quat<T> & other )
    {
        this->re += other.re;
        this->im += other.im;
    }

    template <typename T>
    inline void quat<T>::
    operator+=( const T constant )
    {
        this->re += constant;
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator+( const quat<T> & other ) const
    {
        return quat<T>( this->re      + other.re,
                        this->im + other.im );
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator+( const T constant ) const
    {
        return quat<T>( this->re + constant,
                        this->im );
    }

    template <typename T>
    inline void quat<T>::
    operator-=( const quat<T> & other )
    {
        this->re -= other.re;
        this->im -= other.im;
    }

    template <typename T>
    inline void quat<T>::
    operator-=( const T constant )
    {
        this->re      -= constant;
    }

    template <typename T>
    inline void quat<T>::
    operator- ( void )
    {
        this->re = -this->re;
        this->im = -this->im ;
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator- ( const quat<T> & other ) const
    {
        return quat<T>( this->re - other.re,
                        this->im - other.im );
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator- ( const T constant ) const
    {
        return quat<T>( this->re - constant,
                        this->im );
    }

    template <typename T>
    inline void quat<T>::
    operator*= ( const quat<T> & other )
    {
        T tmp_re = this->re * other.re - bsc::dot( this->im, other.im );
        vec3<T> tmp_im = other.im * this->re  +
                         this->im * other.re +
                         bsc::cross( this->im, other.im );

        this->re = tmp_re;
        this->im = tmp_im;
    }

    template <typename T>
    inline void quat<T>::
    operator*= ( const T constant )
    {
        this->re      *= constant;
        this->im *= constant;
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator* ( const quat<T> & other ) const
    {
        quat<T> Result( *this );
        Result *= other;
        return Result;
    }

    template <typename T>
    inline quat<T> quat<T>::
    operator* ( const T constant ) const
    {
        return quat<T>( this->re * constant,
                        this->im * constant );
    }


    template <typename T>
    inline void quat<T>::
    operator/= ( const quat<T> & other )
    {
        quat<T> otherTmp ( other );
        otherTmp.inverse();

        this *= otherTmp;
    }

    template <typename T>
    inline void quat<T>::
    operator/= ( const T constant )
    {
        this->re      /= constant;
        this->im /= constant;
    }

    template <typename T>
    inline quat<T> quat<T> ::
    operator/ ( const quat<T> & other ) const
    {
        quat<T> Result( *this );
        Result /= other;
        return Result;
    }

    template <typename T>
    inline quat<T> quat<T> ::
    operator/ ( const T constant ) const
    {
        return quat<T>( this->re / constant,
                        this->im / constant );
    }
}
