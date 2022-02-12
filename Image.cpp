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
              // cout << "number is " << number <<  endl;
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
    
        int *pointer2 = (this->getArray());
        
        outFile2 << numRows << " " <<  numCols << " " << minVal << " " << maxVal <<endl;
        
        if(outFile2.is_open()){
            for (int i = 0; i < this->getMax() + 1; i++){
                outFile2 <<  i  << " " << "(" << pointer2[i] << "):";
                
                if(pointer2[i] >= 70){
                    for(int x = 0; x < 70; x++){
                        outFile2 << "+";
                    }
                    outFile2 << endl;
                }else{
                    
                    for(int m=0; m < pointer2[i]; m++){
                        //cout << pointer2[i] << endl;
                        outFile2 << "+";
                       //cout << "inside the for loop " <<endl;
                    }

                   // outFile2 << "after the for loop " <<endl;
                    outFile2 << endl;
                }
            }
        }
}

//when you call the threshold method on image object it will write to outFile3 and outFile4 
void Image::threshold(ifstream& inFile, ofstream& outFile3, ofstream& outFile4, int thrVal){
    //step 1 minVal = 0 and maxVal = 1
    this->setMin(0);
    this->setMax(1);

    outFile3 << numRows << " " <<  numCols << " " << minVal << " " << maxVal <<endl;
    outFile4 << numRows << " " <<  numCols << " " << minVal << " " << maxVal <<endl;

    string line;
    int number;
    istringstream iss;
    bool firstLine = true;
    
    if (inFile.is_open()){
        getline(inFile, line);  //this gets the first line so the program can look at the second line 

        while (!inFile.eof()){
            getline(inFile, line);

            iss.clear();
            iss.str(line);

             while (iss >> number){

                //prints the first line only
    
                //cout << "number is " << number << endl;
                 if(number >= thrVal){
                    //cout << " entered the if statment" <<endl;
                    outFile3 << "1 ";
                    outFile4 << "1 ";
                }else{
                   // cout << "entered the else statement " <<endl;
                    outFile3 << "0 ";
                    outFile4 << ". ";   
                }

            }

            outFile3 <<endl;
            outFile4 << endl;

        }
    }
}

