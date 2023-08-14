w, h, n = input().strip().split()
w = int(w)
h = int(h)
n = int(n)

low = 0
high = int(1e18)

while (low < high):
    mid = int((low + high) >> 1)
    can = int(mid / w) * int(mid / h)

    if (can >= n):
        high = mid 
    else:
        low = mid + 1

print(low)