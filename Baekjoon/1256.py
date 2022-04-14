'''
aazz 0
azaz 1
azza 2
zaaz 3
zaza 4
zzaa 5

aaazz
aazaz
aazza
azaaz
azaza
azzaa
zaaaz
zaaza
zazaa
zzaaa
'''

n, m, k = map(int, input().split())
dp = [[0 for i in range(101)] for j in range(201)]

def comb(a, b):
    if(a <= 0 or b < 0): return 1
    if(dp[a][b]): return dp[a][b]
    if(a == b or b == 0): dp[a][b] = 1
    else: dp[a][b] = comb(a-1, b-1) + comb(a-1, b)
    return dp[a][b]

def func(a, z, t):
    if(a+z == 0): return
    sub = comb(a+z-1, a-1)
    if(t < sub and a > 0):
        print('a', end='')
        func(a-1, z, t)
    else:
        print('z', end='')
        func(a, z-1, t-sub)

if(comb(n+m, n) < k):
    print(-1)
else:
    func(n, m, k-1)