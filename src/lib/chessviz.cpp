#include "chessviz.h"
#include <iostream>
#include <string>
using namespace std;

string buff, doska[9][9];
bool doska_b[9][9];
const int max_coordinate_number = 8;
const int max_number_character = 104;

struct Figura {
    string K, k, Q, q, R, r, N, n, B, b, P, p;
    Figura()
        : K{"K"},
          k{"k"},
          Q{"Q"},
          q{"q"},
          R{"R"},
          r{"r"},
          N{"N"},
          n{"n"},
          B{"B"},
          b{"b"},
          P{"P"},
          p{"p"}
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
    if ((sum_hod % 2 == 0 && sum_hod > 0) || sum_hod == 1) {
        cout << endl << "Ход черных: ";
    } else {
        cout << endl << "Ход белых: ";
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
    doska[max_coordinate_number - y]
         [max_coordinate_number - (max_number_character - x)]
            = "   ";
}

bool Ppawn_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    int h;
    if (y1 > max_coordinate_number - y) {
        h = y1 - (max_coordinate_number - y);
    }
    if (max_coordinate_number - y > y1) {
        h = (max_coordinate_number - y) - y1;
    }
    if (max_coordinate_number - (max_number_character - x) == x1 && h <= 2) {
        doska[max_coordinate_number - y]
             [max_coordinate_number - (max_number_character - x)]
                = buff;
        doska_b[max_coordinate_number - y]
               [max_coordinate_number - (max_number_character - x)]
                = 1;
        buff = "  ";
        flag_buff = false;
    } else {
        cout << "Неправильный ввод:введите только вторую измененную координату "
                "хода пешки (вид: a3) \n";
    }
    return flag_buff;
}

bool Rrook_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    if (max_coordinate_number - (max_number_character - x) == x1
        || max_coordinate_number - y == y1) {
        doska[max_coordinate_number - y]
             [max_coordinate_number - (max_number_character - x)]
                = buff;
        doska_b[max_coordinate_number - y]
               [max_coordinate_number - (max_number_character - x)]
                = 1;
        buff = "  ";
        flag_buff = false;
    } else {
        cout << "Неправильный ввод:введите только вторую измененную координату "
                "хода ладьи (вид: a3)\n";
    }
    return flag_buff;
}

bool Nknight_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    int h, h1;
    if (x1 > max_coordinate_number - (max_number_character - x)) {
        h = x1 - (max_coordinate_number - (max_number_character - x));
    }
    if (max_coordinate_number - (max_number_character - x) > x1) {
        h = max_coordinate_number - (max_number_character - x) - x1;
    }
    if (h == 1) {
        if (y1 > max_coordinate_number - y) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if (max_coordinate_number - y > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (h1 == 2) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода коня (вид: a3)\n";
        }
    }
    if (h == 2) {
        if (y1 > (max_coordinate_number - y)) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if ((max_coordinate_number - y) > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (h1 == 1) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода коня (вид: a3)\n";
        }
    }
    if (h != 1 && h != 2) {
        cout << "Неправильный ввод:введите только вторую измененную координату "
                "хода коня (вид: a3)\n";
    }
    return flag_buff;
}

bool Bbishop_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    int h, h1;
    if (x1 != max_coordinate_number - (max_number_character - x)
        || y1 != max_coordinate_number - y) {
        if (x1 > max_coordinate_number - (max_number_character - x)) {
            h = x1 - (max_coordinate_number - (max_number_character - x));
        }
        if (max_coordinate_number - (max_number_character - x) > x1) {
            h = max_coordinate_number - (max_number_character - x) - x1;
        }
        if (y1 > max_coordinate_number - y) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if (max_coordinate_number - y > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (h == h1) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода слона (вид: a3)\n";
        }
    } else {
        cout << "Неправильный ввод:введите только вторую измененную координату "
                "хода слона (вид: a3)\n";
    }
    return flag_buff;
}

