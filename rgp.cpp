// Assignment 1
// Last Modification Date: 19/10/2023
// Author1 and ID and Group: mohamed magdy lamey     20220306
// Author2 and ID and Group: Malk Mostafa Habib       20220342




#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;

unsigned char imageRGB[SIZE][SIZE][3];
unsigned char imageRGB1[SIZE][SIZE][3];
unsigned char newImageRGB[SIZE][SIZE][3];


void readRGB();
void readRGB1();
void saveRGB();
void invertRGB();
void blackWhiteRGB();
void darkenLightenRGB();
void darkenRGB();
void lightenRGB();
void flipRGB();
void flipVerticallyRGB();
void flipHorizontalyRGB();
void mergeRGB();
void rotateRGB();
void rotate90RGB();
void rotate180RGB();
void rotate270RGB();
void enlargeRGB();
void shrinkRGB(int num);
void mirrorRGB();
void leftMirrorRGB();
void rightMirrorRGB();
void upperMirrorRGB();
void lowerMirrorRGB();
void blurRGB();
void RGB_detect();
void shuffleRGB();
void divideImageRGB();



int main()
{
    int choiceImage;
    cout<<" hello :)"<<endl;
    readRGB();
    while (true){
     char choice;
    cout<<"1- Black & White Filter"<<endl<<"2- Invert Filter"<<endl<<"3- Merge Filter"<<endl<<"4- Flip Image"<<endl<<"5- Darken and Lighten Image"<<endl<<"6- Rotate Image"<<endl<<"7- Detect Image Edges "<<endl<<"8- Enlarge Image"<<endl<<"9- Shrink Image"<<endl;
    cout<<"a- Mirror 1/2 Image"<<endl<<"b- Shuffle Image"<<endl<<"c- Blur Image"<<endl<<"s- Save the image to a file"<<endl<<"0- Exit"<<endl;
    cout<<endl<<endl;
    cin>>choice;
    cout<<endl;
   if(choice=='1')
        blackWhiteRGB();

    else if(choice=='2')
        invertRGB();

    else if (choice=='3')
        mergeRGB();

    else if (choice=='4')
        flipRGB();

    else if (choice=='5')
        darkenLightenRGB();

    else if (choice=='6')
        rotateRGB();

    else if(choice=='7')
        RGB_detect();

    else if(choice=='8')
        enlargeRGB();

    else if(choice=='9'){
         int num;
        string shrinkChoice;
        cout<<"Shrink to (1/2), (1/3) or (1/4)?"<<endl;
        cin>>shrinkChoice;
        if (shrinkChoice=="1/2")
            num=1;
        if (shrinkChoice=="1/3")
            num=2;
        if (shrinkChoice=="1/4")
            num=3;
        shrinkRGB(num);
    }

    else if(choice=='a')
        mirrorRGB();

    else if(choice=='b')
        shuffleRGB;

    else if(choice=='c')
        blurRGB();

    else if(choice=='s')
        saveRGB();

    else if(choice=='0')
        return 0;
    else
        cout<<"Invalid Input. Please Try Again."<<endl<<endl;


    }


}


void readRGB(){
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, imageRGB);

}
void readRGB1(){
   char imageFileName[100];

   // Get RGB scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, imageRGB1);

}

void saveRGB(){
   char imageFileName[100];

   // Get RGB scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, imageRGB);

}

void invertRGB(){

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][0]=255-imageRGB[i][j][0];
            }
        }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][1]=255-imageRGB[i][j][1];
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][2]=255-imageRGB[i][j][2];
            }
        }

}
void blackWhiteRGB(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][0]>127)
                    imageRGB[i][j][0]=0;
                else
                    imageRGB[i][j][0]=255;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][1]>127)
                    imageRGB[i][j][1]=0;
                else
                    imageRGB[i][j][1]=255;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][2]>127)
                    imageRGB[i][j][2]=0;
                else
                    imageRGB[i][j][2]=255;
            }
        }


}

