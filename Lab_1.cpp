//We need to print 10000th fibonacci number 



#include <iostream>
#include <vector>
#include <string>
using namepsace std;
vector<vector<<ll>>indetitymatrix({
    {1,0},
    {0,1}
});
vector<vector<ll>>result({
    {0,0},
    {0,0}
});
void multiply(vector<vector<<ll>>a,vector<vector<<ll>>b){
    for(auto &i:result){
        for(auto &j:i){
            j=0;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                result[i][k]+=a[i][j]*b[j][k];
                
            }
        }
    }
}
void matrixexpo(vector<vector<ll>>matrix,ll n){
    if(n==0){
        result=identitymatrix;
        return;
    }
    matrixexpo(matrix,n/2);
    multiply(result,matrix);
    if(n&1) multiply(result,matrix);
}
ll nthfibonacci(ll n){
    if(n<=1) return n;
    vector<vector<ll>>basematrix({
        {1,1},
        {1,0}
    });
    multiply(basematrix,indentitymatrix);
    matrixexpo(basematrix,n-1);
    return result[0][0];
}
