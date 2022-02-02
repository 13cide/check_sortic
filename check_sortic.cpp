#include "check_sort.h"

void initialize_a(vector<int> &a, string nums) { // заполнение массива
    string n = "";
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

vector<string> commands_to_mass(int argc, char *argv[]) { // чтобы влезать в строки я сделал функцию для переделки файла с коммандами в вектор
    vector<string> commands;
    string command = "";
    if (argc < 3) {
        ifstream input_commands;
        input_commands.open(R"(C:\Users\aleks\CLionProjects\check\input_commands.txt)"); //файл с командами (запись через пробел
        getline(input_commands, command);
    }
    else command = argv[2];
    string c = "";
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

void out(vector<int> &a, vector<int> &b) {
    ofstream output;
    output.open(R"(C:\Users\aleks\CLionProjects\check\output.txt)"); // файл для записи результата
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (is_sorted(a) && b.empty()) {
        output << "OK";
        SetConsoleTextAttribute(hConsole, 2);
        cout << "OK";
    }
    else if (!b.empty()) {
        output << "KO\rb isn`t empty" << endl;
        SetConsoleTextAttribute(hConsole, 1);
        cout << "KO" << endl;
        SetConsoleTextAttribute(hConsole, 0);
        cout << "b isn`t empty";
    }
    else {
        output << "KO\r\ra\r-\r";
        for (int i = 0; i < a.size(); i++) output << a[i] << endl; // вывод a, если он не отсортированный
        SetConsoleTextAttribute(hConsole, 1);
        cout << "KO" << endl << endl;
        SetConsoleTextAttribute(hConsole, 14);
        cout << "a" << endl << '-' << endl;
        SetConsoleTextAttribute(hConsole, 247);
        for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
    }
}

int main(int argc, char *argv[]) {
    vector<int> a;
    vector<int> b;
    ifstream input_nums;
    input_nums.open(R"(C:\Users\aleks\CLionProjects\check\input_nums.txt)"); //файл с числами
    string nums;
    getline(input_nums, nums);
    if (argc == 1) initialize_a(a, nums);
    else initialize_a(a, argv[1]);
    start(a, b, commands_to_mass(argc, argv));
    out(a, b);
    return 0;
}
