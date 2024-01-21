import itertools
from collections import Counter

S1, S2, S3 = map(int, input().split())
L1 = [i for i in range(1, S1 + 1)]
L2 = [i for i in range(1, S2 + 1)]
L3 = [i for i in range(1, S3 + 1)]
product = list(itertools.product(L1, L2, L3))
sum = [sum(l) for l in product]
counter = Counter(sum)
print(counter.most_common(1)[0][0])