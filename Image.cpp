#include"Image.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Image::Image(){ //constructor
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

void Image::setArray(int **histArray){
    this->histAry = *histArray;
}

int *Image::getArray(){
    return histAry;
}

//compute histogram
void Image::ComputeHist(ifstream& inFile){

    string line;
    int number;
    istringstream iss;
    int i = 0;

    if(inFile.is_open()){
        while(!inFile.eof()){
            getline(inFile,line);
            
            // if(inFile.good()){
                iss.clear();
                iss.str(line);
                //cout << "line " << i << " " << line << endl; 
                i++;

                // cout << "printing out array" <<  this->histAry <<endl;;
                
                while(iss >> number){
                    //iss >> number;
                    //cout << number << endl;
                    //this->histAry[number]++;
                    //cout << this->histAry[number];
                }
                
                //cout << inFile.eof() << endl;
                 //cout << inFile.good() << endl;
                
                //    // this->histAry[number]++;
                // }
           // }
        }

     //           cout << inFile.eof() << endl;

    }

}