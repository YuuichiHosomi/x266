// Copyright (c) 2016 Min Chen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <stdio.h>
#include <stdlib.h>
#include "tb_common.h"

const int16_t g_t32[32][32] =
{
    { 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
    { 90, 90, 88, 85, 82, 78, 73, 67, 61, 54, 46, 38, 31, 22, 13,  4, -4, -13, -22, -31, -38, -46, -54, -61, -67, -73, -78, -82, -85, -88, -90, -90 },
    { 90, 87, 80, 70, 57, 43, 25,  9, -9, -25, -43, -57, -70, -80, -87, -90, -90, -87, -80, -70, -57, -43, -25, -9,  9, 25, 43, 57, 70, 80, 87, 90 },
    { 90, 82, 67, 46, 22, -4, -31, -54, -73, -85, -90, -88, -78, -61, -38, -13, 13, 38, 61, 78, 88, 90, 85, 73, 54, 31,  4, -22, -46, -67, -82, -90 },
    { 89, 75, 50, 18, -18, -50, -75, -89, -89, -75, -50, -18, 18, 50, 75, 89, 89, 75, 50, 18, -18, -50, -75, -89, -89, -75, -50, -18, 18, 50, 75, 89 },
    { 88, 67, 31, -13, -54, -82, -90, -78, -46, -4, 38, 73, 90, 85, 61, 22, -22, -61, -85, -90, -73, -38,  4, 46, 78, 90, 82, 54, 13, -31, -67, -88 },
    { 87, 57,  9, -43, -80, -90, -70, -25, 25, 70, 90, 80, 43, -9, -57, -87, -87, -57, -9, 43, 80, 90, 70, 25, -25, -70, -90, -80, -43,  9, 57, 87 },
    { 85, 46, -13, -67, -90, -73, -22, 38, 82, 88, 54, -4, -61, -90, -78, -31, 31, 78, 90, 61,  4, -54, -88, -82, -38, 22, 73, 90, 67, 13, -46, -85 },
    { 83, 36, -36, -83, -83, -36, 36, 83, 83, 36, -36, -83, -83, -36, 36, 83, 83, 36, -36, -83, -83, -36, 36, 83, 83, 36, -36, -83, -83, -36, 36, 83 },
    { 82, 22, -54, -90, -61, 13, 78, 85, 31, -46, -90, -67,  4, 73, 88, 38, -38, -88, -73, -4, 67, 90, 46, -31, -85, -78, -13, 61, 90, 54, -22, -82 },
    { 80,  9, -70, -87, -25, 57, 90, 43, -43, -90, -57, 25, 87, 70, -9, -80, -80, -9, 70, 87, 25, -57, -90, -43, 43, 90, 57, -25, -87, -70,  9, 80 },
    { 78, -4, -82, -73, 13, 85, 67, -22, -88, -61, 31, 90, 54, -38, -90, -46, 46, 90, 38, -54, -90, -31, 61, 88, 22, -67, -85, -13, 73, 82,  4, -78 },
    { 75, -18, -89, -50, 50, 89, 18, -75, -75, 18, 89, 50, -50, -89, -18, 75, 75, -18, -89, -50, 50, 89, 18, -75, -75, 18, 89, 50, -50, -89, -18, 75 },
    { 73, -31, -90, -22, 78, 67, -38, -90, -13, 82, 61, -46, -88, -4, 85, 54, -54, -85,  4, 88, 46, -61, -82, 13, 90, 38, -67, -78, 22, 90, 31, -73 },
    { 70, -43, -87,  9, 90, 25, -80, -57, 57, 80, -25, -90, -9, 87, 43, -70, -70, 43, 87, -9, -90, -25, 80, 57, -57, -80, 25, 90,  9, -87, -43, 70 },
    { 67, -54, -78, 38, 85, -22, -90,  4, 90, 13, -88, -31, 82, 46, -73, -61, 61, 73, -46, -82, 31, 88, -13, -90, -4, 90, 22, -85, -38, 78, 54, -67 },
    { 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64, 64, -64, -64, 64 },
    { 61, -73, -46, 82, 31, -88, -13, 90, -4, -90, 22, 85, -38, -78, 54, 67, -67, -54, 78, 38, -85, -22, 90,  4, -90, 13, 88, -31, -82, 46, 73, -61 },
    { 57, -80, -25, 90, -9, -87, 43, 70, -70, -43, 87,  9, -90, 25, 80, -57, -57, 80, 25, -90,  9, 87, -43, -70, 70, 43, -87, -9, 90, -25, -80, 57 },
    { 54, -85, -4, 88, -46, -61, 82, 13, -90, 38, 67, -78, -22, 90, -31, -73, 73, 31, -90, 22, 78, -67, -38, 90, -13, -82, 61, 46, -88,  4, 85, -54 },
    { 50, -89, 18, 75, -75, -18, 89, -50, -50, 89, -18, -75, 75, 18, -89, 50, 50, -89, 18, 75, -75, -18, 89, -50, -50, 89, -18, -75, 75, 18, -89, 50 },
    { 46, -90, 38, 54, -90, 31, 61, -88, 22, 67, -85, 13, 73, -82,  4, 78, -78, -4, 82, -73, -13, 85, -67, -22, 88, -61, -31, 90, -54, -38, 90, -46 },
    { 43, -90, 57, 25, -87, 70,  9, -80, 80, -9, -70, 87, -25, -57, 90, -43, -43, 90, -57, -25, 87, -70, -9, 80, -80,  9, 70, -87, 25, 57, -90, 43 },
    { 38, -88, 73, -4, -67, 90, -46, -31, 85, -78, 13, 61, -90, 54, 22, -82, 82, -22, -54, 90, -61, -13, 78, -85, 31, 46, -90, 67,  4, -73, 88, -38 },
    { 36, -83, 83, -36, -36, 83, -83, 36, 36, -83, 83, -36, -36, 83, -83, 36, 36, -83, 83, -36, -36, 83, -83, 36, 36, -83, 83, -36, -36, 83, -83, 36 },
    { 31, -78, 90, -61,  4, 54, -88, 82, -38, -22, 73, -90, 67, -13, -46, 85, -85, 46, 13, -67, 90, -73, 22, 38, -82, 88, -54, -4, 61, -90, 78, -31 },
    { 25, -70, 90, -80, 43,  9, -57, 87, -87, 57, -9, -43, 80, -90, 70, -25, -25, 70, -90, 80, -43, -9, 57, -87, 87, -57,  9, 43, -80, 90, -70, 25 },
    { 22, -61, 85, -90, 73, -38, -4, 46, -78, 90, -82, 54, -13, -31, 67, -88, 88, -67, 31, 13, -54, 82, -90, 78, -46,  4, 38, -73, 90, -85, 61, -22 },
    { 18, -50, 75, -89, 89, -75, 50, -18, -18, 50, -75, 89, -89, 75, -50, 18, 18, -50, 75, -89, 89, -75, 50, -18, -18, 50, -75, 89, -89, 75, -50, 18 },
    { 13, -38, 61, -78, 88, -90, 85, -73, 54, -31,  4, 22, -46, 67, -82, 90, -90, 82, -67, 46, -22, -4, 31, -54, 73, -85, 90, -88, 78, -61, 38, -13 },
    {  9, -25, 43, -57, 70, -80, 87, -90, 90, -87, 80, -70, 57, -43, 25, -9, -9, 25, -43, 57, -70, 80, -87, 90, -90, 87, -80, 70, -57, 43, -25,  9 },
    {  4, -13, 22, -31, 38, -46, 54, -61, 67, -73, 78, -82, 85, -88, 90, -90, 90, -90, 88, -85, 82, -78, 73, -67, 61, -54, 46, -38, 31, -22, 13, -4 }
};

static void partialButterfly32(const int16_t* src, int16_t* dst, int shift, int line)
{
    int j, k;
    int E[16], O[16];
    int EE[8], EO[8];
    int EEE[4], EEO[4];
    int EEEE[2], EEEO[2];
    int add = 1 << (shift - 1);

    for (j = 0; j < line; j++)
    {
        /* E and O*/
        for (k = 0; k < 16; k++)
        {
            E[k] = src[k] + src[31 - k];
            O[k] = src[k] - src[31 - k];
        }

#if 1
        if (/*(j < 2) && */(shift == 11))
        {
            printf("I: ");
            for (k = 0; k < 32; k++)
            {
                printf("%04X, ", src[k] & 0xFFFF);
            }
            printf("\n");
            printf("E: ");
            for (k = 0; k < 16; k++)
            {
                printf("%04X, ", E[k] & 0xFFFF);
            }
            printf("\n");
            printf("O: ");
            for (k = 0; k < 16; k++)
            {
                printf("%04X, ", O[k] & 0xFFFF);
            }
            printf("\n");
        }
#endif

        /* EE and EO */
        for (k = 0; k < 8; k++)
        {
            EE[k] = E[k] + E[15 - k];
            EO[k] = E[k] - E[15 - k];
        }

        /* EEE and EEO */
        for (k = 0; k < 4; k++)
        {
            EEE[k] = EE[k] + EE[7 - k];
            EEO[k] = EE[k] - EE[7 - k];
        }

        /* EEEE and EEEO */
        EEEE[0] = EEE[0] + EEE[3];
        EEEO[0] = EEE[0] - EEE[3];
        EEEE[1] = EEE[1] + EEE[2];
        EEEO[1] = EEE[1] - EEE[2];

        dst[0] = (int16_t)((g_t32[0][0] * EEEE[0] + g_t32[0][1] * EEEE[1] + add) >> shift);
        dst[16 * line] = (int16_t)((g_t32[16][0] * EEEE[0] + g_t32[16][1] * EEEE[1] + add) >> shift);
        dst[8 * line] = (int16_t)((g_t32[8][0] * EEEO[0] + g_t32[8][1] * EEEO[1] + add) >> shift);
        dst[24 * line] = (int16_t)((g_t32[24][0] * EEEO[0] + g_t32[24][1] * EEEO[1] + add) >> shift);
        for (k = 4; k < 32; k += 8)
        {
            dst[k * line] = (int16_t)((g_t32[k][0] * EEO[0] + g_t32[k][1] * EEO[1] + g_t32[k][2] * EEO[2] +
                                       g_t32[k][3] * EEO[3] + add) >> shift);
        }

        for (k = 2; k < 32; k += 4)
        {
            dst[k * line] = (int16_t)((g_t32[k][0] * EO[0] + g_t32[k][1] * EO[1] + g_t32[k][2] * EO[2] +
                                       g_t32[k][3] * EO[3] + g_t32[k][4] * EO[4] + g_t32[k][5] * EO[5] +
                                       g_t32[k][6] * EO[6] + g_t32[k][7] * EO[7] + add) >> shift);
        }

        for (k = 1; k < 32; k += 2)
        {
            dst[k * line] = (int16_t)((g_t32[k][0] * O[0] + g_t32[k][1] * O[1] + g_t32[k][2] * O[2] + g_t32[k][3] * O[3] +
                                       g_t32[k][4] * O[4] + g_t32[k][5] * O[5] + g_t32[k][6] * O[6] + g_t32[k][7] * O[7] +
                                       g_t32[k][8] * O[8] + g_t32[k][9] * O[9] + g_t32[k][10] * O[10] + g_t32[k][11] *
                                       O[11] + g_t32[k][12] * O[12] + g_t32[k][13] * O[13] + g_t32[k][14] * O[14] +
                                       g_t32[k][15] * O[15] + add) >> shift);
        }

#if 0
        if (/*(j < 2) && */(shift == 4))
        {
            printf("%2d: ", j);
            for(k = 0; k < 32; k++)
            {
                printf("%04X, ", dst[k * line] & 0xFFFF);
            }
            printf("\n");
            fflush(stdout);
        }
#endif

        src += 32;
        dst++;
    }
}


static int16_t mat[32 * 32];
static int16_t dct[32 * 32];
static int lastDiff = 0;
static int lastDct = 0;

void dct32_genNew()
{
    const int shift_1st = 4;
    const int shift_2nd = 11;

    int16_t coef[32 * 32];

    int i, j;

    for(i = 0; i < 32; i++)
    {
        for(j = 0; j < 32; j++)
        {
            const int a = rand() & 0xFF;
            const int b = rand() & 0xFF;
            mat[i * 32 + j] = (a - b);
        }
    }

    partialButterfly32(mat, coef, shift_1st, 32);
    partialButterfly32(coef, dct, shift_2nd, 32);

    lastDiff = 0;
    lastDct  = 0;
}

// Vector#(2, Vector#(32, Bit#(16)))
void dct32_getDiff(unsigned int res[])
{
    int i, j;
    int x = 0;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 32; j+=2)
        {
            const uint32_t a = mat[(lastDiff + i) * 32 + j + 0] & 0xFFFF;
            const uint32_t b = mat[(lastDiff + i) * 32 + j + 1] & 0xFFFF;
            res[x++] = (b << 16) + a;
        }
    }
    lastDiff += 2;
}

