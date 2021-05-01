#pragma once
struct Figura;
void doska_print(int& sum_hod);
void doska_default(int& sum_hod);
void doska_figura_remove(int x, int y);
bool Ppawn_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
bool Rrook_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
bool Nknight_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
bool Bbishop_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
bool Qqueen_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
void Kking_hod(int x, int y, int& x1, int& y1, bool& flag_buff);
int mamba(int x, int y, int& x1, int& y1);
void doska_hod(int x, int y, int& x1, int& y1, int& sum_hod, bool& flag_buff);
