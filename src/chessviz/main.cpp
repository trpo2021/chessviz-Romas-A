#include "lib/chessviz.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(0, "Russian");
    int sum_hod = 0;
    doska_default(sum_hod);
    int str = 0;
    char stb = 0;
    int x1, y1;
    bool flag_buff = false;
    while (cin >> stb >> str) {
        doska_hod(stb, str, x1, y1, sum_hod, flag_buff);
    }
    return 0;

