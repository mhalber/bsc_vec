#pragma once

// TODO: add proper floating point comparison operations!

namespace bsc
{
    template <typename T>
    inline T
    clamp ( T val, T min, T max )
    {
        if ( val < min ) val = min;
        if ( val > max ) val = max;
        return val;
    }

    template <typename T>
    inline void
    swap ( T & a, T & b )
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template <typename T>
    inline T
    square ( const T & a )
    {
        return a * a;
    }

    template <typename T>
    inline T
    cube ( const T & a )
    {
        return a * a * a;
    }

    template <typename T>
    inline T
    max ( T a, T b )
    {
        return a > b ? a : b;
    }

    template <typename T>
    inline T
    min ( T a, T b )
    {
        return a > b ? b : a;
    }

    template <typename T>
    inline T
    min3 ( T a, T b, T c )
    {
        return min( c, min( a, b ) );
    }

    template <typename T>
    inline T
    max3 ( T a, T b, T c )
    {
        return max( c, max( a, b ) );
    }


    template <typename T>
    inline T
    deg2rad ( T deg )
    {
        return deg * M_PI / 180.0;
    }

    template <typename T>
    inline T
    rad2deg ( T rad )
    {
        return rad * 180.0 / M_PI;
    }

    template< int NReps = 1, typename TimeUnit = std::chrono::duration<double>, typename F, typename ...Args >
    typename TimeUnit::rep MeasureTime ( F function, Args&&... arguments )
    {
        auto start = std::chrono::system_clock::now();

        for ( int i = 0 ; i < NReps; ++i )
        {
            function( std::forward<Args>(arguments)... );
        }

        auto duration = std::chrono::duration_cast<TimeUnit>( std::chrono::system_clock::now() - start );

        return duration.count() / (double)NReps;
    }

    template<typename TimeUnit = std::chrono::duration<double> >
    struct Timer
    {
        std::chrono::time_point<std::chrono::system_clock> s; // start
        std::chrono::time_point<std::chrono::system_clock> e; // end

        void start () { s = std::chrono::system_clock::now(); }
        void stop ()  { e = std::chrono::system_clock::now(); }
        typename TimeUnit::rep duration() { return std::chrono::duration_cast<TimeUnit>( e - s ).count(); }
        typename TimeUnit::rep elapsed () { return std::chrono::duration_cast<TimeUnit>( std::chrono::system_clock::now() - s ).count(); }
    };

        /*
    inline bool
    IsPositive( r32 s, r32 epsilon  )
    {
        return (s > epsilon);
    }

    inline bool
    IsNegative ( r32 s, r32 epsilon  )
    {
        return ( s < -epsilon );
    }

    inline bool
    IsPositiveOrZero ( r32 s, r32 epsilon )
    {
        return ( s >= -epsilon );
    }

    inline bool
    IsNegativeOrZero ( r32 s, r32 epsilon )
    {
        return ( s <= epsilon );
    }

    inline bool
    IsZero ( r32 s, r32 epsilon )
    {
        return ( IsPositiveOrZero( s, epsilon ) && IsNegativeOrZero( s, epsilon ) );
    }

    inline bool
    IsNotZero ( r32 s, r32 epsilon )
    {
        return ( IsPositive( s, epsilon ) || IsNegative( s, epsilon ) );
    }

    inline bool
    Equal ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsZero( s1 - s2, epsilon );
    }

    inline bool
    NotEqual ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsNotZero( s1 - s2, epsilon );
    }

    inline bool
    Greater ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsPositive( s1 - s2, epsilon );
    }

    inline bool
    Less ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsNegative( s1 - s2, epsilon );
    }

    inline bool
    GreaterOrEqual ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsPositiveOrZero( s1 - s2, epsilon );
    }

    inline bool
    LessOrEqual ( r32 s1, r32 s2, r32 epsilon )
    {
        return IsNegativeOrZero( s1 - s2, epsilon );
    }
    */
}

