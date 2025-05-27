#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> factor;
    int n = 21;
    for(int i=2; i*i <= n; i++){
        while(n%i == 0){
            factor.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factor.push_back(n);

    for(int i=0; i<factor.size(); i++){
        cout<<factor[i]<<" ";
    }

    return 0;
}