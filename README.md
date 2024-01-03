# 2023 코테 스터디

- 기간: 2023.10.03 ~ ing 

## 진행 방식

- **매주 5문제 이상** 꾸준히 문제를 푸는 것을 목표로 합니다.
  - 난이도는 골고루 섞어서 (주로 실버 ~ 골드) 
  - 풀이한 문제에 대한 정리는 자유 (개인 블로그, 노션, 마크다운 등)
- **매주 화요일 22시**에 구글미트에서 이번 주차 문제에 대한 풀이를 진행합니다.
  - 모임 시간 전까지 이 레포로 PR을 보내야 정상 제출로 간주합니다.
  - 같이 풀어볼 문제를 논의해서 정하고, 발표자는 랜덤으로 뽑습니다. 
  - 발표자는 자신의 풀이 과정과 시간 복잡도 등에 관해 설명합니다. 
- 주차별 참여 현황은 [Wiki](https://github.com/2023-Coding-Test-Study/Coding-Test-Study/wiki/%EC%A3%BC%EC%B0%A8%EB%B3%84-%EC%B0%B8%EC%97%AC-%ED%98%84%ED%99%A9) 에 올라갑니다.

## 문제 선정

- 해당 주차 담당자가 **최소 5문제를 선정**하여 이슈에 올립니다. 
    - 순서: 선희 → 의정 → 하은 → 윤재
    - 5문제 이상 고르는 경우에는, 필수/선택으로 문제를 구분해주세요. 
- 문제 선정 플랫폼은 백준, 프로그래머스, SWEA 등 모두 가능 
- 참고 레퍼런스
    - https://github.com/tony9402/baekjoon
    - [https://www.acmicpc.net/workbook/top](https://www.acmicpc.net/workbook/top)

## 폴더링 & PR 작성 규칙

- 기본적으로 **자신의 이름으로 branch**를 따서 진행합니다.
- 해당 주차 폴더 아래에 **자신의 이름으로 폴더를 생성**합니다.
- 그 폴더 안에 이번 주에 풀이한 문제들을 넣고 **자신의 branch로 push 한 다음, main 브랜치로 PR을 보냅니다.**
- PR 올릴 때 **자신이 푼 언어를 라벨로 지정**합니다.
- **파일 이름**은 다음과 같이 작성해주세요.
    - 백준) `문제번호_문제이름` ex) 02-BruteForce/haeun/1104_거북이.cpp
    - 프로그래머스) `문제이름`  ex) 02-BruteForce/haeun/거북이.cpp
- **PR 제목**은 `[해당 주차] 유형 - 이름` 으로 작성해주세요.
    - ex) [Week 1] DataStructure - 하은

## 주차별 학습 내용 

|주차|주제|
|:---:|:---:|
|1|자료구조|
|2|브루트포스|
|3|재귀 + 백트래킹|
|4|분할정복 + 정렬|
|5|이분탐색 + 파라메트릭 서치|
|6|그리디|
|7|다이나믹 프로그래밍|
|8|그래프 + DFS/BFS|
|9|최단 경로|
|10|서로소 집합 + MST|
|11|시뮬레이션|
|12|실전 기출문제 (삼성, 카카오)|
|13|취약 유형 (DP, 이분탐색)|
|14|취약 유형 (BFS/DFS, 시뮬레이션)|
|15|취약 유형 (구현, 그리디)|
|16~|랜덤 문제|

## 패널티

- 스터디에 참여하지 못할 때는 **최소 하루 전에** 팀원들에게 사유를 알려주세요!
- 사유가 합당하지 않은 경우에는 다음과 같은 패널티를 적용합니다.
    - **지각 제출 시, 한 문제당 500원** (다음날 자정까지 지각으로 인정, 그 후에는 미제출로 간주)
    - **미제출 시, 한 문제당 1000원**
    - 한달에 한번 오프라인으로 만날 때, 벌금 정산하기!

## 학습 자료 추천

- [바킹독 실전 알고리즘 강의](https://github.com/encrypted-def/basic-algo-lecture)
- [이것이 취업을 위한 코딩 테스트다 with 파이썬](https://www.youtube.com/playlist?list=PLVsNizTWUw7H9_of5YCB0FmsSc-K44y81)

## 커밋 메시지 컨벤션 

- [ADD] : 문제 풀이 파일이나 부수적인 코드 추가
- [MOD] : 코드 및 내부 파일 수정
- [DEL] : 불필요한 코드나 파일 삭제
- [FIX] : 문제 오류, 버그 수정 
- [CHORE] : 함수 및 변수 이름 변경, 사소한 문법 오류 해결 등의 작은 작업
- [COMMENT] : 주석 추가 및 수정 
- [DOCS] : README, Wiki 등의 문서 작업 
- [MOVE] : 프로젝트 파일 및 코드 이동
- [RENAME] : 파일 이름 변경
- [MERGE] : 다른 브랜치와의 충돌 해결 후 Merge
- [REFACTOR] : 코드 리팩토링 작업

## 참고 레포

- https://github.com/b1urrrr/Algorithm-Study
- https://github.com/CODING-TEST-ANYMORE/Coding-Test-Study
- https://github.com/TeamCrazyPerformance/Algorithm_Basic
- https://github.com/TeamCrazyPerformance/algorithm2023-1-H
