#pragma once

namespace bsc
{
    template <typename T>
    struct mat3 {

        union
        {
            T data[9];
            vec3<T> cols[3];
        };

        mat3 ( bool initialize = true );
        mat3 ( const T constant );
        mat3 ( const T other[9] );
        mat3 ( const mat2<T> & other );
        mat3 ( const mat3<T> & other );
        mat3 ( const mat4<T> & other );
        mat3 ( const vec3<T> & diagonal );
        mat3 ( const vec3<T> & col0,
               const vec3<T> & col1,
               const vec3<T> & col2 );

        mat3<T> & operator= ( const mat3<T> & other );

        void operator+= ( const mat3<T> & other );
        void operator+= ( const T constant );

        void operator-= ( const mat3<T> & other );
        void operator-= ( const T constant );

        void operator*= ( const mat3<T> & other );
        void operator*= ( const T constant );
        void pointwiseMultiply( const mat3<T> &other );

        void operator/= ( const mat3<T> & other );
        void operator/= ( const T constant );

        vec3<T>& operator[] ( unsigned int i );
        vec3<T>  operator[] ( unsigned int i ) const;

        bool operator== ( const mat2<T> & other ) const;
        bool operator!= ( const mat2<T> & other ) const;

        const constexpr int dimensionality () const  { return 3; }
        const constexpr int size () const  { return 9; }
    };

    template <typename T>
    mat3<T> ::
    mat3 ( bool intialize )
    {
        if ( intialize )
        {
            this->data[0] = (T)1.0;
            this->data[1] = (T)0.0;
            this->data[2] = (T)0.0;

            this->data[3] = (T)0.0;
            this->data[4] = (T)1.0;
            this->data[5] = (T)0.0;

            this->data[6] = (T)0.0;
            this->data[7] = (T)0.0;
            this->data[8] = (T)1.0;
        }
    }

    template <typename T>
    mat3<T> ::
    mat3 ( const T c )
    {
        for ( int i = 0 ; i < 9 ; ++i )
        {
            data[i] = c;
        }
    }

    template <typename T>
    mat3<T> ::
    mat3 ( const T other[9] )
    {
        for ( int i = 0 ; i < 9 ; ++i )
        {
            data[i] = other[i];
        }
    }

    template <typename T>
    mat3<T>::
    mat3 ( const mat2<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = (T)0.0;
        this->data[3] = other.data[2];
        this->data[4] = other.data[3];
        this->data[5] = (T)0.0;
        this->data[6] = (T)0.0;
        this->data[7] = (T)0.0;
        this->data[8] = (T)1.0;
    }

    template <typename T>
    mat3<T> ::
    mat3 ( const mat3<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = other.data[2];
        this->data[3] = other.data[3];
        this->data[4] = other.data[4];
        this->data[5] = other.data[5];
        this->data[6] = other.data[6];
        this->data[7] = other.data[7];
        this->data[8] = other.data[8];
    }


    template <typename T>
    mat3<T>::
    mat3 ( const mat4<T> & other )
    {
        this->data[ 0] = other.data[ 0];
        this->data[ 1] = other.data[ 1];
        this->data[ 2] = other.data[ 2];
        this->data[ 3] = other.data[ 4];
        this->data[ 4] = other.data[ 5];
        this->data[ 5] = other.data[ 6];
        this->data[ 6] = other.data[ 8];
        this->data[ 7] = other.data[ 9];
        this->data[ 8] = other.data[10];
    }

    template <typename T>
    mat3<T> ::
    mat3 ( const vec3<T> & diagonal )
    {
        for ( int i = 0 ; i < 9 ; ++i )
        {
            data[i] = 0;
        }
        data[0] = diagonal.x;
        data[4] = diagonal.y;
        data[8] = diagonal.z;
    }

    template <typename T>
    mat3<T> ::
    mat3 ( const vec3<T> & col0, const vec3<T> & col1, const vec3<T> & col2 )
    {
        cols[0] = col0;
        cols[1] = col1;
        cols[2] = col2;
    }

