#include<iostream>
#include<vector>
#include <queue>
#include <cstdio>
using namespace std;

queue<int>way;
void dfs(int v,vector<int>& color, vector<vector<int> >& q){
    color[v]=1;
   for(auto t:q[v]){
        if(!color[t])dfs(t,color,q);
    }
    color[v]=2;
//    way.push_back(v);
    way.push(v);
}
int main(){
    int n,m;
    setlocale(LC_CTYPE,"RUS");
    cout<<"Пожалуйста, введите количество вершин и количество ребер ориентированного графа q (в таком порядке через пробел)\n";
    cin>>n>>m;//n-кол-во вершин графа,m - кол-во рёбер графа
    vector<vector<int> > q(n);
    cout<<"Пожалуйста, введите m пар вершин (вершины вводятся через пробел, по паре на строку,задаются целочисленным номером(нум.с нуля) )таких, что между вершинами одной пары есть ребро\n";
       for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        q[a].push_back(b);
    }
    vector<int>color(n,0);
    for(int i=0;i<n;++i){
        if(color[i]==0)dfs(i,color,q);
    }
    printf("Граф q: ");
    for(int i=0;i<n;++i){
       printf("\nq[%d]: ",i);
       for(int j=0;j<q[i].size();++j)(j<q[i].size()-1) ? (printf("%d, ",q[i][j]) ): (printf("%d",q[i][j] ) );
    }
    printf("\n");
   cout<<"Порядок обхода вершин графа q\n";
    while(!way.empty()){
        cout<<way.front()<<' ';
        way.pop();
    }
}
