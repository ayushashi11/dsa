#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int stepCount=0;
void motherVertexBFS(int n, int** adj){
    for(int i=0; i<n; i++){
        bool visited[n]={false};
        queue<int> q, bfs;
        q.push(i);
        visited[i]=true;
        stepCount+=4;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            bfs.push(j);
            stepCount+=4;
            for(int k=0;k<n;k++){
                stepCount+=2;
                if(adj[j][k]==1){
                    stepCount++;
                    if(!visited[k]){
                        visited[k]=true;
                        q.push(k);
                        stepCount+=2;
                    }
                }
            }
        }
        stepCount++;
        if(bfs.size()==n){
            stepCount++;
            cout<<i<<" is a mother vertex"<<endl;
        }
    }
}

void motherVertexDFS(int n, int** adj){
    for(int i=0; i<n; i++){
        bool visited[n]={false};
        queue<int> dfs;
        stack<int> s;
        s.push(i);
        stepCount+=4;
        while(!s.empty()){
            int j=s.top();
            s.pop();
            visited[j]=true;
            dfs.push(j);
            stepCount+=5;
            for(int k=0;k<n;k++){
                stepCount+=2;
                if(adj[j][k]==1){
                    stepCount++;
                    if(!visited[k]){
                        stepCount++;
                        s.push(k);
                    }
                }
            }
        }
        stepCount++;
        if(dfs.size()==n){
            stepCount++;
            cout<<i<<" is a mother vertex"<<endl;
        }
    }
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
    motherVertexBFS(n, A);
    //motherVertexDFS(n, A);
    cout<<"step count: "<<stepCount<<endl;
}

