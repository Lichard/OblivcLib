#include<stdio.h>
#include<obliv.h>
#include"testStack.h"

int main(int argc, char* argv[])
{
    ProtocolDesc pd;
    protocolIO io;
	
    if(argc<3)
    {
        if(argc<2) fprintf(stderr, "Party missing\n");
        else fprintf(stderr, "data missing");
		fprintf(stderr, "Usage: %s <1|2> <string>\n", argv[0]);
        return 1;
    }
	sscanf(argv[2], "%s[10]", io.data); 
    protocolUseStdio(&pd);
    setCurrentParty(&pd, argv[1][0]=='1'?1:2);
    execYaoProtocol(&pd, hamming, &io);
	fprintf(stderr,"Gate Count: %u\n",yaoGateCount());
    cleanupProtocol(&pd);
    fprintf(stderr, "Hamming Distance: %d\n", io.hammingDist);
}
