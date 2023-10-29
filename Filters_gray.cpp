// FCAI - OOP Programming - 2023 - Assignment 1
// Program Name : CS213-2023-20220204-20220177-20220509-A1-Part1.cpp
// Last Modification Date : 9/10/2023
// Author1 : Abdullah Mohamed Abdullah Mohamed  ID : 20220204
// Author2 : Abdelrahman Fathy Mohamed Hammad   ID : 20220177
// Author3 : Omar Khaled Elsayed Hussien        ID : 20220509

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include "bmplib.h"
#include "Filters_gray.h"




using namespace std;

unsigned char image_marge[SIZE][SIZE];


// new_image --> The new picture
// image --> Current picture (input user)

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1 , 2 , 0 , -2 , 0 , -2 , -2 , 2 , 2 , -2 , -2, -1 , -1 ,2 , 2, 1 , 1 };
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1 , 0 , -2 , 0 , 2 , -2 , 2 , -2 , 2 , -1 , 1 ,-2 , 2 ,-1 , 1 ,-2 , 2 };


bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < SIZE && y < SIZE ;
}   // check if the point(in pixle ) valid


// interface of program
char input_program (){
    // interface of program
    char num ;
    cout << "Please select a filter to apply or 0 to exit: \n" ;
    cout << "1-\tBlack & White Filter\n"
         << "2-\tInvert Filter\n"
         << "3-\tMerge Filter\n"
         << "4-\tFlip Image\n"
         << "5-\tDarken and Lighten Image\n"
         << "6-\tRotate Image\n"
         << "7-\tDetect Image Edges\n"
         << "8-\tEnlarge Image\n"   // abdo
         << "9-\tShrink Image\n"  // omar
         <<"a-\tMirror 1/2 Image\n"
         <<"b-\tShuffle Image\n"  // abdo
         <<"c-\tBlur Image\n"  // omar
         <<"d-\tCrop Image\n"
         <<"e-\tSkew Image Right\n" // abdo
         <<"f-\tSkew Image Up\n"   // omar
         <<"s-\tSave the image to a file\n"
         <<"0-\tExit \n";
    cin >> num ;
    return num;
}

void Black_White(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){

    // filter for conversion image to  black and white

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0 ; j < SIZE ; j++) {
            if (image[i][j] > 128 ){
                new_image[i][j] = 255 ;
            }else{
                new_image[i][j] = 0;
            }
            image[i][j] = new_image[i][j];
        }
    }
}
void Invert_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // filter for invert image by complement

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0 ; j < SIZE ; j++) {
            new_image[i][j] = 255 - image[i][j];
            image[i][j] = new_image[i][j];
        }
    }
}
void Merge_filter(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // the input new of image for merge of them

    char imageFileName[100];
    cout << "Please enter name of image file to merge with:  " ;
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image_marge);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            // The program will create a new image, with every pixel equal the average gray level of the corresponding pixels in the images to merge
            int avr = image[i][j] + image_marge[i][j] ;
            avr /= 2;
            new_image[i][j] = image[i][j] = avr;
        }
    }
}
void Flip_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    int num  ;
    cout << "1-\tFlip horizontally \n2-\tFlip vertically\n" ;
    cin >> num ;
    switch (num) {
        case 1: // Flip horizontally
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[i][j] = image[255- i][j];
                }
            }
            break;
        case 2: // Flip vertically
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[i][j] = image[i][255 - j];
                }
            }
            break;
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}
void Darken_lighten_filter(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    int num ;
    // input case
    cout<<"Would you like to darken or lighten the image?\n" ;
    cout << "1-\tDarken\n"
         << "2-\tLighten\n";
    cin >> num ;
    switch (num) {
        case 1 : // make the image darker
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    new_image[i][j] = image[i][j] = image[i][j]/2;
                }
            }
            break;
        case 2 : // make the image lighten
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    int x = image[i][j] + 50;
                    new_image[i][j] = image[i][j] = min(255, x); // to make sure within the range
                }
            }
            break;
    }
}
void Rotate_90(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    //This filter allows the user to rotate the image clockwise by 90º
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE-1 ; ~j ; j--) {
            new_image[i][SIZE-j-1] = image[j][i];
        }
    }
}
void Rotate_180(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // This filter allows the user to rotate the image clockwise by 180º
    for (int i = SIZE-1 ; ~i; i--) {
        for(int j = SIZE-1 ; ~j; j--) {
            new_image[SIZE-i-1][SIZE-j-1] = image[i][j];
        }
    }
}
void Rotate_270(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // This filter allows the user to rotate the image clockwise by 270º
    for (int i = SIZE-1 ; ~i; i--) {
        for (int j = 0  ; j < SIZE ; j++) {
            new_image[SIZE-i-1][j] = image[j][i];
        }
    }
}
void Rotate_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // This filter allows the user to input degree rotate
    int degree ;
    cout << "Rotate (90), (180) or (270) degrees? " ;
    cin >> degree;
    switch (degree) {
        case 90:
            Rotate_90(image , new_image);
            break;
        case 180:
            Rotate_180(image , new_image);
            break;
        case 270:
            Rotate_270(image , new_image);
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE ; i++){
        for (int j  = 0 ; j < SIZE ; j++){
            image[i][j] = new_image[i][j];
        }
    }
}

