#pragma once

namespace bsc
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

        void operator-= ( const mat4<T> & other );
        void operator-= ( const T constant );

        void operator*= ( const mat4<T> & other );
        void operator*= ( const T constant );
        void pointwiseMultiply ( const mat4<T> &other );

        void operator/= ( const mat4<T> & other );
        void operator/= ( const T constant );

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
    inline mat4<T>
    operator+ ( const mat4<T> & m1, const mat4<T> & m2 )
    {
        mat4<T> result( m1[0] + m2[0],
                        m1[1] + m2[1],
                        m1[2] + m2[2],
                        m1[3] + m2[3] );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator+ ( const mat4<T> & m, const T constant )
    {
        mat4<T> result( m[0] + constant,
                        m[1] + constant,
                        m[2] + constant,
                        m[3] + constant );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator+ ( const T constant, const mat4<T> & m )
    {
        mat4<T> result( m[0] + constant,
                        m[1] + constant,
                        m[2] + constant,
                        m[3] + constant );
        return result;
    }



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
    inline mat4<T>
    operator- ( const mat4<T> & m1, const mat4<T> & m2 )
    {
        mat4<T> result( m1[0] - m2[0],
                        m1[1] - m2[1],
                        m1[2] - m2[2],
                        m1[3] - m2[3] );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator- ( const mat4<T> & m, const T constant )
    {
        mat4<T> result( m[0] - constant,
                        m[1] - constant,
                        m[2] - constant,
                        m[3] - constant );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator- ( const T constant, const mat4<T> & m )
    {
        mat4<T> result( constant - m[0],
                        constant - m[1],
                        constant - m[2],
                        constant - m[3] );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator- ( const mat4<T> & m )
    {
        mat4<T> result( -m[0],
                        -m[1],
                        -m[2],
                        -m[3] );
        return result;
    }

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

        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   = vals[i]  ;
            this->data[i+1] = vals[i+1];
            this->data[i+2] = vals[i+2];
            this->data[i+3] = vals[i+3];
        }
    }

    template <typename T>
    inline void mat4<T>::
    operator*= ( const T constant )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   *= constant;
            this->data[i+1] *= constant;
            this->data[i+2] *= constant;
            this->data[i+3] *= constant;
        }
    }

    template <typename T>
    inline mat4<T>
    operator* ( const mat4<T> & m1, const mat4<T> & m2 )
    {
        T vals[16];

        vals[ 0] = m2.data[ 0] * m1.data[0] + m2.data[ 1] * m1.data[4] + m2.data[ 2] * m1.data[ 8] + m2.data[ 3] * m1.data[12];
        vals[ 1] = m2.data[ 0] * m1.data[1] + m2.data[ 1] * m1.data[5] + m2.data[ 2] * m1.data[ 9] + m2.data[ 3] * m1.data[13];
        vals[ 2] = m2.data[ 0] * m1.data[2] + m2.data[ 1] * m1.data[6] + m2.data[ 2] * m1.data[10] + m2.data[ 3] * m1.data[14];
        vals[ 3] = m2.data[ 0] * m1.data[3] + m2.data[ 1] * m1.data[7] + m2.data[ 2] * m1.data[11] + m2.data[ 3] * m1.data[15];

        vals[ 4] = m2.data[ 4] * m1.data[0] + m2.data[ 5] * m1.data[4] + m2.data[ 6] * m1.data[ 8] + m2.data[ 7] * m1.data[12];
        vals[ 5] = m2.data[ 4] * m1.data[1] + m2.data[ 5] * m1.data[5] + m2.data[ 6] * m1.data[ 9] + m2.data[ 7] * m1.data[13];
        vals[ 6] = m2.data[ 4] * m1.data[2] + m2.data[ 5] * m1.data[6] + m2.data[ 6] * m1.data[10] + m2.data[ 7] * m1.data[14];
        vals[ 7] = m2.data[ 4] * m1.data[3] + m2.data[ 5] * m1.data[7] + m2.data[ 6] * m1.data[11] + m2.data[ 7] * m1.data[15];

        vals[ 8] = m2.data[ 8] * m1.data[0] + m2.data[ 9] * m1.data[4] + m2.data[10] * m1.data[ 8] + m2.data[11] * m1.data[12];
        vals[ 9] = m2.data[ 8] * m1.data[1] + m2.data[ 9] * m1.data[5] + m2.data[10] * m1.data[ 9] + m2.data[11] * m1.data[13];
        vals[10] = m2.data[ 8] * m1.data[2] + m2.data[ 9] * m1.data[6] + m2.data[10] * m1.data[10] + m2.data[11] * m1.data[14];
        vals[11] = m2.data[ 8] * m1.data[3] + m2.data[ 9] * m1.data[7] + m2.data[10] * m1.data[11] + m2.data[11] * m1.data[15];

        vals[12] = m2.data[12] * m1.data[0] + m2.data[13] * m1.data[4] + m2.data[14] * m1.data[ 8] + m2.data[15] * m1.data[12];
        vals[13] = m2.data[12] * m1.data[1] + m2.data[13] * m1.data[5] + m2.data[14] * m1.data[ 9] + m2.data[15] * m1.data[13];
        vals[14] = m2.data[12] * m1.data[2] + m2.data[13] * m1.data[6] + m2.data[14] * m1.data[10] + m2.data[15] * m1.data[14];
        vals[15] = m2.data[12] * m1.data[3] + m2.data[13] * m1.data[7] + m2.data[14] * m1.data[11] + m2.data[15] * m1.data[15];

        mat4<T> result( vals );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator* ( const mat4<T> & m, const T constant )
    {
        mat4<T> result( m[0] * constant,
                        m[1] * constant,
                        m[2] * constant,
                        m[3] * constant );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator* ( const T constant, const mat4<T> & m )
    {
        mat4<T> result( m[0] * constant,
                        m[1] * constant,
                        m[2] * constant,
                        m[3] * constant );
        return result;
    }

    template <typename T>
    inline vec4<T>
    operator* ( const mat4<T> & m, const vec4<T> & v )
    {
        vec4<T> output;

        output.x = m.data[0] * v.x + m.data[4] * v.y + m.data[ 8] * v.z + m.data[12] * v.w;
        output.y = m.data[1] * v.x + m.data[5] * v.y + m.data[ 9] * v.z + m.data[13] * v.w;
        output.z = m.data[2] * v.x + m.data[6] * v.y + m.data[10] * v.z + m.data[14] * v.w;
        output.w = m.data[3] * v.x + m.data[7] * v.y + m.data[11] * v.z + m.data[15] * v.w;

        return output;
    }

    template <typename T>
    inline void mat4<T>::
    pointwiseMultiply ( const mat4<T> & other )
    {
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   *= other.data[i];
            this->data[i+1] *= other.data[i+1];
            this->data[i+2] *= other.data[i+2];
            this->data[i+3] *= other.data[i+3];
        }
    }


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
        for ( int i = 0 ; i < 16 ; i += 4 )
        {
            this->data[i]   *= inv_constant;
            this->data[i+1] *= inv_constant;
            this->data[i+2] *= inv_constant;
            this->data[i+3] *= inv_constant;
        }
    }

    template <typename T>
    inline mat4<T>
    operator/ ( const mat4<T> & m1, const mat4<T> & m2 )
    {
        mat4<T> result( m1 );
        result /= m2;
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator/ ( const mat4<T> & m, const T constant )
    {
        float inv_constant = (T)1.0 / constant;
        mat4<T> result( m[0] * inv_constant,
                        m[1] * inv_constant,
                        m[2] * inv_constant,
                        m[3] * inv_constant );
        return result;
    }

    template <typename T>
    inline mat4<T>
    operator/ ( const T constant, const mat4<T> & m )
    {
        mat4<T> result( constant / m[0],
                        constant / m[1],
                        constant / m[2],
                        constant / m[3] );
        return result;
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
