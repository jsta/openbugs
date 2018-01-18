#include "OpenBUGS.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
    int len, res;
    char *scriptcmd = "BugsEmbed.isScript := TRUE";
    if (argc > 1) { 
	if (strcmp(argv[1], "-s") == 0) {
	    len = strlen(scriptcmd);
	    CmdInterpreter(&scriptcmd, &len, &res);
	}
    }
    CLI();
}

