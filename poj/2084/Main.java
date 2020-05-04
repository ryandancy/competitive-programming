// 2084 Game of Connections
import java.math.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    BigInteger[] dp = new BigInteger[101];
    dp[0] = dp[1] = BigInteger.ONE;
    for (int n = 2; n <= 100; n++) {
      dp[n] = BigInteger.ZERO;
      for (int i = 1; i < 2*n; i += 2) {
        dp[n] = dp[n].add(dp[(i-1)/2].multiply(dp[(2*n-i-1)/2]));
      }
    }
    
    Scanner scan = new Scanner(System.in);
    while (true) {
      int n = scan.nextInt();
      if (n == -1) break;
      System.out.println(dp[n]);
    }
  }
}
