package main

func steinsGcd(a int, b int) int {
	if a == 0 {
		return b
	}

	if b == 0 {
		return a
	}

	// Find greatest power of 2 that
	// divides both a and b
	pow := 0
	for pow = 0; ((a | b) & 1) == 0; pow++ {
		a = a >> 1
		b = b >> 1
	}

	// Make sure a is odd
	for a&1 == 0 {
		a = a >> 1
	}

	for {
		// Make sure b is odd
		for b&1 == 0 {
			b = b >> 1
		}

		if a > b {
			a, b = b, a
		}
		b = b - a
		if b == 0 {
			return a << pow
		}
	}
}

func findGcd(a int, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}

func hasGroupsSizeX(deck []int) bool {

	if len(deck) < 2 {
		return false
	}

	freqMap := make(map[int]int)
	for _, card := range deck {
		freqMap[card]++
	}

	freqs := make([]int, len(freqMap))
	for _, freq := range freqMap {
		freqs = append(freqs, freq)
	}

	gcd := steinsGcd(freqs[0], freqs[1])
	for _, freq := range freqs {
		gcd = steinsGcd(gcd, freq)
	}

	if gcd < 2 {
		return false
	}

	return true
}
