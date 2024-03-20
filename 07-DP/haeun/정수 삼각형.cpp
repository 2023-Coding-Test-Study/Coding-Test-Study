#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size(); 
    
    // 아래에서부터 위로 올라오면서 더 큰 값을 누적해서 더한다. 
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]); 
        }
    }
    
    // 꼭대기에 있는 값이 최댓값 
    return triangle[0][0]; 
}