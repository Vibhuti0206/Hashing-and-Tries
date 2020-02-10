#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long int l;
        long int n;
        cin>>l;
        long int arr[l];
        unordered_map<long int,bool> m;
        for(long int j=0;j<l;j++)
        {   cin>>arr[j];
           m[arr[j]]=true;
        }
        long int q;
        cin>>q;
        while(q--)
        {
            
            cin>>n;
            if(m.count(n))
              cout<<"Yes"<<endl;
            else
              cout<<"No"<<endl;
        }
               
    }
	return 0;
}
