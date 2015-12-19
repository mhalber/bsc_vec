// funct_matrix.h

// TODO: eigendecomposition ( start with wiki descriptions : https://en.wikipedia.org/wiki/Eigenvalue_algorithm#3.C3.973_matrices )
// TODO: svd http://pages.cs.wisc.edu/%7Esifakis/papers/SVD_TR1690.pdf

//---------------------------------------------------
// Interface
//---------------------------------------------------
namespace bvu
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
    void lookAt();

    template< typename T>
    void perspective();

    template< typename T>
    void ortho();

    template< typename T>
    void project();

    template< typename T>
    void unproject();

    template< typename T>
    void translate();

    template< typename T>
    void scale();

    template< typename T>
    void rotate();
}


//---------------------------------------------------
// Implementation
//---------------------------------------------------


template <typename T>
inline T
compute_determinant ( const bvu::mat2<T> & mat )
{
    return ( mat.data[0] * mat.data[3] - mat.data[2] * mat.data[1] );
}

template <typename T>
inline T
compute_determinant ( const bvu::mat3<T> & mat )
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
T compute_determinant ( const bvu::mat4<T> & mat )
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
inline T bvu ::
determinant ( const matX<T> & mat )
{
    return compute_determinant ( mat );
}




template< typename T, template <typename Q> class matX >
inline T bvu ::
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
inline bvu::mat2<T>
compute_transpose ( const bvu::mat2<T> & src )
{
    bvu::mat2<T> trg ( false );
    trg[0][0] = src[0][0];
    trg[0][1] = src[1][0];
    trg[1][0] = src[0][1];
    trg[1][1] = src[1][1];
    return trg;
}

template< typename T >
inline bvu::mat3<T>
compute_transpose ( const bvu::mat3<T> & src )
{
    bvu::mat3<T> trg ( false );
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
inline bvu::mat4<T>
compute_transpose ( const bvu::mat4<T> & src )
{
    bvu::mat4<T> trg ( false );
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
inline matX<T> bvu ::
transpose ( const matX<T> & mat )
{
    return compute_transpose( mat );
}


template <typename T>
void
compute_inverse ( bvu::mat2<T> & mat )
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
compute_inverse ( bvu::mat3<T> & mat )
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
compute_inverse ( bvu::mat4<T> & mat )
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
inline matX<T> bvu ::
inverse ( const matX<T> & mat )
{
    static_assert(std::numeric_limits<T>::is_iec559, "'Inverse' only accepts real numbers!");
    matX<T> mat_copy ( mat );
    compute_inverse( mat_copy );
    return mat_copy;
}