void darkenLightenRGB(){
    char choice;
    cout<<"Do you want to (d)arken or (l)ighten?"<<endl<<endl;
    cin>>choice;
    if (choice=='d')
        darkenRGB();
    else if (choice=='l')
        lightenRGB();
}

void darkenRGB(){
   for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
               if (imageRGB[i][j][0]>127)
                    imageRGB[i][j][0]-=63;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
              if (imageRGB[i][j][1]>127)
                    imageRGB[i][j][1]-=63;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
             if (imageRGB[i][j][2]>127)
                imageRGB[i][j][2]-=63;

            }
        }

}

void lightenRGB(){
   for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
               if (imageRGB[i][j][0]<127)
                    imageRGB[i][j][0]+=63;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
              if (imageRGB[i][j][1]<127)
                    imageRGB[i][j][1]+=63;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
             if (imageRGB[i][j][2]<127)
                imageRGB[i][j][2]+=63;

            }
        }

}

void flipRGB(){
    char choice;
    cout<<"Flip (h)orizontally or (v)ertically ?"<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if (choice=='h')
        flipVerticallyRGB();

    else if (choice=='v')
        flipHorizontalyRGB();

}

void flipHorizontalyRGB(){
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
           int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
                imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
                int temp = imageRGB[i][j][1];
                imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
                imageRGB[SIZE-i-1][j][1]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
                int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
                imageRGB[SIZE-i-1][j][2]=temp;
        }
    }
}
void flipVerticallyRGB(){
   for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
                imageRGB[i][SIZE-j-1][0]=temp;
        }
        }



    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][1];
                imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
                imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
                imageRGB[i][SIZE-j-1][2]=temp;
        }
    }

}

void mergeRGB(){
    readRGB1();
   for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
               imageRGB[i][j][0]=(imageRGB[i][j][0]+imageRGB1[i][j][0])/2;
        }
   }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][1]=(imageRGB[i][j][1]+imageRGB1[i][j][1])/2;
        }
    }




    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][2]=(imageRGB[i][j][2]+imageRGB1[i][j][2])/2;
        }
    }



}

void rotateRGB(){
    int choice;
    cout<<"Rotate (90), (180) or (270) degrees"<<endl<<endl;
    cin>>choice;
    if (choice==90)
        rotate90RGB();
    else if (choice==180)
        rotate180RGB();
    else if (choice==270)
        rotate270RGB();

}

void rotate90RGB(){
    unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
             imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
                int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
                imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
               int temp = imageRGB[i][j][1];
                imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
                imageRGB[SIZE-i-1][j][1]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
               int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
                imageRGB[SIZE-i-1][j][2]=temp;
        }
    }

}

void rotate180RGB(){
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
                int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
                imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
              int temp = imageRGB[i][j][1];
              imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
              imageRGB[SIZE-i-1][j][1]=temp;
        }
    }




    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
              int temp = imageRGB[i][j][2];
              imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
              imageRGB[SIZE-i-1][j][2]=temp;
        }
    }

    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
                imageRGB[i][SIZE-j-1][0]=temp;
            }
    }


    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                 int temp = imageRGB[i][j][1];
                 imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
                 imageRGB[i][SIZE-j-1][1]=temp;
            }
    }



    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
                imageRGB[i][SIZE-j-1][2]=temp;
            }
    }

}

