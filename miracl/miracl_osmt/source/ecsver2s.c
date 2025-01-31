/*
 *   Digital Signature Standard (DSS)
 *
 *   Elliptic Curve Variation GF(2^m) - See Dr. Dobbs Journal April 1997
 *
 *   This program verifies the signature given to a <file> in
 *   <file>.ecs generated by program ecsign2
 * 
 *   The curve is y^2+xy = x^3+Ax^2+B over GF(2^m) using a trinomial or 
 *   pentanomial basis (t^m+t^a+1 or t^m+t^a+t^b+t^c+1), These parameters
 *   can be generated using the findbase.cpp example program, or taken from tables
 *   provided, for example in IEEE-P1363 Annex A
 *
 *   The file common2.ecs is presumed to exist and contain 
 *   {m,A,B,q,x,y,a,b,c} where A and B are parameters of the equation 
 *   above, (x,y) is an initial point on the curve, {m,a,b,c} are the field 
 *   parameters, (b is zero for a trinomial) and q is the order of the 
 *   (x,y) point, itself a large prime. The number of points on the curve is 
 *   cf.q where cf is the "co-factor", normally 2 or 4.
 *  
 *   This program is written for static mode.
 *   For a 163-bit modulus p, MR_STATIC could be defined as 6 in mirdef.h
 *   for a 32-bit processor, or 11 for a 16-bit processor (11*16 > 163).
 *   The system parameters can be found in the file common2.ecs
 *   Assumes MR_GENERIC_MT is defined in mirdef.h
 */

#include <stdio.h>
#include "miracl.h"
#include <stdlib.h>
#include <string.h>

void strip(char *name)
{ /* strip off filename extension */
    int i;
    for (i=0;name[i]!='\0';i++)
    {
        if (name[i]!='.') continue;
        name[i]='\0';
        break;
    }
}

static void hashing(miracl *mip,FILE *fp,big hash)
{ /* compute hash function */
    char h[20];
    sha sh;
    int i,ch;
    shs_init(&sh);
    while ((ch=fgetc(fp))!=EOF) shs_process(&sh,ch);
    shs_hash(&sh,h);
    bytes_to_big(mip,20,h,hash);
}

int main()
{
    FILE *fp;
    int ep,m,a,b,c;
    epoint *g,*public;
    char ifname[50],ofname[50];
    big a2,a6,q,x,y,v,u1,u2,r,s,hash;
    miracl instance;
    miracl *mip=&instance;
    char mem[MR_BIG_RESERVE(11)];           /* reserve space on the stack for 11 bigs */
    char mem1[MR_ECP_RESERVE(2)];           /* and two elliptic curve points         */
    memset(mem,0,MR_BIG_RESERVE(11));
    memset(mem1,0,MR_ECP_RESERVE(2));

/* get public data */
    fp=fopen("common2.ecs","rt");
    if (fp==NULL)
    {
        printf("file common2.ecs does not exist\n");
        return 0;
    }
    fscanf(fp,"%d\n",&m);

    mip=mirsys(mip,MR_ROUNDUP(abs(m),4),16);
    a2=mirvar_mem(mip,mem,0);
    a6=mirvar_mem(mip,mem,1);
    q=mirvar_mem(mip,mem,2);
    x=mirvar_mem(mip,mem,3);
    y=mirvar_mem(mip,mem,4);
    v=mirvar_mem(mip,mem,5);
    u1=mirvar_mem(mip,mem,6);
    u2=mirvar_mem(mip,mem,7);
    s=mirvar_mem(mip,mem,8);
    r=mirvar_mem(mip,mem,9);
    hash=mirvar_mem(mip,mem,10);

    innum(mip,a2,fp);
    innum(mip,a6,fp);
    innum(mip,q,fp);
    innum(mip,x,fp);
    innum(mip,y,fp);

    fscanf(fp,"%d\n",&a);
    fscanf(fp,"%d\n",&b);
    fscanf(fp,"%d\n",&c);

    fclose(fp);

    ecurve2_init(mip,m,a,b,c,a2,a6,FALSE,MR_PROJECTIVE);  /* initialise curve */
    g=epoint_init_mem(mip,mem1,0);
    epoint2_set(mip,x,y,0,g); /* initialise point of order q */

/* get public key of signer */
    fp=fopen("public.ecs","rt");
    if (fp==NULL)
    {
        printf("file public.ecs does not exist\n");
        return 0;
    }
    fscanf(fp,"%d",&ep);
    innum(mip,x,fp);
    fclose(fp);

    public=epoint_init_mem(mip,mem1,1);
    epoint2_set(mip,x,x,ep,public);  /* decompress */

/* get message */
    printf("signed file = ");
    gets(ifname);
    strcpy(ofname,ifname);
    strip(ofname);
    strcat(ofname,".ecs");
    if ((fp=fopen(ifname,"rb"))==NULL)
    { /* no message */
        printf("Unable to open file %s\n",ifname);
        return 0;
    }
    hashing(mip,fp,hash);
    fclose(fp);
    fp=fopen(ofname,"rt");
    if (fp==NULL)
    { /* no signature */
        printf("signature file %s does not exist\n",ofname);
        return 0;
    }
    innum(mip,r,fp);
    innum(mip,s,fp);
    fclose(fp);
    if (mr_compare(r,q)>=0 || mr_compare(s,q)>=0)
    {
        printf("Signature is NOT verified\n");
        return 0;
    }
    xgcd(mip,s,q,s,s,s);
    mad(mip,hash,s,s,q,q,u1);
    mad(mip,r,s,s,q,q,u2);

    ecurve2_mult2(mip,u2,public,u1,g,g);
    epoint2_get(mip,g,v,v);
    divide(mip,v,q,q);
    if (mr_compare(v,r)==0) printf("Signature is verified\n");
    else                 printf("Signature is NOT verified\n");
/* clear all memory used */
    memset(mem,0,MR_BIG_RESERVE(11));
    memset(mem1,0,MR_ECP_RESERVE(2));

    return 0;
}

