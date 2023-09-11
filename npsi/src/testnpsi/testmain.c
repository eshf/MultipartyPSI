#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv)
{

    uint64_t trials = 1;
	uint64_t pSetSize = 5, psiSecParam = 40, bitSize = 128;

	uint64_t nParties, setSize;

	char delimiterN;

	char delimiterM;

	char delimiterP;
    
    while (argc)
    {
        if (argv[0][0] == "-" && argv[0][1] == "n")

        {
			
			delimiterN= atoi(argv[0]);
			nParties = atoi(argv[1]);
		if(argv[0][2] == "-" && argv[0][3] == "m") 
		{	
			delimiterM= atoi(argv[2]);
			setSize = 1 << atoi(argv[3]);

		
		if (argv[0][4] == "-" && argv[0][5] == "p")
		{

			delimiterP= atoi(argv[2]);
            uint64_t pIdx = atoi(argv[5]);
			
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

