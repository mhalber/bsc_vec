

//---------------------------------------------------
// Interface
//---------------------------------------------------
namespace bvu
{
    template <typename T>
    T dot ( const quat<T> & q1,  const quat<T> & q2 );

    template <typename T>
    T norm ( const quat<T> & q );

    template <typename T>
    T normSq ( const quat<T> & q );

    template <typename T>
    quat<T> normalize( const quat<T> & q );

    template <typename T>
    quat<T> conjugate( const quat<T> & q );

    template <typename T>
    quat<T> inverse( const quat<T> & q );

    template <typename T>
    mat3<T> to_mat3 ( const quat<T> & q );

    template <typename T>
    mat4<T> to_mat4 ( const quat<T> & q );

    template <typename T>
    quat<T> to_quat ( const mat3<T> & m );

    template <typename T>
    quat<T> to_quat ( const mat4<T> & m );
}
//---------------------------------------------------
// Implementation
//---------------------------------------------------

template <typename T>
inline T bvu ::
dot ( const quat<T> & q1, const quat<T> & q2 )
{
    return q1.re * q2.re + bvu::dot( q1.im, q2.im );
}

template <typename T>
inline T bvu ::
norm ( const quat<T> & q )
{
    return std::sqrt( bvu::dot( q, q ) );
}

template <typename T>
inline T bvu ::
normSq ( const quat<T> & q )
{
    return bvu::dot( q, q );
}


template <typename T>
inline bvu::quat<T> bvu ::
inverse ( const quat<T> & q )
{
    quat<T> p( q );
    T Normalization = bvu::normSq( p );
    p.re /= Normalization;
    p.im = -p.im;
    p.im /= Normalization;
    return p;
}

template <typename T>
inline bvu::quat<T> bvu ::
conjugate ( const quat<T> & q )
{
    quat<T> p( q );
    p.im = -p.im;
    return p;
}

// derivation http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/
template <typename T>
inline bvu::mat3<T> bvu ::
to_mat3 ( const quat<T> & q )
{
    mat3<T> m(false);
    T xx( q.x * q.x );
    T xy( q.x * q.y );
    T xz( q.x * q.z );
    T xw( q.x * q.w );

    T yy( q.y * q.y );
    T yz( q.y * q.z );
    T yw( q.y * q.w );

    T zz( q.z * q.z );
    T zw( q.z * q.w );

    m[0][0] = 1 - 2 * (yy +  zz);
    m[0][1] = 2 * (xy + zw);
    m[0][2] = 2 * (xz - yw);

    m[1][0] = 2 * (xy - zw);
    m[1][1] = 1 - 2 * (xx +  zz);
    m[1][2] = 2 * (yz + xw);

    m[2][0] = 2 * (xz + yw);
    m[2][1] = 2 * (yz - xw);
    m[2][2] = 1 - 2 * (xx +  yy);
    return m;
}

template <typename T>
inline bvu::mat4<T> bvu ::
to_mat4 ( const quat<T> & q )
{
    return mat4<T>( to_mat3( q ) );
}

// derivation  http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/
template <typename T>
inline bvu::quat<T> bvu ::
to_quat ( const mat3<T> & m )
{
    float tr = m[0][0] + m[1][1] + m[2][2];
    quat<T> q;
    if (tr > 0)
    {
        float S = std::sqrt( tr + 1.0) * 2;
        q.w = 0.25 * S;
        q.x = ( m[1][2] - m[2][1] ) / S;
        q.y = ( m[2][0] - m[0][2] ) / S;
        q.z = ( m[0][1] - m[1][0] ) / S;
    }
    else if ( ( m[0][0] > m[1][1]) && (m[0][0] > m[2][2] ) )
    {
        float S = std::sqrt( 1.0 + m[0][0] - m[1][1] - m[2][2]) * 2;
        q.w = ( m[1][2] - m[2][1] ) / S;
        q.x = 0.25 * S;
        q.y = ( m[1][0] + m[0][1] ) / S;
        q.z = ( m[2][0] + m[0][2] ) / S;
    }
    else if ( m[1][1] > m[2][2] )
    {
        float S = std::sqrt( 1.0 + m[1][1] - m[0][0] - m[2][2]) * 2;
        q.w = ( m[2][0] - m[0][2] ) / S;
        q.x = ( m[1][0] + m[0][1] ) / S;
        q.y = 0.25 * S;
        q.z = ( m[2][1] + m[1][2] ) / S;
    } else
    {
        float S = std::sqrt( 1.0 + m[2][2] - m[0][0] - m[1][1]) * 2;
        q.w = ( m[0][1] - m[1][0] ) / S;
        q.x = ( m[2][0] + m[0][2] ) / S;
        q.y = ( m[2][1] + m[1][2] ) / S;
        q.z = 0.25 * S;
    }
    return q;
}

template <typename T>
inline bvu::quat<T> bvu ::
to_quat ( const mat4<T> & m )
{
    return to_quat( mat3<T>(m) );
}
