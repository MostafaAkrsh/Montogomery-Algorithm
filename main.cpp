#include <iostream>

using namespace std;

typedef long long int DWORD;

DWORD montgomery_mul(DWORD in , DWORD exp , DWORD n){
    DWORD c = 0;
    DWORD f = 1;

    for ( int i = 63 ; i >= 0 ; i-- )
    {
        c *= 2;

        f = (f * f)%n;

        if ( (exp>>i) & (0x0000000000000001) )
        {
            c++;
            f = (f * in) % n ;
        }
    }
    return f;
}

int main()
{
    cout<<montgomery_mul(155,23,187);

    return 0 ;
}
