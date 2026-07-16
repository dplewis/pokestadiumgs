#include "global.h"

#ifdef VERSION_JP
#include "lib/ultralib/include/PR/os_internal_reg.h"

void func_80001E0C(s32);
void func_80001F54(s32);
void func_80002014();
void func_80002B34(s32);
void func_80002BE8(s32);
void func_800063C0();
void func_80035040(s32);
void func_800352BC();
void func_80035520();
void func_80041A84();
void func_80046880();
void func_80049D20();
void func_8004B530();
void func_8004BE70();
void func_80050A40();
void func_80056968();
void func_8005B11C();
void func_80005EC0();
void func_80005EEC();
void func_80065854();
void func_8006EA40();

extern s32 D_8009F670;
extern s32 D_8009F674;
extern s32 D_8012A220;
extern s32 D_8012A224;
extern s16 D_8012A228;
extern s16 D_8012A22A;
extern s32 D_14B3C0;
extern s32 D_14F030;
extern s32 D_150E20;
extern s32 D_82700000;
extern s32 D_82A00000;

void func_800029D0(s32 (*)(s32, s32));
s32 (*func_800047D8())(s32, s32);

s32 func_80065680(s32 state)
{
    u32 intr = osSetIntMask(1);

    // if the 16-bit value at ROM offset 0xE38 is not 0x828A, make the state an invalid one.
    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32 *)0xB0000E38 & 0xFFFF) != 0x828A))
    {
        state = -0x10;
    }

    osSetIntMask(intr);

    return state;
}

s32 func_800656E8(void)
{
    return D_8012A220;
}

s32 func_800656F4(s32 arg0)
{
    s32 var_v1;

    var_v1 = 0;
    if ((arg0 >= 0) && (arg0 < 4))
    {
        D_8012A220 = arg0;
        var_v1 = 1;
    }
    return var_v1;
}

void func_80065718(s32 arg0)
{
    D_8012A228 = arg0;
}

s16 func_80065724(void)
{
    return D_8012A228;
}

void func_80065730(s32 arg0)
{
    D_8012A22A = arg0;
}

s16 func_8006573C(void)
{
    return D_8012A22A;
}

s32 func_80065748(s32 arg0, u8 *romStart, u8 *romEnd, s32 arg3, s32 arg4)
{
    s32 result;
    s32 (*func)(s32, s32);

    func = func_800047D8(arg0, romStart, romEnd);
    result = func(arg3, arg4);
    func_800029D0(func);
    return result;
}

void func_80065788(void)
{
    func_80005EC0();
    func_80005EEC();
    func_80049D20();
}

void func_800657B8(s32 arg0, s32 arg1)
{
    osViBlack(1U);
    func_80056968();
    func_800352BC();
    func_80065854();
    func_80001E0C(1);
    func_80002014();
    func_80001F54(0xA);
    func_80002BE8('GAME');
    func_80065748(((u32)((s32)&D_82A00000 & 0x0FF00000) >> 0x14) - 0x10, &D_14F030, &D_150E20, arg0, arg1);
}

void func_80065854(void)
{
}

s32 func_8006585C(s32 arg0)
{
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != D_8009F674)
    {
        D_8012A224 = D_8009F674;
        D_8009F674 = arg0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8006588C(void)
{
    return D_8009F674;
}

s32 func_80065898(void)
{
    return D_8012A224;
}

void func_800658A4(void)
{
    s32 sp24;

    func_80002B34('optn');
    sp24 = func_80065748(((u32)((s32)&D_82700000 & 0x0FF00000) >> 0x14) - 0x10, &D_14B3C0, &D_14F030, 0, 0);
    func_80002BE8('optn');
    if (sp24 == 0)
    {
        func_8006585C(2);
        return;
    }
    func_8006585C(1);
}

void func_80065930(void)
{
    __osSetFpcCsr(0x01000C01);
    func_800063C0();
    func_80035040(0);
    func_80035520();
    func_8004BE70();
    func_80046880();
    func_80041A84();
    func_8006EA40();
    func_8006585C(0x11);
    D_8012A220 = -1;
    D_8009F670 = 0;
    func_80002B34('GAME');
}

void func_800659B4(void)
{
    if (D_8009F670 == 0)
    {
        D_8009F670 = 1;
        func_8004B530();
        func_80050A40();
        func_80002B34('GPAK');
        func_8005B11C();
        func_80002BE8('GPAK');
    }
}

void Game_Thread(UNUSED void *arg0)
{
    s32 temp_v0;

    func_80065930();

    while (1)
    {
        temp_v0 = func_80065680(D_8009F674);

        switch (temp_v0)
        {
        case 17:
            func_800353B4(0, 0, 0);
            func_80066620();
            break;
        case 1:
            func_8006650C();
            break;
        case 2:
            func_800353B4(2, 0, 0);
            func_800354E4(0x25);
            func_800666B0();
            break;
        case 3:
            func_800353B4(2, 0, 0);
            func_800354E4(0x25);
            func_800668AC();
            break;
        case 4:
            func_80066A60();
            break;
        case 5:
            func_800353B4(3, 0, 0);
            func_800354E4(8);
            func_8006EC40();
            func_8006585C(3);
            break;
        case 6:
            func_80066D00();
            break;
        case 7:
            func_800353B4(5, 0, 0);
            func_800354E4(0x29);
            func_80067200();
            break;
        case 8:
            func_80067834();
            break;
        case 9:
            func_80068718();
            break;
        case 10:
            func_800353B4(6, 0, 0);
            func_80073FC4(0);
            func_8006585C(3);
            func_800354D4();
            break;
        case 11:
            func_800353B4(2, 0, 0);
            func_800354E4(0x2A);
            func_800658A4();
            break;
        case 12:
            func_800353B4(0x1E, 0, 0);
            func_800673D0();
            break;
        case 13:
            func_80069070();
            break;
        case 14:
            func_80069EF0();
            break;
        case 15:
            func_8006A480();
            break;
        case 16:
            func_80069994();
            break;
        case 18:
            // Mobile Stadium Screen
            func_8006B200();
            break;
        case 19:
            func_800354E4(0x44);
            func_8006F2CC();
            func_8006585C(2);
            break;
        }
    }
}
#endif
