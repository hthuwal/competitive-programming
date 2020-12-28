/**
 * https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/min-cost-2-fe2d3308/
 **/
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class TheMinimumCost {
    static Scanner scanner = new Scanner(System.in);
    
    static void solve_test_case() {
        scanner.nextLine();
        long n = scanner.nextInt();
        long c01 = scanner.nextInt();
        long c10 = scanner.nextInt();
        int b;
        scanner.nextLine();
        List<Integer> bits = new ArrayList<>((int)n);
        for (int i = 0; i < n; i++) {
            b = scanner.nextInt();
            bits.add(b);
        }

        long cost_a=0;
        int a = 0;
        b = 1;
        long cost_b=0;
        for(Integer bit: bits) {
            if (bit != a) {
                cost_a += bit == 1 ? c10: c01;
            }
            if (bit != b) {
                cost_b += bit == 1 ? c10: c01;
            }
            a ^= 1;
            b ^= 1;
        }
        System.out.println(cost_a < cost_b? cost_a: cost_b);
    }
    public static void main(String[] args) throws Exception {
        int t = scanner.nextInt();
        while (t > 0) {
            solve_test_case();
            t--;
        }
        scanner.close();
    }
}
