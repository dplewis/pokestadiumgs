#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "global.h"

// thread pris
#define THREAD_PRI_RESET 30
#define THREAD_PRI_IDLE_INIT 100

// thread IDs
#define THREAD_ID_IDLE 1
#define THREAD_ID_RESET 21

typedef struct UnkArray4 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ u32 unk_0C;
} UnkArray4; // size = 0x10

// there's some wonkyness going on like the compiler trying to 8-align filler arrays? I dont understand.
typedef struct RenderContext {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ OSMesg unk_1B0;
    /* 0x1B4 */ char unk1B4[0xC];
    /* 0x1C0 */ OSMesgQueue unk_1C0;
    /* 0x1D8 */ s32 unk_1D8;
    /* 0x1DC */ s32 unk_1DC;
    /* 0x1E0 */ u8 unk1E0[0x800];
    /* 0x9E0 */ UnkArray4* unk_9E0;
    /* 0x9E4 */ char unk9E4[0x48];
    /* 0xA2C */ s32 unk_A2C;
    /* 0xA30 */ char unkA30[0x58];
    /* 0xA88 */ u16 unk_A88;
    /* 0xA8A */ u8 unk_A8A;
    /* 0xA8B */ u8 unk_A8B;
    /* 0xA8C */ u8 unk_A8C;
    /* 0xA8D */ u8 unk_A8D;
    /* 0xA8E */ u8 unk_A8E;
    /* 0xA8F */ u8 unk_A8F;
    /* 0xA90 */ s32 unk_A90;
    /* 0xA94 */ s32 unk_A94;
    /* 0xA98 */ s32 unk_A98;
    /* 0xA9C */ u8 unk_A9C;
    /* 0xA9D */ u8 unk_A9D;
    /* 0xA9E */ u8 unk_A9E;
    /* 0xA9F */ u8 unk_A9F;
    /* 0xAA0 */ s32 unk_AA0;
    /* 0xAA4 */ char unkAA4[0x4];
    /* 0xAA8 */ UnkArray4* unk_AA8;
    /* 0xAAC */ u8 unk_AAC;
    /* 0xAAD */ u8 unk_AAD;
    /* 0xAAE */ u8 unk_AAE;
    /* 0xAAF */ u8 unk_AAF;
    /* 0xAB0 */ char unkAB0[0x8];
    /* 0xAB8 */ s32 unk_AB8;
} RenderContext; // size >= 0xABC

extern RenderContext gRenderContext;

#endif //_VARIABLES_H_
