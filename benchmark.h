#pragma once

template<typename T>
void
generateVectorData( std::vector<T> & vecs)
{
    for ( int i = 0 ; i < vecs.capacity() ; ++i )
    {
        T v( drand48(), drand48(), drand48(), drand48() );
        vecs.push_back( v );
    }
}

void
copyVectorData( const std::vector<bvu::vec4f> & vecs1, std::vector< glm::vec4> & vecs2)
{
    for ( int i = 0 ; i < vecs1.size() ; ++i )
    {
        glm::vec4 v( vecs1[i].x, vecs1[i].y, vecs1[i].z, vecs1[i].w );
        vecs2.push_back( v );
    }
}

template<typename T, typename G>
void
generateMatrixData( std::vector<T> & mats)
{
    for ( int i = 0 ; i < mats.capacity() ; ++i )
    {
        G v1( drand48(), drand48(), drand48(), drand48() );
        G v2( drand48(), drand48(), drand48(), drand48() );
        G v3( drand48(), drand48(), drand48(), drand48() );
        G v4( drand48(), drand48(), drand48(), drand48() );

        T m ( v1, v2, v3, v4 );

        mats.push_back( m );
    }
}

void
copyMatrixData( const std::vector<bvu::mat4f> & mats1, std::vector< glm::mat4> & mats2)
{
    for ( int i = 0 ; i < mats1.size() ; ++i )
    {
        glm::vec4 v1( mats1[i][0][0], mats1[i][0][1], mats1[i][0][2], mats1[i][0][3] );
        glm::vec4 v2( mats1[i][1][0], mats1[i][1][1], mats1[i][1][2], mats1[i][1][3] );
        glm::vec4 v3( mats1[i][2][0], mats1[i][2][1], mats1[i][2][2], mats1[i][2][3] );
        glm::vec4 v4( mats1[i][3][0], mats1[i][3][1], mats1[i][3][2], mats1[i][3][3] );

        glm::mat4 m( v1, v2, v3, v4 );
        mats2.push_back(  m );
    }
}

void
bvuNormalizeAll ( std::vector<bvu::vec4f> & vecs )
{
    for ( int i = 0 ; i < vecs.size() ; ++i )
    {
        vecs[i] = bvu::normalize ( vecs[i] );
    }
}

void
glmNormalizeAll ( std::vector<glm::vec4> & vecs )
{
    for ( int i = 0 ; i < vecs.size() ; ++i )
    {
        vecs[i] = glm::normalize ( vecs[i] );
    }
}

void
bvuAddAll ( std::vector<bvu::vec4f> & vecs )
{
    for ( int i = 0 ; i < vecs.size() ; ++i )
    {
        vecs[i] += vecs[i];
    }
}

void
glmAddAll ( std::vector<glm::vec4> & vecs )
{
    for ( int i = 0 ; i < vecs.size() ; ++i )
    {
        vecs[i] += vecs[i];
    }
}

void
bvuInvertAll ( std::vector<bvu::mat4f> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = bvu::inverse( mats[i] );
    }
}

void
glmInvertAll ( std::vector<glm::mat4> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = glm::inverse( mats[i] );
    }
}

void
bvuLookAtGen ( std::vector<bvu::mat4f> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = bvu::lookAt( bvu::vec3f( 0.0, 0.0, 0.0 ), bvu::vec3f( 0.0, 0.0, -5.0 ), bvu::vec3f( 0.0, 1.0, 0.0 ) );
    }
}

void
glmLookAtGen ( std::vector<glm::mat4> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = glm::lookAt( glm::vec3( 0.0, 0.0, 0.0 ), glm::vec3( 0.0, 0.0, -5.0 ), glm::vec3( 0.0, 1.0, 0.0 ) );
    }
}

void
bvuPerspectiveGen ( std::vector<bvu::mat4f> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = bvu::perspective( 0.785398f, 1.3f, 0.01f, 100.0f );
    }
}

void
glmPerspectiveGen ( std::vector<glm::mat4> & mats )
{
    for ( int i = 0 ; i < mats.size() ; ++i )
    {
        mats[i] = glm::perspective( 45.0f, 1.3f, 0.01f, 100.0f );
    }
}

void
RunBenchmark ()
{
    int n_examples = 100000;
    const int n_reps = 10000;
    std::vector < bvu::vec4f > vectors_A;
    std::vector < glm::vec4 > vectors_B;
    std::vector < bvu::mat4f > matrices_A;
    std::vector < glm::mat4 > matrices_B;
    vectors_A.reserve( n_examples );
    vectors_B.reserve( n_examples );
    matrices_A.reserve( n_examples );
    matrices_B.reserve( n_examples );

    generateVectorData( vectors_A );
    copyVectorData( vectors_A, vectors_B );
    generateMatrixData<bvu::mat4f, bvu::vec4f>( matrices_A );
    copyMatrixData( matrices_A, matrices_B );

    printf( "   (glm) Time to normalize %d vectors - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( glmNormalizeAll, vectors_B ) );
    printf( "   (bvu) Time to normalize %d vectors - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( bvuNormalizeAll, vectors_A ) );

    printf( "   (glm) Time to add %d vectors - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( glmAddAll, vectors_B ) );
    printf( "   (bvu) Time to add %d vectors - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( bvuAddAll, vectors_A ) );

    printf( "   (glm) Time to invert %d matrices - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( glmInvertAll, matrices_B ) );
    printf( "   (bvu) Time to invert %d matrices - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( bvuInvertAll, matrices_A ) );

    printf( "   (glm) Time to generate %d lookAt matrices - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( glmLookAtGen, matrices_B ) );
    printf( "   (bvu) Time to generate %d lookAt matrices - %f sec.\n", n_examples, bsc::MeasureTime<n_reps>( bvuLookAtGen, matrices_A ) );

    printf( "   (glm) Time to generate %d persp. matrices - %f sec.\n", n_examples,
           bsc::MeasureTime<n_reps>( glmPerspectiveGen, matrices_B ) );
    printf( "   (bvu) Time to generate %d persp. matrices - %f sec.\n", n_examples,
           bsc::MeasureTime<n_reps>( bvuPerspectiveGen, matrices_A ) );
}
