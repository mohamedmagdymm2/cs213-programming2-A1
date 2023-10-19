// Assignment 1
// Last Modification Date: 19/10/2023
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
void mirror();
void leftMirror();
void rightMirror();
void upperMirror();
void lowerMirror();
void mergeImage();
void shrink(int num);
void enlarge();
void detect_edge();
void shuffle();
void cutImage(int quarter, unsigned char fillImage[][SIZE/2]);
void blur();



int main()
{
    cout<<" hello :)"<<endl;
    read();
    while (true){
    char choice;
    cout<<"1- Black & White Filter"<<endl<<"2- Invert Filter"<<endl<<"3- Merge Filter"<<endl<<"4- Flip Image"<<endl<<"5- Darken and Lighten Image"<<endl<<"6- Rotate Image"<<endl<<"7- Detect Image Edges "<<endl<<"8- Enlarge Image"<<endl<<"9- Shrink Image"<<endl;
    cout<<"a- Mirror 1/2 Image"<<endl<<"b- Shuffle Image"<<endl<<"c- Blur Image"<<endl<<"s- Save the image to a file"<<endl<<"0- Exit"<<endl;
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

    else if(choice=='7')
        detect_edge();

    else if(choice=='8')
        enlarge();

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
        shrink(num);
    }

    else if(choice=='a')
        mirror();

    else if(choice=='b')
        shuffle();

    else if(choice=='c')
        blur();

    else if(choice=='s')
        save();

    else if(choice=='0')
        return 0;

    else
        cout<<"Invalid Input. Please Try Again."<<endl<<endl;


    }



}

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


void mirror(){
    char choice;
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side?"<<endl<<endl;
    cin>>choice;
    if (choice=='l')
        leftMirror();
    else if(choice=='r')
        rightMirror();
    else if(choice=='u')
        upperMirror();
    else if(choice=='d')
        lowerMirror();


}

void leftMirror(){
    for (int i=0;i<SIZE;i++){
            for (int j=0;j<SIZE/2;j++){
                 image[i][SIZE-j-1]=image[i][j];
            }
    }
}

void rightMirror(){
        for (int i=0;i<SIZE;i++){
         for (int j=0;j<SIZE/2;j++){
                image[i][j]=image[i][SIZE-j-1];
         }
        }
}


void upperMirror(){
  for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            image[SIZE-i-1][j]=image[i][j];
        }
    }
}


void lowerMirror(){
     for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=image[SIZE-i-1][j];
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
void shrink(int num)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i != 0) {
				for (int x = i; x <= SIZE - i; x++) {
					if (x == SIZE - i) {
						image[x][j] = 255;
					}
					else {
						image[x][j] = image[x + num][j];
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
						image[i][x] = 255;
					}
					else {
						image[i][x] = image[i][x + num];
					}
				}
			}
		}
	}
}

void enlarge(){
    unsigned char temp[SIZE/2][SIZE/2];
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
            temp[row][col]=image[i][j];
            col++;
        }
        row++;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            image[row][col]=temp[i][j];
            image[row+1][col]=temp[i][j];
            image[row][col+1]=temp[i][j];
            image[row+1][col+1]=temp[i][j];
            col+=2;
        }
        row+=2;
    }



}
void detect_edge()
{
    unsigned char arr[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = image[i][j];
        }
    }

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int x = 2*arr[i][j-1] - 2*arr[i][j+1] + arr[i-1][j-1] - arr[i-1][j+1] + arr[i+1][j-1] - arr[i+1][j+1];
            int y = 2*arr[i+1][j] - 2*arr[i-1][j] + arr[i+1][j-1] - arr[i-1][j-1] + arr[i+1][j+1] - arr[i-1][j+1];

            if (abs(x) > 100 || abs(y) > 100) {
                image[i][j] = 0;
            }
            else {
                image[i][j] = 255;
            }
        }
    }
}

void shuffle(){

    int order[4];

    cout << "New order of quarters ? ";
    for(int i=0; i<4; i++){
        cin >> order[i];
        if( order[i] > 4 || order[i] < 1){
            cout << "reject\n";
            return;
        }
    }

    vector<unsigned char[SIZE/2][SIZE/2]>quarterImages(4);

    for(int i=0; i<quarterImages.size(); i++){
        cutImage(order[i], quarterImages[i]);
    }

    int rowIndex, colIndex;
    for(int i=0; i<4; i++){


        rowIndex = i == 0 || i == 1  ? 0 : SIZE / 2;

        for(int j=0; j<SIZE/2; j++){

            colIndex = i == 0 || i == 2  ? 0 : SIZE / 2;

            for(int k=0; k<SIZE/2; k++){
                image[rowIndex][colIndex] = quarterImages[i][j][k];
                colIndex++;
            }
            rowIndex++;
        }
    }

}
void cutImage(int quarter, unsigned char fillImage[][SIZE/2]){
    int startRow, endRow, startCol, endCol;

    startRow    = quarter == 1 || quarter == 2 ? 0 : SIZE / 2;
    endRow      = quarter == 1 || quarter == 2 ? SIZE / 2 : SIZE;
    startCol    = quarter == 1 || quarter == 3 ? 0 : SIZE / 2 ;
    endCol      = quarter == 1 || quarter == 3 ? SIZE / 2 : SIZE;


    // fill given image
    for(int i=startRow, rowIndex=0; i<endRow; i++){
        for(int j=startCol, colIndex=0; j<endCol; j++){

            fillImage[rowIndex][colIndex] = image[i][j];

        colIndex++;
        }
        rowIndex++;
    }

}

void blur()
{
    char arr[SIZE][SIZE];
    int res=0;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            image[i][j]=(image[i][j]+image[i][j+1]+image[i][j-1]+image[i+1][j]+image[i+1][j+1]+image[i+1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j-1])/9;
        }
    }

}






