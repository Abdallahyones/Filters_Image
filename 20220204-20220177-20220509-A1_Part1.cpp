// FCAI - OOP Programming - 2023 - Assignment 1
// Program Name : CS213-2023-20220204-20220177-20220509-A1-Part1.cpp
// Last Modification Date : 9/10/2023
// Author1 : Abdullah Mohamed Abdullah Mohamed  ID : 20220204
// Author2 : Abdelrahman Fathy Mohamed Hammad   ID : 20220177
// Author3 : Omar Khaled Elsayed Hussien        ID : 20220509



#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "Filters_gray.h"


using namespace std;
const double  BY = 3.14285714286 ;
unsigned char image[SIZE][SIZE] ;
unsigned char new_image[SIZE][SIZE] , ans[SIZE][SIZE] ;

// new_image --> The new picture
// image --> Current picture (input user)

void loadImage ();
void saveImage ();


int main() {
    cout << "Ahlan ya user ya habibi\n";
    loadImage();
    char num = input_program();
    while (num){
        switch (num) {
            case '1':
                Black_White(image , new_image);
                break;
            case '2':
                Invert_Image(image , new_image);
                break;
            case '3' :
                Merge_filter(image , new_image);
                break;
            case '4':
                Flip_Image(image , new_image);
                break;
            case '5':
                Darken_lighten_filter(image , new_image);
                break;
            case '6':
                Rotate_Image(image , new_image);
                break;
            case '7':
                Detect_Image(image , new_image);
                break;
            case '8':
                Enlarge_Image(image , new_image);
                break;
            case '9':
                Shrink_Image(image , new_image);
                break;
            case 'a':
                Mirror_Image(image , new_image);
                break;
            case 'b':
                Shuffle_Image(image , new_image);
                break;
            case 'c':
                Blur(image, new_image);
                break;
            case 'd':
                Crop_Image(image , new_image);
                break;
            case 'e':
                Skew_Horizontally(image , new_image);
                break;
            case 'f':
                Skew_Vertically(image , new_image);
                break;
            case 's':
                saveImage();
                break;
            case '0':
                return 0 ;
        }
        num = input_program();
    }
    return 0 ;
}
void loadImage () {
    char imageFileName[100];

    // get gray scale image file name

    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image

    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage () {
    char imageFileName[100];

    // get gray scale image target file name

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image

    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, new_image);
}

