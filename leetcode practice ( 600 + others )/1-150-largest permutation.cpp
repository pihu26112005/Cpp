// https://www.interviewbit.com/problems/largest-permutation/

vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int j=n;
    vector<int> nid(n+1);
    for(int i=0;i<n;i++){
        nid[A[i]]=i;
    }
    
    for(int i=0;i<n && B>0;i++){
       if(A[i]==j){
           j--;
       }
       else{
           int idx=nid[j];
           nid[j]=i;
           nid[A[i]]=idx;
           swap(A[i],A[idx]);
           j--;
           B--;
       }
    }
    return A;
}
