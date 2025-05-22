//count good numbers
//lc 1922
//A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
//return the result modulo 10^9 + 7
//the length of the string is n

//method 1
int countgood(long long n){
    if(n==0)return 0;//n=0 meant no digits
    long long result=1;
    long long mod=1000000007;
    int i=0;
    while(i<n){
        if(i%2==0){
            result=(result*5)%mod;
            i++;
        }
        else{
            result=(result*4)%mod;
            i++;
        }
        

    }
    return result%mod;
}
//output will be tle for large values of n
//so we have to do the problem at at tc of less than n.
//we can implement the pow method we did before

//method 2
//the total num of good digits= 5*no.of even places + 4*no.of odd places % mod .
//so we can use pow method to calculate the result

long long mypow(long long x,long long exp){
    
    long long result=1;
    while(n>0){
        if(n%2==0){
            x=(x*x)%1000000007;
            exp=exp/2;
        }
        else{
            result=(result*x)%1000000007;
            exp--;
        }
    }
    return result;
}
int countgood(long long n){
    if(n==0)return 0;
    long long mod=1000000007;
    int even=(n+1)/2;
    int odd=n/2;
    return mypow(5,even)*mypow(4,odd)%mod;
}

//time complexity
//O(logn) due to binary exponentiation  
//space complexity
//O(1) no extra space is used
//the above code will work for large values of n

//why even=(n+1)/2 and odd=n/2?
//for n=1, even=1 and odd=0
//for n=2, even=1 and odd=1
//for n=3, even=2 and odd=1
//for n=4, even=2 and odd=2

//if u can see, for n is odd, even=(n+1)/2 and odd=n/2
//if u can see, for n is even, even=n/2 and odd=n/2
//for n= even, n+1/2 and n/2 are the same