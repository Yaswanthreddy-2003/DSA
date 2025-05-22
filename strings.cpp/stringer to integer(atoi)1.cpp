//to convert string to 32 bit integer
//leetcode 8

int myAtoi(string s) {
        int i=0;
        int sign=1;
        long num=0;

        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(i<s.length() && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='+'){
                sign=1;
                i++;
            }
            else if(s[i]=='-'){
                sign=-1;
                i++;
            }
        }
        
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
                if(sign*num>INT_MAX)return INT_MAX;
                if(sign*num<INT_MIN)return INT_MIN;
                i++;
            }
            else{
                return sign*num;
            }
        }
        return sign*num;

    }
    //time complexity
    //O(n) for traversing the string
    //space complexity
    //O(1) no extra space is used

    //recursive method
    int result(string &s,int i,int sign,long num){
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
                if(num*sign<INT_MIN)return INT_MIN;
                if(num*sign>INT_MAX)return INT_MAX;
                return result(s,i+1,sign,num);
            }
            else{
                return sign*num;
            }
        }
        return sign*num;
        
    }
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long num=0;

        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(i<s.length() && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='+'){
                sign=1;
                i++;
            }
            else if(s[i]=='-'){
                sign=-1;
                i++;
            }
        }
        int k=result(s,i,sign,num);
        return k;
        
    }
//time complexity
//O(n)
//recursion calls O(d) where d are number of digits and each digit does O(1) work
//and also considering whitespaces and digit check
//total O(n)

//sc
//O(n) for recursion stack
