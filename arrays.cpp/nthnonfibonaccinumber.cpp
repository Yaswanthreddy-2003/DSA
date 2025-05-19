//find nth non fibonaci number
#include<iostream>
#include<vector>
using namespace std;
int nonfib(int n){
    if(n==0) return 0;
    int a=0,b=1; //u can also take a=1,b=2 because 
    int count=0;

    while(count<n){
        int nextfib=a+b;

        for(int i=b+1;i<nextfib;i++){
            count++;
            if(count==n){
                return i;
            }
        }

        a=b;
        b=nextfib;

    }
    return -1; //if no non fibonaci number is found
}
int main(){
    int n;
    cin>>n;
    
    int result=nonfib(n);
    cout<<result;
}
