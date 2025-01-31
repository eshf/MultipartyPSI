/*
 *   MIRACL compiler/hardware definitions - mirdef.h
 */

#define MR_LITTLE_ENDIAN
#define MIRACL 32
#define mr_utype int
#define MR_IBITS 32
#define MR_LBITS 32
#define mr_unsign32 unsigned int
#define mr_dltype __int64
#define mr_unsign64 unsigned __int64
#define MR_STATIC 12
#define MR_ALWAYS_BINARY
#define MR_NOASM
#define MR_STRIPPED_DOWN
#define MR_GENERIC_MT
#define MAXBASE ((mr_small)1<<(MIRACL-1))
#define MR_BITSINCHAR 8
#define MR_SHORT_OF_MEMORY
#define MR_AFFINE_ONLY
#define MR_NOSUPPORT_COMPRESSION
