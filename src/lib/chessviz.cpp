#include "chessviz.h"
#include <iostream>
#include <string>
using namespace std;

string buff, doska[9][9];
bool flag_buff = false, doska_b[9][9];

struct Figura {
    string K, k, Q, q, R, r, N, n, B, b, P, p;
    Figura()
        : K{ "K" }
        , k{ "k" }
        , Q{ "Q" }
        , q{ "q" }
        , R{ "R" }
        , r{ "r" }
        , N{ "N" }
        , n{ "n" }
        , B{ "B" }
        , b{ "b" }
        , P{ "P" }
        , p{ "p" }
    {
    }
};

void doska_print(int& sum_hod)
{
    char num = 'a';
    for (int i = 0; i < 8; i++) {
        cout << "\t" << 8 - i;
        for (int j = 0; j < 9; j++) {
            cout << doska[i][j];
        }
        cout << endl;
    }
    cout << "\t";
    for (int i = 1; i < 9; i++) {
        cout << "  " << num;
        ++num;
    }
    cout << "\n Вид записи хода: a2a3 ";
    if ((sum_hod % 2 == 0 && sum_hod > 0 )|| sum_hod == 1) {
        cout << endl
             << "Ход черных: ";
    }
    else {
        cout << endl
             << "Ход белых: ";
    }
}

void doska_default(int& sum_hod)
{
    Figura f;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 9; j++) {
            doska[i][j] = "   ";
            doska_b[i][j] = 0;
        }
    }
    for (int i = 1; i < 9; i++) {
        doska[1][i] = " " + f.p + " ";
        doska_b[1][i] = 1;
        doska[6][i] = " " + f.P + " ";
        doska_b[6][i] = 1;
    }
    doska[0][1] = doska[0][8] = " " + f.r + " ";
    doska_b[0][1] = doska_b[0][8] = 1;
    doska[7][1] = doska[7][8] = " " + f.R + " ";
    doska_b[7][1] = doska_b[7][8] = 1;
    doska[0][2] = doska[0][7] = " " + f.n + " ";
    doska_b[0][2] = doska_b[0][7] = 1;
    doska[7][2] = doska[7][7] = " " + f.N + " ";
    doska_b[7][2] = doska_b[7][7] = 1;
    doska[0][3] = doska[0][6] = " " + f.b + " ";
    doska_b[0][3] = doska_b[0][6] = 1;
    doska[7][3] = doska[7][6] = " " + f.B + " ";
    doska_b[7][3] = doska_b[7][6] = 1;
    doska[0][4] = " " + f.q + " ";
    doska_b[0][4] = 1;
    doska[0][5] = " " + f.k + " ";
    doska_b[0][5] = 1;
    doska[7][4] = " " + f.Q + " ";
    doska_b[7][4] = 1;
    doska[7][5] = " " + f.K + " ";
    doska_b[7][5] = 1;

    doska_print(sum_hod);
}

void doska_figura_remove(int x, int y)
{
    doska[8 - y][8 - (104 - x)] = "   ";
}

void Ppawn_hod(int x, int y, int& x1, int& y1)
{
    int h;
    if (y1 > 8 - y) {
        h = y1 - (8 - y);
    }
    if (8 - y > y1) {
        h = (8 - y) - y1;
    }
    if (8 - (104 - x) == x1 && h <= 2) {
        doska[8 - y][8 - (104 - x)] = buff;
        doska_b[8 - y][8 - (104 - x)] = 1;
        buff = "  ";
        flag_buff = false;
    }
    else {
        cout << "Неправильный ввод:введите только вторую измененную координату хода пешки (вид: a3) \n";
    }
}

void Rrook_hod(int x, int y, int& x1, int& y1)
{
    if (8 - (104 - x) == x1 || 8 - y == y1) {
        doska[8 - y][8 - (104 - x)] = buff;
        doska_b[8 - y][8 - (104 - x)] = 1;
        buff = "  ";
        flag_buff = false;
    }
    else {
        cout << "Неправильный ввод:введите только вторую измененную координату хода ладьи (вид: a3)\n";
    }
}

void Nknight_hod(int x, int y, int& x1, int& y1)
{
    int h, h1;
    if (x1 > 8 - (104 - x)) {
        h = x1 - (8 - (104 - x));
    }
    if (8 - (104 - x) > x1) {
        h = 8 - (104 - x) - x1;
    }
    if (h == 1) {
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (h1 == 2) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода коня (вид: a3)\n";
        }
    }
    if (h == 2) {
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (h1 == 1) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода коня (вид: a3)\n";
        }
    }
    if (h != 1 && h != 2) {
        cout << "Неправильный ввод:введите только вторую измененную координату хода коня (вид: a3)\n";
    }
}

