/*

Example Elliptic Curve Diffie-Hellman program for 32-bit constrained environments. Uses point compression.
Stack-only memory allocation

Use with this mirdef.h header (for a PC using MS C)

#define MR_LITTLE_ENDIAN
#define MIRACL 32
#define mr_utype int
#define MR_IBITS 32
#define MR_LBITS 32
#define mr_unsign32 unsigned int
#define mr_dltype __int64
#define mr_unsign64 unsigned __int64
#define MR_STATIC 6
#define MR_ALWAYS_BINARY
#define MR_STRIPPED_DOWN
#define MR_GENERIC_MT
#define MAXBASE ((mr_small)1<<(MIRACL-1))
#define MR_BITSINCHAR 8
#define MR_COMBA 6
#define MR_GENERALIZED_MERSENNE
#define MR_SPECIAL
#define MR_SIMPLE_BASE
#define MR_SIMPLE_IO

In an embedded environment perhaps these should be defined as well..

#define MR_NO_STANDARD_IO
#define MR_NO_FILE_IO

Build the library from these modules (Example using MS C compiler)

mex 6 ms86 mrcomba
rem (mex 6 sse2 mrcomba) will be faster on most PCs that support SSE2 
cl /c /O2 /W3 mrcore.c
cl /c /O2 /W3 mrarth0.c
cl /c /O2 /W3 mrarth1.c
cl /c /O2 /W3 mrio1.c
cl /c /O2 /W3 mrbits.c
cl /c /O2 /W3 mrcurve.c
cl /c /O2 /W3 mrsroot.c
cl /c /O2 /W3 mrjack.c
cl /c /O2 /W3 mrlucas.c
cl /c /O2 /W3 mrarth2.c
cl /c /O2 /W3 mrmonty.c
cl /c /O2 /W3 mrcomba.c
cl /c /O2 /W3 mrxgcd.c
cl /c /O2 /W3 mrmuldv.c
cl /c /O2 /W3 mrebrick.c

rem
rem Create library 'miracl.lib'
del miracl.lib

lib /OUT:miracl.lib mrio1.obj mrmonty.obj mrcomba.obj mrxgcd.obj mrmuldv.obj
lib /OUT:miracl.lib miracl.lib mrbits.obj mrarth2.obj mrlucas.obj mrjack.obj
lib /OUT:miracl.lib miracl.lib mrarth0.obj mrarth1.obj mrcore.obj mrebrick.obj
lib /OUT:miracl.lib miracl.lib mrcurve.obj mrsroot.obj
del mr*.obj

rem Create the program

cl /O2 ecdhp.c miracl.lib

*/

#include <stdio.h>
#include <string.h>
#include "miracl.h"

/* !!!!!! THIS CODE AND THESE ROMS ARE NOW CREATED AUTOMATICALLY USING THE ROMAKER.C APPLICATION !!!!!!!! */
/* !!!!!! READ COMMENTS IN ROMAKER.C !!!!!! */

#define HEXDIGS (MIRACL/4)
#define CURVE_BITS 192

/* NIST p192 bit elliptic curve Y^2=X^3-3X+B (from secp192.ecs). 
   Here is stored P, B, the group order q, and the generator G(x,y) */

static const mr_small rom[]=
{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
0xC146B9B1,0xFEB8DEEC,0x72243049,0x0FA7E9AB,0xE59C80E7,0x64210519,
0xB4D22831,0x146BC9B1,0x99DEF836,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
0x82FF1012,0xF4FF0AFD,0x43A18800,0x7CBF20EB,0xB03090F6,0x188DA80E,
0x1E794811,0x73F977A1,0x6B24CDD5,0x631011ED,0xFFC8DA78,0x07192B95};

#define WINDOW 4

/* 32 precomputed points based on fixed generator G(x,y)        */
/* (created using romaker.c program with window size of 4)      */

