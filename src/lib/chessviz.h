#pragma once
struct Figura;
void doska_print(int& sum_hod);
void doska_default(int& sum_hod);
void doska_figura_remove(int x, int y);
void Ppawn_hod(int x, int y, int& x1, int& y1);
void Rrook_hod(int x, int y, int& x1, int& y1);
void Nknight_hod(int x, int y, int& x1, int& y1);
void Bbishop_hod(int x, int y, int& x1, int& y1);
void Qqueen_hod(int x, int y, int& x1, int& y1);
void Kking_hod(int x, int y, int& x1, int& y1);
void mamba(int x, int y, int& x1, int& y1);
void doska_hod(int x, int y, int& x1, int& y1, int& sum_hod);
