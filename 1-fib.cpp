#include<bits/stdc++.h>
using namespace std;

void nonrec(int n){
    int a = 0,b = 1;

    cout << "Fibonacci Sequence up to"<< n <<"terms (Iterative) : ";

    if(n >=1) cout << a << " ";
    if(n >=2) cout << b << " ";

    for(int i = 2;i < n;i++){
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }

}

int rec(int n){
    if(n <=1 )
        return n;

    return rec(n - 1) + rec(n - 2);
}

int main(){
    int  n;
    cout << "Enter number of terms : ";
    cin >> n;

    nonrec(n);
    cout << endl;

    cout << "Fibonacci sequence up to" << n <<"terms (Recursive) : ";

    for(int i = 0;i < n;i++){
        cout << rec(i) << " ";
    }

    cout << endl;
    
    
    return 0 ;
}