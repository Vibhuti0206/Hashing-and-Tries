#include<bits/stdc++.h>
using namespace std;
int main() 
{
    long int n;
    cin>>n;
    long int arr[n];
    for(int j=0;j<n;j++)
       cin>>arr[j];
    //set <long int> s;
    map<int,int>s;
    int j=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && s.find(arr[j]) ==s.end())
        {
            s.insert(make_pair(arr[j],arr[j]));
            j++;
        }
        sum += ((j-i)*(j-i+1))/2;
        s.erase(arr[i]);
    }
    
    //int k=pow(10,9);
    //int m=k+7;
    //int len=sum.length();
    //int p=0;
    //for(int i=0;i<len;i++)
    //{
      //  p=(p%m+sum[i]%m)%m;
    //}
    cout<<sum;
	return 0;
}