/* These values are only correct if MR_SPECIAL is defined!      */

static const mr_small prom[]=
{0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,
0x82ff1012,0xf4ff0afd,0x43a18800,0x7cbf20eb,0xb03090f6,0x188da80e,
0x1e794811,0x73f977a1,0x6b24cdd5,0x631011ed,0xffc8da78,0x7192b95,
0x5d7c48d8,0xc39649c5,0x5a927c35,0xeb2cdfae,0xcba671fb,0x67e30cbd,
0xecbfbe7d,0x7a83cee1,0x6301577,0xce32d03c,0x5810f5c3,0xa93549c4,
0x66e3ead3,0x6f5ef889,0xdfc9bf1a,0xf29e6fea,0x452006e0,0xce216bb8,
0x927b3779,0x46b9092d,0xb5b80a20,0x1d0aeb4b,0x5aaec958,0xd98a2ee2,
0xc0a1e340,0xb19963d8,0x80d1090b,0x4730d4f4,0x184ac737,0x51a581d9,
0xe69912a5,0xecc56731,0x2f683f16,0x7cdfcea0,0xe0bb9f6e,0x5bd81ee2,
0xd4f43374,0xe4b15a2d,0xf292c341,0x757eea7,0xd0f8dc24,0xc730691,
0xbbf45e00,0xdf797890,0xe9de8708,0x8a9e83,0x9354de3e,0x31b24c31,
0xddf63aba,0xcb5ec043,0xf84f41e1,0xc94c21d9,0x61d24416,0xf0f40883,
0x406495f7,0xf37585b0,0x16bcd0ca,0xe5de3b5b,0xe13ea488,0x27853c1a,
0x8e8ae68f,0xd074232a,0xee29f7a9,0x749e528e,0x9716469f,0x611dea3,
0xd8043cc,0x66b867dd,0x3a727de6,0x6a654654,0x8338bdc9,0xf9546052,
0xc5d8f50,0xb6eb7193,0xb904b596,0x1c245c02,0x951f7513,0x4bc1f71,
0xbe34803d,0xa4d0916e,0x8c21962a,0x8bec948a,0xfd69f8d0,0x150096e7,
0xe71aac0c,0xbd44ffe8,0x4322d065,0x7d69a0b0,0xeca3ba2a,0x9f56d96c,
0x25a59dce,0xee59f0d1,0xc3f4575a,0x837d62dd,0x35de73d9,0xa4e07fb3,
0x1cf46ae2,0xec76760c,0xa33d44b0,0xff549832,0xf3185c11,0xe95ad210,
0x38ed372e,0x273e5ec5,0xb0ab1169,0x51d39136,0x8f3a27c8,0xa5ea86f6,
0x74d2d7d5,0x291237ea,0x56338e9b,0x953636ee,0x285c120c,0xda65e86,
0xf13c3233,0x1302f04c,0x978391b2,0xfc898ab9,0x3aa06272,0x26d65c2e,
0x18c5efe6,0xd50947a8,0xfe113c6c,0x45db23ae,0xe5bbe86d,0x91f199f2,
0x60fec064,0x376881b6,0x475daea4,0x387343e9,0xac8d8a19,0xeccd57e8,
0x5b510228,0xc9fef5b9,0x192ebcd6,0x374c0a4c,0xce6a83f9,0x2298f204,
0xf4c574d0,0x46e4b820,0xefeb2cc0,0x6d58644,0x10c3c949,0xe713a400,
0x2d64eedf,0x6178cb0e,0xb85e1f99,0x27af7d5e,0x6cb7be1f,0xd873ced7,
0x52a67f9c,0xefc9129c,0x6004d9ad,0xa3d7b957,0xdc41f8e2,0xfc599808,
0x7fdf928a,0xbb6c6b59,0xd7f93bf4,0xad167ef0,0x154e061c,0xfaa9e432,
0xd52c8f3f,0xc3d0d63,0xd5f7e08f,0x6101b2be,0xd6ae3cf3,0xd877cddd};


