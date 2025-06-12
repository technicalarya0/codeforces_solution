#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void sumOfAllSubarrays(const vector<int>& arr) {
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            cout<<sum<<endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    sumOfAllSubarrays(arr);
    return 0;
}