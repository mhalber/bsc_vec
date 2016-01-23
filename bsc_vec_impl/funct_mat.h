// funct_matrix.h

// TODO: eigendecomposition ( start with wiki descriptions : https://en.wikipedia.org/wiki/Eigenvalue_algorithm#3.C3.973_matrices )
// TODO: svd http://pages.cs.wisc.edu/%7Esifakis/papers/SVD_TR1690.pdf

//---------------------------------------------------
// Interface
//---------------------------------------------------
namespace bsc
{
    template< typename T, template <typename Q> class matX >
    T determinant ( const matX<T> & mat );

    template< typename T, template <typename Q> class matX >
    T trace ( const matX<T> & mat );

    template< typename T, template <typename Q> class matX >
    matX<T> inverse ( const matX<T> & mat );

    template< typename T, template <typename Q> class matX >
    matX<T> transpose ( const matX<T> & mat );

    // TODO: implement these functions
    template< typename T>
    mat4<T> lookAt ( const vec3<T> & eye, const vec3<T> & center, const vec3<T> & up );

    template< typename T>
    mat4<T> perspective ( const T & fovy, const T & aspect, const T & z_near, const T & z_far);

    template< typename T>
    mat4<T> frustum ( const T & left, const T & right, const T & bottom, const T & top, const T & z_near, const T & z_far );

    template< typename T>
    mat4<T> ortho ( const T & left, const T & right, const T & bottom, const T & top, const T & z_near, const T & z_far );

    template< typename T>
    vec3<T> project ( const vec4<T> & obj, const mat4<T> & model, const mat4<T> & project, const vec4<T> & viewport );

    template< typename T>
    vec4<T> unproject ( const vec3<T> & win, const mat4<T> & model, const mat4<T> & project, const vec4<T> & viewport );

    template< typename T>
    mat4<T> translate( const mat4<T> & m, const vec3<T> & t );

    template< typename T>
    mat4<T> scale( const mat4<T> & m, const vec3<T> & s );

    template< typename T>
    mat4<T> rotate( const mat4<T> & m, const T & angle, const vec3<T> & axis );
}


//---------------------------------------------------
// Implementation
//---------------------------------------------------


template <typename T>
inline T
compute_determinant ( const bsc::mat2<T> & mat )
{
    return ( mat.data[0] * mat.data[3] - mat.data[2] * mat.data[1] );
}

template <typename T>
inline T
compute_determinant ( const bsc::mat3<T> & mat )
{
    // code folows same intuition as inverse calculation for 3d matrices, however we only compute information needed
    // for determinant calculation.

    float C[3];

    // get required cofactors
    C[0] = mat.data[4] * mat.data[8] - mat.data[5] * mat.data[7];
    C[1] = mat.data[5] * mat.data[6] - mat.data[3] * mat.data[8]; // negated
    C[2] = mat.data[3] * mat.data[7] - mat.data[4] * mat.data[6];

    return ( mat.data[0] * C[0] + mat.data[1] * C[1] + mat.data[2] * C[2] );
}

template <typename T>
T compute_determinant ( const bsc::mat4<T> & mat )
{
    // code folows same intuition as inverse calculation for 4d matrices, however we only compute information needed
    // for determinant calculation.
    float C[4];
    float coeffs[6];

    // coeffs are determinants of 2x2 matrices
    coeffs[0] = mat.data[10] * mat.data[15] - mat.data[14] * mat.data[11];
    coeffs[1] = mat.data[ 6] * mat.data[11] - mat.data[10] * mat.data[ 7];
    coeffs[2] = mat.data[ 2] * mat.data[ 7] - mat.data[ 6] * mat.data[ 3];
    coeffs[3] = mat.data[ 6] * mat.data[15] - mat.data[14] * mat.data[ 7];
    coeffs[4] = mat.data[ 2] * mat.data[11] - mat.data[10] * mat.data[ 3];
    coeffs[5] = mat.data[ 2] * mat.data[15] - mat.data[14] * mat.data[ 3];

    // Cofactor matrix
    /*00*/ C[0] = mat.data[5] * coeffs[0] - mat.data[9] * coeffs[3] + mat.data[13] * coeffs[1];
    /*01*/ C[1] = mat.data[9] * coeffs[5] - mat.data[1] * coeffs[0] - mat.data[13] * coeffs[4]; // negated
    /*02*/ C[2] = mat.data[1] * coeffs[3] - mat.data[5] * coeffs[5] + mat.data[13] * coeffs[2];
    /*03*/ C[3] = mat.data[5] * coeffs[4] - mat.data[9] * coeffs[2] - mat.data[ 1] * coeffs[1]; // negated

    // determinant
    T det = mat.data[0] * C[0] + mat.data[4] * C[1] + mat.data[8] * C[2] + mat.data[12] * C[3];

    return det;
}

