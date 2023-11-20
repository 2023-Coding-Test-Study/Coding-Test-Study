#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<set<int>> v;
    set<int> first;

    first.insert(N);
    v.push_back(first);

    for (int i = 1; i < 8; i++)
    {
        set<int> vec;

        int num = N;
        for (int j = 0; j < i; j++)
        {
            num = num * 10 + N;
        }

        vec.insert(num);

        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (j + k + 1 != i) continue;
                else
                {
                    for (int num1 : v[j])
                    {
                        for (int num2 : v[k])
                        {
                            vec.insert(num1 + num2);

                            if (num1 - num2 >= 0) vec.insert(num1 - num2);

                            vec.insert(num1 * num2);

                            if (num2 != 0) vec.insert(num1 / num2);
                        }
                    }
                }
            }
        }

        if (vec.find(number) != vec.end()) return i + 1;

        v.push_back(vec);
    }

    return -1;
}