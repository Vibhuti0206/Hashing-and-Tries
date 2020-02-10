#include<bits/stdc++.h>
using namespace std;
class node
{
public:

    node *left;
    node *right;
};

void insert(int num,node *head)
{
    
    node *curr=head;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i) & 1;
        if(bit==0)
        {
            if(curr->left == NULL)
            {
                curr->left = new node();
                curr = curr->left;
            }
            else 
              curr = curr->left;
        }
        if(bit==1)
        {
            if(curr->right == NULL)
            {
                curr->right = new node();
                curr = curr->right;
            }
            else 
              curr = curr->right;
        }
    }

}
int check(int value,node *head)
{
  node *curr=head;
  
  int curr_xor = 0;
  

  for(int i=31;i>=0;i--)
  {
      int b = (value>>i) & 1;
      if(b==0)
      {
          if(curr->right !=NULL)
          {
              curr=curr->right;
              curr_xor += pow(2,i);
          }
          else
             curr = curr->left;
      }
       if(b==1)
      {
          if(curr->left !=NULL)
          {
              curr=curr->left;
              curr_xor += pow(2,i);
          }
          else
             curr = curr->right;
      }
  }
  return curr_xor;
}
int main() {
    int q;
    cin>>q;
    vector<long long int> arr;
    while(q--)
    {
       int type;
       cin>>type;
        if(type == 0)
        {
           int x;
           cin>>x;
           arr.push_back(x);
        }
        else
        {
          int l,r,x;
          cin>>l>>r>>x;
          arr.push_back(x);
          int max=INT_MIN;
          node *head = new node();
          insert(x,head);
          int final;
          int ans1;
          for(int m=l-1;m<r;m++)
          {
              int ans=check(arr[m],head);
              if(ans > max)
              {
                  max=ans;
                  ans1=arr[m];
              }
              final=ans1;
          }
          cout<<final<<endl;
        }
    }
	return 0;
}