template< typename T, template <typename Q> class matX >
inline T bsc ::
determinant ( const matX<T> & mat )
{
    return compute_determinant ( mat );
}




template< typename T, template <typename Q> class matX >
inline T bsc ::
trace ( const matX<T> & mat )
{
    T trace = (T)0;
    for ( int i = 0 ; i < mat.Dimensionality() ; ++i )
    {
        trace += mat.cols[i][i];
    }
    return trace;
}


template< typename T >
inline bsc::mat2<T>
compute_transpose ( const bsc::mat2<T> & src )
{
    bsc::mat2<T> trg ( false );
    trg[0][0] = src[0][0];
    trg[0][1] = src[1][0];
    trg[1][0] = src[0][1];
    trg[1][1] = src[1][1];
    return trg;
}

template< typename T >
inline bsc::mat3<T>
compute_transpose ( const bsc::mat3<T> & src )
{
    bsc::mat3<T> trg ( false );
    trg[0][0] = src[0][0];
    trg[0][1] = src[1][0];
    trg[0][2] = src[2][0];

    trg[1][0] = src[0][1];
    trg[1][1] = src[1][1];
    trg[1][2] = src[2][1];

    trg[2][0] = src[0][2];
    trg[2][1] = src[1][2];
    trg[2][2] = src[2][2];

    return trg;
}

template< typename T >
inline bsc::mat4<T>
compute_transpose ( const bsc::mat4<T> & src )
{
    bsc::mat4<T> trg ( false );
    trg[0][0] = src[0][0];
    trg[0][1] = src[1][0];
    trg[0][2] = src[2][0];
    trg[0][3] = src[3][0];

    trg[1][0] = src[0][1];
    trg[1][1] = src[1][1];
    trg[1][2] = src[2][1];
    trg[1][3] = src[3][1];

    trg[2][0] = src[0][2];
    trg[2][1] = src[1][2];
    trg[2][2] = src[2][2];
    trg[2][3] = src[3][2];

    trg[3][0] = src[0][3];
    trg[3][1] = src[1][3];
    trg[3][2] = src[2][3];
    trg[3][3] = src[3][3];

    return trg;
}

template< typename T, template <typename Q> class matX >
inline matX<T> bsc ::
transpose ( const matX<T> & mat )
{
    return compute_transpose( mat );
}


template <typename T>
void
compute_inverse ( bsc::mat2<T> & mat )
{
    T one_over_det = ((T)1.0) / Determinant( mat );

    T vals[4];
    vals[0] =  mat.data[3];
    vals[1] = -mat.data[1];
    vals[2] = -mat.data[2];
    vals[3] =  mat.data[0];

    mat.data[0] = one_over_det * vals[0];
    mat.data[1] = one_over_det * vals[1];
    mat.data[2] = one_over_det * vals[2];
    mat.data[3] = one_over_det * vals[3];
}

template <typename T>
void
compute_inverse ( bsc::mat3<T> & mat )
{
    // To calculate inverse :
    //     1. Transpose M
    //     2. Calculate cofactor matrix C
    //     3. Caluclate determinant of M
    //     4. Inverse is given as (1/det) * C

    // Access cheat sheat for transpose matrix:
    //     original indices
    //      0  1  2
    //      3  4  5
    //      6  7  8

    //     transposed indices
    //      0  3  6
    //      1  4  7
    //      2  5  8

    // Calulate cofactor matrix
    float C[9];

    C[0] = mat.data[4] * mat.data[8] - mat.data[7] * mat.data[5];
    C[1] = mat.data[7] * mat.data[2] - mat.data[1] * mat.data[8]; // negated
    C[2] = mat.data[1] * mat.data[5] - mat.data[4] * mat.data[2];

    C[3] = mat.data[6] * mat.data[5] - mat.data[3] * mat.data[8]; // negated
    C[4] = mat.data[0] * mat.data[8] - mat.data[6] * mat.data[2];
    C[5] = mat.data[3] * mat.data[2] - mat.data[0] * mat.data[5]; // negated

    C[6] = mat.data[3] * mat.data[7] - mat.data[6] * mat.data[4];
    C[7] = mat.data[6] * mat.data[1] - mat.data[0] * mat.data[7]; // negated
    C[8] = mat.data[0] * mat.data[4] - mat.data[3] * mat.data[1];

    // determinant
    T det = mat.data[0] * C[0] + mat.data[3] * C[1] + mat.data[6] * C[2];
    T one_over_det = (T)1.0 / det;

    // store result
    mat.data[ 0] = one_over_det * C[ 0];
    mat.data[ 1] = one_over_det * C[ 1];
    mat.data[ 2] = one_over_det * C[ 2];
    mat.data[ 3] = one_over_det * C[ 3];
    mat.data[ 4] = one_over_det * C[ 4];
    mat.data[ 5] = one_over_det * C[ 5];
    mat.data[ 6] = one_over_det * C[ 6];
    mat.data[ 7] = one_over_det * C[ 7];
    mat.data[ 8] = one_over_det * C[ 8];
}

