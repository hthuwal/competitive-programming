/**
 * https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/alice-and-customer-satisfaction-b6dc3745/
 **/ 
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Pair {
    Long first;
    Long second;
    Pair(long f, long s) {
        this.first = f;
        this.second = s;
    }
}

class CustomerSatisfaction {
    static Scanner scanner;
    
    static boolean isValid(List<Pair> ranges, long rate) {
        for (Pair range: ranges) {
            if (range.first * rate < range.second) {
                return false;
            }
        }
        return true;
    }

    static long solve(List<Pair> ranges, long l, long h) {
        while(l!=h) {
            long m = l + (h-l)/2;
            if (isValid(ranges, m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    static void solveTestCase(){
        long n, e, q;
        List<Pair> ranges = new ArrayList<>();
        scanner.nextLine();
        n = scanner.nextLong();
        for (int i = 0; i < n; i++) {
            scanner.nextLine();
            e = scanner.nextLong();
            e = scanner.nextLong();
            q = scanner.nextLong();
            ranges.add(new Pair(e, q));
        }
        ranges.sort((p1, p2) -> p1.first.compareTo(p2.first));
        for(int i=1; i<ranges.size(); i++) {
            Pair prev = ranges.get(i-1);
            Pair curr = ranges.get(i);
            curr.second += prev.second;
        }
        System.out.println(solve(ranges, 1, ranges.get(ranges.size()-1).second + 1));
    }    
    public static void main(String[] args) {
        int t;
        scanner = new Scanner(System.in);
        t = scanner.nextInt();
        while(t>0) {
            solveTestCase();
            t--;
        }
        scanner.close();
    }
}