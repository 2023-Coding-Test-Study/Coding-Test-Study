#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4]; // d , l , r, u;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    int dist = abs(r - x) + abs(c - y);
    k -= dist;
    if (k % 2 != 0 || k < 0) return "impossible";

    // 최단 거리 
    if (x < r) dir[0] = r - x;
    else dir[3] = x - r;

    if (y < c) dir[2] = c - y;
    else dir[1] = y - c;

    //d 삽입
    for (int i = 0; i < dir[0] ; i++)
    {
        answer += "d";
    }
    

    //d 추가 삽입
    int d_num = min(k / 2, n - (x + dir[0]));
    for (int i = 0; i < d_num; i++)
    {
        answer += "d";
    }
    dir[3] += d_num;

    //위 아래 왔다갔다 값
    k -= 2 * d_num;

    //l 삽입
    for (int i = 0; i < dir[1]; i++)
    {
        answer += "l";
    }

    //ㅣ 추가 삽입
    int l_num = min(k / 2, y - dir[1] - 1); // 후자는 최대 왼쪽으로 이동할 수 있는 수
    for (int i = 0; i < l_num; i++)
    {
        answer += "l";
    }
    dir[2] += l_num;
    k -= 2 * l_num;

    //좌우 왔다갔다
    for (int i = 0; i < k / 2; i++)
    {
        answer += "rl";
    }

    for (int i = 0; i < dir[2]; i++)
    {
        answer += "r";
    }
    for (int i = 0; i < dir[3]; i++)
    {
        answer += "u";
    }


    return answer;
}