template <typename T>
void
compute_inverse ( bsc::mat4<T> & mat )
{
    // TODO(maciej) : find intel document that was describing that
    // Inverse using cramers rule
    //     1. Transpose  M
    //     2. Calculate cofactor matrix C
    //     3. Caluclate determinant of M
    //     4. Inverse is given as (1/det) * C

    // Access cheat sheat:
    //     original indices
    //      0  1  2  3
    //      4  5  6  7
    //      8  9 10 11
    //     12 13 14 15

    //     transposed indices
    //      0  4  8 12
    //      1  5  9 13
    //      2  6 10 14
    //      3  7 11 15


    // Calulate cofactor matrix
    float C[16];
    float coeffs[6];

    // First 8
    // coeffs are determinants of 2x2 matrices
    coeffs[0] = mat.data[10] * mat.data[15] - mat.data[14] * mat.data[11];
    coeffs[1] = mat.data[ 6] * mat.data[11] - mat.data[10] * mat.data[ 7];
    coeffs[2] = mat.data[ 2] * mat.data[ 7] - mat.data[ 6] * mat.data[ 3];
    coeffs[3] = mat.data[ 6] * mat.data[15] - mat.data[14] * mat.data[ 7];
    coeffs[4] = mat.data[ 2] * mat.data[11] - mat.data[10] * mat.data[ 3];
    coeffs[5] = mat.data[ 2] * mat.data[15] - mat.data[14] * mat.data[ 3];

    // Cofactor matrix
    /*00*/ C[0] = mat.data[5] * coeffs[0] - mat.data[9] * coeffs[3] + mat.data[13] * coeffs[1];
    /*01*/ C[1] = mat.data[9] * coeffs[5] - mat.data[1] * coeffs[0] - mat.data[13] * coeffs[4]; // negated
    /*02*/ C[2] = mat.data[1] * coeffs[3] - mat.data[5] * coeffs[5] + mat.data[13] * coeffs[2];
    /*03*/ C[3] = mat.data[5] * coeffs[4] - mat.data[9] * coeffs[2] - mat.data[ 1] * coeffs[1]; // negated

    /*10*/ C[4] = mat.data[8] * coeffs[3] - mat.data[4] * coeffs[0] - mat.data[12] * coeffs[1]; // negated
    /*11*/ C[5] = mat.data[0] * coeffs[0] - mat.data[8] * coeffs[5] + mat.data[12] * coeffs[4];
    /*12*/ C[6] = mat.data[4] * coeffs[5] - mat.data[0] * coeffs[3] - mat.data[12] * coeffs[2]; // negated
    /*13*/ C[7] = mat.data[0] * coeffs[1] - mat.data[4] * coeffs[4] + mat.data[ 8] * coeffs[2];

    //Second 8

    // coeffs are Determinants of 2x2 matrices
    coeffs[0] = mat.data[ 8] * mat.data[13] - mat.data[12] * mat.data[ 9];
    coeffs[1] = mat.data[ 4] * mat.data[ 9] - mat.data[ 8] * mat.data[ 5];
    coeffs[2] = mat.data[ 0] * mat.data[ 5] - mat.data[ 4] * mat.data[ 1];
    coeffs[3] = mat.data[ 4] * mat.data[13] - mat.data[12] * mat.data[ 5];
    coeffs[4] = mat.data[ 0] * mat.data[ 9] - mat.data[ 8] * mat.data[ 1];
    coeffs[5] = mat.data[ 0] * mat.data[13] - mat.data[12] * mat.data[ 1];

    // actual coefficient matrix
    /*20*/ C[ 8] = mat.data[ 7] * coeffs[0] - mat.data[11] * coeffs[3] + mat.data[15] * coeffs[1];
    /*21*/ C[ 9] = mat.data[11] * coeffs[5] - mat.data[ 3] * coeffs[0] - mat.data[15] * coeffs[4]; // negated
    /*22*/ C[10] = mat.data[ 3] * coeffs[3] - mat.data[ 7] * coeffs[5] + mat.data[15] * coeffs[2];
    /*23*/ C[11] = mat.data[ 7] * coeffs[4] - mat.data[ 3] * coeffs[1] - mat.data[11] * coeffs[2]; // negated

    /*30*/ C[12] = mat.data[10] * coeffs[3] - mat.data[ 6] * coeffs[0] - mat.data[14] * coeffs[1]; // negated
    /*31*/ C[13] = mat.data[ 2] * coeffs[0] - mat.data[10] * coeffs[5] + mat.data[14] * coeffs[4];
    /*32*/ C[14] = mat.data[ 6] * coeffs[5] - mat.data[ 2] * coeffs[3] - mat.data[14] * coeffs[2]; // negated
    /*33*/ C[15] = mat.data[ 2] * coeffs[1] - mat.data[ 6] * coeffs[4] + mat.data[10] * coeffs[2];

    // determinant
    T det = mat.data[0] * C[0] + mat.data[4] * C[1] + mat.data[8] * C[2] + mat.data[12] * C[3];
    T one_over_det = ((T)1) / det;

    // store result
    mat.data[ 0] = one_over_det * C[ 0];
    mat.data[ 1] = one_over_det * C[ 1];
    mat.data[ 2] = one_over_det * C[ 2];
    mat.data[ 3] = one_over_det * C[ 3];
    mat.data[ 4] = one_over_det * C[ 4];
    mat.data[ 5] = one_over_det * C[ 5];
    mat.data[ 6] = one_over_det * C[ 6];
    mat.data[ 7] = one_over_det * C[ 7];
    mat.data[ 8] = one_over_det * C[ 8];
    mat.data[ 9] = one_over_det * C[ 9];
    mat.data[10] = one_over_det * C[10];
    mat.data[11] = one_over_det * C[11];
    mat.data[12] = one_over_det * C[12];
    mat.data[13] = one_over_det * C[13];
    mat.data[14] = one_over_det * C[14];
    mat.data[15] = one_over_det * C[15];

}

