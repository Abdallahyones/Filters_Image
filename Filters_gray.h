//
// Created by dell on 10/14/2023.
//

#ifndef TESTING_FILTERS_GRAY_H
#define TESTING_FILTERS_GRAY_H

bool valid(int x , int y);    // check if the point(in pixle) valid

char input_program ();      // interface of program

// filter for conversion image to  black and white
void Black_White(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// filter for invert image by complement
void Invert_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// the input new of image for merge of them
void Merge_filter(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to flip the image horizontally or vertically
void Flip_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to make the image darker or lighter by 50%
void Darken_lighten_filter(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to rotate the image clockwise by 90º
void Rotate_90(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to rotate the image clockwise by  180º
void Rotate_180(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

//This filter allows the user to rotate the image clockwise by 270º
void Rotate_270(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to input degree rotate
void Rotate_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This function finds the edges of the drawings in the image and turns the image into a skeleton version of the original
void Detect_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter mirrors 1/2 of the image as seen here in order: Left 1/2, Right 1/2, Upper 1/2 and Lower 1/2.
void Mirror_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);


// This filter allows entering an x, y position and cutting a square of length and width l, w to keep and removing the rest
void Crop_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to enlarge one of the four quarters of the image into a separate new image
void Enlarge_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);
void filter8_1(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);
void filter8_2(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);
void filter8_3(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);
void filter8_4(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

//Assume the image consist of 4 quarters as shown, the user enters the order he wants to the quarters in the new image
void Shuffle_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter allows the user to shrink the image dimensions to 1/2, 1/3 or 1/4 the original dimensions.
void Shrink_Image(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// calculate avrage for pixle in image
int average(int x , int y , unsigned char image[][SIZE] );

// This filter produces a bury version of the image.
void Blur(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter skews the image to the right or up with a given degree and compresses it to stay 256x256
void Skew_Horizontally(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]);

// This filter skews the image to the right or up with a given degree and compresses it to stay 256x256
void Skew_Vertically(unsigned char image[][SIZE] , unsigned char new_image[][SIZE]) ;

#endif //TESTING_FILTERS_GRAY_H
