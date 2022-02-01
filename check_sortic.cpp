#include "check_sort.h"

void initialize_a(vector<int> &a) { // ���������� ���ᨢ�
    ifstream input_nums;
    input_nums.open(R"()"); //䠩� � �᫠��
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

vector<string> commands_to_mass() { // �⮡� ������� � ��ப� � ᤥ��� �㭪�� ��� ��।���� 䠩�� � ���������� � �����
    vector<string> commands;
    ifstream input_commands;
    input_commands.open(R"()"); //䠩� � ��������� (������ �१ �஡��)
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

void start(vector<int> &a, vector<int> &b, vector<string> commands) { // ���뢠��� ������ (������� �१ �஡��)
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
    output.open(R"()"); // 䠩� ��� ����� १����
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (is_sorted(a) && b.empty()) {
        output << "OK";
        SetConsoleTextAttribute(hConsole, 2);
        cout << "OK";
    }
    else if (is_sorted(a)) {
        output << "KO\rb isn`t empty";
        SetConsoleTextAttribute(hConsole, 1);
        cout << "KO" << endl;
        SetConsoleTextAttribute(hConsole, 8);
        cout << "b isn`t empty";
    }
    else {
        output << "KO\r\ra\r-\r";
        for (int i = 0; i < a.size(); i++) output << a[i] << endl; // �뢮� a, �᫨ �� �� �����஢����
        SetConsoleTextAttribute(hConsole, 1);
        cout << "KO" << endl << endl;
        SetConsoleTextAttribute(hConsole, 14);
        cout << "a" << endl << '-' << endl;
        SetConsoleTextAttribute(hConsole, 247);
        for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
    }
}

int main() {
    vector<int> a;
    vector<int> b;
    initialize_a(a);
    start(a, b, commands_to_mass());
    out(a, b);
    return 0;
}