template< typename T, template <typename Q> class matX >
inline matX<T> bsc ::
inverse ( const matX<T> & mat )
{
    static_assert(std::numeric_limits<T>::is_iec559, "'Inverse' only accepts real numbers!");
    matX<T> mat_copy ( mat );
    compute_inverse( mat_copy );
    return mat_copy;
}

template< typename T>
inline bsc::mat4<T> bsc ::
perspective ( const T & fovy, const T & aspect, const T & z_near, const T & z_far)
{
    T f = tan( 0.5 * (M_PI - fovy) );
    T diff = z_near - z_far;
    T tmp[16] =  { f / aspect, 0.0,                           0.0,  0.0,
                          0.0,   f,                           0.0,  0.0,
                          0.0, 0.0,       (z_far + z_near) / diff, -1.0,
                          0.0, 0.0, ((T)2 * z_far * z_near) / diff,  0.0 };
    return  mat4<T>( tmp );
}

template< typename T>
inline bsc::mat4<T> bsc ::
frustum ( const T & left, const T & right, const T & bottom, const T & top, const T & z_near, const T & z_far )
{
    T x_diff = right - left;
    T y_diff = top - bottom;
    T z_diff = z_far - z_near;
    T a = (right + left) / x_diff;
    T b = (top + bottom) / y_diff;
    T c = -(z_far + z_near ) / z_diff;
    T d = -(2 * z_far * z_near ) / z_diff;

    T tmp[16] = { ((T)2 * z_near) / x_diff,                      0.0, 0.0,  0.0,
                                       0.0, ((T)2 * z_near) / y_diff, 0.0,  0.0,
                                         a,                        b,   c, -1.0,
                                       0.0,                      0.0,   d,  0.0 };
    return  mat4<T>( tmp );
}

