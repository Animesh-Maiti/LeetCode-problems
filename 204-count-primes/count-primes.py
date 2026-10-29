class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        # is_prime[i] tracks whether i is prime
        is_prime = bytearray([1]) * n
        is_prime[0] = is_prime[1] = 0
        
        # Sieve up to sqrt(n)
        for p in range(2, int(n**0.5) + 1):
            if is_prime[p]:
                # Cross out multiples starting from p * p
                is_prime[p * p : n : p] = bytearray((n - 1 - p * p) // p + 1)
        
        return sum(is_prime)