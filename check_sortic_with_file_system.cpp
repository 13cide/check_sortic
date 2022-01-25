#include "check_sort.h"

void initialize_a(vector<int> &a) { // заполнение массива
    ifstream input_nums;
    input_nums.open(R"()"); //файл с числами
    string nums;
    string n = "";
    getline(input_nums, nums);
    for (int i = 0; nums[i] != '\0'; i++) {
        if (nums[i] != ' ') {
            n += nums[i];
        }
        else {
            a.push_back(string_to_int(n));
            n = "";
        }
    }
    a.push_back(string_to_int(n));
}

vector<string> commands_to_mass() { // чтобы влезать в строки я сделал функцию для переделки файла с коммандами в вектор
    vector<string> commands;
    ifstream input_commands;
    input_commands.open(R"()"); //файл с командами (запись через пробел)
    string command = "";
    string c = "";
    getline(input_commands, command);
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] != ' ') {
            c += command[i];
        }
        else {
            commands.push_back(c);
            c = "";
        }
    }
    commands.push_back(c);
    return commands;
}

void start(vector<int> &a, vector<int> &b, vector<string> commands) { // считывание команд (команды через пробел)
    for (int j = 0; j < commands.size(); j++) {
        if (commands[j] == "sa") s(a);
        if (commands[j] == "sb") s(b);
        if (commands[j] == "ss") {
            s(a);
            s(b);}
        if (commands[j] == "ra") r(a);
        if (commands[j] == "rb") r(b);
        if (commands[j] == "rr") {
            r(a);
            r(b);}
        if (commands[j] == "rra") rr(a);
        if (commands[j] == "rrb") rr(b);
        if (commands[j] == "rrr") {
            rr(a);
            rr(b);}
        if (commands[j] == "pa") p(a, b);
        if (commands[j] == "pb") p(b, a);
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
    start(a, b, commands_to_mass());
    if (is_sorted(a) && b.empty()) output << "OK";
    else if (is_sorted(a)) output << "KO\rb isn`t empty";
    else {
        output << "KO\r\ra\r-\r";
        for (int i = 0; i < a.size(); i++) output << a[i] << endl; // вывод a, если он не отсортированный
    }
    return 0;
}
