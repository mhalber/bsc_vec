#pragma once

namespace bvu
{
    template <typename T>
    struct mat4 {

        union
        {
            T data[16];
            vec4<T> cols[4];
        };

        mat4 ( bool initialize = true );
        mat4 ( const T constant );
        mat4 ( const T other[16] );
        mat4 ( const mat2<T> & other );
        mat4 ( const mat3<T> & other );
        mat4 ( const mat4<T> & other );
        mat4 ( const vec4<T> & diagonal );
        mat4 ( const vec4<T> & col0,
               const vec4<T> & col1,
               const vec4<T> & col2,
               const vec4<T> & col3 );

        mat4<T> & operator= ( const mat4<T> & other );

        void operator+= ( const mat4<T> & other );
        void operator+= ( const T constant );
        mat4<T> operator+ ( const mat4<T> & other ) const;
        mat4<T> operator+ ( const T constant ) const;

        void operator-= ( const mat4<T> & other );
        void operator-= ( const T constant );
        mat4<T> operator- ( const mat4<T> & other ) const;
        mat4<T> operator- ( const T constant ) const;

        void operator*= ( const mat4<T> & other );
        void operator*= ( const T constant );
        mat4<T> operator* ( const mat4<T> & other ) const;
        mat4<T> operator* ( const T constant ) const;
        vec4<T> operator* ( const vec4<T> & v ) const;
        void pointwiseMultiply ( const mat4<T> &other );

        void operator/= ( const mat4<T> & other );
        void operator/= ( const T constant );
        mat4<T> operator/ ( const mat4<T> & other ) const;
        mat4<T> operator/ ( const T constant ) const;

        vec4<T>& operator[] ( unsigned int i );
        vec4<T>  operator[] ( unsigned int i ) const;

        bool operator== ( const mat2<T> & other ) const;
        bool operator!= ( const mat2<T> & other ) const;

        const constexpr int dimensionality () const  { return 4; }
        const constexpr int size () const  { return 16; }
    };

    template <typename T>
    mat4<T>::
    mat4 ( bool intialize )
    {
        if ( intialize )
        {
            this->data[ 0] = (T)1.0;
            this->data[ 1] = (T)0.0;
            this->data[ 2] = (T)0.0;
            this->data[ 3] = (T)0.0;

            this->data[ 4] = (T)0.0;
            this->data[ 5] = (T)1.0;
            this->data[ 6] = (T)0.0;
            this->data[ 7] = (T)0.0;

            this->data[ 8] = (T)0.0;
            this->data[ 9] = (T)0.0;
            this->data[10] = (T)1.0;
            this->data[11] = (T)0.0;

            this->data[12] = (T)0.0;
            this->data[13] = (T)0.0;
            this->data[14] = (T)0.0;
            this->data[15] = (T)1.0;
        }
    }

    template <typename T>
    mat4<T>::
    mat4 ( const T c )
    {
        for ( int i = 0 ; i < 16 ; ++i )
        {
            data[i] = c;
        }
    }


    template <typename T>
    mat4<T>::
    mat4 ( const T other[16] )
    {
        for ( int i = 0 ; i < 16 ; ++i )
        {
            data[i] = other[i];
        }
    }

    template <typename T>
    mat4<T>::
    mat4 ( const mat2<T> & other )
    {
        this->data[ 0] = other.data[0];
        this->data[ 1] = other.data[1];
        this->data[ 2] = (T)0.0;
        this->data[ 3] = (T)0.0;
        this->data[ 4] = other.data[2];
        this->data[ 5] = other.data[3];
        this->data[ 6] = (T)0.0;
        this->data[ 7] = (T)0.0;
        this->data[ 8] = (T)0.0;
        this->data[ 9] = (T)0.0;
        this->data[10] = (T)1.0;
        this->data[11] = (T)0.0;
        this->data[12] = (T)0.0;
        this->data[13] = (T)0.0;
        this->data[14] = (T)0.0;
        this->data[15] = (T)1.0;
    }

    template <typename T>
    mat4<T>::
    mat4 ( const mat3<T> & other )
    {
        this->data[ 0] = other.data[0];
        this->data[ 1] = other.data[1];
        this->data[ 2] = other.data[2];
        this->data[ 3] = (T)0.0;
        this->data[ 4] = other.data[3];
        this->data[ 5] = other.data[4];
        this->data[ 6] = other.data[5];
        this->data[ 7] = (T)0.0;
        this->data[ 8] = other.data[6];
        this->data[ 9] = other.data[7];
        this->data[10] = other.data[8];
        this->data[11] = (T)0.0;
        this->data[12] = (T)0.0;
        this->data[13] = (T)0.0;
        this->data[14] = (T)0.0;
        this->data[15] = (T)1.0;
    }