void rotate270RGB(){
     unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
             imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }

    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
                imageRGB[i][SIZE-j-1][0]=temp;
            }
    }


    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = imageRGB[i][j][1];
                imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
                imageRGB[i][SIZE-j-1][1]=temp;
            }
    }



    for (int i=0;i<SIZE;i++) {
            for (int j=0;j<SIZE/2;j++) {
                int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
                imageRGB[i][SIZE-j-1][2]=temp;
            }
    }

}
void enlargeRGB(){
    unsigned char temp[SIZE/2][SIZE/2][3];
    int  startRow, startCol, endRow, endCol;
    int quarter=0;
    while(quarter>4 || quarter<1){
    cout<<"Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
    cin>>quarter;
    }

    startRow = quarter ==1 || quarter==2 ? 0 : SIZE/2;
    endRow   = quarter ==1 || quarter==2 ? SIZE/2 : SIZE;
    startCol = quarter ==1 || quarter==3 ? 0 : SIZE/2;
    endCol   = quarter ==1 || quarter==3 ? SIZE/2 : SIZE;

    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][0]=imageRGB[i][j][0];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][1]=imageRGB[i][j][1];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][2]=imageRGB[i][j][2];
            col++;
        }
        row++;
    }
    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][0]=temp[i][j][0];
            imageRGB[row+1][col][0]=temp[i][j][0];
            imageRGB[row][col+1][0]=temp[i][j][0];
            imageRGB[row+1][col+1][0]=temp[i][j][0];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][1]=temp[i][j][1];
            imageRGB[row+1][col][1]=temp[i][j][1];
            imageRGB[row][col+1][1]=temp[i][j][1];
            imageRGB[row+1][col+1][1]=temp[i][j][1];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][2]=temp[i][j][2];
            imageRGB[row+1][col][2]=temp[i][j][2];
            imageRGB[row][col+1][2]=temp[i][j][2];
            imageRGB[row+1][col+1][2]=temp[i][j][2];
            col+=2;
        }
        row+=2;
    }
}

void shrinkRGB(int num)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != 0) {
                for (int x = i; x <= SIZE - i; x++) {
                    if (x == SIZE - i) {
                        for (int r = 0 ; r < RGB ; r++) {
                            imageRGB[x][j][r] = 255;
                        }
                    }
                    else {
                        for (int r = 0 ; r < RGB ; r++) {
                            imageRGB[x][j][r] = imageRGB[x + num][j][r];
                        }
                    }
                }
            }

        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) {
                for (int x = j; x <= SIZE - j; x++) {
                    if (x == SIZE - j) {
                        for (int r = 0 ; r < RGB ; r++) {
                            imageRGB[i][x][r] = 255;
                        }
                    }
                    else {
                        for (int r = 0 ; r < RGB ; r++) {
                            imageRGB[i][x][r] = imageRGB[i][x + num][r];
                        }
                    }
                }
            }
        }
    }
}

