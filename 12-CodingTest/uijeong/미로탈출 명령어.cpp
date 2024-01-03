#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char d[4] = {'d', 'l' , 'r', 'u'}; // 하 상 우 좌 
string temp = ""; 
string answer = "";
int check;

void dfs(int n, int m, int x, int y, int r, int c, int cnt, int k){
    if(check == 1) return;
    
    if(x==r && y == c && cnt ==k){
        answer = temp;
        check = 1; // 종료 
        return;
    }
    
    if(cnt + abs(x-r)+abs(y-c) > k) return;
    for(int i=0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<1 || nx>n || ny<1 || ny>m) continue;
        temp += d[i];
        dfs(n, m, nx, ny, r, c, cnt+1, k);
        temp.pop_back(); // 원상 복구 
    }
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int move = abs(x-r) + abs(y-c); // 시작점과 도착점까지 최소 이동 
    int remain = abs(k-move); // 남은 이동 
    
    if(remain % 2 == 1 || move > k){
        // 남은 이동이 홀수 이거나 도착할 수 없는 거리 인 경우 
        answer = "impossible";
    }
    else{
        dfs(n, m, x, y, r, c, 0, k); // cnt = 이동거리 k = 이동해야 하는 거리 
    }
    
    return answer;
}
