# Return the nth number of the fibonacci sequence
# Use memoization for faster operation (more space)

Memo = {1:0, 2:1}
def fib(n, memo=Memo):
    if n not in memo:
        memo[n] = fib(n-1,memo)+ fib(n-2,memo)
    return memo[n]
