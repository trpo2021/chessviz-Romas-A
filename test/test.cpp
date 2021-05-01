#include "ctest.h"
#include "lib/chessviz.h"

CTEST(Pflag0, 1test)
{
    bool flag_buff = true;
    int y = 4;
    int x = 97;
    int y1 = 6;
    int x1 = 1;
    bool real = Ppawn_hod(x, y, x1, y1, flag_buff);
    ASSERT_FALSE(real);
}

CTEST(Pflag1, 2test)
{
    bool flag_buff = true;
    int y = 7;
    int x = 97;
    int y1 = 6;
    int x1 = 1;
    bool real = Ppawn_hod(x, y, x1, y1, flag_buff);
    ASSERT_TRUE(real);
}

CTEST(Rflag0, 3test)
{
    bool flag_buff = true;
    int y = 4;
    int x = 97;
    int y1 = 7;
    int x1 = 1;
    bool real = Rrook_hod(x, y, x1, y1, flag_buff);
    ASSERT_FALSE(real);
}

CTEST(Rflag1, 4test)
{
    bool flag_buff = true;
    int y = 4;
    int x = 98;
    int y1 = 7;
    int x1 = 1;
    bool real = Rrook_hod(x, y, x1, y1, flag_buff);
    ASSERT_TRUE(real);
}

CTEST(Nflag0, 5test)
{
    bool flag_buff = true;
    int y = 3;
    int x = 99;
    int y1 = 7;
    int x1 = 2;
    bool real = Nknight_hod(x, y, x1, y1, flag_buff);
    ASSERT_FALSE(real);
}

CTEST(Nflag1, 6test)
{
    bool flag_buff = true;
    int y = 4;
    int x = 99;
    int y1 = 7;
    int x1 = 2;
    bool real = Nknight_hod(x, y, x1, y1, flag_buff);
    ASSERT_TRUE(real);
}

CTEST(Bflag0, 7test)
{
    bool flag_buff = true;
    int y = 3;
    int x = 101;
    int y1 = 7;
    int x1 = 3;
    bool real = Bbishop_hod(x, y, x1, y1, flag_buff);
    ASSERT_FALSE(real);
}

CTEST(Bflag1, 8test)
{
    bool flag_buff = true;
    int y = 3;
    int x = 99;
    int y1 = 7;
    int x1 = 3;
    bool real = Bbishop_hod(x, y, x1, y1, flag_buff);
    ASSERT_TRUE(real);
}

CTEST(Qflag0, 9test)
{
    bool flag_buff = true;
    int y = 3;
    int x = 102;
    int y1 = 7;
    int x1 = 4;
    bool real = Qqueen_hod(x, y, x1, y1, flag_buff);
    ASSERT_FALSE(real);
}

CTEST(Qflag1, 10test)
{
    bool flag_buff = true;
    int y = 3;
    int x = 103;
    int y1 = 7;
    int x1 = 4;
    bool real = Qqueen_hod(x, y, x1, y1, flag_buff);
    ASSERT_TRUE(real);
}

CTEST(znacheniya, 11test)
{
    int y = 3;
    int x = 102;
    int y1 = 0;
    int x1 = 0;
    int real = mamba(x, y, x1, y1);
    int exp = 11;
    ASSERT_EQUAL(exp, real);
}
