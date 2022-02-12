#include "Image.h"
#include "Image.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){ // argc= total number of arguments you entered; *argv[] = array of character pointers listing all the arguments

    Image imageObject;

    // Used to obtain values from the text file
    string inputName = argv[1];
    ifstream inFile;
    inFile.open(inputName);

    //this sets the threshold value that we pass in
    char *threspointer = argv[2];
    int thresholdValue = atoi(threspointer);
    imageObject.setThreshold(thresholdValue);

    //outFile 1
    string outName1 = argv[3];
    ofstream outFile1;
    outFile1.open(outName1);

    //outFile 2
    string outName2 = argv[4];
    ofstream outFile2;
    outFile2.open(outName2);

    //outFile 3
    string outName3 = argv[5];
    ofstream outFile3;
    outFile3.open(outName3);

    //outFile 4
    string outName4 = argv[6];
    ofstream outFile4;
    outFile4.open(outName4);

    //Variables are used to look at the first line of the text file
    int number;
    string line;
    istringstream iss;

    //array to hold the values for numRows, numCols, minVal, maxVal
    int imageHeader[4];

    if (inFile.good()){
        getline(inFile, line);

        //if (inFile.good()){
            iss.clear();
            iss.str(line);

            int i = 0;

            while (iss >> number){ // only used for collecting the values from the image header
                imageHeader[i] = number;
                i++;
            }

            imageObject.setRows(imageHeader[0]);
            imageObject.setCols(imageHeader[1]);
            imageObject.setMin(imageHeader[2]);
            imageObject.setMax(imageHeader[3]);
     //   }
    }

    int index = imageObject.getMax() + 1;
    int histArray[index] = {0}; // array of pointers; will be an array of pointers
    int *pointer = histArray;
    // int *ptr = histArray[0]; //ptr will look towards histAray[0]
    // int *ptr= histArray[0];
    // int n = *ptr + 1;

    // histArray[0] = {ptr};
    // cout << *histArray[0] << endl;
    // cout << *ptr << endl;
    // cout << n << endl;

    //cout << sizeof(histArray) / sizeof(histArray[0]) << endl;
    imageObject.setArray(histArray); // we pass this to histArray image object
    // // cout << imageObject.getArray() << endl;

    imageObject.ComputeHist(inFile);

    imageObject.printHist(outFile1);

    imageObject.dispHist(outFile2);

    //close inFile & reopen it
    inFile.close();
    inFile.open(inputName);

    imageObject.threshold(inFile, outFile3, outFile4, thresholdValue);

    //closed all files
    inFile.close();
    outFile1.close(); 
    outFile2.close();
    outFile3.close();
    outFile4.close();


    // int *pointer1 = (imageObject.getArray());

    // for (int i = 0; i < index; i++){
    //     cout << "value at index " << i  << " " << pointer1[i] << endl;
    // }

    return 0;
}
