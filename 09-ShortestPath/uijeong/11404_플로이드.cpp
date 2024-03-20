#include <bits/stdc++.h>
using namespace std;

int N, M;
int d[101][101];
int def = 0x3f3f3f3f;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    fill(d[0], d[N+1], def);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (d[a][b] > c) d[a][b] = c; // 간선이 여러 개일 수도 있으므로 
    } // 간선 입력 및 업데이트 

		for(int i = 1; i <= N; i++) d[i][j] = 0; // 같은 위치 
    for (int k = 1; k <= N; k++) { // 중간 정점 
        for (int i = 1; i <= N; i++) { // 시작
            for (int j = 1; j <= N; j++) { // 도착 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
						if(d[i][j] == def) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
