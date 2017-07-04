#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;
   void dfsrec(vector<set<int>>a,int v,vector<bool>& color,queue <int>& q){
    color[v]=true;
    for(auto t: a[v]){
        if(!color[t])dfsrec(a,t,color,q);
    }
    q.push(v);
}
class graph{
private:

public:
    vector<set<int> > a;
    graph(int size) {
        a.resize(size);
    }
    void add(int from, int to, int w=1, bool bidirectional=false){
        if(from <a.size() && to<a.size()) {
            a[from].insert(to);
            if(bidirectional) a[to].insert(from);
        }
    }//sourse-bcnjxybr
    vector <int> getn(int n){
        vector <int> res;
        if(n>=a.size()) return res;
        for(auto t:a[n]) res.push_back(t);
        return res;
    }
    vector<int> bfs(int s){
        queue<int> q;
        vector <int>res (a.size());
        vector <bool> colors(a.size());
        if(s>=a.size()) return res;
        q.push(s);
        while(!q.empty()){
            int c=q.front();
            q.pop();
            vector<int>neibs=getn(c);

            colors[c]=true;
            for(auto t: neibs){
                if (colors[t])continue;
                q.push(t);
                res[t]=res[c]+1;

            }
        }
        return res;
    }

    void print (){
        set<int> ::iterator it;
        for(int i=0; i<a.size(); ++i){
                printf("a[%d]: ",i);
                for(auto v: a[i])
                    cout << v << ", ";
                printf("\n");
        }
    }
    bool S(int from,int to){
         if(from <a.size() && to<a.size()) {
                if (a[from].find(to)!=a[from].end())return 1;
         }
         return false;
    }

};
int main () {
    setlocale(LC_CTYPE,"RUS");

    cout<<"Пожалуйста, скажите,будет ли ваш граф ориентированным или нет!\nYES-будет, NO-не будет\n";
    string s;
    cin>>s;
    bool WEE;
    if(s=="YES")WEE=false;
    else if(s=="NO")WEE=true;
    else {
        cout<<"Вы что-то не то ввели, попробуйте сначала";
        return 0;
    }
    cout<<"Пожалуйста, введите количество вершин и количество ребер графа (в таком порядке через пробел)\n";
    int n, m;
    cin >> n >> m;//эн-это кол-во вершин, а эм - кол-во рёбер

    graph d(n);
    vector<bool>color(n,false);
    queue <int> q;
    cout<<"Пожалуйста, введите m пар вершин (вершины вводятся через пробел, по паре на строку,задаются целочисленным номером(нум.с нуля) )таких, что между вершинами одной пары есть ребро\n";

    for(int i=0; i<m; ++i){
        int a,b;
        cin >> a >> b;
        d.add(a,b,1,WEE);
    }
   // d.print();
    cout<<"выберите от какой вершины графа до всех прочих его вершин искать кратчайший путь\n";
    int yer;
    cin>>yer;
    auto y=d.bfs(yer);
    cout<<"i-ое число - кратчайший путь в графе до i-ой вершины от заданной, где i=0,...,n-1 \n";
    for(auto t:y) cout << t <<' ';
    cout <<endl;
    system("pause");
}
#if 0
6 10
0 1 15
0 5 10
0 3 1
3 4 2
4 0 5
4 2 2
5 4 4
0 2 20
2 1 3

//////////////////
NO
7 6
0 1
0 4
2 1
3 4
4 6
5 6

#endif //0

