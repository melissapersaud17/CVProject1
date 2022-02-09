#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// void ComputeHist(ifstream inFile);

int main(int argc, char *argv[])
{ // argc= total number of arguments you entered; *argv[] = array of character pointers listing all the arguments

    Image imageObject;

    // Used to obtain 4 values from header
    ifstream inFile(argv[1]);
    string line;
    int number;
    istringstream iss;
    int imageHeader[4];

    if (inFile.good())
    {
        getline(inFile, line);

        if (inFile.good())
        {
            iss.clear();
            iss.str(line);

            int i = 0;

            while (iss >> number)
            { // only used for collecting the values from the image header
                // cout << number << endl;
                imageHeader[i] = number;
                i++;
                // cout << typeid(number).name() << endl;
            }

            imageObject.setRows(imageHeader[0]);
            imageObject.setCols(imageHeader[1]);
            imageObject.setMin(imageHeader[2]);
            imageObject.setMax(imageHeader[3]);
        }
    }

    int index = imageObject.getMax() + 1;
    int *histArray[index] = {new int(0)}; //array of pointers
   // int *ptr = histArray[0]; //ptr will look towards histAray[0]
    int *ptr= histArray[0];
    int n = *ptr + 12;
    
    // histArray[0] = {ptr};
    // cout << *histArray[0] << endl;
    // cout << *ptr << endl;
     cout << n << endl;


    
    //cout << sizeof(histArray) / sizeof(histArray[0]) << endl;
    // imageObject.setArray(histArray);
    // // cout << imageObject.getArray() << endl;

    // imageObject.ComputeHist(inFile);
    // cout << imageObject.getArray() << endl;

    return 0;
}

// void ComputeHist(ifstream inFile){

//     string line;
//     int number;
//     istringstream iss;

//     //int *histAry[maxVal + 1];

//        while(!inFile.eof()){
//         getline(inFile,line);

//         if(inFile.good()){
//             iss.clear();
//             iss.str(line);

//             while(iss >> number){ //only used for collecting the values from the image header
//                 cout << number << endl;
//                 //histAry[number]++;
//                 //cout << typeid(number).name() << endl;
//             }

//         }
//     }
// }
