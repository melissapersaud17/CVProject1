// header file - contains function prototype and variable declarations

#ifndef Image_H
#define Image_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Image
{
private:
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int *histAry;   
    int thresholdValue;

public:
    Image();
    void setRows(int rows);
    void setCols(int cols);
    void setMin(int min);
    void setMax(int max);
    void setThreshold(int threshold);
    int getThreshold();
    int getMax();
    void setArray(int *histArray);
    int *getArray();
    void ComputeHist(ifstream& inFile); //computes the histogram 
    void printHist(ofstream& outFile1);
    void dispHist(ofstream& outFile2);
};

#endif