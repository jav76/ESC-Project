//
// Created by Jaret on 12/2/2020.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void filter(bool approximation)
{
    float x1,x1p,x2,x2p,x3,x3p,x4,x4p,y,u;
    int k;
    int N=30;
    double coefA1[4], coefA2[4], coefA3[4], coefA4[4],
        coefB[4],
        coefC[4];

    //Open an Input File
    FILE *inputFile;
    inputFile=fopen("input.txt", "r");

    //Open an Output File
    char outputFileName[24];

    if (approximation)
    {
        strcpy(outputFileName, "outputApprox.txt");
        coefA1[0] = 0.9129;
        coefA1[1] = 0.1674;
        coefA1[2] = 0;
        coefA1[3] = 0;

        coefA2[0] = -0.1674;
        coefA2[1] = 0.9129;
        coefA2[2] = 0;
        coefA2[3] = 0;

        coefA3[0] = 0;
        coefA3[1] = 0;
        coefA3[2] = 0.8314;
        coefA3[3] = 0.0631;

        coefA4[0] = 0;
        coefA4[1] = 0;
        coefA4[2] = -0.0631;
        coefA4[3] = 0.8314;

        coefB[0] = -280.4633;
        coefB[1] = -178.6837;
        coefB[2] = 246.9775;
        coefB[3] = 735.9525;

        coefC[0] = 0.0026;
        coefC[1] = 0.0009;
        coefC[2] = 0.0025;
        coefC[3] = 0.0004;

    }
    else
    {
        strcpy(outputFileName, "outputExact.txt");
        coefA1[0] = 3.4885;
        coefA1[1] = -4.5922;
        coefA1[2] = 2.7013;
        coefA1[3] = -0.5988;

        coefA2[0] = 1;
        coefA2[1] = 0;
        coefA2[2] = 0;
        coefA2[3] = 0;

        coefA3[0] = 0;
        coefA3[1] = 1;
        coefA3[2] = 0;
        coefA3[3] = 0;

        coefA4[0] = 0;
        coefA4[1] = 0;
        coefA4[2] = 1;
        coefA4[3] = 0;

        coefB[0] = 1;
        coefB[1] = 0;
        coefB[2] = 0;
        coefB[3] = 0;

        coefC[0] = 0.0027;
        coefC[1] = 0.0005;
        coefC[2] = 0.0024;
        coefC[3] = 0.0001;
    }
    FILE *outputFile;
    outputFile=fopen(outputFileName,"w");

    //Initialize the State Variable to Zero
    x1=0;
    x2=0;
    x3=0;
    x4=0;


    for(k=0;k<N;k++)
    {
        fscanf(inputFile,"%f,",&u);
        //State-Update Equations
        x1p=coefA1[0]*x1 + coefA1[1]*x2 + coefA1[2]*x3 + coefA1[3]*x4 + coefB[0]*u;
        x2p=coefA2[0]*x1 + coefA2[1]*x2 + coefA2[2]*x3 + coefA2[3]*x4 + coefB[1]*u;
        x3p=coefA3[0]*x1 + coefA3[1]*x2 + coefA3[2]*x3 + coefA3[3]*x4 + coefB[2]*u;
        x4p=coefA4[0]*x1 + coefA4[1]*x2 + coefA4[2]*x3 + coefA4[3]*x4 + coefB[3]*u;
        //Output Equation
        y=coefC[0]*x1 + coefC[1]*x2 + coefC[2]*x3 + coefC[3]*x4 + 0*u;

        //Remember the New States (move from k to k+1)
        x1=x1p;
        x2=x2p;
        x3=x3p;
        x4=x4p;

        fprintf(outputFile,"%f, ", y);
        printf("%5.4f\n",y);
    }


    fclose(inputFile);
    fclose(outputFile);
}

int main()
{
    filter(true);
    filter(false);
}