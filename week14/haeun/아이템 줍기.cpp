#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 101; 
int graph[MAX][MAX]; 
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int endX, endY; 

void initMap(vector<vector<int>> rects) {
	// 직사각형의 좌표를 모두 2배로 만든다. 
    for(auto& rect: rects){
        for(auto& coord: rect){
            coord *= 2;
        }
    }
    
    // 모든 직사각형의 테두리와 그 내부를 1로 채운다. 
    // 이미 1이면 그냥 놔둔다. 
    for(auto& rect: rects){
        int x1 = rect[0];
        int y1 = rect[1];
        int x2 = rect[2];
        int y2 = rect[3];
        
        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                if(graph[y][x] == 0) graph[y][x] = 1;
            }
        }
    }
    
    // 모든 직사각형의 내부를 2로 채운다. 
    for(auto& rect: rects){
        int x1 = rect[0];
        int y1 = rect[1];
        int x2 = rect[2];
        int y2 = rect[3];
        
        for(int y = y1 + 1; y < y2; y++){
            for(int x = x1 + 1; x < x2; x++){
                graph[y][x] = 2; 
            }
        }
    }
}

void bfs(int startY, int startX) {
    queue<pii> q;
    q.push({startY, startX});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        // 아이템 위치까지 도달한 경우 반복문 종료
        if(y == endY && x == endX) {
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 직사각형의 가장 바깥쪽 테두리인 경우, 방문 처리 후 이동 거리 갱신 
            if(graph[ny][nx] == 1){
                q.push({ny, nx});
                graph[ny][nx] = graph[y][x] + 1; 
            }
        }
    }
}

int solution(
    vector<vector<int>> rects, 
    int characterX, int characterY, 
    int itemX, int itemY
){
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    endX = itemX, endY = itemY; 
    
    initMap(rects);
    bfs(characterY, characterX);
 
    // 초기값 1부터 시작했기 때문에
    // 2로 나눈 뒤의 소수점은 버린다.
    return graph[itemY][itemX] / 2; 
}