    template <typename T>
    mat4<T>::
    mat4 ( const mat4<T> & other )
    {
        this->data[ 0] = other.data[ 0];
        this->data[ 1] = other.data[ 1];
        this->data[ 2] = other.data[ 2];
        this->data[ 3] = other.data[ 3];
        this->data[ 4] = other.data[ 4];
        this->data[ 5] = other.data[ 5];
        this->data[ 6] = other.data[ 6];
        this->data[ 7] = other.data[ 7];
        this->data[ 8] = other.data[ 8];
        this->data[ 9] = other.data[ 9];
        this->data[10] = other.data[10];
        this->data[11] = other.data[11];
        this->data[12] = other.data[12];
        this->data[13] = other.data[13];
        this->data[14] = other.data[14];
        this->data[15] = other.data[15];
    }

    template <typename T>
    mat4<T>::
    mat4 ( const vec4<T> & diagonal )
    {
        for ( int i = 0 ; i < 16 ; ++i )
        {
            data[i] = (T)0.0;
        }
        data[ 0]  = diagonal.x;
        data[ 5]  = diagonal.y;
        data[10] = diagonal.z;
        data[15] = diagonal.w;
    }

    template <typename T>
    mat4<T>::
    mat4 ( const vec4<T> & col0, const vec4<T> & col1, const vec4<T> & col2, const vec4<T> & col3 )
    {
        cols[0] = col0;
        cols[1] = col1;
        cols[2] = col2;
        cols[3] = col3;

    }

    template <typename T>
    inline mat4<T> & mat4<T>::
    operator= ( const mat4<T> & other )
    {
        this->data[ 0] = other.data[ 0];
        this->data[ 1] = other.data[ 1];
        this->data[ 2] = other.data[ 2];
        this->data[ 3] = other.data[ 3];
        this->data[ 4] = other.data[ 4];
        this->data[ 5] = other.data[ 5];
        this->data[ 6] = other.data[ 6];
        this->data[ 7] = other.data[ 7];
        this->data[ 8] = other.data[ 8];
        this->data[ 9] = other.data[ 9];
        this->data[10] = other.data[10];
        this->data[11] = other.data[11];
        this->data[12] = other.data[12];
        this->data[13] = other.data[13];
        this->data[14] = other.data[14];
        this->data[15] = other.data[15];
        return *this;
    }

