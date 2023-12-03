#include <iostream>
#include <queue>

using namespace std;

int board[101][101];
int N, M;
int answer[101][101];
bool visited[101];

void bfs(int num)
{
    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {
            if (board[tmp][i] && !visited[i])
            {
                q.push(i);
                answer[num][i] = 1;
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp; 

            board[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        bfs(i);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}
