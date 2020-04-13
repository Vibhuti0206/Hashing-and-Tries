int Solution::colorful(int A) {
      
   if(A == NULL){
        return 0;
    }
    
    vector<int> vec;
     int product = 1;
   int value = 1;
    
    while(A){
        
        vec.push_back(A%10);
        A = A/10;
    }
    
    unordered_map<int, int> m;
    
    for(int i = 0; i < vec.size(); i++)
    {
        value = 1;
        for(int j = i; j < vec.size(); j++)
        {
            value = value*vec[j];
            if(m.find(value) != m.end())
                return 0;  
            else 
             m[value]++;
            }
           
        }
    
    
    
    return 1;

}

OR
int Solution::colorful(int A) {
  
string a=to_string( A);
int len=a.length();

unordered_map<long long, bool> Hash;

        for(int i = 0; i < len; i++) {
            long long mul = 1;
            for(int j = i; j < len; j++) {
                mul *= (long long)(a[j] - '0');
                if(Hash.find(mul) != Hash.end())   return 0;
                       
                Hash[mul] = true;
            }
        }

        return 1;




}


