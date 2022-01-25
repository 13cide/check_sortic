#include "check_sort.h"

void initialize_a(vector<int> &a) { // заполнение массива
    ifstream input_nums;
    input_nums.open(R"(C:\Users\aleks\CLionProjects\check\input_nums.txt)"); //файл с числами
    string j;
    input_nums >> j;
    while( j != "!" ) {
        a.push_back(string_to_int(j));
        input_nums >> j;
    }
}

void start(vector<int> &a, vector<int> &b) { // считывание команд
    ifstream input_commands;
    input_commands.open(R"(C:\Users\aleks\CLionProjects\check\input_commands.txt)"); //файл с командами
    string j;
    input_commands >> j;
    while( j != "*" ) {
        if (j == "sa") s(a);
        if (j == "sb") s(b);
        if (j == "ss") {
            s(a);
            s(b);}
        if (j == "ra") r(a);
        if (j == "rb") r(b);
        if (j == "rr") {
            r(a);
            r(b);}
        if (j == "rra") rr(a);
        if (j == "rrb") rr(b);
        if (j == "rrr") {
            rr(a);
            rr(b);}
        if (j == "pa") p(a, b);
        if (j == "pb") p(b, a);
        input_commands >> j;
    }
}

bool is_sorted(vector<int> &v) { // проверка на отсортированность
    if (v.size() > 2) {
        for (int i = 0; i < v.size() - 2; i++) if (v[i + 1] < v[i]) return false;
    }
    return true;
}


int main() {
    ofstream output;
    output.open(R"(C:\Users\aleks\CLionProjects\check\output.txt)"); // файл для записи результата
    vector<int> a;
    vector<int> b;
    initialize_a(a);
    start(a, b);
    if (is_sorted(a) && b.empty()) output << "OK";
    else output << "KO";
    return 0;
}
