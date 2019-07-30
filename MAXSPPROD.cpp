// PROBLEM LINK https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) {
    long long i,j,max, k;
    long long n = A.size();
    long long maxProd = 0;
    int MAX = 1000000007;
    long long leftvalue[100002] = {0};
    long long rightvalue[100002] = {0};
    stack<long long> sl;
    stack<long long> sr;
    sl.push(0);
    sr.push(n-1);
    for(i = 1, j = n-2; i <= n & j >= 0; i++, j--){
        while(!sl.empty()&&A[sl.top()] < A[i]){
            leftvalue[sl.top()] = i;
            sl.pop();
        }
        sl.push(i);
        while(!sr.empty()&&A[sr.top()] < A[j]){
            rightvalue[sr.top()] = j;
            sr.pop();
        }
        sr.push(j);
    }
   for(i = 0; i < n; i++){
        long long prod = (leftvalue[i]* rightvalue[i]);
        if(maxProd < prod){
            maxProd = prod;
        }
    }
    return maxProd%MAX;
}
