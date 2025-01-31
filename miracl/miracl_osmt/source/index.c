/*
 *   Test program to find discrete logarithms using Pollard's rho method.
 *   Suitable primes are generated by "genprime" program
 *
 *   See "Monte Carlo Methods for Index Computation"
 *   by J.M. Pollard in Math. Comp. Vol. 32 1978 pp 918-924
 */

#include <stdio.h>
#include <stdlib.h>
#include "miracl.h"

#define NPRIMES 10
#define PROOT 2

static big p,p1,order,lim1,lim2;
static BOOL flag=FALSE;

void iterate(big x,big q,big r,big a,big b)
{ /* apply Pollards random mapping */
    if (mr_compare(x,lim1)<0)
    {
        mad(x,q,q,p,p,x);
        incr(a,1,a);
        if (mr_compare(a,order)==0) zero(a);
        return;
    }
    if (mr_compare(x,lim2)<0)
    {
        mad(x,x,x,p,p,x);
        premult(a,2,a);
        if (mr_compare(a,order)>=0) subtract(a,order,a);
        premult(b,2,b);
        if (mr_compare(b,order)>=0) subtract(b,order,b);
        return;
    }
    mad(x,r,r,p,p,x);
    incr(b,1,b);
    if (mr_compare(b,order)==0) zero(b);
}

long rho(big q,big r,big m,big n)
{ /* find q^m = r^n */
    long iter,rr,i;
    big ax,bx,ay,by,x,y;
    ax=mirvar(0);
    bx=mirvar(0);
    ay=mirvar(0);
    by=mirvar(0);
    x=mirvar(1);
    y=mirvar(1);
    iter=0L;
    rr=1L;
    do
    { /* Brent's Cycle finder */
        copy(y,x);
        copy(ay,ax);
        copy(by,bx);
        rr*=2;
        for (i=1;i<=rr;i++)
        {
            iter++;
            iterate(y,q,r,ay,by);
            if (mr_compare(x,y)==0) break;
        }
    } while (mr_compare(x,y)!=0);

    subtract(ax,ay,m);
    if (size(m)<0) add(m,order,m);
    subtract(by,bx,n);
    if (size(n)<0) add(n,order,n);
    mirkill(y);
    mirkill(x);
    mirkill(by);
    mirkill(ay);
    mirkill(bx);
    mirkill(ax);
    return iter;
}

int main()
{
    int i,id,np;
    long iter;
    big pp[NPRIMES],rem[NPRIMES];
    big m,n,Q,R,q,w,x;
    FILE *fp;
    big_chinese bc;
    miracl *mip=mirsys(50,0);
    for (i=0;i<NPRIMES;i++) 
    {
        pp[i]=mirvar(0);
        rem[i]=mirvar(0);
    }
    q=mirvar(0);
    Q=mirvar(0);
    R=mirvar(0);
    w=mirvar(0);
    m=mirvar(0);
    n=mirvar(0);
    x=mirvar(0);
    p=mirvar(0);
    p1=mirvar(1);
    order=mirvar(0);
    lim1=mirvar(0);
    lim2=mirvar(0);
    if ((fp=fopen("prime.dat","rt"))==NULL)
    {
        printf("Unable to find prime.dat\n");
        return 0;
    }
    fscanf(fp,"%d\n",&np);
    for (i=0;i<np;i++) cinnum(pp[i],fp);
    fclose(fp);
    for (i=0;i<np;i++) multiply(p1,pp[i],p1);
    incr(p1,1,p);
    if (!isprime(p))
    {
        printf("Huh - modulus is not prime!");
        return 0;
    }
    subdiv(p,3,lim1);
    premult(lim1,2,lim2);
    printf("solve discrete logarithm problem - using Pollard rho method\n");
    printf("finds x in y=%d^x mod p, given y, for fixed p\n",PROOT);
    printf("p=");
    cotnum(p,stdout);
    printf("given factorisation of p-1 = \n2");
    for (i=1;i<np;i++) 
    {
        cotstr(pp[i],mip->IOBUFF);
        printf("*%s",mip->IOBUFF);
    }
    printf("\n\nEnter y= ");
    cinnum(q,stdin);
    crt_init(&bc,np,pp);
    for (i=0;i<np;i++)
    { /* accumulate solutions for each pp */
        copy(p1,w);
        divide(w,pp[i],w);
        powmod(q,w,p,Q);
        powltr(PROOT,w,p,R);
        copy(pp[i],order);
        iter=rho(Q,R,m,n);
        xgcd(m,order,w,w,w);
        mad(w,n,n,order,order,rem[i]);
        printf("%ld iterations needed\n",iter);
    }
    crt(&bc,rem,x);   /* apply Chinese remainder thereom */
    printf("Discrete log of y= ");
    cotnum(x,stdout);
    powltr(PROOT,x,p,w);
    printf("check = ");
    cotnum(w,stdout);
    crt_end(&bc);
    return 0;
}

