
#include "bvu.h"
#include "test.h"

// TODO add function to compare results.

// template<typename T>
// void
// generateData( std::vector<T> & vecs)
// {
//     for ( int i = 0 ; i < vecs.capacity() ; ++i )
//     {
//         T v( drand48(), drand48(), drand48(), drand48() );
//         vecs.push_back( v );
//     }
// }

// void
// copyData( const std::vector<vec4f> & vecs1, std::vector< glm::vec4> & vecs2)
// {

//     for ( int i = 0 ; i < vecs1.size() ; ++i )
//     {
//         glm::vec4 v( vecs1[i].x, vecs1[i].y, vecs1[i].z, vecs1[i].w );
//         vecs2.push_back( v );
//     }
// }

// void
// myNormalizeAll ( std::vector<vec4f> & vecs )
// {
//     for ( int i = 0 ; i < vecs.size() ; ++i )
//     {
//         vecs[i] = lvu::normalize ( vecs[i] );
//     }
// }

// void
// glmNormalizeAll ( std::vector<glm::vec4> & vecs )
// {
//     for ( int i = 0 ; i < vecs.size() ; ++i )
//     {
//         vecs[i] = glm::normalize ( vecs[i] );
//     }
// }

// void
// printData ( std::vector<vec4f> & vecs )
// {
//     for ( int i = 0 ; i < vecs.size() ; ++i )
//     {
//         printf( "%f %f %f %f [%f] \n", vecs[i].x, vecs[i].y, vecs[i].z, vecs[i].w, lvu::norm( vecs[i] ));
//     }
// }


void
RunBenchmark ()
{
    // int n_vectors = 1000000;
    // std::vector < vec4f > normalsA;
    // std::vector < glm::vec4 > normalsB;
    // normalsA.reserve( n_vectors );
    // normalsB.reserve( n_vectors );

    // generateData( normalsA );
    // copyData( normalsA, normalsB );

    // const int n_reps = 10;
    // double c = MeasureTime<n_reps>( myNormalizeAll, normalsA );
    // double d = MeasureTime<n_reps>( glmNormalizeAll, normalsB );
    // printf( "My Normalization : %f in %d reps || GLM Normalization : %f in %d reps \n", c, n_reps, d, n_reps  );

}


int main( int argc, char ** argv )
{
    RunTests();
    RunBenchmark();
    // int NPassed, NTests;
    // printf( "Testing Mat2 :\n" );
    // TestMat2( NPassed, NTests);
    // printf( "%d out of %d tests succeeded!\n\n", NPassed, NTests );

    // NPassed = 0;
    // NTests = 0;

    // printf( "Testing Mat3 :\n" );
    // TestMat3( NPassed, NTests);
    // printf( "%d out of %d tests succeeded!\n\n", NPassed, NTests );

    // NPassed = 0;
    // NTests = 0;

    // printf( "Testing Mat4 :\n" );
    // // TestMat4( NPassed, NTests);
    // printf( "%d out of %d tests succeeded!\n\n", NPassed, NTests );

    return 1;
}

