package main

import "fmt"

/* ----------------- STRUCT TIME WITH METHODS === TIME CLASS ---------------- */
type time struct {
	hour   int
	minute int
}

func (t time) isValid() bool {
	if t.hour < 0 || t.hour > 23 {
		return false
	}
	if t.minute < 0 || t.minute > 59 {
		return false
	}
	return true
}

func (t time) toString() string {
	return fmt.Sprintf("%02d:%02d", t.hour, t.minute)
}

/* --------------------------- END OF TIME STRUCT --------------------------- */

/*
 * Function to convert slice of four ints to time object
 */
func getTimeStamp(A []int) time {
	timeStamp := time{}
	timeStamp.hour = A[0]*10 + A[1]
	timeStamp.minute = A[2]*10 + A[3]
	return timeStamp
}

/*
 * All permutation of A which are valid time
 * are appended to timeStamps slice. Its important to have a pointer to slice.
 * Because on size increase the slice starts pointing to a different memory location.
 */
func perm(A []int, i int, timeStamps *[]time) {
	if i > len(A) {
		timeStamp := getTimeStamp(A)
		if timeStamp.isValid() {
			*timeStamps = append(*timeStamps, timeStamp)
		}
		return
	}
	perm(A, i+1, timeStamps)
	for j := i + 1; j < len(A); j++ {
		A[i], A[j] = A[j], A[i]
		perm(A, i+1, timeStamps)
		A[i], A[j] = A[j], A[i]
	}
}

func max(a time, b time) time {
	if a.hour > b.hour {
		return a
	} else if a.hour == b.hour {
		if a.minute > b.minute {
			return a
		}
		return b
	}
	return b
}

func largestTimeFromDigits(A []int) string {
	timeStamps := []time{}
	perm(A, 0, &timeStamps)
	if len(timeStamps) == 0 {
		return ""
	}

	ans := timeStamps[0]
	for _, timestamp := range timeStamps {
		ans = max(ans, timestamp)
	}
	return ans.toString()
}

func main() {
	a := []int{5, 5, 5, 5}
	fmt.Println(largestTimeFromDigits(a))
	a = []int{1, 2, 4, 5}
	fmt.Println(largestTimeFromDigits(a))
	a = []int{1, 2, 4, 3}
	fmt.Println(largestTimeFromDigits(a))
}
