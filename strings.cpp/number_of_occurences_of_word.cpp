//number of occurences of word in a string.
//case insensitive

// #include <iostream>
// #include<string>
// using namespace std;

// int main(){
//     string str="learn learning learnings learning learnt Learn Learnt learn";
//     string word="learn";
//     int count=0;
//     string curr="";
//     transform(str.begin(),str.end(),str.begin(),::tolower); //convert string to lowercase
//     //transform(word.begin(),word.end(),word.begin(),::tolower); //convert word to lowercase
//     //tolower() function converts only a single character to lowercase but not for string.
//     for(int i=0;i<str.length();i++){
//         if((str[i]==' ')){
//             if(curr==word){
//                 count++;
//             }
//             curr="";
//         }else{
//             curr+=str[i];
//         }
//     }
//     //check for last word
//     if(curr==word)count++;
//     cout<<count<<endl;
//     return 0;
// }
//tc transform function takes O(n) for converting string to lowercase of length n.
//for loop O(n)
//tc: O(n)

//sc o(n)