template< typename T>
inline bsc::mat4<T> bsc ::
ortho ( const T & left, const T & right, const T & bottom, const T & top, const T & z_near, const T & z_far )
{
    T x_diff = right - left;
    T y_diff = top - bottom;
    T z_diff = z_far - z_near;
    T tx = - ( right + left ) / x_diff;
    T ty = - ( top + bottom ) / y_diff;
    T tz = - ( z_near + z_far ) / z_diff;

    T tmp[16] =  { (T)2 / x_diff,          0.0,           0.0, 0.0,
                            0.0, (T)2 / x_diff,           0.0, 0.0,
                            0.0,          0.0, -(T)2 / z_diff, 0.0,
                             tx,           ty,            tz, 1.0 } ;
    return  mat4<T>( tmp );
}


template< typename T>
inline bsc::mat4<T> bsc ::
lookAt ( const vec3<T> & eye, const vec3<T> & center, const vec3<T> & up )
{
    vec3<T> n = normalize( center - eye );
    vec3<T> u = normalize( cross( n, up ) );
    vec3<T> v = cross( u, n );

    T tmp[16] = {         u[0],          v[0],        -n[0], 0.0,
                          u[1],          v[1],        -n[1], 0.0,
                          u[2],          v[2],        -n[2], 0.0,
                   -dot(eye,u),   -dot(eye,v),   dot(eye,n), 1.0 };

    return mat4<T>( tmp );
}


template< typename T>
inline bsc::vec3<T> bsc ::
project ( const vec4<T> & obj, const mat4<T> & model, const mat4<T> & project, const vec4<T> & viewport )
{
    vec4<T> tmp = project * model * obj;
    tmp /= tmp.w;

    vec3<T> win;
    win.x = viewport[0] + ( viewport[2] * (tmp.x + 1.0) ) / 2.0;
    win.y = viewport[1] + ( viewport[3] * (tmp.y + 1.0) ) / 2.0;
    win.z = (tmp.z + 1.0) / 2.0;

    return win;
}

template< typename T>
inline bsc::vec4<T> bsc ::
unproject ( const vec3<T> &win, const mat4<T> & model, const mat4<T> & project, const vec4<T> & viewport )
{
    mat4<T> inv_pm = inverse( project * model );
    vec4<T> tmp;
    tmp.x = ( 2.0 * ( win.x - viewport[0] ) ) / viewport[2] - 1.0;
    tmp.y = ( 2.0 * ( win.y - viewport[1] ) ) / viewport[3] - 1.0;
    tmp.z = 2.0 * win.z - 1.0;
    tmp.w = 1.0;

    vec4<T> obj = inv_pm * tmp;
    obj /= obj.w;
    return obj;
}

template< typename T>
inline bsc::mat4<T> bsc ::
translate( const mat4<T> & m, const vec3<T> & t )
{
    mat4<T> result( m );
    result[3] = m[0] * t.x + m[1] * t.y + m[2] * t.z + m[3];
    return result;
}

    template< typename T>
inline bsc::mat4<T> bsc ::
scale( const mat4<T> & m, const vec3<T> & s )
{
    mat4<T> result( m );
    result[0] *= s.x;
    result[1] *= s.y;
    result[2] *= s.z;
    return result;
}

// derivation : http://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/
template< typename T>
inline bsc::mat4<T> bsc ::
rotate( const mat4<T> & m, const T & angle, const vec3<T> & v )
{
    T c = cos ( angle );
    T s = sin ( angle );
    T t = 1.0 - c;

    vec3<T> axis = normalize( v );

    mat4<T> rotate( false );
    rotate[0][0] = c + axis.x * axis.x * t;
    rotate[1][1] = c + axis.y * axis.y * t;
    rotate[2][2] = c + axis.z * axis.z * t;

    T tmp_1 = axis.x * axis.y * t;
    T tmp_2 = axis.z * s;

    rotate[0][1] = tmp_1 + tmp_2;
    rotate[1][0] = tmp_1 - tmp_2;

    tmp_1 = axis.x * axis.z * t;
    tmp_2 = axis.y * s;

    rotate[0][2] = tmp_1 - tmp_2;
    rotate[2][0] = tmp_1 + tmp_2;

    tmp_1 = axis.y * axis.z * t;
    tmp_2 = axis.x * s;

    rotate[1][2] = tmp_1 + tmp_2;
    rotate[2][1] = tmp_1 - tmp_2;

    mat4<T> result( m );
    result[0] = m[0] * rotate[0][0] + m[1] * rotate[0][1] + m[2] * rotate[0][2];
    result[1] = m[0] * rotate[1][0] + m[1] * rotate[1][1] + m[2] * rotate[1][2];
    result[2] = m[0] * rotate[2][0] + m[1] * rotate[2][1] + m[2] * rotate[2][2];
    result[3] = m[3];
    return result;
}
