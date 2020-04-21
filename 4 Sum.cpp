vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    set<vector<int>> result;
    vector<int> res;
    unordered_map<int,vector<pair<int,int>>> mp;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int tf=B-A[i]-A[j];
            if(mp.find(tf)!=mp.end())
            {   for(auto it=mp[tf].begin();it!=mp[tf].end();it++)
                {if(it->first!=it->second&&it->first!=i&&it->first!=j&&it->second!=i&&it->second!=j&&i!=j)
                {res.push_back(A[it->first]);
                res.push_back(A[(it->second)]);
                res.push_back(A[i]);
                res.push_back(A[j]);
                sort(res.begin(),res.end());
                result.insert(res);
                res.clear();}
                    
                }
                
            }
             mp[A[i]+A[j]].push_back(make_pair(i,j));
               
            
        }
    }
    vector<vector<int>> nrs;
    for(auto i:result)
    {
        nrs.push_back(i);
    }
    return nrs;
}






OR/////




vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> v;
    int n = A.size();
    if(n<4)
     return res;
    sort(A.begin(),A.end());
   int i=0;
   while(i<n-3)
    {
        int j= i+1;
        while(j<n-2)
        {
            int one = A[i];
            int sec = A[j];
            int req = B-one-sec;
            int k = j+1; int l = n-1;
            while(k<l && k<n)
            {
                if(A[k] + A[l] == req)
                {
                    v.push_back(one);
                    v.push_back(sec);
                    v.push_back(A[k]);
                    v.push_back(A[l]);
                    
                    res.push_back(v);
                    v.clear();
                    while(A[k] == A[k+1] && k<n-1)
                     {
                         k++;
                     }
                     while(A[l] == A[l-1] && l>j)
                     {
                         l--;
                     }
                     k++;
                     l--;
                    
                }
                else if(A[k] + A[l] < req)
                 k++;
                else
                 l--;
                    
            }
            while(A[j] == A[j+1])
            {
                j++;
            }
            j++;

        }
        while(A[i] == A[i+1])
        {i++;
        }
        i++;
    }
   // sort(res.begin(),res.end());
    return res;
}
