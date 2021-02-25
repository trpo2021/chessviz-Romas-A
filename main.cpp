#include <iostream>
#include <string>
using namespace std;
string doska[9][9];
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

void doska_print()
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
}

void doska_default()
{
    Figura f;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 9; j++) {
            doska[i][j] = " ";
        }
    }
    for (int i = 1; i < 9; i++) {
        doska[1][i] = " " + f.p + " ";
        doska[6][i] = " " + f.P + " ";
    }
    doska[0][1] = doska[0][8] = " " + f.r + " ";
    doska[7][1] = doska[7][8] = " " + f.R + " ";
    doska[0][2] = doska[0][7] = " " + f.n + " ";
    doska[7][2] = doska[7][7] = " " + f.N + " ";
    doska[0][3] = doska[0][6] = " " + f.b + " ";
    doska[7][3] = doska[7][6] = " " + f.B + " ";
    doska[0][4] = " " + f.q + " ";
    doska[0][5] = " " + f.k + " ";
    doska[7][4] = " " + f.Q + " ";
    doska[7][5] = " " + f.K + " ";

    doska_print();
}

int main()
{
    doska_default();
    return 0;
}