void Bbishop_hod(int x, int y, int& x1, int& y1)
{
    int h, h1;
    if (x1 != 8 - (104 - x) || y1 != 8 - y) {
        if (x1 > 8 - (104 - x)) {
            h = x1 - (8 - (104 - x));
        }
        if (8 - (104 - x) > x1) {
            h = 8 - (104 - x) - x1;
        }
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (h == h1) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода слона (вид: a3)\n";
        }
    }
    else {
        cout << "Неправильный ввод:введите только вторую измененную координату хода слона (вид: a3)\n";
    }
}

void Qqueen_hod(int x, int y, int& x1, int& y1)
{
    int h, h1;
    if (8 - (104 - x) == x1 || 8 - y == y1) {
        doska[8 - y][8 - (104 - x)] = buff;
        doska_b[8 - y][8 - (104 - x)] = 1;
        buff = "  ";
        flag_buff = false;
    }
    else {
        if (x1 > 8 - (104 - x)) {
            h = x1 - (8 - (104 - x));
        }
        if (8 - (104 - x) > x1) {
            h = 8 - (104 - x) - x1;
        }
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (h == h1) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода королевы (вид: a3)\n";
        }
    }
}

void Kking_hod(int x, int y, int& x1, int& y1)
{
    int h, h1;
    if (x1 > 8 - (104 - x)) {
        h = x1 - (8 - (104 - x));
    }
    if (8 - (104 - x) > x1) {
        h = 8 - (104 - x) - x1;
    }
    if (8 - (104 - x) == x1) {
        h = 0;
    }

    if (h == 0) {
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (h1 == 1) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода короля (вид: a3)\n";
        }
    }

    if (h == 1) {
        if (y1 > 8 - y) {
            h1 = y1 - (8 - y);
        }
        if (8 - y > y1) {
            h1 = (8 - y) - y1;
        }
        if (8 - y == y1) {
            h1 = 0;
        }

        if (h1 == 1) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        if (h1 == 0) {
            doska[8 - y][8 - (104 - x)] = buff;
            doska_b[8 - y][8 - (104 - x)] = 1;
            buff = "  ";
            flag_buff = false;
        }
        else {
            cout << "Неправильный ввод:введите только вторую измененную координату хода короля (вид: a3)\n";
        }
    }
    if (h != 0 && h != 1) {
        cout << "Неправильный ввод:введите только вторую измененную координату хода короля (вид: a3)\n";
    }
}

void mamba(int x, int y, int& x1, int& y1)
{
    y1 = 8 - y;
    x1 = 8 - (104 - x);
}

void doska_hod(int x, int y, int& x1, int& y1, int& sum_hod)
{
    Figura f;
    if (y > 9 || y < 0) {
        cout << "Неправильный ввод хода: ушли за границы доски по у\n";
    }
    if (x > 104 || x < 97) {
        cout << "Неправильный ввод хода: ушли за границы доски по х\n";
    }
    else {
        if (doska_b[8 - y][8 - (104 - x)] == 1) {
            mamba(x, y, x1, y1);
            buff = doska[8 - y][8 - (104 - x)];
            doska_figura_remove(x, y);
            doska_b[8 - y][8 - (104 - x)] = 0;
            flag_buff = true;
        }
        else {
            if (flag_buff == true) {
                if (buff == " " + f.p + " " || buff == " " + f.P + " ") {
                    Ppawn_hod(x, y, x1, y1);
                }
                if (buff == " " + f.r + " " || buff == " " + f.R + " ") {
                    Rrook_hod(x, y, x1, y1);
                }
                if (buff == " " + f.n + " " || buff == " " + f.N + " ") {
                    Nknight_hod(x, y, x1, y1);
                }
                if (buff == " " + f.b + " " || buff == " " + f.B + " ") {
                    Bbishop_hod(x, y, x1, y1);
                }
                if (buff == " " + f.q + " " || buff == " " + f.Q + " ") {
                    Qqueen_hod(x, y, x1, y1);
                }
                if (buff == " " + f.k + " " || buff == " " + f.K + " ") {
                    Kking_hod(x, y, x1, y1);
                }
                doska_print(sum_hod);
            }
        }
    }
    ++sum_hod;
}
