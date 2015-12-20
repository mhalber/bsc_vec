#pragma once

namespace bvu
{
    template <typename T>
    struct mat2 {

        union
        {
            T data[4];
            vec2<T> cols[2];
        };

        mat2 ( bool initialize = true );
        mat2 ( const T constant );
        mat2 ( const T other[4] );
        mat2 ( const mat2<T> & other );
        mat2 ( const mat3<T> & other );
        mat2 ( const mat4<T> & other );
        mat2 ( const vec2<T> & diagonal );
        mat2 ( const vec2<T> & col0,
               const vec2<T> & col1 );

        mat2<T> & operator= ( const mat2<T> & other );

        void operator+= ( const mat2<T> & other );
        void operator+= ( const T constant );
        mat2<T> operator+ ( const mat2<T> & other ) const;
        mat2<T> operator+ ( const T constant ) const;

        void operator-=( const mat2<T> & other );
        void operator-=( const T constant );
        mat2<T> operator-( const mat2<T> & other ) const;
        mat2<T> operator-( const T constant ) const;

        void operator*= ( const mat2<T> & other );
        void operator*= ( const T constant );
        mat2<T> operator* ( const mat2<T> & other ) const;
        mat2<T> operator* ( const T constant ) const;
        vec2<T> operator* ( const vec2<T> & v ) const;
        void pointwiseMultiply ( const mat2<T> &other ); // this is sort of an operator

        void operator/= ( const mat2<T> & other );
        void operator/= ( const T constant );
        mat2<T> operator/ ( const mat2<T> & other ) const;
        mat2<T> operator/ ( const T constant ) const;

        vec2<T>& operator[] ( unsigned int i );
        vec2<T>  operator[] ( unsigned int i ) const;

        bool operator== ( const mat2<T> & other ) const;
        bool operator!= ( const mat2<T> & other ) const;

        const constexpr int dimensionality () const  { return 2; }
        const constexpr int size () const  { return 4; }
    };


    template <typename T>
    mat2<T>::
    mat2 ( bool intialize )
    {
        if ( intialize )
        {
            this->data[ 0] = (T)1.0;
            this->data[ 1] = (T)0.0;
            this->data[ 2] = (T)0.0;
            this->data[ 3] = (T)1.0;
        }
    }

    template <typename T>
    inline mat2<T> ::
    mat2 ( const T c )
    {
        for ( int i = 0 ; i < 4 ; ++i )
        {
            data[i] = c;
        }
    }

    template <typename T>
    inline mat2<T> ::
    mat2 ( const T other[4] )
    {
        for ( int i = 0 ; i < 4 ; ++i )
        {
            data[i] = other[i];
        }
    }


    template <typename T>
    mat2<T>::
    mat2 ( const mat2<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = other.data[2];
        this->data[3] = other.data[3];
    }

    template <typename T>
    mat2<T>::
    mat2 ( const mat3<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = other.data[3];
        this->data[3] = other.data[4];
    }

    template <typename T>
    mat2<T>::
    mat2 ( const mat4<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = other.data[4];
        this->data[3] = other.data[5];
    }


    template <typename T>
    mat2<T>::
    mat2 ( const vec2<T> & diagonal )
    {
        for ( int i = 0 ; i < 4 ; ++i )
        {
            data[i] = 0;
        }
        data[0]  = diagonal.x;
        data[3]  = diagonal.y;

    }


    template <typename T>
    mat2<T>::
    mat2 ( const vec2<T> & col0, const vec2<T> & col1 )
    {
        cols[0] = col0;
        cols[1] = col1;
    }

    // Mat2 addition

    template <typename T>
    inline void mat2<T>::
    operator+= ( const mat2<T> & other )
    {
        this->data[0] += other.data[0];
        this->data[1] += other.data[1];
        this->data[2] += other.data[2];
        this->data[3] += other.data[3];
    }

