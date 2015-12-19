

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

    // TODO implement conversions!
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
