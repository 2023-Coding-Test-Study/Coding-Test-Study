def solution(s):
    l_s = len(s)
    ans = ""
    idx = 0
    
    while idx < l_s:
        if s[idx] < "a": # 숫자인 경우
            ans += s[idx]
            idx += 1
        else: # 영단어인 경우 
            if s[idx] == "z":
                ans += "0"
                idx += 4
            elif s[idx] == "o":
                ans += "1"
                idx += 3
            elif s[idx: idx+2] == "tw":
                ans += "2"
                idx += 3
            elif s[idx: idx+2] == "th":
                ans += "3"
                idx += 5
            elif s[idx: idx+2] == "fo":
                ans += "4"
                idx += 4
            elif s[idx: idx+2] == "fi":
                ans += "5"
                idx += 4
            elif s[idx: idx+2] == "si":
                ans += "6"
                idx += 3
            elif s[idx: idx+2] == "se":
                ans += "7"
                idx += 5
            elif s[idx] == "e":
                ans += "8"
                idx += 5
            elif s[idx] == "n":
                ans += "9"
                idx += 4
         
    return int(ans)
