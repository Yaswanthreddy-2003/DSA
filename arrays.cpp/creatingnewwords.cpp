//You are given a vector (or list) of strings. Your task is to create a new array of strings such that:

// Each element in the result is formed by:

// The first letter of the current word and

// The last letter of the next word in the list.

// If the current word is the last one in the list, then pair it with the first letter of the first word (circular fashion).
#include <iostream>
#include <vector>
using namespace std;
vector<string>ans(vector<string>&v){
    vector<string>ans;
    int n=v.size();
    if(n==0){
        //return vector<string>();
        return ans;
    }
    for(int i=0;i<v.size();i++){
        string s;
        s+=v[i][0];
        int j=(i+1)%n;
        s.push_back(v[j].back());//s.push_back(v[j][v[j].length()-1])
        ans.push_back(s);
    }
    return ans;
    
}

int main() {
    // Write C++ code here
    vector<string>v={"apply","ball","cat","dog","eye"};
    vector<string>final=ans(v);
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<endl;
    }
    

    return 0;
}