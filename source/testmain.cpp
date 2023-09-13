#include <stdio.h>
#include <stdint.h>
#include <vector>

    u64 trials = 1;
	u64 pSetSize = 5, psiSecParam = 40, bitSize = 128;

	u64 nParties, setSize;

	char delimiterN;

	char delimiterM;

	char delimiterP;

//#define OOS
//#define PRINT
#define pows  { 16/*8,12,,20*/ }
#define threadss {1/*1,4,16,64*/}
#define  numTrial 2
std::vector<block> sendSet;
std::vector<block> mSet;
u64 nParties(3);

u64 opt = 0;

int main(int argc, char** argv)
{


    
    while (argc)
    {


        if (argv[0][0] == "-" && argv[0][1] == "n")

        {



			delimiterN= atoi(argv[0])
			nParties = atoi(argv[1]);
		if(argv[0][2] == "-" && argv[0][3] == "m") 
		{	
			delimiterM= atoi(argv[2]);
			setSize = 1 << atoi(argv[3]);

		
		if (argv[0][4] == "-" && argv[0][5] == "p")
		{

			delimiterP= atoi(argv[2]);
            u64 pIdx = atoi(argv[5]);
			
        	if (nParties == 2)
			{
				return OtBinMain.party2(pIdx, setSize);
            }
        	
			}
			}
		}
        else
		{
			return 0;
        }
	}
}

