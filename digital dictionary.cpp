#include<bits/stdc++.h>
using namespace std;
class node
{
public:
   char data;
   bool terminal;
   unordered_map<char,node*> children;

   node(char d)
   {
       data=d;
       terminal=false;
   }
};
class trie
{
    public:
    node *root;
    
    int count;
     trie()
     {
         root=new node('\0');
         count=0;
     }
     void addword(string str)
     {
         node *temp=root;
         for(int i=0;str[i] !='\0';i++)
         {
             char ch=str[i];
             if(temp->children.count(ch))
             {
                 temp= temp->children[ch];
             }
             else
             {
                 node* n=new node(ch);
                 temp->children[ch]=n;
                 temp = n;
             }

         }
         temp->terminal=true;
     }
     bool search(string str)
	{
		node *temp=root;
		for(int i=0;str[i] !='\0'; i++)
		{
			char ch=str[i];
			if(temp->children.count(ch))  //if that character is the child of the root
			{
				temp = temp->children[ch];
			}
			else
			{
			return false;                  //the word is not present 
			}
		}
	 vector<string>v;
    print(str,v,temp);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return true;        

        
    }
     void print(string s,vector<string>&v,node* temp){
    if(temp->terminal){
        v.push_back(s);
    }
    for(auto i=temp->children.begin();i!=temp->children.end();i++){
        s+=i->second->data;
        print(s,v,i->second);
        s.pop_back();
    }
}
         
         
         

};   
                 
int main() {
    
      int n;
      cin>>n;
	  
      trie t;
      while(n--)
      {
          string s;
          cin>>s;
          t.addword(s);
      }
      int q;
      cin>>q;
      while(q--)
      {
          string str;
          cin>>str;
          
           bool temp=t.search(str);
        if(!temp){
            cout<<"No suggestions"<<endl;
            t.addword(str);
      }
      }


	return 0;
}
