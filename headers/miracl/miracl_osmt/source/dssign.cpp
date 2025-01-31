/*
 *   Digital Signature Algorithm (DSA)
 *
 *   See Communications ACM July 1992, Vol. 35 No. 7
 *   This new standard for digital signatures has been proposed by 
 *   the American National Institute of Standards and Technology (NIST)
 *   under advisement from the National Security Agency (NSA). 
 *
 *   This program asks for the name of a <file>, computes its message digest,
 *   signs it, and outputs the signature to a file <file>.dss. It is assumed 
 *   that the common values p, q and g, as well as the private key of the 
 *   signer have been previously generated by the dssgen program
 *
 *   Requires: big.cpp
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include "big.h"

using namespace std;

Miracl precision(200,256);

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

static Big hash(ifstream &fp)
{ /* compute hash function */
    char ch,s[20];
    int i;
    Big h;
    sha sh;
    shs_init(&sh);
    forever 
    { /* read in bytes from message file */
        fp.get(ch);
        if (fp.eof()) break;
        shs_process(&sh,ch);
    }
    shs_hash(&sh,s);
    h=from_binary(20,s);
    return h;
}

int main()
{
    ifstream common("common.dss");    /* construct file I/O streams */
    ifstream private_key("private.dss");
    ifstream message;
    ofstream signature;
    char ifname[13],ofname[13];
    Big p,q,g,x,r,s,k,h;
    long seed;
    int bits;
    miracl *mip=&precision;

/* randomise */
    cout << "Enter 9 digit random number seed  = ";
    cin >> seed;
    irand(seed);

/* get common data */
    common >> bits;
    mip->IOBASE=16;
    common >> p >> q >> g;
    mip->IOBASE=10;

/* calculate r - this can be done off-line, 
   and hence amortized to almost nothing   */
    k=rand(q);
    r=pow(g,k,p);   /* see brick.cpp for method to speed this up */
    r%=q;

/* get private key of signer */
    private_key >> x;

/* get message to be signed */
    cout << "file to be signed = " ;
    cin >> ifname;

    strcpy(ofname,ifname);
    strip(ofname);
    strcat(ofname,".dss");
    message.open(ifname,ios::binary|ios::in);
    if (!message)
    {
        cout << "Unable to open file " << ifname << "\n";
        return 0;
    }
    h=::hash(message);

/* calculate s */
    k=inverse(k,q);
    s=((h+x*r)*k)%q;
    signature.open(ofname);
    signature << r << endl;
    signature << s << endl;
    return 0;
}

