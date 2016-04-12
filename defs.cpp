#include "defs.h"
#include <stdio.h>

void writer(const char* msg)
{
    FILE *fp = fopen(LOG_FILE, "a");
    if (!fp)
    {
        return;
    } else {
        fprintf(fp, "%s", msg);
        fclose(fp);
    }
}
