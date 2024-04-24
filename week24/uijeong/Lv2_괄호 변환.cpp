#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string s){
    stack<char> st;
    
    for(int i=0; i < s.size(); i++){
        if(s[i] == '(') st.push('(');
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    if(st.empty()) return true;
    return false;
}

string solution(string p) {
    string answer = "";
    
    if(p == "") return ""; // 1번 처리 
    
    string u = "";
    string v = "";
    
    int left = 0;
    int right = 0;
    int idx = 0;
    for(int i=0; i < p.size();i++){ // 2. 균형잡힌 괄호 문자열 u, v로 분리 
        if(p[i] == '(') left++;
        else right++;
        
        if(left == right){
            idx = i;
            break;
        }
    }
    u = p.substr(0,idx+1);
    v = p.substr(idx+1);
    
    if(isCorrect(u)){
        v = solution(v);
        answer = u + v;
        return answer;
    }
    else{
        answer = "(";
        answer += solution(v);
        answer += ")";
        for(int i = 1; i < u.length()-1; i++) {
            if(u[i] == '(')
                answer = answer + ')';
            else if(u[i] == ')')
                answer = answer + '(';
        }
    }
    
    return answer;
}
