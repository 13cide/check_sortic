#ifndef CHECK_CHECK_SORT_H
#define CHECK_CHECK_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

int string_to_int(string str);
int pow(int n, int i);
int itc_len(string str);
bool is_sorted(vector<int> &v);

void start(vector<int> &a, vector<int> &b, vector<string> commands);
vector<string> commands_to_mass(int i, char **pString);
void initialize_a(vector<int> &a);

void p(vector <int> &v_to, vector <int> &v_from);
void r(vector <int> &v);
void rr(vector <int> &v);
void s(vector<int> &v);

#endif //CHECK_CHECK_SORT_H
