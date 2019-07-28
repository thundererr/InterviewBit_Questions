/*Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details. */
/* https://www.interviewbit.com/problems/anti-diagonals/ */

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int N = A.size();
    vector<vector <int>> B;
    int count, row, col;
    int i, j;
    int line = (2*N) -1; 
    for(count = 1; count <= line; count++){
        vector <int> temp;
        if(count <= N){
            row = 0;
            col = count-1;
        }
        if(count > N){
            col = N-1;
            row = count % N;
        }
        for(i = row, j = col; i <= col&&j >= 0; i++, j--){
            temp.push_back(A[i][j]);
        }
        B.push_back(temp);
    }
    return B;
}
