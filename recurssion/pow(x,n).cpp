//implement pow(x,n)
//consider both positive and negative values of n.

double myPow(double x,int n){
    if(n==0)return 1;
    if(n==1)return x;
    long long nn=n;
    double ans=1.0;
    if(n<0) nn=-1*nn;
    while(nn!=0){
        if(nn%2==0){
            x*=x;
            nn=nn/2;
        }
        if(nn%2!=0){
            ans*=x;
            nn=nn-1;
        }
    }
    if(n<0)ans=1.0/ans;
    return ans;
}

//why i took nn as long instead of int
//for int, INT_MIN= -(2^31)
//INT_MAX=2^31 -1
//so if n=-2^31, then -n=2^31 which is out of range of int
//so i took long long which is 64 bit.
//so nn will be in the range of -2^63 to 2^63-1

//why not long??
//long is 32 bit in some compilers and 64 bit in others.
//long long is 64 bit in all compilers.
//so i took long long to avoid overflow.

//time complexity
//O(logn) due to square exponentiation, dividing n by 2
//for every iteration, we are doing O(1) work

//for example x=2 and n=11
//x^11=x^10*x
//x^10=x^5*x^5

//x^5=x^4*x
//x^4=x^2*x^2

//x^2=x*x
//x^1=x*x^0

//x^0=1(if n=0)

//for every two steps,the value of n is halved.
//if 2 steps are considered as one, then it takes 3 steps ~ O(log11)~O(3)

//the max is o(⌊logn⌋)+1 = O(logn)

//space complexity
//O(1) no extra space is used

//method 2 recursion
double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        long nn=n;
        if(n<0)nn=-1*nn;
        double result;

        result=x*myPow(x,nn-1);
        if(n<0)result=1.0/result;
        return result;
    }
//will lead to stack overflow for large values of n

//one more method
double myPow(double x, int n) {
    if(n==0)return 1;
    if(n==1)return x;
    long nn=n;
    if(n<0)nn=-1*nn;
    
    double result=myPow(x,nn/2) * myPow(x,nn-nn/2);
    if(n<0)result=1.0/result;
    return result;

}
//will lead to tle due to redundannt calls

//similarly u take an array of n+1 size,
//array[0]=1
//array[1]=x
//for(int i=2;i<=n;i++){
//    array[i]=array[i-1]*x;
//}

//this also stack overflow for large values of n


