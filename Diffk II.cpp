int Solution::diffPossible(const vector<int> &A, int B) {
    
    unordered_set<int> table;
    
    for(int i = 0;i<A.size();i++){
        if(table.find(A[i]-B)!=table.end() || table.find(A[i]+B)!=table.end())
            return 1;
        table.insert(A[i]);
    }
    return 0;
}
