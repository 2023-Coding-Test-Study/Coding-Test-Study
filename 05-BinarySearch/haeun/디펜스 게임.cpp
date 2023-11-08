#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
	// 무적권 사용해서 막은 적의 수 저장 
	priority_queue<int, vector<int>, greater<int>> pq; 

	// 무적권 없이 소모한 병사 수 
	int cosumedSoldiers = 0; 

	for(int i = 0; i < enemy.size(); i++){
		// 무적권 사용 
		pq.push(enemy[i]);

		// 무적권 k개를 모두 사용한 경우 
		if(pq.size() > k){ 
			cosumedSoldiers += pq.top(); 
			pq.pop(); 
		}

		// 병사를 모두 소모한 경우, 게임 종료 
		if(cosumedSoldiers > n){ 
			return i; 
		}
	}

	// 모든 라운드를 통과한 경우 
	return enemy.size(); 
}