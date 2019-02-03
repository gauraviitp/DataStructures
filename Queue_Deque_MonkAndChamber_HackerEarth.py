from collections import deque
import sys

#sys.stdin = open('input.txt')
#sys.stdout = open('output.txt', 'w')

f = sys.stdin
o = sys.stdout

def run(q, x):
    for i in range(x):
        it = 0
        maxPowerSpider = [-1, -1]
        nq = deque()
        while(q and it < x):
            spider = q.popleft()
            if maxPowerSpider[1] < spider[1]:
                maxPowerSpider = spider
            nq.append(spider)
            it += 1;
        while(nq):
            spider = nq.popleft()
            if spider[0] != maxPowerSpider[0]:
                spider[1] = spider[1]  - 1 if spider[1] > 0 else 0
                q.append(spider)
        o.write(str(maxPowerSpider[0]) + ' ')
    o.write('\n')

def main():
    n, x = map(int, f.readline().split())
    q = deque([[i + 1, v] for i, v in enumerate(map(int, f.readline().split()))])

    run(q, x)

if __name__ == '__main__':
    main()