void Detect_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    Black_White(image , new_image);      // filter for conversion image to  black and white
    bool chek[SIZE][SIZE];

    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++ ){
            chek[i][j] = false;
            for (int g = 0 ; g < 4 ; g++){
                int nx = i+dx[g] , ny = j + dy[g];
                if (valid(nx , ny) && new_image[i][j] == 0  && image[nx][ny] == 255){
                    chek[i][j] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++ ){
            if (!chek[i][j]) new_image[i][j] = 255;
            image[i][j] = new_image[i][j];  // Current image equal new_image
        }
    }
}

void Mirror_Image (unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // This filter mirrors 1/2 of the image as seen here in order: Left 1/2, Right 1/2, Upper 1/2 and Lower 1/2.
    int num , cnt = 0 ;
    // input case
    cout<<"Mirror left, right, upper, down side?\n" ;
    cout << "1-\tLeft\n"
         << "2-\tRight\n"
         << "3-\tUpper\n"
         << "4-\tDown\n";

    cin >> num ;
    switch (num) {
        case 1:
            // This filter mirrors 1/2 of the image of Left 1/2
            for (int i = 0 ; i < SIZE ; i++){
                cnt = 0 ;
                for (int j = 0 ; j < SIZE ; j++){
                    if (j >= SIZE/2) {
                        cnt++;
                        (j > SIZE/2) && cnt++;
                    }
                    new_image[i][j] = image[i][j-cnt];
                }
            }
            break;
        case 2:
            // This filter mirrors 1/2 of the image of Right 1/2
            for (int i = 0 ; i < SIZE ; i++){
                cnt = 0 ;
                for (int j = 0 ; j < SIZE ; j++){
                    if (j < SIZE/2) {
                        cnt++;
                        (j < SIZE/2 -1) && cnt++;
                    }
                    new_image[i][j] = image[i][j-cnt];
                }
            }
            break;
        case 3:
            // This filter mirrors 1/2 of the image of upper 1/2
            for (int i = 0; i < SIZE ; i++){
                if (i >= SIZE/2){
                    cnt++;
                    (i > SIZE/2) && cnt++;
                }
                for (int j = 0 ; j < SIZE ; j++){
                    new_image[i][j] = image[i-cnt][j];
                }
            }
            break;
        case 4 :
            // This filter mirrors 1/2 of the image of down 1/2
            for (int i = SIZE-1 ; ~i ; i--){
                if (i < SIZE/2){
                    cnt++;
                    i < (SIZE/2 -1) && cnt++;
                }
                for (int j = 0 ; j < SIZE ; j++){
                    new_image[i][j] = image[i+cnt][j];
                }
            }
            break;
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE ; i++){
        for (int j  = 0 ; j < SIZE ; j++){
            image[i][j] = new_image[i][j];
        }
    }
}

void Crop_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    // This filter allows entering an x, y position and cutting a square of length and width l, w to keep and removing the rest.
    cout << "Please enter x y l w : " ;
    int x,y,l,w;
    cin>>x >> y >> l >> w ;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            new_image[i][j]=255;
        }
    }
    for(int i=x; i<x+l && i<SIZE;i++){
        for(int j=y; j < y+w && j <SIZE;j++){
            new_image[i][j]=image[i][j];
        }
    }
    // Current image equal new_image
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] =  new_image[i][j];
        }
    }

}

