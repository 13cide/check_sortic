#include "check_sort.h"

void s(vector<int> &v) { // sa будет писаться в коде как s(a); sb как s(b);
    if(v.size() > 2) {
        int tmp = v[0];
        v[0] = v[1];
        v[1] = tmp;
    }
}

void p(vector <int> &v_to, vector <int> &v_from) { // v_to - в какой массив мы перекидываем значение, v_from - из какого
    if (!v_from.empty()) {                       // pa будет писаться в коде как p(a, b); pb как p(b, a);
        v_to.push_back(v_from[0]);
        rr(v_to);
        r(v_from);
        v_from.pop_back();
    }
}

void r(vector <int> &v) { // ra будет писаться в коде как r(a); rb как r(b);
    if (v.size() > 1) {
        int tmp = v[0];
        for (int i = 0; i < v.size() - 1; i++) {
            v[i] = v[i + 1];
        }
        v[v.size() - 1] = tmp;
    }
}

void rr(vector <int> &v) { // rra будет писаться в коде как rr(a); rrb как rr(b);
    if (v.size() > 1) {
        int tmp = v[v.size() - 1];
        for (int i = int(v.size()) - 1; i > 0; i--) {
            v[i] = v[i - 1];
        }
        v[0] = tmp;
    }
}