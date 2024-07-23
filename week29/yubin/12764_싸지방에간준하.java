import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
import org.jetbrains.annotations.NotNull;

public class Main {

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        PriorityQueue<WaitingPerson> waitingPeople = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int startTime = Integer.parseInt(st.nextToken());
            int endTime = Integer.parseInt(st.nextToken());

            waitingPeople.offer(new WaitingPerson(startTime, endTime));
        }

        PriorityQueue<PlayingPerson> playingPeople = new PriorityQueue<>();
        PriorityQueue<Integer> computers = new PriorityQueue<>();

        int[] used = new int[100001];

        int max = 1;
        while (!waitingPeople.isEmpty()) {
            WaitingPerson person = waitingPeople.poll();

            while (!playingPeople.isEmpty()) {
                if (person.startTime >= playingPeople.peek().endTime) {
                    PlayingPerson playingPerson = playingPeople.poll();
                    computers.offer(playingPerson.computerIndex);
                } else {
                    break;
                }
            }

            if (computers.isEmpty()) {
                playingPeople.offer(new PlayingPerson(person.endTime, max));
                used[max]++;
                max++;
            } else {
                int computerIndex = computers.poll();
                used[computerIndex]++; // 사용 횟수 표시
                playingPeople.add(new PlayingPerson(person.endTime, computerIndex));
            }
        }


        for (int i = 1; i < 100001; i++) {
            if (used[i] == 0) {
                max = i - 1;
                break;
            }
            sb.append(used[i] + " ");
        }

        System.out.println(max);
        System.out.println(sb);

    }
}

// 시작하는 시간을 기준으로 정렬
class WaitingPerson implements Comparable<WaitingPerson>{
    int startTime;
    int endTime;

    @Override
    public int compareTo(@NotNull WaitingPerson o) {
        return startTime - o.startTime;
    }

    public WaitingPerson(int startTime, int endTime) {
        this.startTime = startTime;
        this.endTime = endTime;
    }
}

// 끝나는 시간을 기준으로 정렬
class PlayingPerson implements Comparable<PlayingPerson>{
    int endTime;
    int computerIndex;

    @Override
    public int compareTo(@NotNull PlayingPerson o) {
        return endTime - o.endTime;
    }

    public PlayingPerson(int endTime, int computerIndex) {
        this.endTime = endTime;
        this.computerIndex = computerIndex;
    }
}
