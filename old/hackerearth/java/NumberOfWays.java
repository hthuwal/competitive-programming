/**
 * https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/rook-path-142e55ee/
 **/
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Triplet {
    long numW;
    long sumL;
    long sumU;
    Triplet(long n, long sl, long sU) {
        this.numW = n;
        this.sumL = sl;
        this.sumU = sU;
    }
}

class NumberOfWays {
    static final long MOD = 1000000007;
    static Scanner scanner = new Scanner(System.in);
    
    static void solve() {
        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();
        List<String> grid = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            grid.add(scanner.nextLine());
        }

        List<List<Triplet>> dp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            dp.add(new ArrayList<>());
            for (int j=0; j < m; j++) {
                if (i==0 && j==0) {
                    dp.get(i).add(new Triplet(1, 1, 1));
                    continue;
                }

                if (grid.get(i).charAt(j) == '*') {
                    dp.get(i).add(new Triplet(0, 0, 0));
                    continue;
                }

                long sumL = 0;
                long sumU = 0;

                if (j!=0) {
                    sumL = dp.get(i).get(j-1).sumL;
                }
                if (i!=0) {
                    sumU = dp.get(i-1).get(j).sumU;
                }

                long numW = (sumL + sumU) % MOD;
                dp.get(i).add(
                    new Triplet(
                        numW,
                        (sumL + numW) % MOD,
                        (sumU + numW) % MOD
                    )
                );
            }
        }
        System.out.println(dp.get(n-1).get(m-1).numW);
    }

    public static void main(String[] args) {
        int t = scanner.nextInt();
        while (t>0) {
            solve();
            t--;
        }    
    }    
}
