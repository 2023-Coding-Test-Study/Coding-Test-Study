#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, M;

    cin >> A >>B>>C >> M;
    
    if (A > M)
    {
        cout << 0;
        return 0;
    }

    int fatigue = 0;
    int workAmount = 0;
    int Time = 24;
    while (true)
    {
        if (Time > 0)
        {
            if (fatigue <= M - A)
            {
                fatigue += A;
                workAmount += B;
            }
            else
            {
                fatigue -= C;
                if (fatigue < 0)
                {
                    fatigue = 0;
                }
            }
            Time--;
        }
        else
        {
            cout << workAmount;
            break;
        }
    }
    
}