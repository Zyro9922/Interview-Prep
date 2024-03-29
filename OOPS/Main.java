import java.io.*;
import java.util.*;

public class Main {

	public static int solution(int n) {
		int[] dp = new int[n + 1];
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = i; //As every number can be expressed as (1*1)+(1*1)....
			for (int j = 1; j * j <= i; j++) {
				int squareVal = j * j;
				if (squareVal > i) {
					break;
				} else {
					dp[i] = Math.min(dp[i], 1 + dp[i - squareVal]);
				}
			}
			System.out.println(dp[i]);
		}
		return dp[n];
	}

	public static void main(String[] args) {
		int n = 19;
		System.out.println(solution(n));
	}
}