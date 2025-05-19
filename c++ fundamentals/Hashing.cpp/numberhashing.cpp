//hashing
lets say you were given an array [1,2,3,1,2] and you were given queries [1,3,4,2,10].
the question is for each query you have to find how many times the query appears inn the array. example for query 1, it appeared 2 times in the array.
query  no:of times 
1          2
3          1
4          0
2          2
10         0

the above question can be solved using hashing.

the basic approach would be to use two loops and compare each element of the array with the query and increment the count if the element is equal to the query.
this approach would take O(n^2) time complexity.
code:
int main(){
    vector<int>arr={1,2,3,1,2};   
    vector<int>queries={1,3,4,2,10};
    for(int i=0;i<queries.size();i++){
        int count=0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==queries[i]){
                count++;
            }
        }
        cout<<queries[i]<<" "<<count<<endl;
    }
    return 0;
}

for array of size n, for one query it would take O(n) time complexity and for q queries it would take O(n*q) time complexity.

if the length of the array is 10^5 and the number of queries is 10^5 then the time complexity would be O(10^10).
Compiler takes 10^8 operations in one second.
for 10^10,it takes 100 secinds which is not feasible.

so we need to optimize the above approach.

Hashing

Hashing is a technique that is used to store the data in such a way that it becomes easy to search, insert and delete the data. 
It is a technique that is used to map a given value with a particular key for faster access of elements.

Hashing is implemented using arrays.

code:
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
//precomputing the hash array
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    int q;
    cin>>q; 
    while(q--){
        int number;
        cin>>number;
        cout<<number<<" "<<hash[number]<<endl;


    }

    return 0;

}
eg:
5
1 2 3 2 1
3
1
2
3

int n;
cin >> n; // n = 5
int arr[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i]; // arr = [1, 2, 3, 2, 1]
}

int hash[13] = {0};
for(int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
}
// After this loop, hash = [0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
// Explanation: 
// hash[1] = 2 (because 1 appears twice in arr)
// hash[2] = 2 (because 2 appears twice in arr)
// hash[3] = 1 (because 3 appears once in arr)

int q;
cin >> q; // q = 3

while(q--) {
    int number;
    cin >> number;
    cout << number << " " << hash[number] << endl;
}

First Query:
number is read as 1.
Output: 1 2 (because hash[1] is 2).
Second Query:
number is read as 2.    
Output: 2 2 (because hash[2] is 2).
Third Query:
number is read as 3.
Output: 3 1 (because hash[3] is 1).
Summary

ARRAY DECLARATION INSIDE main(), the maximum size is 10^6.
ARRAY DECLARATION OUTSIDE main(), the maximum size is 10^7.
eg:
int hashh[10000000]={0};
int main(){
    
}

similarly for boolean,
inside main() the maximum size is 10^7.
outside main() the maximum size is 10^8.

