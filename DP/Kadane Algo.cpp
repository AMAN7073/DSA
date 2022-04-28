#include<bits/stdc++.h>
using namespace std;
 
int Kadane_Algo(vector<long long> a, int size)
{
    int Maximum_Till_Now = INT_MIN, Maximum_Ending_Here = 0;
    for (int i = 0; i < size; i++)
    {
        Maximum_Ending_Here = Maximum_Ending_Here + a[i];
        if (Maximum_Till_Now < Maximum_Ending_Here)
            Maximum_Till_Now = Maximum_Ending_Here;
 
        if (Maximum_Ending_Here < 0)
            Maximum_Ending_Here = 0;
    }
    return Maximum_Till_Now;
}
 
int main(){
    int n;
    cout<<"Enter the Size of Array: ";
    cin>>n;

    vector<long long> Arr(n);
    for (int i = 0; i < n; i++){
        cout<<"Enter the "<<i+1<<" Element: ";
        cin>>Arr[i];
    }
    
    int Maximum_Sum = Kadane_Algo(Arr, n);
    cout << "Maximum contiguous sum is " << Maximum_Sum;
    return 0;
}