void Shuffle_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    cout << "Please enter new order of quarters ? " ;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(a==4)new_image[i/2][j/2]=image[(i/2)+128][(j/2)+128];
            if(a==3)new_image[i/2][j/2]=image[(i/2)+128][(j/2)];
            if(a==2)new_image[i/2][j/2]=image[(i/2)][(j/2)+128];
            if(a==1) new_image[i/2][j/2]=image[(i/2)][(j/2)];
            if(b==4)new_image[i/2][(j/2)+128]=image[(i/2)+128][(j/2)+128];
            if(b==3)new_image[i/2][(j/2)+128]=image[(i/2)+128][(j/2)];
            if(b==2)new_image[i/2][(j/2)+128]=image[(i/2)][(j/2)+128];
            if(b==1)new_image[i/2][(j/2)+128]=image[(i/2)][(j/2)];
            if(c==4)new_image[(i/2)+128][j/2]=image[(i/2)+128][(j/2)+128];
            if(c==3)new_image[(i/2)+128][j/2]=image[(i/2)+128][(j/2)];
            if(c==2)new_image[(i/2)+128][j/2]=image[(i/2)][(j/2)+128];
            if(c==1)new_image[(i/2)+128][j/2]=image[(i/2)][(j/2)];
            if(d==4)new_image[(i/2)+128][(j/2)+128]=image[(i/2)+128][(j/2)+128];
            if(d==3)new_image[(i/2)+128][(j/2)+128]=image[(i/2)+128][(j/2)];
            if(d==2)new_image[(i/2)+128][(j/2)+128]=image[(i/2)][(j/2)+128];
            if(d==1)new_image[(i/2)+128][(j/2)+128]=image[(i/2)][(j/2)];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}

void filter8_4(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = image[(i / 2) + 128][(j / 2) + 128];
        }
    }
}

void filter8_3(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = image[(i/2)+128][(j/2)];

        }
    }
}
void filter8_2(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = image[i/2][(j/2)+128];

        }
    }
}
void filter8_1(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = image[i / 2][j / 2];
        }
    }
}

void Enlarge_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    cout << "Which quarter to enlarge 1, 2, 3 or 4? ";
    int num ;
    cin >> num ;
    switch (num) {
        case 1:
            filter8_1(image , new_image);
            break;
        case 2:
            filter8_2(image , new_image);
            break;
        case 3:
            filter8_3(image , new_image);
            break;
        case 4:
            filter8_4(image, new_image);
            break;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}



// This filter allows the user to shrink the image dimensions to 1/2, 1/3 or 1/4 the original dimensions.
void Shrink_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    int x , new_size ;
    cout<<"Would you like to shrink it to 1/2, 1/3, or 1/4?"<<endl;
    cout << "1-\t 1/2\n"
         << "2-\t 1/3\n"
         << "3-\t 1/4\n";

    cin >> x;

    for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            new_image[i][j]=255;
        }
    }
    switch (x) {
        case 1:
            new_size = SIZE/2;
            for(int i=0; i< new_size; i++){
                for(int j=0; j< new_size; j++){
                    int sum = 0;
                    for (int k = i * 2; k < (i * 2) + 2; k++) {
                        for (int l = j * 2; l < (j * 2) + 2; l++) {
                            sum += image[k][l];
                        }
                    }
                    int average = sum / 4;
                    new_image[i][j]=average;
                }
            }
            break;
        case 2:
            new_size = SIZE/3;
            for(int i=0; i< new_size; i++){
                for(int j=0; j< new_size; j++){
                    int sum = 0;

                    for (int k = i * 3; k < (i * 3) + 3; k++) {
                        for (int l = j * 3; l < (j * 3) + 3; l++) {
                            sum += image[k][l];
                        }
                    }

                    int average = sum / 9;
                    new_image[i][j]=average;
                }
            }
            break;
        case 3:
            new_size = SIZE/4;
            for(int i=0; i<new_size; i++){
                for(int j=0; j<new_size; j++){
                    int sum = 0;
                    for (int k = i * 4; k < (i * 4) + 4; k++) {
                        for (int l = j * 4; l < (j * 4) + 4; l++) {
                            sum += image[k][l];
                        }
                    }
                    int average = sum / 16;
                    new_image[i][j]=average;
                }
            }
            break;
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}


