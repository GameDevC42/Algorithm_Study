#include<bits/stdc++.h>
using namespace std;

int dist[1000005];
int dx[2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist+1000005, -1);

    queue<int> Q;
    int F, S, G, U, D;

    cin >> F >> S >> G >> U >> D;

    dx[0] = U;
    dx[1] = D;

    dist[S] = 0;
    Q.push(S);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == G){
            cout << dist[cur];
            return 0;
        }
        for(int i = 0; i < 2; i++){
            int nx;
            if( i == 0)
                nx = cur + dx[i];
            else if(i == 1)
                nx = cur - dx[i];
            if(nx <= 0 || nx >= 1000005 || nx > F)
                continue;
            if(dist[nx] >= 0)
                continue;
            if(nx == G){
                cout << dist[cur] + 1;
                return 0;
            }
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }

    cout << "use the stairs";
}