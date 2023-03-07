#include<iostream>
#include<stack>
#include<queue>
using namespace std;
bool isConnectedDFS(int n, int** adj){
    for(int i=0; i<n; i++){
        bool visited[n];
        for(int i=0;i<n;i++) visited[i]=false;
        int count=0;
        stack<int> s;
        s.push(i);
        cout<<"dfs"<<endl;
        while(!s.empty()){
            int j=s.top();
            s.pop();
            visited[j]=true;
            count++;
            cout<<j<<endl;
            for(int k=0;k<n;k++){
                if(adj[j][k]==1){
                    if(!visited[k]) s.push(k);
                }
            }
        }
        if(count==n){
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cout<<"enter number of vertices: ";
    cin>>n;
    int **A=new int*[n];
    for(int i=0;i<n;i++){
        A[i]=new int[n];
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }
    cout<<"enter the number of edges: ";
    cin>>m;
    for(int t=0; t<m; t++){
        int p,q;
        cout<<"enter source and destination: ";
        cin>>p>>q;
        A[p][q]=1;
    }
    if(isConnectedDFS(n, A)){
        cout<<"Connected"<<endl;
    }
    else{
        cout<<"Not Connected"<<endl;
    }
}
