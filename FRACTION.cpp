string Solution::fractionToDecimal(int A, int B) {
 
 if (A == 0)
        return "0";
    long long int n = A, d = B;
    string res = "";
    
    if (n < 0 ^ d < 0)      
        res += '-';
    
    n = abs(n), d = abs(d);
    
    res += to_string(n/d);
    long long int rem = n%d;
    
    if (rem == 0)
        return res;
    
    res += '.';
    
    unordered_map<int, int> m;
    bool repeat = false;
    int idx; 
    while(rem >0 && !repeat)
    {
        if (m.find(rem) != m.end())
        {
            idx = m[rem];
            repeat = true;
            break;
        }
        else
        m[rem] = res.size();
        rem *= 10;
       long long int k = rem/d;
      res += to_string(k);
      rem = rem % d;
    }
     if(repeat)
  {
      res += ")";
      res.insert(idx,"(");
  }
    return res;
   




}