#define WORDS 6  /* Number of words per big variable 6*32 = 192 */

/* Note that in a real application a source of real random numbers would be required, to
   replace those generated by MIRACL's internal pseudo-random generator "bigbits"  
   Alternatively from a truly random and unguessable seed, use MIRACL's strong random 
   number generator */

/* Elliptic Curve Diffie-Hellman, using point compression to minimize bandwidth, 
   and precomputation to speed up off-line calculation */

int main()
{
    int promptr;
    epoint *PB;
    big A,B,p,a,b,pa,pb,key;
    ebrick binst;
    miracl instance;      /* create miracl workspace on the stack */

/* Specify base 16 here so that HEX can be read in directly without a base-change */

    miracl *mip=mirsys(&instance,WORDS*HEXDIGS,16); /* size of bigs is fixed */
    char mem_big[MR_BIG_RESERVE(8)];          /* we need 8 bigs... */
    char mem_ecp[MR_ECP_RESERVE(1)];          /* ..and 1 elliptic curve points */
 	memset(mem_big, 0, MR_BIG_RESERVE(8));    /* clear the memory */
	memset(mem_ecp, 0, MR_ECP_RESERVE(1));

    A=mirvar_mem(mip, mem_big, 0);       /* Initialise big numbers */
    B=mirvar_mem(mip, mem_big, 1);
    pa=mirvar_mem(mip, mem_big, 2);
    pb=mirvar_mem(mip, mem_big, 3);
    key=mirvar_mem(mip, mem_big, 4);
    a=mirvar_mem(mip, mem_big, 5);
    b=mirvar_mem(mip, mem_big, 6);
    p=mirvar_mem(mip, mem_big, 7);

    PB=epoint_init_mem(mip, mem_ecp, 0); /* initialise Elliptic Curve points */

    irand(mip, 3L);                      /* change parameter for different random numbers */

    promptr=0;
    init_big_from_rom(p,WORDS,rom,WORDS*5,&promptr);  /* Read in prime modulus p from ROM   */
    init_big_from_rom(B,WORDS,rom,WORDS*5,&promptr);  /* Read in curve parameter B from ROM */
                                                 /* don't need q or G(x,y) (we have precomputed table from it) */

    convert(mip,-3,A);                           /* set A=-3 */

/* Create precomputation instance from precomputed table in ROM */

    ebrick_init(&binst,prom,A,B,p,WINDOW,CURVE_BITS);

/* offline calculations */

    bigbits(mip,CURVE_BITS,a);  /* A's random number */
    mul_brick(mip,&binst,a,pa,pa);    /* a*G =(pa,ya) */

    bigbits(mip,CURVE_BITS,b);  /* B's random number */
    mul_brick(mip,&binst,b,pb,pb);    /* b*G =(pb,yb) */

/* swap X values of point */

/* online calculations */
    ecurve_init(mip,A,B,p,MR_PROJECTIVE);
    epoint_set(mip,pb,pb,0,PB); /* decompress PB */
    ecurve_mult(mip,a,PB,PB);
    epoint_get(mip,PB,key,key);

/* since internal base is HEX, can use otnum instead of cotnum - avoiding a base change */
#ifndef MR_NO_STANDARD_IO
printf("Alice's Key= ");
otnum(mip,key,stdout);
#endif

    epoint_set(mip,pa,pa,0,PB); /* decompress PA */
    ecurve_mult(mip,b,PB,PB);
    epoint_get(mip,PB,key,key);

#ifndef MR_NO_STANDARD_IO
printf("Bob's Key=   ");
otnum(mip,key,stdout);
#endif

/* clear the memory */

	memset(mem_big, 0, MR_BIG_RESERVE(8));
	memset(mem_ecp, 0, MR_ECP_RESERVE(1));

	return 0;
}
