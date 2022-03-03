/**
 * https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/multiple-occurence-97c00160/
 **/
import java.util.*;

class Tuple {
    int low;
    int high;

    Tuple(int l, int h) {
        low=l;
        high=h;
    }
}

class MultipleOccurrences {
    public static void main(String[] args) throws Exception {
        int x, n, t;
        Scanner s = new Scanner(System.in);
        Map<Integer, Tuple> freq;

        t = s.nextInt();
        while(t > 0) {
            s.nextLine();
            freq = new HashMap<>();

            n = s.nextInt(); s.nextLine();
            for (int i = 0; i < n; i++) {
                x = s.nextInt();
                if (freq.containsKey(x)) {
                    Tuple val = freq.get(x);
                    val.high = i;
                } else {
                    freq.put(x, new Tuple(i, i));
                }
            }
            int ans = freq.values()
                    .stream()
                    .map(value -> value.high - value.low)
                    .reduce(0, Integer::sum);
            System.out.println(ans);
            
            t--;
        }
        s.close();
    }
}