    template <typename T>
    inline mat3<T> & mat3<T> ::
    operator= ( const mat3<T> & other )
    {
        this->data[0] = other.data[0];
        this->data[1] = other.data[1];
        this->data[2] = other.data[2];
        this->data[3] = other.data[3];
        this->data[4] = other.data[4];
        this->data[5] = other.data[5];
        this->data[6] = other.data[6];
        this->data[7] = other.data[7];
        this->data[8] = other.data[8];
        return *this;
    }

    template <typename T>
    inline void mat3<T>::
    operator+= ( const mat3<T> & other )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   += other.data[i];
            this->data[i+1] += other.data[i+1];
            this->data[i+2] += other.data[i+2];
        }
    }

    template <typename T>
    inline void mat3<T>::
    operator+= ( const T constant )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   += constant;
            this->data[i+1] += constant;
            this->data[i+2] += constant;
        }
    }

    template <typename T>
    inline mat3<T>
    operator+ ( const mat3<T> & m1, const mat3<T> & m2 )
    {
        mat3<T> result( m1[0] + m2[0],
                        m1[1] + m2[1],
                        m1[2] + m2[2] );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator+ ( const mat3<T> & m, const T constant )
    {
        mat3<T> result( m[0] + constant,
                        m[1] + constant,
                        m[2] + constant);
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator+ ( const T constant, const mat3<T> & m )
    {
        mat3<T> result( m[0] + constant,
                        m[1] + constant,
                        m[2] + constant );
        return result;
    }



    template <typename T>
    inline void mat3<T>::
    operator-= ( const mat3<T> & other )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   -= other.data[i];
            this->data[i+1] -= other.data[i+1];
            this->data[i+2] -= other.data[i+2];
        }
    }

    template <typename T>
    inline void mat3<T>::
    operator-= ( const T constant )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   -= constant;
            this->data[i+1] -= constant;
            this->data[i+2] -= constant;
        }
    }

    template <typename T>
    inline mat3<T>
    operator- ( const mat3<T> & m1, const mat3<T> & m2 )
    {
        mat3<T> result( m1[0] - m2[0],
                        m1[1] - m2[1],
                        m1[2] - m2[2] );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator- ( const mat3<T> & m, const T constant )
    {
        mat3<T> result( m[0] - constant,
                        m[1] - constant,
                        m[2] - constant );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator- ( const T constant, const mat3<T> & m )
    {
        mat3<T> result( constant - m[0],
                        constant - m[1],
                        constant - m[2] );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator- ( const mat3<T> & m )
    {
        mat3<T> result( -m[0],
                        -m[1],
                        -m[2] );
        return result;
    }

    template <typename T>
    inline void mat3<T>::
    operator*= ( const mat3<T> & other )
    {
        T vals[9];


        vals[0] = other.data[0] * data[0] + other.data[1] * data[3] + other.data[2] * data[6];
        vals[1] = other.data[0] * data[1] + other.data[1] * data[4] + other.data[2] * data[7];
        vals[2] = other.data[0] * data[2] + other.data[1] * data[5] + other.data[2] * data[8];

        vals[3] = other.data[3] * data[0] + other.data[4] * data[3] + other.data[5] * data[6];
        vals[4] = other.data[3] * data[1] + other.data[4] * data[4] + other.data[5] * data[7];
        vals[5] = other.data[3] * data[2] + other.data[4] * data[5] + other.data[5] * data[8];

        vals[6] = other.data[6] * data[0] + other.data[7] * data[3] + other.data[8] * data[6];
        vals[7] = other.data[6] * data[1] + other.data[7] * data[4] + other.data[8] * data[7];
        vals[8] = other.data[6] * data[2] + other.data[7] * data[5] + other.data[8] * data[8];


        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   = vals[i]  ;
            this->data[i+1] = vals[i+1];
            this->data[i+2] = vals[i+2];
        }
    }

    template <typename T>
    inline void mat3<T>::
    operator*= ( const T constant )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   *= constant;
            this->data[i+1] *= constant;
            this->data[i+2] *= constant;
        }
    }

    template <typename T>
    inline mat3<T>
    operator* ( const mat3<T> & m1, const mat3<T> & m2 )
    {
        T vals[9];

        vals[0] = m2.data[0] * m1.data[0] + m2.data[1] * m1.data[3] + m2.data[2] * m1.data[6];
        vals[1] = m2.data[0] * m1.data[1] + m2.data[1] * m1.data[4] + m2.data[2] * m1.data[7];
        vals[2] = m2.data[0] * m1.data[2] + m2.data[1] * m1.data[5] + m2.data[2] * m1.data[8];

        vals[3] = m2.data[3] * m1.data[0] + m2.data[4] * m1.data[3] + m2.data[5] * m1.data[6];
        vals[4] = m2.data[3] * m1.data[1] + m2.data[4] * m1.data[4] + m2.data[5] * m1.data[7];
        vals[5] = m2.data[3] * m1.data[2] + m2.data[4] * m1.data[5] + m2.data[5] * m1.data[8];

        vals[6] = m2.data[6] * m1.data[0] + m2.data[7] * m1.data[3] + m2.data[8] * m1.data[6];
        vals[7] = m2.data[6] * m1.data[1] + m2.data[7] * m1.data[4] + m2.data[8] * m1.data[7];
        vals[8] = m2.data[6] * m1.data[2] + m2.data[7] * m1.data[5] + m2.data[8] * m1.data[8];

        mat3<T> result( vals );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator* ( const mat3<T> & m, const T constant )
    {
        mat3<T> result( m[0] * constant,
                        m[1] * constant,
                        m[2] * constant );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator* ( const T constant, const mat3<T> & m )
    {
        mat3<T> result( m[0] * constant,
                        m[1] * constant,
                        m[2] * constant );
        return result;
    }

    template <typename T>
    inline vec3<T>
    operator* ( const mat3<T> & m, const vec3<T> & v )
    {
        vec3<T> output;

        output.x = m.data[0] * v.x + m.data[3] * v.y + m.data[6] * v.z;
        output.y = m.data[1] * v.x + m.data[4] * v.y + m.data[7] * v.z;
        output.z = m.data[2] * v.x + m.data[5] * v.y + m.data[8] * v.z;

        return output;
    }

    template <typename T>
    inline void mat3<T>::
    pointwiseMultiply ( const mat3<T> & other )
    {
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   *= other.data[i];
            this->data[i+1] *= other.data[i+1];
            this->data[i+2] *= other.data[i+2];
        }
    }


    template <typename T>
    inline void mat3<T>::
    operator/= ( const mat3<T> & other )
    {
        mat3<T> inv_other = Inverse( other );
        (*this) *= inv_other;
    }

    template <typename T>
    inline void mat3<T>::
    operator/= ( const T constant )
    {
        float inv_constant = (T)1.0 / constant;
        for ( int i = 0 ; i < 9 ; i += 3 )
        {
            this->data[i]   *= inv_constant;
            this->data[i+1] *= inv_constant;
            this->data[i+2] *= inv_constant;
        }
    }

    template <typename T>
    inline mat3<T>
    operator/ ( const mat3<T> & m1, const mat3<T> & m2 )
    {
        mat3<T> result( m1 );
        result /= m2;
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator/ ( const mat3<T> & m, const T constant )
    {
        float inv_constant = (T)1.0 / constant;
        mat3<T> result( m[0] * inv_constant,
                        m[1] * inv_constant,
                        m[2] * inv_constant );
        return result;
    }

    template <typename T>
    inline mat3<T>
    operator/ ( const T constant, const mat3<T> & m )
    {
        mat3<T> result( constant / m[0],
                        constant / m[1],
                        constant / m[2] );
        return result;
    }

    template <typename T>
    inline vec3<T> & mat3<T> ::
    operator[] ( unsigned int i )
    {
        return cols[i];
    }

    template <typename T>
    inline vec3<T> mat3<T> ::
    operator[] ( unsigned int i ) const
    {
        return cols[i];
    }
}
