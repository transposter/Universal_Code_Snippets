Fig10_46.cpp - Dynamic programming algorithm for optimal chain matrix multiplication,
with a test program
	
	#include <iostream.h>
        #include <limits.h>
        #include "matrix.h"

/* START: Fig10_46.txt */
        const long INFINITY = LONG_MAX;

        /**
         * Compute optimal ordering of matrix multiplication.
         * c contains the number of columns for each of the n matrices.
         * c[ 0 ] is the number of rows in matrix 1.
         * The minimum number of multiplications is left in m[ 1 ][ n ].
         * Actual ordering is computed via another procedure using lastChange.
         * m and lastChange are indexed starting at 1, instead of 0.
         * Note: Entries below main diagonals of m and lastChange
         * are meaningless and uninitialized.
         */
        void optMatrix( const vector<int> & c,
                        matrix<long> & m, matrix<int> & lastChange ) 
        {
            int n = c.size( ) - 1;

            for( int left = 1; left <= n; left++ )
                m[ left ][ left ] = 0;
            for( int k = 1; k < n; k++ )   // k is right - left
                for( int left = 1; left <= n - k; left++ )
                {
                    // For each position
                    int right = left + k;
                    m[ left ][ right ] = INFINITY;
                    for( int i = left; i < right; i++ )
                    {
                        long thisCost = m[ left ][  i ] + m[ i + 1 ][ right ]
                             + c[ left - 1 ] * c[ i ] * c[ right ];
                        if( thisCost < m[ left ][ right ] )  // Update min
                        {
                            m[ left ][ right ] = thisCost;
                            lastChange[ left ][ right ] = i;
                        }
                    }
                }
        }
/* END */

        int main( )
        {
            vector<int> c( 5 );
            c[ 0 ] = 50; c[ 1 ] = 10; c[ 2 ] = 40; c[ 3 ] = 30; c[ 4 ] = 5;
            matrix<long> m( 5, 5 );
            matrix<int>lastChange( 5, 5 );

            optMatrix( c, m, lastChange );

            int i;
            for( i = 1; i < m.numrows( ); i++ )
            {
                for( int j = 1; j < m.numcols( ); j++ )
                    cout << m[ i ][ j ] << "    ";
                cout << endl;
            }
            for( i = 1; i < lastChange.numrows( ); i++ )
            {
                for( int j = 1; j < lastChange.numcols( ); j++ )
                    cout << lastChange[ i ][ j ] << "    ";
                cout << endl;
            }

            return 0;
        }
