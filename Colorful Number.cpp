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