int average(int x , int y , unsigned char image[][SIZE] ) {
    // calculate avrage for pixle in image
    int sum = 0 , cnt = 0 ;
    for(int g = 0 ; g < 8 ; g++){
        for (int m = 1 ; m <=3  ; m++){
            int nx = x + dx[g]*m  , ny = y + dy[g]*m ;
            if (valid(nx , ny) ){
                sum += image[nx][ny];
                cnt++;
            }
        }
    }
    return sum/cnt ;
}

void Blur(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    for (int i = 0 ; i < SIZE  ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            int avr = average(i , j , image);
            new_image[i][j] = avr ;
        }
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }

}


// void Skew_Horizontally(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
//     double degree ;
//     cout << "Please enter degree to skew right: " ;
//     cin >> degree;
//     degree = (degree*22)/(7*180);

//     double x = (tan(degree)*256 + 256)/256;  // rate of shrink
//     degree = atan(tan(degree)/x);    // shrink angle

//     for (int i = 0 ; i < SIZE ; i++){
//         int st = (SIZE-i-1)*tan(degree)  , end = SIZE-(i * tan(degree));
//         double lenght = end - st+1;
//         double shrink = SIZE / lenght;
//         int g = 0 , average = 0 , cnt = 1 ;
//         for  (int j = 0 ; j < SIZE ; j++){
//             average = 0 ;
//             if (j < st || j > end){
//                 new_image[i][j] = 255;
//                 continue;
//             }

//             // shrink of image

//             int num = 0 ;
//             for (; g < shrink*cnt ; g++){
//                 average += image[i][g];
//                 num++;
//             }
//             new_image[i][j] = average/num;
//             cnt++;
//         }
//     }

//     // Current image equal new_image
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             image[i][j] = new_image[i][j];
//         }
//     }

// }

void Skew_Horizontally(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) {
    cout << "Please enter degree to skew right: " ;
    double rad ; cin >> rad ;
    rad=90-rad;
    rad =(rad*3.14159/180);
    int x=256/(1+1/tan(rad));
    double step=SIZE-x;
    double mov =step/SIZE;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            new_image[i][j] = 255;

    for (int i = 0 ; i < SIZE ; i++ ){
        for ( int j=0;j<SIZE; j++ ){
            new_image[i][j*int(x)/SIZE] = image[i][j];
            new_image[i][j*int(x)/255] = image[i][j];
        }
    }
    for (int i = 0 ; i < SIZE ; i++ ){
        for ( int j=0;j<SIZE; j++ ){
            image[i][j]=new_image[i][j];
        }
    }
    for (int i = 0 ; i < SIZE ; i++ ){
        for ( int j=0;j<SIZE; j++ ){
            new_image[i][j+(int)step]=image[i][j];
        }
        step-=mov;
    }
    // Current image equal new_image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}

void Skew_Vertically(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]){
    double degree ;
    cout << "Please enter degree to skew right: " ;
    cin >> degree;
    degree = (degree*22)/(7*180);

    double x = (tan(degree)*256 + 256)/256;  // rate of shrink
    degree = atan(tan(degree)/x);    // shrink angle

    for (int j = 0 ; j < SIZE ; j++){
        int st = (SIZE-j-1)*tan(degree)  , end = SIZE-(j * tan(degree));
//        cout << st << ' '<< end << '\n';
        double lenght = end - st+1;
        double shrink = SIZE / lenght;
        int g = 0 , average = 0 , cnt = 1 ;
        for  (int i = 0 ; i < SIZE ; i++){
            average = 0 ;

            if (i < st || i > end){
                new_image[i][j] = 255;
                continue;
            }

            // shrink of image

            int num = 0 ;
            for (; g < shrink*cnt ; g++){
                average += image[g][j];
                num++;
            }
            new_image[i][j] = average / num;
            cnt++;
        }
    }

    // Current image equal new_image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}





