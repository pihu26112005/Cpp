#include<iostream>
using namespace std;

bool checkPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        if(n==1 && k==1){
            cout<<"NO"<<endl;
            continue;
        }
        if(n==1 && k==2){
            cout<<"YES"<<endl;
            continue;
        }

        if(k==1){
            if(checkPrime(n)){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }

        else{
          cout<<"NO"<<endl;
            continue;
        }
    }
}