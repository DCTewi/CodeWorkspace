#include<cstdio>
#include<cstdlib>
const int N = 70 ;
int n , cnt , tot , maxn , minn , tm[ N ] /* 2 */ ; 
void dfs( int res , int sum , int target , int p ) {
    if( res == 0 ) {
        printf("%d", target  );
        exit( 0 );
    }
    if( sum == target ) {
        dfs( res - 1 , 0 , target , maxn );
        return;
    }
    for( int i = p ; i >= minn ; i -- ) { // 2  3 
        if( tm[ i ] && i + sum <= target ) {
            tm[ i ] -- ;
            dfs( res , sum + i , target , i );
            tm[ i ] ++ ;
            if ( sum == 0 || sum + i == target )  //4
                break;
        }
    }
    return;
}
int main() {
    scanf("%d" , &n ) ;
    minn = N ;
    int temp;
    while( n -- ) {
        scanf("%d" , &temp );
        if( temp <= 50 ) {
            cnt ++;
            tm[ temp ] ++;
            tot += temp;
            maxn = maxn > temp ? maxn : temp ;   //1
            minn = minn < temp ? minn : temp ;
        }
    }
    temp = tot >> 1;
    for( int i = maxn ; i <= temp ; i ++ ) {
        if( tot % i == 0 ) {
            dfs( tot / i , 0 , i , maxn );
        }
    }
    printf("%d" , tot );
    return 0;
}
