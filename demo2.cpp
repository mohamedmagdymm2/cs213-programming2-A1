// Assignment 1
// Last Modification Date: 10/10/2023
// Author1 and ID and Group: mohamed magdy lamey     20220306
// Author2 and ID and Group: Malk Mostafa Habib       20220342





#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];


void read();
void read1();
void save();
void blackWhite();
void invert();
void darkenLighten(); 
void darken();
void lighten();
void mergeImage();
void flip();
void flipVertically();
void flipHorizontaly();
void rotateImage();
void rotate180();
void rotate90();
void rotate270();
void mergeImage();


int main()
{
    cout<<" Hello :)"<<endl;
    read();
    while (true){
    char choice;
    cout<<"1- Black & White Filter"<<endl<<"2- Invert Filter"<<endl<<"3- Merge Filter"<<endl<<"4- Flip Image"<<endl<<"5- Darken and Lighten Image"<<endl<<"6- Rotate Image"<<endl<<"0- Exit"<<endl;
    cout<<endl<<endl;
    cin>>choice;
    cout<<endl;
    if(choice=='1')
        blackWhite();

    else if(choice=='2')
        invert();

    else if (choice=='3')
        mergeImage();

    else if (choice=='4')
        flip();

    else if (choice=='5')
        darkenLighten();

    else if (choice=='6')
        rotateImage();

    }}


void read(){
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);

}

void read1(){
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the other image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image1);

}


void save(){
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);

}



void blackWhite(){
    long avg;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            avg+=image[i][j];
        }
    }
    avg/=(SIZE*SIZE);
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (image[i][j]>avg)
                image[i][j]=255;
            else
                image[i][j]=0;
        }
    }

}

void invert(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=255-image[i][j];
        }
    }

}


void darkenLighten(){
    char choice;
    cout<<"Do you want to (d)arken or (l)ighten?"<<endl<<endl;
    cin>>choice;
    if (choice=='d')
        darken();
    else if (choice=='l')
        lighten();



}
void darken(){
for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (image[i][j]>127)
                    image[i][j]-=63;
        }
    }
}


void lighten(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (image[i][j]<127)
                    image[i][j]+=63;
        }
    }
}


void flip(){
    char choice;
    cout<<"Flip (h)orizontally or (v)ertically ?"<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if (choice=='h')
        flipVertically();

    else if (choice=='v')
        flipHorizontaly();

}


void flipVertically()
{
    for (int i= 0;i<SIZE/2;i++) {
            for (int j=0;j<SIZE;j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i-1][j];
                image[SIZE-i-1][j]=temp;
            }
    }
}

void flipHorizontaly(){
    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = image[i][j];
                image[i][j]=image[i][SIZE-j-1];
                image[i][SIZE-j-1]=temp;
            }
    }

}


void rotateImage(){
    int choice;
    cout<<"Rotate (90), (180) or (270) degrees"<<endl<<endl;
    cin>>choice;
    if (choice==90)
        rotate90();
    else if (choice==180)
        rotate180;
    else if (choice==270)
        rotate270();

}

void rotate180(){
    for (int i= 0;i<SIZE/2;i++) {
            for (int j=0;j<SIZE;j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i-1][j];
                image[SIZE-i-1][j]=temp;
            }
    }
    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = image[i][j];
                image[i][j]=image[i][SIZE-j-1];
                image[i][SIZE-j-1]=temp;
            }
    }

}

void rotate90(){
    unsigned char imageTran[SIZE][SIZE];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j]=image[j][i];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=imageTran[i][j];
        }
    }

    for (int i= 0;i<SIZE/2;i++) {
            for (int j=0;j<SIZE;j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i-1][j];
                image[SIZE-i-1][j]=temp;
            }
    }
}


void rotate270(){
    unsigned char imageTran[SIZE][SIZE];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j]=image[j][i];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=imageTran[i][j];
        }
    }
    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = image[i][j];
                image[i][j]=image[i][SIZE-j-1];
                image[i][SIZE-j-1]=temp;
            }
    }

}


void mergeImage(){
    read1();
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
           image[i][j]=(image[i][j]+image1[i][j])/2;
        }
    }
}
