/**
 * https://www.hackerearth.com/problem/algorithm/maximum-profit-5-c3c2ce7c/description/
 **/
import java.util.Comparator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class MaximumPorfit {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        long n, t, ans, count, k;
        Set<Long> coins;
        t = scanner.nextInt();
        while(t>0) {
            scanner.nextLine();
            n = scanner.nextLong();
            k = scanner.nextLong();
            scanner.nextLine();
            coins = new TreeSet<>(new Comparator<Long>(){
                public int compare(Long a, Long b) {
                    return b.compareTo(a);
                }
            });
            for(int i=0; i<n; i++) {
                coins.add(scanner.nextLong());
            }
            count = 0;
            ans = 0;
            for(Long coin: coins) {
                ans += coin;
                count ++;
                if (count == k) {
                    break;
                }
            }
            System.out.println(ans);
            t--;
        }
    }
}