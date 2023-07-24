#include <stdio.h>

using namespace std;



#include <numeric>
#include <iostream>



int main() {
    printf("Hello NPSI\n");
    return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE void party3(int argc, char ** argv) {
    printf("MyFunction Called\n");
}