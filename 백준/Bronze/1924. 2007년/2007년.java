import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        final int month = Integer.parseInt(input[0]);
        final int date = Integer.parseInt(input[1]);
        int calM = 0;
        String day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        int cnt[] = {0, 31, 28, 31, 30, 31, 30 ,31 ,31, 30, 31, 30, 31};

        for(int i = 1; i < month; i++)
            calM += cnt[i];
        System.out.print(day[(calM + date) % 7]);
    }
}
