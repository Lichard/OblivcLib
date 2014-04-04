#include<stdio.h>
#include<obliv.h>
#include"testStack.h"

int main(int argc, char*argv[])
{
    ProtocolDesc pd;
    protocolIO io;
	/*
    if(argc<3)
    {
        if(argc<2) fprintf(stderr, "Party missing\n");
        else fprintf(stderr, "data missing");
        return 1;
    }
    else if(argc>12) 
    {
        fprintf(stderr, "Too many entries");
        return 1;
    }
	*/
    io.size = argc-2;
	int i;
    for(i=2; i<argc; i++)
        sscanf(argv[i], "%d",&io.data[i]); 
	
    protocolUseStdio(&pd);
    setCurrentParty(&pd, argv[1][0]=='1'?1:2);
    execYaoProtocol(&pd, testStack, &io);
    cleanupProtocol(&pd);
    //fprintf(stderr, "Result: %d\n", io.hammingDist);
	fprintf(stderr, "Finished running\n");
}
