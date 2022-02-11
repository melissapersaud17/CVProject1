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
    int i = 0;
    // *histAry[number] = *histAry[number] + 1;
    // cout << "calling ptr compute hist " << ptr << " " << histAry <<endl;
    
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            getline(inFile, line);

            // if(inFile.good()){
            iss.clear();
            iss.str(line);
            //cout << "line " << i << " " << line << endl;
            i++;

            // cout << "printing out array" <<  this->histAry <<endl;;

            
            while (iss >> number){
                this->histAry[number] = this->histAry[number] + 1;
               //cout << "value at index 8 " << this->histAry[8] <<endl;
                // iss >> number;
                //cout << "number is " << number << endl;
                //cout << "number in this array should be (0) = " << this->histAry[number] <<endl;
                 //cout << this->histAry[number] << endl;
                // cout << this->histAry[number];
            }

            // cout << inFile.eof() << endl;
            // cout << inFile.good() << endl;

            //    // this->histAry[number]++;
            // }
            // }
        }

        //           cout << inFile.eof() << endl;
    }

   
}