    template <typename T>
    inline void mat4<T>::
    operator+= ( const mat4<T> & other )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   += other.data[i];
            this->data[i+1] += other.data[i+1];
            this->data[i+2] += other.data[i+2];
            this->data[i+3] += other.data[i+3];
        }
    }

    template <typename T>
    inline void mat4<T>::
    operator+= ( const T constant )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   += constant;
            this->data[i+1] += constant;
            this->data[i+2] += constant;
            this->data[i+3] += constant;
        }
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator+ ( const mat4<T> & other ) const
    {
        mat4<T> Result( *this );
        Result += other;
        return Result;
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator+ ( const T constant ) const
    {
        mat4<T> Result( *this );
        Result += constant;
        return Result;
    }

    // Mat4 substraction

    template <typename T>
    inline void mat4<T>::
    operator-= ( const mat4<T> & other )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   -= other.data[i];
            this->data[i+1] -= other.data[i+1];
            this->data[i+2] -= other.data[i+2];
            this->data[i+3] -= other.data[i+3];
        }
    }

    template <typename T>
    inline void mat4<T>::
    operator-= ( const T constant )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   -= constant;
            this->data[i+1] -= constant;
            this->data[i+2] -= constant;
            this->data[i+3] -= constant;
        }
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator- ( const mat4<T> & other ) const
    {
        mat4<T> Result( *this );
        Result -= other;
        return Result;
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator- ( const T constant ) const
    {
        mat4<T> Result( *this );
        Result -= constant;
        return Result;
    }

    // Mat4 multiplication

    template <typename T>
    inline void mat4<T>::
    operator*= ( const mat4<T> & other )
    {
        T vals[16];

        vals[ 0] = other.data[ 0] * data[0] + other.data[ 1] * data[4] + other.data[ 2] * data[ 8] + other.data[ 3] * data[12];
        vals[ 1] = other.data[ 0] * data[1] + other.data[ 1] * data[5] + other.data[ 2] * data[ 9] + other.data[ 3] * data[13];
        vals[ 2] = other.data[ 0] * data[2] + other.data[ 1] * data[6] + other.data[ 2] * data[10] + other.data[ 3] * data[14];
        vals[ 3] = other.data[ 0] * data[3] + other.data[ 1] * data[7] + other.data[ 2] * data[11] + other.data[ 3] * data[15];

        vals[ 4] = other.data[ 4] * data[0] + other.data[ 5] * data[4] + other.data[ 6] * data[ 8] + other.data[ 7] * data[12];
        vals[ 5] = other.data[ 4] * data[1] + other.data[ 5] * data[5] + other.data[ 6] * data[ 9] + other.data[ 7] * data[13];
        vals[ 6] = other.data[ 4] * data[2] + other.data[ 5] * data[6] + other.data[ 6] * data[10] + other.data[ 7] * data[14];
        vals[ 7] = other.data[ 4] * data[3] + other.data[ 5] * data[7] + other.data[ 6] * data[11] + other.data[ 7] * data[15];

        vals[ 8] = other.data[ 8] * data[0] + other.data[ 9] * data[4] + other.data[10] * data[ 8] + other.data[11] * data[12];
        vals[ 9] = other.data[ 8] * data[1] + other.data[ 9] * data[5] + other.data[10] * data[ 9] + other.data[11] * data[13];
        vals[10] = other.data[ 8] * data[2] + other.data[ 9] * data[6] + other.data[10] * data[10] + other.data[11] * data[14];
        vals[11] = other.data[ 8] * data[3] + other.data[ 9] * data[7] + other.data[10] * data[11] + other.data[11] * data[15];

        vals[12] = other.data[12] * data[0] + other.data[13] * data[4] + other.data[14] * data[ 8] + other.data[15] * data[12];
        vals[13] = other.data[12] * data[1] + other.data[13] * data[5] + other.data[14] * data[ 9] + other.data[15] * data[13];
        vals[14] = other.data[12] * data[2] + other.data[13] * data[6] + other.data[14] * data[10] + other.data[15] * data[14];
        vals[15] = other.data[12] * data[3] + other.data[13] * data[7] + other.data[14] * data[11] + other.data[15] * data[15];

        for ( int i = 0 ; i < 16 ; ++i )
        {
            data[i] = vals[i];
        }
    }

    template <typename T>
    inline void mat4<T>::
    operator*= ( const T constant )
    {
        for ( int i = 0 ; i < 16 ; ++i )
        {
            data[i] *= constant;
        }
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator* ( const mat4<T> & other ) const
    {
        mat4<T> Result( *this );
        Result *= other;
        return Result;
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator* ( const T constant ) const
    {
        mat4<T> Result( *this );
        Result *= constant;
        return Result;
    }

    template <typename T>
    inline vec4<T> mat4<T>::
    operator* ( const vec4<T> & v ) const
    {
        vec4<T> output;

        output.x = data[0] * v.x + data[4] * v.y + data[ 8] * v.z + data[12] * v.w;
        output.y = data[1] * v.x + data[5] * v.y + data[ 9] * v.z + data[13] * v.w;
        output.z = data[2] * v.x + data[6] * v.y + data[10] * v.z + data[14] * v.w;
        output.w = data[3] * v.x + data[7] * v.y + data[11] * v.z + data[15] * v.w;

        return output;
    }

    template <typename T>
    inline void mat4<T>::
    pointwiseMultiply ( const mat4<T> & other )
    {
        for ( int i = 0 ; i < 16 ; ++i ) {
            data[i] *= other.data[i];
        }
    }

    // Mat4 division

    template <typename T>
    inline void mat4<T>::
    operator/= ( const mat4<T> & other )
    {
        mat4<T> inv_other = Inverse( other );
        (*this) *= inv_other;
    }

    template <typename T>
    inline void mat4<T>::
    operator/= ( const T constant )
    {
        float inv_constant = (T)1.0 / constant;
        for ( int i = 0 ; i < 16 ; ++i ) {
            data[i] *= inv_constant;
        }
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator/ ( const mat4<T> & other ) const
    {
        mat4<T> Result( *this );
        Result /= other;
        return Result;
    }

    template <typename T>
    inline mat4<T> mat4<T>::
    operator/ ( const T constant ) const
    {
        mat4<T> Result( *this );
        Result /= constant;
        return Result;
    }


    template <typename T>
    inline vec4<T> & mat4<T>::
    operator[] ( unsigned int i )
    {
        return cols[i];
    }

    template <typename T>
    inline vec4<T> mat4<T>::
    operator[] ( unsigned int i ) const
    {
        return cols[i];
    }
}
