import java.util.HashMap;
import java.util.Scanner;
import java.io.*;


class zeroSumSubArray {
    public static void main(String... args) throws Exception{
        InputStream in = new FileInputStream("in.txt");
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i= 0; i<n;i++)arr[i]=sc.nextInt();
        HashMap<Integer,Integer> h = new HashMap<Integer,Integer>();
        int sum = 0;
        for(int i =0;i < n;i++){
            sum += arr[i];
            if(h.containsKey(sum)){
                System.out.println("Found at " + (h.get(sum) + 1) + " " + i + " " + sum);
                break;
            }
            h.put(sum, i);
        }
        System.out.println("Not Found");
        sc.close();
    }
}