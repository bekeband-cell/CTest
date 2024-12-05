

#include <stdio.h> // define the header file
#include <math.h>

const char *outfile_name = "fekvorendor.txt";

const int MAX_SAMPLE = 1000;

const float h = 300;
const float alpha = 30;
const float sz = 200;

FILE *outfile;
int main()
{
    float nextvalue;
    outfile = fopen(outfile_name, "w+");
    if (outfile == NULL)
    {
        printf("Nem hozható létre %s", outfile_name); // print the statement.
        return 1;
    }

    fprintf(outfile, "%d ", MAX_SAMPLE);
    // egyenes szakasz
    for (int i = 0; i < 100; i++)
    {
        fprintf(outfile, "%f ", 0);
    }
    // felfutás
    for (int i = 0; i < 300; i++)
    {
        nextvalue += atan(alpha) / 10;
        fprintf(outfile, "%f ", nextvalue);
    }
    // plató
    for (int i = 0; i < 200; i++)
    {
        fprintf(outfile, "%f ", nextvalue);
    }
    // lefutás
    for (int i = 0; i < (300); i++)
    {
        nextvalue -= atan(alpha) / 10;
        fprintf(outfile, "%f ", nextvalue);
    }
    // egyenes szakasz
    for (int i = 0; i < 100; i++)
    {
        fprintf(outfile, "%f ", 0);
    }

    fclose(outfile);
}