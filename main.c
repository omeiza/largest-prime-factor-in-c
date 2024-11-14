#include <stdio.h>;
#include <stdbool.h>;

// Utility function to find prime factor of any integer
bool isPrime ( const int input ) {
    for ( int i = 2; i < input; i++ ) {
        if ( input % i == 0 ) return false;
    }

    return input > 1;
}

int largestPrimeFactor( long num ) {
    // We need to set the initial value of largestPrimeFactor
    int largestPrimeFactor = 0;

    for ( int divisor = 2; divisor <= num; divisor++ ) {
        if ( num % divisor == 0 ) {
            num = num / divisor;

            // Update largestPrimeFactor at every iteration when we encounter a larger prime factor
            if ( isPrime( divisor ) && largestPrimeFactor < divisor ) largestPrimeFactor = divisor;
        }
    }

    return largestPrimeFactor;
}

int main() {
    const long num = 600851475143;

    largestPrimeFactor( num )
        ? printf( "The largest prime factor of %ld is %d\n", num, largestPrimeFactor( num ) )
        : printf( "%ld has no prime factor\n", num );

    return 0;
}