    template <typename T>
    inline void mat2<T>::
    operator+= ( const T constant )
    {
        this->data[0] += constant;
        this->data[1] += constant;
        this->data[2] += constant;
        this->data[3] += constant;
    }

    template <typename T>
    inline mat2<T> mat2<T> :: // TODO inline?
    operator+ ( const mat2<T> & other ) const
    {
        mat2<T> Result( *this );
        Result += other;
        return Result;
    }

    template <typename T>
    inline mat2<T> mat2<T> ::
    operator+ ( const T constant ) const
    {
        mat2<T> Result( *this );
        Result += constant;
        return Result;
    }

    // Mat2 substraction

    template <typename T>
    inline void mat2<T>::
    operator-= ( const mat2<T> & other )
    {
        this->data[0] -= other.data[0];
        this->data[1] -= other.data[1];
        this->data[2] -= other.data[2];
        this->data[3] -= other.data[3];
    }

    template <typename T>
    inline void mat2<T>::
    operator-= ( const T constant )
    {
        this->data[0] -= constant;
        this->data[1] -= constant;
        this->data[2] -= constant;
        this->data[3] -= constant;
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator- ( const mat2<T> & other ) const
    {
        mat2<T> Result( *this );
        Result -= other;
        return Result;
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator- ( const T constant ) const
    {
        mat2<T> Result( *this );
        Result -= constant;
        return Result;
    }

    // Mat2 multiplication

    template <typename T>
    inline void mat2<T>::
    operator*= ( const mat2<T> & other )
    {
        T vals[4];

        vals[0] = other.data[0] * data[0] + other.data[1] * data[2];
        vals[1] = other.data[0] * data[1] + other.data[1] * data[3];
        vals[2] = other.data[2] * data[0] + other.data[3] * data[2];
        vals[3] = other.data[2] * data[1] + other.data[3] * data[3];

        for ( int i = 0 ; i < 4 ; ++i ) {
            data[i] = vals[i];
        }
    }

    template <typename T>
    inline void mat2<T>::
    operator*= ( const T constant )
    {
        for ( int i = 0 ; i < 4 ; ++i )
        {
            data[i] *= constant;
        }
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator* ( const mat2<T> & other ) const
    {
        mat2<T> Result( *this );
        Result *= other;
        return Result;
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator* ( const T constant ) const
    {
        mat2<T> Result( *this );
        Result *= constant;
        return Result;
    }

    template <typename T>
    inline vec2<T> mat2<T>::
    operator* ( const vec2<T> & v ) const
    {
        vec2<T> output;

        output.x = data[0] * v.x + data[2] * v.y;
        output.y = data[1] * v.x + data[3] * v.y;

        return output;
    }

    template <typename T>
    inline void mat2<T>::
    pointwiseMultiply ( const mat2<T> & other )
    {
        for ( int i = 0 ; i < 4 ; ++i )
        {
            data[i] *= other.data[i];
        }
    }

    // Mat2 division

    template <typename T>
    inline void mat2<T>::
    operator/= ( const mat2<T> & other )
    {
        mat2<T> inv_other = Inverse( other );
        (*this) *= inv_other;
    }

    template <typename T>
    inline void mat2<T>::
    operator/= ( const T constant )
    {
        float inv_constant = (T)1.0 / (T)constant;
        for ( int i = 0 ; i < 4 ; ++i ) {
            data[i] *= inv_constant;
        }
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator/ ( const mat2<T> & other ) const
    {
        mat2<T> Result( *this );
        Result /= other;
        return Result;
    }

    template <typename T>
    inline mat2<T> mat2<T>::
    operator/ ( const T constant ) const
    {
        mat2<T> Result( *this );
        Result /= constant;
        return Result;
    }

    template <typename T>
    inline vec2<T> & mat2<T>::
    operator[] ( unsigned int i )
    {
        return cols[i];
    }

    template <typename T>
    inline vec2<T> mat2<T>::
    operator[] ( unsigned int i ) const
    {
        return cols[i];
    }
}
