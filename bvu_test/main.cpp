
#include "bvu.h"
#include "test.h"
#include "benchmark.h"



int main( int argc, char ** argv )
{
    RunTests();
    printf( "-----------------------------\n" );
    RunBenchmark();
    return 1;
}

