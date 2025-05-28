// //given integer n
// //u have to  print all binary strings of length n

// //recursion
// #include <iostream>
// using namespace std;
// #include <vector>

// void recur(vector<string>&arr,int i,string &s){
//         if(i==s.size()){
//             arr.push_back(s);
            
//             return;
//         }
//         s[i]='0';
//         recur(arr,i+1,s);
//         s[i]='1';
//         recur(arr,i+1,s);
        
//     }
//     vector<string> generateBinaryStrings(int num) {
//         // Write your code
//         vector<string>arr;
//         int i=0;
//         string s(num,' ');
//         recur(arr,i,s);
//         return arr;
        
        
//     }


// int main()
// {
//     int num=3;
//     vector<string>k = generateBinaryStrings(num);
//     for(int i=0;i<k.size();i++){
//         cout<<k[i]<<" ";
//     }
    
    
// }

//time complexity
//O(2^n) for n length string
//why 2^n?
//because for every bit, we have two choices: 0 or 1
//so for n bits, we have 2^n combinations

//total calls: 1+2+4+8+....
//O(2^n-1) ~ O(2^n)

//space complexity
//O(n) for the recursion stack
//O(n) for the string
//O(n) for the vector
//total O(n)


//to find all binary strings without consecutive 1s

// void recur(vector<string>&arr,int i,string &s){
//         if(i==s.size()){
//             arr.push_back(s);
            
//             return;
//         }
//         s[i]='0';
//         recur(arr,i+1,s);
//         if(i==0||s[i-1]!='1'){
//             s[i]='1';
//             recur(arr,i+1,s);
//         }
        
//     }
    