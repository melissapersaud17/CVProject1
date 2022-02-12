#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Image::Image(){ // constructor
    // cout << "melissa" << endl;
}

void Image::setRows(int rows){
    this->numRows = rows;
}

void Image::setCols(int cols){
    this->numCols = cols;
}

void Image::setMin(int min){
    this->minVal = min;
}

void Image::setMax(int max){
    this->maxVal = max;
}

void Image::setThreshold(int threshold){
    this->thresholdValue = threshold;
}

int Image::getThreshold(){
    return this->thresholdValue;
}

int Image::getMax(){
    return this->maxVal;
}

void Image::setArray(int *histArray){
    this->histAry = histArray;
}

int *Image::getArray(){
   
    return histAry;
}

// compute histogram
void Image::ComputeHist(ifstream &inFile)
{
    string line;
    int number;
    istringstream iss;

    // *histAry[number] = *histAry[number] + 1;
    // cout << "calling ptr compute hist " << ptr << " " << histAry <<endl;
    
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            getline(inFile, line);

            iss.clear();
            iss.str(line);

            while (iss >> number){
                this->histAry[number] = this->histAry[number] + 1;
            }

        }
    }


   
}

void Image::printHist(ofstream& outFile1){ // will print to an outfile1 argv[3]

        int *pointer1 = (this->getArray());
        
        outFile1 << numRows << " " <<  numCols << " " << minVal << " " << maxVal <<endl;
        
        if(outFile1.is_open()){
            for (int i = 0; i < this->getMax() + 1; i++){
                outFile1 <<  i  << " " << pointer1[i] << endl;
            }
        }
}

void Image::dispHist(ofstream& outFile2){
    
        int *pointer1 = (this->getArray());
        
        outFile2 << numRows << " " <<  numCols << " " << minVal << " " << maxVal <<endl;
        
        if(outFile2.is_open()){
            for (int i = 0; i < this->getMax() + 1; i++){
                outFile2 <<  i  << " " << "(" << pointer1[i] << "):";
                
                if(pointer1[i] >= 70){
                    for(int x = 0; x < 70; x++){
                        outFile2 << "+";
                    }
                    outFile2 << endl;
                }else{
                    for(int y=0; y < pointer1[y]; y++){
                        outFile2 << "+";
                    }
                    outFile2 << endl;

                }


            }
        }
}