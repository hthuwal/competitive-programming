/**
 * https://www.spoj.com/problems/INVCNT/
 **/
#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
using namespace std;

class MergeSorter {
    private:
        lli num_inversion;

        void reset() {
            num_inversion = 0;
        }

        void merge(vi &list, int start, int mid, int end) {
            int i=start;
            int j=mid+1;
            int k=0;
            vi mergedList(end-start+1);
            for(; i<=mid && j <= end;) {
                if (list[i] <= list[j]) {
                    mergedList[k++] = list[i++];
                } else {
                    num_inversion += (mid-i+1);
                    mergedList[k++] = list[j++];
                }
            }

            while(i <= mid) {
                mergedList[k++]=list[i++];
            }

            while(j<=end) {
                mergedList[k++]=list[j++];
            }

            for(int k=0; k<mergedList.size(); k++) {
                list[start+k] = mergedList[k];
            }
        }

        void do_merge_sort(vi &list, int start, int end) {
            if (start < end) {
                int mid = start + (end - start) / 2;
                do_merge_sort(list, start, mid);
                do_merge_sort(list, mid+1, end);
                merge(list, start, mid, end);
            }
        }
    public:
        void merge_sort(vi &list) {
            reset();
            do_merge_sort(list, 0, list.size()-1);
        }

        lli get_num_inversions() {
            return this->num_inversion;
        }
};

int main() {
    MergeSorter merge_sorter;
    int n;
    int t;
    cin>>t;
    while(t--) {
        cin >> n;
        vi list(n);
        for(int i=0; i<n; i++)
            cin>>list[i];
        merge_sorter.merge_sort(list);
        cout<<merge_sorter.get_num_inversions()<<"\n";
    }
}