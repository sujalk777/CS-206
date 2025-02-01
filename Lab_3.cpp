#include<bits/stdc++.h>
using namespace std;
int count(const vector<vector<int>>&matrix){
    int n=matrix.size();
    vector<vector<int>>reachable(n, vector<int>(n,0));

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         reachable[i][j]=matrix[i][j];
    //     }
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            reachable[i][j]=matrix[i][j];
            if(matrix[i][j]){   
                for(int k=0;k<n;k++){
                    if(matrix[j][k]){
                        reachable[i][k]=1;
                    }
                }
            }
        }
    }
    int count =0;
    int connected=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(reachable[i][j] && i!=j) {
                connected++;
            }
        }
        if (connected>=n-1) count++;
    }
    return count;
}



int main(){
    int n;
    cout<<"Enter the number of cities:";
    cin>>n;

    vector<vector<int>>matrix(n,vector<int>(n));
    cout<<"Enter the connection between the cities";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int res=count(matrix);
    cout<<"Number of cities reachable in one or two steps are: "<<res<<endl;
    return 0;
}
