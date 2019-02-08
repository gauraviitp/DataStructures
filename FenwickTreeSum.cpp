// 21:42

#include <cassert>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

typedef vector<int> VI;

class FenwickTree{
    VI bit;
    int n;
    const int INF = (int)1e9;

public:
    FenwickTree(int n){
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(VI& ar) : FenwickTree(ar.size()) {
        REP(i, 0, n){
            update(i, ar[i]);
        }
    }

    int sum(int r){
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
        }
        return ret;
    }

    void update(int index, int delta){
        for (; index < n; index = index | (index + 1)){
            bit[index] += delta;
        }
    }
};

int main(){
    VI ar{1, 3, 2, 4};
    FenwickTree ft(ar);
    assert(ft.sum(0) == 1);
    assert(ft.sum(1) == 4);
    assert(ft.sum(2) == 6);
    assert(ft.sum(3) == 10);
}