void blurRGB(){
    char arr[SIZE][SIZE];
    int res=0;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            imageRGB[i][j][0]=(imageRGB[i][j][0]+imageRGB[i][j+1][0]+imageRGB[i][j-1][0]+imageRGB[i+1][j][0]+imageRGB[i+1][j+1][0]+imageRGB[i+1][j-1][0]+imageRGB[i-1][j][0]+imageRGB[i-1][j+1][0]+imageRGB[i-1][j-1][0])/9;
            imageRGB[i][j][1]=(imageRGB[i][j][1]+imageRGB[i][j+1][1]+imageRGB[i][j-1][1]+imageRGB[i+1][j][1]+imageRGB[i+1][j+1][1]+imageRGB[i+1][j-1][1]+imageRGB[i-1][j][1]+imageRGB[i-1][j+1][1]+imageRGB[i-1][j-1][1])/9;
            imageRGB[i][j][2]=(imageRGB[i][j][2]+imageRGB[i][j+1][2]+imageRGB[i][j-1][2]+imageRGB[i+1][j][2]+imageRGB[i+1][j+1][2]+imageRGB[i+1][j-1][2]+imageRGB[i-1][j][2]+imageRGB[i-1][j+1][2]+imageRGB[i-1][j-1][2])/9;
        }
    }
}
void mirrorRGB()
{
    int n;
    cout << "Upper 1/2 ---> 1" << endl << "Lower 1/2 ---> 2" << endl << "Right 1/2 ---> 3" << endl << "Left 1/2 ---> 4" <<endl;
    cout << "choose 1 , 2 , 3 or 4: ";
    cin >> n;
    if(n == 1)
    {
        	int s = SIZE/2;

      for(int m = 0; m < RGB; m++)
      {
      for (int j = 0; j < SIZE; j++)
        {

            int k = SIZE;
            for (int i = 0; i< s; i++)
            {
                imageRGB[k][j][m]=imageRGB[i][j][m];
                k--;
            }
        }
      }
    }
    else if(n == 2)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int j = 0; j < SIZE; j++)
    {

        int k = SIZE;
        for (int i = 0; i< s; i++)
        {
            imageRGB[i][j][m]=imageRGB[k][j][m];
            k--;
        }
    }
    }
    }
    else if(n == 3)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            imageRGB[i][j][m]=imageRGB[i][k][m];
            k--;
        }
    }
    }
    }
    else if(n == 4)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            imageRGB[i][k][m]=imageRGB[i][j][m];
            k--;
        }
    }
    }
    }
}
void RGB_detect()
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (imageRGB [i][j][0]< 127 && imageRGB [i][j][1]< 127 && imageRGB [i][j][2]< 127)
                imageRGB [i][j][0]=imageRGB [i][j][1]=imageRGB [i][j][2]=0;
            else
                imageRGB [i][j][0]=imageRGB [i][j][1]=imageRGB [i][j][2]= 255;
        }
    }
    unsigned char detect[SIZE][SIZE][3];
    for(int k = 0; k < 3 ; k++){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                detect[i][j][k] = imageRGB[i][j][k];
            }
        }
    }
    for(int k = 0 ; k < 3 ; k++){
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                int x = 2*detect[i][j-1][k] - 2*detect[i][j+1][k] + detect[i-1][j-1][k] - detect[i-1][j+1][k] + detect[i+1][j-1][k] - detect[i+1][j+1][k];
                int y = 2*detect[i+1][j][k] - 2*detect[i-1][j][k] + detect[i+1][j-1][k] - detect[i-1][j-1][k] + detect[i+1][j+1][k] - detect[i-1][j+1][k];

                if (abs(x) > 600 || abs(y) > 600) {
                    imageRGB[i][j][k] = 0;
                }
                else {
                    imageRGB[i][j][k] = 255;
                }
            }
        }
    }
}

void divideImageRGB(int quarter, unsigned char newImage[][SIZE / 2][RGB]) {
    int startRow, endRow, startCol, endCol;

    startRow = quarter == 1 || quarter == 2 ? 0 : SIZE / 2;
    endRow = quarter   == 1 || quarter == 2 ? SIZE / 2 : SIZE;
    startCol = quarter == 1 || quarter == 3 ? 0 : SIZE / 2;
    endCol = quarter == 1   || quarter == 3 ? SIZE / 2 : SIZE;


    for (int i = startRow, row = 0; i < endRow; i++) {
        for (int j = startCol, col = 0; j < endCol; j++) {
            for (int k = 0 ; k < RGB ; k++) {
                newImageRGB[row][col][k] = imageRGB[i][j][k];
            }
            col++;
        }
        row++;
    }
}


void shuffleRGB() {

    int seq[4];

    cout << "New sequence of quarters ? ";
    for (int i = 0; i < 4; i++) {
        cin >> seq[i];
        if (seq[i] > 4 || seq[i] < 1) {
            cout << "reject\n";
            return;
        }
    }

    vector<unsigned char[SIZE / 2][SIZE / 2][RGB]>quarterImages(4);

    for (int i = 0; i < quarterImages.size(); i++) {
        divideImageRGB(seq[i], quarterImages[i]);
    }

    int row, col;
    for (int i = 0; i < 4; i++) {

        row = i == 0 || i == 1 ? 0 : SIZE / 2;

        for (int j = 0; j < SIZE / 2; j++) {

            col = i == 0 || i == 2 ? 0 : SIZE / 2;

            for (int k = 0; k < SIZE / 2; k++) {
                for (int n = 0 ; n <RGB; n++)
                imageRGB[row][col][n] = quarterImages[i][j][k][n];
                col++;
            }
            row++;
        }
    }
}

