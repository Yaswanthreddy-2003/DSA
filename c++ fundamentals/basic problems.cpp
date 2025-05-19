//reverse a number
int reverse(int n){
    int rev=0;
    while(n>0){
        rev=rev*10 + n%10;
        n=n/10;

    }
    return rev;
}

//convert string to integer
int stringtoint(string s){
    int n=0;
    for(int i=0;i<s.length();i++){
        n=n*10 + (s[i]-'0');
    }
    return n;
}

//convert integer to string
string inttostring(int n){
    string s="";
    while(n>0){
        s=char(n%10+'0')+s;
        n=n/10;
    }
    return s;
}
