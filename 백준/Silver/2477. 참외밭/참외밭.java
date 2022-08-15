import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt = Integer.parseInt(br.readLine());
        int maxW = 0, maxH = 0, maxHI = 0, maxWI = 0;
        int[] arr = new int[6];
        for(int i = 0; i < 6; i++){
            String[] input = br.readLine().split(" ");
            int line = Integer.parseInt(input[0]);
            arr[i] = Integer.parseInt(input[1]);
            if((line == 1 || line == 2) && maxH < arr[i]){
                maxH = arr[i];
                maxHI = i;
            }
            else if((line == 3 || line == 4) && maxW < arr[i]){
                maxW = arr[i];
                maxWI = i; 
            }
        } 
        int right,left,minW,minH;

        if(maxWI+1==6)right=0;
	    else right=maxWI+1;
	    
	    if(maxWI-1==-1)left=5;
	    else left=maxWI-1;
	    //빈 사각형의 세로 길이
	    minH=Math.abs(arr[right]-arr[left]);

	    if(maxHI+1==6)right=0;
	    else right=maxHI+1;
	    
	    if(maxHI-1==-1)left=5;
	    else left=maxHI-1;
	    //빈 사각형의 가로 길이
	    minW=Math.abs(arr[right]-arr[left]);
        
        System.out.print((maxH * maxW - minH * minW) * cnt);
    }
}