bool Qqueen_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    int h, h1;
    if (max_coordinate_number - (max_number_character - x) == x1
        || max_coordinate_number - y == y1) {
        doska[max_coordinate_number - y]
             [max_coordinate_number - (max_number_character - x)]
                = buff;
        doska_b[max_coordinate_number - y]
               [max_coordinate_number - (max_number_character - x)]
                = 1;
        buff = "  ";
        flag_buff = false;
    } else {
        if (x1 > max_coordinate_number - (max_number_character - x)) {
            h = x1 - (max_coordinate_number - (max_number_character - x));
        }
        if (max_coordinate_number - (max_number_character - x) > x1) {
            h = max_coordinate_number - (max_number_character - x) - x1;
        }
        if (y1 > max_coordinate_number - y) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if (max_coordinate_number - y > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (h == h1) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода королевы (вид: a3)\n";
        }
    }
    return flag_buff;
}

void Kking_hod(int x, int y, int& x1, int& y1, bool& flag_buff)
{
    int h, h1;
    if (x1 > max_coordinate_number - (max_number_character - x)) {
        h = x1 - (max_coordinate_number - (max_number_character - x));
    }
    if (max_coordinate_number - (max_number_character - x) > x1) {
        h = max_coordinate_number - (max_number_character - x) - x1;
    }
    if (max_coordinate_number - (max_number_character - x) == x1) {
        h = 0;
    }

    if (h == 0) {
        if (y1 > max_coordinate_number - y) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if (max_coordinate_number - y > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (h1 == 1) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода короля (вид: a3)\n";
        }
    }

    if (h == 1) {
        if (y1 > max_coordinate_number - y) {
            h1 = y1 - (max_coordinate_number - y);
        }
        if (max_coordinate_number - y > y1) {
            h1 = (max_coordinate_number - y) - y1;
        }
        if (max_coordinate_number - y == y1) {
            h1 = 0;
        }

        if (h1 == 1) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        }
        if (h1 == 0) {
            doska[max_coordinate_number - y]
                 [max_coordinate_number - (max_number_character - x)]
                    = buff;
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 1;
            buff = "  ";
            flag_buff = false;
        } else {
            cout << "Неправильный ввод:введите только вторую измененную "
                    "координату хода короля (вид: a3)\n";
        }
    }
    if (h != 0 && h != 1) {
        cout << "Неправильный ввод:введите только вторую измененную координату "
                "хода короля (вид: a3)\n";
    }
}

int coordinate_1figura(int x, int y, int& x1, int& y1)
{
    y1 = max_coordinate_number - y;
    x1 = max_coordinate_number - (max_number_character - x);
    int z = x1 + y1;
    return z;
}

void doska_hod(int x, int y, int& x1, int& y1, int& sum_hod, bool& flag_buff)
{
    Figura f;
    if (y > 9 || y < 0) {
        cout << "Неправильный ввод хода: ушли за границы доски по у\n";
    }
    if (x > 104 || x < 97) {
        cout << "Неправильный ввод хода: ушли за границы доски по х\n";
    } else {
        if (doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
            == 1) {
            coordinate_1figura(x, y, x1, y1);
            buff = doska[max_coordinate_number - y]
                        [max_coordinate_number - (max_number_character - x)];
            doska_figura_remove(x, y);
            doska_b[max_coordinate_number - y]
                   [max_coordinate_number - (max_number_character - x)]
                    = 0;
            flag_buff = true;
        } else {
            if (flag_buff == true) {
                if (buff == " " + f.p + " " || buff == " " + f.P + " ") {
                    Ppawn_hod(x, y, x1, y1, flag_buff);
                }
                if (buff == " " + f.r + " " || buff == " " + f.R + " ") {
                    Rrook_hod(x, y, x1, y1, flag_buff);
                }
                if (buff == " " + f.n + " " || buff == " " + f.N + " ") {
                    Nknight_hod(x, y, x1, y1, flag_buff);
                }
                if (buff == " " + f.b + " " || buff == " " + f.B + " ") {
                    Bbishop_hod(x, y, x1, y1, flag_buff);
                }
                if (buff == " " + f.q + " " || buff == " " + f.Q + " ") {
                    Qqueen_hod(x, y, x1, y1, flag_buff);
                }
                if (buff == " " + f.k + " " || buff == " " + f.K + " ") {
                    Kking_hod(x, y, x1, y1, flag_buff);
                }
                doska_print(sum_hod);
            }
        }
    }
    ++sum_hod;
}
