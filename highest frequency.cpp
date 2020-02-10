#include<iostream>
#include<unordered_map>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++) 
       cin>>arr[i];

       unordered_map<long long int,long long int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    long long int max_c=0;
    long long int res=-1;
    for(auto i : m)
    {
        if(max_c<=i.second) 
        {
            res=i.first;        //first tells what number whereas second tells the frequency;
            max_c=i.second;
        }
    }
    cout<<res;
    
	return 0;
}
