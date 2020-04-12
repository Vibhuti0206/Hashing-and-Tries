#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node *left;
    node *right;
};
void insert(node *head,long long int num)
{
    node *temp = head;
    for(int i=31;i>=0;i--)
    {
        long long int b = (num >> i) &1;
        if(b==1)
        {
            if(temp->right)
             temp = temp->right;
            else
            {
                temp->right = new node();
                temp = temp->right;
            }
        }
        if(b==0)
        {
            if(temp->left)
             temp = temp->left;
            else
            {
                temp->left = new node();
                temp = temp->left;
            }
        }
        
        
    }
}
long long int maxxor(node *head,int key)
{
    node *temp = head;
    long long int curxor = 0;
    for(int i=31;i>=0;i--)
    {
       long long  int b = (key>>i)&1;
        if(b==1)
        {
            if(temp->left)
            {
                temp = temp->left;
                curxor += pow(2,i);
                
            }
            else
             temp = temp->right;
        }
         if(b==0)
        {
            if(temp->right)
            {
                temp = temp->right;
                curxor += pow(2,i);
                
            }
            else
             temp = temp->left;
        }
    }
    return curxor;
}
int main()
{
    int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
      cin>>arr[i];
    vector<long long int> v;
      node *head = new node();
      //insert(head,0);
      
      int prexor = 0;
    for(int i=0;i<n;i++)
    {
       prexor = prexor ^ arr[i];
       v.push_back(prexor);
    }
    int c = v.size();
   /* for(int i=0;i<c;i++)
     cout<<v[i]<<" ";
    cout<<endl; */
   long long  int ans;
   // int final;
   long long  int value = INT_MIN;
   insert(head,v[0]);
    for(int i=0;i<n;i++)
    {
       //insert(head,v[i]);
       ans = maxxor(head,v[i]);
     /*  cout<<ans<<" ";
       cout<<endl; */
       if(ans > value)
       {
           value = ans;
       }
       insert(head,v[i]);
       
    }
    cout<<value;
    return 0;
}
