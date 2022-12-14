/*++*
* Copyright (c) 1997 University of British Columbia. All rights reserved.
*
*       File:           encode.h
*       Pourpose:       contains global functions.
*
*       Author:         Ismaeil R. Ismaeil, Aug. 1997
*
*--*/

#include <stdio.h>
//#include <malloc.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#ifndef CLOCKS_PER_SEC
#endif

/*FILE          *ifp , *ofp;*/

extern uint16_t  in_buf[17][18];

extern uint8_t compressed_data[16 *2 *  16];
extern int compressed_data_length;

struct Image_Coord { int x, y; };

extern struct Image_Coord pdim, dim, x, a, b, c, d;


static int bit_set_mask[] =
{0x00000001,0x00000002,0x00000004,0x00000008,
0x00000010,0x00000020,0x00000040,0x00000080,
0x00000100,0x00000200,0x00000400,0x00000800,
0x00001000,0x00002000,0x00004000,0x00008000,
0x00010000,0x00020000,0x00040000,0x00080000,
0x00100000,0x00200000,0x00400000,0x00800000,
0x01000000,0x02000000,0x04000000,0x08000000,
0x10000000,0x20000000,0x40000000,0x80000000};

static int current_write_byte;
static int current_read_byte;
static int read_position;
static int write_position;
extern int  count;

#define mput1()\
{current_write_byte|=bit_set_mask[write_position--];\
if (write_position<0) { compressed_data[compressed_data_length++] = current_write_byte;/*putc(current_write_byte,ofp)*/;\
 if(current_write_byte == 255)\
 write_position=6;else write_position=7; current_write_byte=0;}}

#define mput0()\
{write_position--;if(write_position<0){compressed_data[compressed_data_length++] = current_write_byte/*/putc(current_write_byte,ofp)*/;\
 write_position=7;\
 current_write_byte=0;}}

static int J[] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,
           4,5,5,6,6,7,7,8,9,10,11,12,13,14,15};

/* MAX and MIN macros */
#define MAX(x,y) ((x > y) ? x:y)
#define MIN(x,y) ((x > y) ? y:x)
#define ABS(x) ((x < 0) ? -x:x)


#define MAXIMUM_IMAGE_HEIGHT 65535
#define MAXIMUM_IMAGE_WIDTH 65535
#define MAXIMUM_SOURCES 16
#define MAXIMUM_COMPONENTS 256

#define MAX_C 127    /* maximum allowed value of C[0..364] */
#define MIN_C -128   /* minimum allowed value of C[0..364] */
#define NEAR  0      /*difference bound for near-lossless mode */
#define RESET 64     /* threshold value at which A, B, and N are halved */

#define PASS 1
#define FAIL 0

extern int P, T1, T2, T3, MAXVAL;
extern  int Ix, Ra, Rb, Rc, Rd;
extern int EOLine;
extern int RANGE;
extern int A[367], B[365], C[365], N[367], Nn[367];
extern int RUNindex, RUNval, RUNcnt;
extern int D[3], Q[3], q;
extern int SIGN;
extern int Px, Rx;
extern int Errval, MErrval, EMErrval;
extern int k, TEMP;
extern int RItype, map;
/* updated variables */
extern int LIMIT, qbpp, bpp;