// Vector#(4, Bit#(16))
uint64_t dct32_getDct(/*unsigned int res[]*/)
{
    int i;
    int x = 0;
    uint64_t ret = 0;

    //for(i = 0; i < 4; i++)
    //{
    //    ret = (ret << 16) | (dct[lastDct++] & 0xFFFF);
    //}

    const int col = lastDct >> 5;
    const int row = lastDct & 31;
    const uint64_t x0 = (uint64_t)(dct[(row + 0) * 32 + col] & 0xFFFF) <<  0;
    const uint64_t x1 = (uint64_t)(dct[(row + 1) * 32 + col] & 0xFFFF) << 16;
    const uint64_t x2 = (uint64_t)(dct[(row + 2) * 32 + col] & 0xFFFF) << 32;
    const uint64_t x3 = (uint64_t)(dct[(row + 3) * 32 + col] & 0xFFFF) << 48;

    //printf("R(%d,%d)\n", row, col);
    ret = x3 | x2 | x1 | x0;
    lastDct += 4;

    return ret;
}


#if 0
/*
    { 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
    { 90, 90, 88, 85, 82, 78, 73, 67, 61, 54, 46, 38, 31, 22, 13,  4 },
    { 90, 87, 80, 70, 57, 43, 25,  9, -9,-25,-43,-57,-70,-80,-87,-90 },
    { 90, 82, 67, 46, 22, -4,-31,-54,-73,-85,-90,-88,-78,-61,-38,-13 },
    { 89, 75, 50, 18,-18,-50,-75,-89,-89,-75,-50,-18, 18, 50, 75, 89 },
    { 88, 67, 31,-13,-54,-82,-90,-78,-46, -4, 38, 73, 90, 85, 61, 22 },
    { 87, 57,  9,-43,-80,-90,-70,-25, 25, 70, 90, 80, 43, -9,-57,-87 },
    { 85, 46,-13,-67,-90,-73,-22, 38, 82, 88, 54, -4,-61,-90,-78,-31 },
    { 83, 36,-36,-83,-83,-36, 36, 83, 83, 36,-36,-83,-83,-36, 36, 83 },
    { 82, 22,-54,-90,-61, 13, 78, 85, 31,-46,-90,-67,  4, 73, 88, 38 },
    { 80,  9,-70,-87,-25, 57, 90, 43,-43,-90,-57, 25, 87, 70, -9,-80 },
    { 78, -4,-82,-73, 13, 85, 67,-22,-88,-61, 31, 90, 54,-38,-90,-46 },
    { 75,-18,-89,-50, 50, 89, 18,-75,-75, 18, 89, 50,-50,-89,-18, 75 },
    { 73,-31,-90,-22, 78, 67,-38,-90,-13, 82, 61,-46,-88, -4, 85, 54 },
    { 70,-43,-87,  9, 90, 25,-80,-57, 57, 80,-25,-90, -9, 87, 43,-70 },
    { 67,-54,-78, 38, 85,-22,-90,  4, 90, 13,-88,-31, 82, 46,-73,-61 },
    { 64,-64,-64, 64, 64,-64,-64, 64, 64,-64,-64, 64, 64,-64,-64, 64 },
    { 61,-73,-46, 82, 31,-88,-13, 90, -4,-90, 22, 85,-38,-78, 54, 67 },
    { 57,-80,-25, 90, -9,-87, 43, 70,-70,-43, 87,  9,-90, 25, 80,-57 },
    { 54,-85, -4, 88,-46,-61, 82, 13,-90, 38, 67,-78,-22, 90,-31,-73 },
    { 50,-89, 18, 75,-75,-18, 89,-50,-50, 89,-18,-75, 75, 18,-89, 50 },
    { 46,-90, 38, 54,-90, 31, 61,-88, 22, 67,-85, 13, 73,-82,  4, 78 },
    { 43,-90, 57, 25,-87, 70,  9,-80, 80, -9,-70, 87,-25,-57, 90,-43 },
    { 38,-88, 73, -4,-67, 90,-46,-31, 85,-78, 13, 61,-90, 54, 22,-82 },
    { 36,-83, 83,-36,-36, 83,-83, 36, 36,-83, 83,-36,-36, 83,-83, 36 },
    { 31,-78, 90,-61,  4, 54,-88, 82,-38,-22, 73,-90, 67,-13,-46, 85 },
    { 25,-70, 90,-80, 43,  9,-57, 87,-87, 57, -9,-43, 80,-90, 70,-25 },
    { 22,-61, 85,-90, 73,-38, -4, 46,-78, 90,-82, 54,-13,-31, 67,-88 },
    { 18,-50, 75,-89, 89,-75, 50,-18,-18, 50,-75, 89,-89, 75,-50, 18 },
    { 13,-38, 61,-78, 88,-90, 85,-73, 54,-31,  4, 22,-46, 67,-82, 90 },
    {  9,-25, 43,-57, 70,-80, 87,-90, 90,-87, 80,-70, 57,-43, 25, -9 },
    {  4,-13, 22,-31, 38,-46, 54,-61, 67,-73, 78,-82, 85,-88, 90,-90 }
*/

        dst[ 0       ] = (int16_t)((64 * (E[0] + E[15] + E[7] + E[ 8] + E[3] + E[12] + E[4] + E[11]) + 64 * (E[1] + E[14] + E[6] + E[ 9] + E[2] + E[13] + E[5] + E[10]) + add) >> shift);
        //dst[ 2 * line] = (int16_t)((90 * (E[0] - E[15]) + 87 * (E[1] - E[14]) + 80 * (E[2] - E[13]) + 70 * (E[3] - E[12]) + 57 * (E[4] - E[11]) + 43 * (E[5] - E[10]) + 25 * (E[6] - E[ 9]) + 9 * (E[7] - E[ 8]) + add) >> shift);
        dst[ 2 * line] = (int16_t)((90 * E[0] + 87 * E[1] + 80 * E[2] + 70 * E[3] + 57 * E[4] + 43 * E[5] + 25 * E[6] + 9 * E[7] - 9 * E[ 8] - 25 * E[ 9] - 43 * E[10] - 57 * E[11] - 70 * E[12] - 80 * E[13] - 87 * E[14] - 90 * E[15] + add) >> shift);
        dst[ 4 * line] = (int16_t)((g_t32[k][0] * (E[0] + E[15] - E[7] - E[ 8]) + g_t32[k][1] * (E[1] + E[14] - E[6] - E[ 9]) + g_t32[k][2] * (E[2] + E[13] - E[5] - E[10]) + g_t32[k][3] * (E[3] + E[12] - E[4] - E[11]) + add) >> shift);
        dst[ 6 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        dst[ 8 * line] = (int16_t)((g_t32[8][0] * (E[0] + E[15] + E[7] + E[ 8] - E[3] - E[12] - E[4] - E[11]) + g_t32[8][1] * (E[1] + E[14] + E[6] + E[ 9] - E[2] - E[13] - E[5] - E[10]) + add) >> shift);
        dst[10 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        dst[12 * line] = (int16_t)((g_t32[k][0] * (E[0] + E[15] - E[7] - E[ 8]) + g_t32[k][1] * (E[1] + E[14] - E[6] - E[ 9]) + g_t32[k][2] * (E[2] + E[13] - E[5] - E[10]) + g_t32[k][3] * (E[3] + E[12] - E[4] - E[11]) + add) >> shift);
        dst[14 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        dst[16 * line] = (int16_t)((g_t32[16][0] * (E[0] + E[15] + E[7] + E[ 8] + E[3] + E[12] + E[4] + E[11]) + g_t32[16][1] * (E[1] + E[14] + E[6] + E[ 9] + E[2] + E[13] + E[5] + E[10]) + add) >> shift);
        dst[18 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        dst[20 * line] = (int16_t)((g_t32[k][0] * (E[0] + E[15] - E[7] - E[ 8]) + g_t32[k][1] * (E[1] + E[14] - E[6] - E[ 9]) + g_t32[k][2] * (E[2] + E[13] - E[5] - E[10]) + g_t32[k][3] * (E[3] + E[12] - E[4] - E[11]) + add) >> shift);
        dst[22 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        dst[24 * line] = (int16_t)((g_t32[24][0] * (E[0] + E[15] + E[7] + E[ 8] - E[3] - E[12] - E[4] - E[11]) + g_t32[24][1] * (E[1] + E[14] + E[6] + E[ 9] - E[2] - E[13] - E[5] - E[10]) + add) >> shift);
        dst[26 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);
        //dst[28 * line] = (int16_t)((g_t32[k][0] * (E[0] + E[15] - E[7] - E[ 8]) + g_t32[k][1] * (E[1] + E[14] - E[6] - E[ 9]) + g_t32[k][2] * (E[2] + E[13] - E[5] - E[10]) + g_t32[k][3] * (E[3] + E[12] - E[4] - E[11]) + add) >> shift);

        dst[28 * line] = (int16_t)((18 * E[0] - 50 * E[1] + 75 * E[2] - 89 * E[3] + 89 * E[4] - 75 * E[5] + 50 * E[6] - 18 * E[7] - 18 * E[ 8] + 50 * E[ 9] - 75 * E[10] + 89 * E[11] - 89 * E[12] + 75 * E[13] - 50 * E[14] + 18 * E[15] + add) >> shift);


        dst[30 * line] = (int16_t)((g_t32[k][0] * (E[0] - E[15]) + g_t32[k][1] * (E[1] - E[14]) + g_t32[k][2] * (E[2] - E[13]) + g_t32[k][3] * (E[3] - E[12]) + g_t32[k][4] * (E[4] - E[11]) + g_t32[k][5] * (E[5] - E[10]) + g_t32[k][6] * (E[6] - E[ 9]) + g_t32[k][7] * (E[7] - E[ 8]) + add) >> shift);

#endif
