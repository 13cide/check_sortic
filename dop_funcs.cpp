#include "check_sort.h"

int itc_len(string str) {
    int a = 0;
    while (str[a] != '\0') a++;
    return a;
}

int string_to_int(string str){
    int ste = int(itc_len(str));
    int ans = 0;
    for (int i = 0; i < itc_len(str); i++) {
        ans += (str[i] - 48) * pow(10, ste - 1);
        ste--;
    }
    return ans;
}

int pow(int n, int i) {
    if (i == 0) return 1;
    else return n * pow(n, i - 1);
}

bool is_sorted(vector<int> &v) { // проверка на отсортированность
    if (v.size() > 2) {
        for (int i = 0; i < v.size() - 2; i++) if (v[i + 1] < v[i]) return false;
    }
    return true;
}