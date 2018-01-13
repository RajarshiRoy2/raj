#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <iterator>
#include <stdio.h>

using namespace std;

//initialization everything outside as matrix is sometimes too big.
int const x2=2000;
int const y2=2000;
int arra[x2][y2];
int negativ[x2][y2];
float mean[x2][y2];
int edge[x2][y2];
int sharp[x2][y2];
float blur[x2][y2];
float blur2[x2][y2];
float blur3[x2][y2];
int trans[x2][y2];
int mainarray[x2*y2];
int total[x2*y2];
int length[x2*y2];
int numbers[x2*y2];
int lut[x2][y2];
int stretcher[x2][y2];
int mean1[x2*y2];
int standard[x2*y2];
int gaussian[x2][y2];

int main()
{

//initialization everything

int x3;
int y3;
string str1,str2,str4;
string word;
string str3,height,width;
int x,y,j,k,a,b,c,d,e,z,x1,v,q,f,i,w,s,z1,r1,t;
string u;
string z2;
string u1(".pnm");
string u2;
const double pi=3.142;
const double e1=2.718;


cout<<"Make sure that the picture is in gray scale and in PNM format.Make sure that the image is in the";
cout<<" same folder as the program or write the full address of the program.\n";
cout<<"Enter the file picture you want to change without typing .pnm:";
cin>>u;
u2=u+u1;
fstream file;
file.open(u2.c_str());

if(file.is_open())
    {
        cout<<"The file is opened successfully and can be read into the array.\n";
}
//ignoring the first 4 lines
        getline(file,str1);
        getline(file,str2);
        getline(file,str3);
        getline(file,str4);
//getting the height and width of the matrix automatically
istringstream iss(str3);
        iss >> x3>>y3;
        cout << x3<<" "<<y3<< endl;
//taking the values from file into array
for(x=0;x<x3;x++)
    {
        for ( y=0;y<y3;y++)
        {
            {
                file >> arra[x][y];
}
}
}




cout<<"\nDo you want to read the data to a new text file?\n";
cin>>k;

if (k==1)
    {
        ofstream picture;
        picture.open("new1.pnm");
        if (picture.is_open())
            {
                cout<<"The file can be copied into\n";
        }
        picture<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
        for(a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    picture<<'\t'<<arra[a][b];
        }
        }
        picture.close();
        }

 cout<<"Do you want to make a negative of the image? Press 1 to do so.\n";

 cin>>c;

 if (c==1)

 {//making negative of an image

     ofstream negative;
     negative.open("negative.pnm");

     if(negative.is_open())
     {
         cout<<"The file is open and negative can be made!\n";
     }
         for(d=0;d<x3;d++)
         {
             for(e=0;e<y3;e++)
             {
                negativ[d][e]=255-arra[d][e];
             }
         }
         negative<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
         for(a=0;a<x3;a++)
     {
         for(b=0;b<y3;b++)
         {
            negative<<'\t'<<negativ[a][b];
         }
     }
         negative.close();
     }

cout<<"Enter 1 if you want to do a mean of the image.\n";
cin>>z;
ofstream filter1;
filter1.open("mean.pnm");//mean filter
filter1<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";

for(d=0;d<x3;d++)
    {
        for(e=0;e<y3;e++)
        {
            mean[d][e]=arra[d][e];//reading all the values from array to mean matrix
        }
    }

     if(z==1)
        {
            for(x1=0;x1<x3;x1++)
            {
                for(v=0;v<y3;v++)
                {
                    //making the average of a 3x3 matrix
                    mean[x1][v]=(arra[x1][v]+arra[x1][v+1]+arra[x1][v+2]+arra[x1+1][v]
                                 +arra[x1+2][v+1]+arra[x1+1][v+2]+arra[x1+2][v]+arra[x1+2][v+1]+arra[x1+2][v+2])/9;
     }
     }
     if(filter1.is_open())
     {
         for(a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    filter1<<'\t'<<mean[a][b];
         }
         }
      }
        }

     ofstream filter2;
     filter2.open("edge.pnm");
     cout<<"Do you want to do a edge filter of the image? Press 1 if you want to do it.\n";
     cin>>q;

     if(q==1)
     {
         for(d=0;d<x3;d++)
         {
             for(e=0;e<y3;e++)
             {
                edge[d][e]=arra[d][e]-arra[d-1][e-1];
             }
         }
         filter2<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
         for (a=0;a<x3;a++)
         {
             for(b=0;b<y3;b++)
             {
                filter2<<'\t'<<edge[a][b];//transferring the array to file in proper column
             }

         }
         }


cout<<"Do you want to un sharp filter on image? Press 1 to do so.\n";
cin>>f;
if (f==1)
{
    ofstream filter3;
    filter3.open("unsharp.pnm");
    filter3<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
    for(x1=0;x1<x3;x1++)
         {
           for(v=0;v<y3;v++)
           {//making the average of a 3x3 matrix
             mean[x1][v]=(arra[x1][v]+arra[x1][v+1]+arra[x1][v+2]+arra[x1+1][v]+arra[x1+2][v+1]
                          +arra[x1+1][v+2]+arra[x1+2][v]+arra[x1+2][v+1]+arra[x1+2][v+2])/9;
           }
         }

         for(x1=0;x1<x3;x1++)
         {
           for(v=0;v<y3;v++)
           {//making the average of a 3x3 matrix
             sharp[x1][v]=arra[x1][v]-mean[x1][v];
           }

         }
          for (a=0;a<x3;a++)
         {
             for(b=0;b<y3;b++)
             {
                filter3<<'\t'<<sharp[a][b];//transferring the array to file in proper column
             }
         }
         filter3.close();
}



cout<<"Do you want to make blur of the image at an 45 degree angle? Press 1 to do so.\n";
cin>>i;

if (i==1)
{
    ofstream filter5;
    filter5.open("motion.pnm");
    filter5<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
    for(a=0;a<x3;a++)
        {
            for(b=0;b<y3;b++)
            {
                blur[a][b]=arra[a][b];
    }
    }
    for(a=0;a<x3;a++)
        {
            for(b=0;b<y3;b++)
            {
                blur[a][b]=((arra[a][b]+arra[a+1][b+1]+arra[a+2][b+2]+arra[a+3][b+3]+arra[a+4][b+4]+arra[a+5][b+5])/6);
    }
    }
    for (a=0;a<x3;a++)
        {
            for(b=0;b<y3;b++)
            {
                filter5<<'\t'<<blur[a][b];//transferring the array to file in proper column
    }
    }
    filter5.close();
    }

cout<<"Do you want to blue the image vertically and horizontally?.Press 1 to do so.\n";
cin>>w;

if(w==1)
{
    ofstream filter7;
    filter7.open("vertically.pnm");
    filter7<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
    ofstream filter6;
    filter6.open("horizontally.pnm");
    filter6<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";
    for(a=0;a<x3;a++)
        {
            for(b=0;b<y3;b++)
            {
                blur2[a][b]=arra[a][b];
    }
        }
        for(a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    blur2[a][b]=((arra[a][b]+arra[a][b+1]+arra[a][b+2]+arra[a][b+3]+arra[a][b+4]+arra[a][b+5])/6);//all matrixes are 3x3 windows so large images will not work
        }
        }
        for (a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    filter6<<'\t'<<blur2[a][b];//transferring the array to file in proper column
        }
        }
        filter6.close();
        for(a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    blur3[a][b]=arra[a][b];
        }
        }
        for(a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    blur3[a][b]=((arra[a][b]+arra[a+1][b]+arra[a+2][b]+arra[a+3][b]+arra[a+4][b]+arra[a+5][b])/6);
        }
        }
        for (a=0;a<x3;a++)
            {
                for(b=0;b<y3;b++)
                {
                    filter7<<'\t'<<blur3[a][b];//transferring the array to file in proper column
        }
        }
        filter7.close();
}

cout<<"Do you want to flip the image by 90 degrees? Press 1 to do so.\n";
cin>>s;

if(s==1)
{
    ofstream filter8;
    filter8.open("transpose.pnm");
    filter8<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<y3<<" "<<x3<<"\n"<<"255\n";
    for(i=0; i<x3; i++)
        {
            for(j=0; j<y3; j++)
            {
                trans[j][i]=arra[i][j];
            }
            }
            for(i=0; i<x3; i++)
                {
                    for(j=0; j<y3; j++)
                    {
                        filter8<<'\t'<<trans[i][j];
                    }
                    }
filter8.close();
}

cout<<"Do you want to make a histogram chart? Press to do it.\n";
cin>>z1;
if(z1==1)
    {
        for(y=0;y<x3;y++)
        {
            for(x=0;x<y3;x++)
            {
                mainarray[y*x3+x]=arra[y][x];//it works to convert 2d array to 1d array
}
}
for(a=0;a<(x3*y3);a++)
    {
        numbers[a]=0;
}
for(z=0;z<(x3*y3);z++)
    {
        numbers[mainarray[z]]=numbers[mainarray[z]]+1;
}
ofstream histogram;
histogram.open("histogram.txt");
for(a=0;a<=255;a++)
    {
        histogram<<a<<'\t'<<"   "<<numbers[a]<<"\n";
}
ofstream histogramchart;
histogramchart.open("histogramchart.txt");
for(a=0;a<=255;a++)
    {
        histogramchart<<a;
for(b=0;b<numbers[a];b++)

histogramchart<<"*";
histogramchart<<endl;
    }
histogramchart.close();
histogram.close();
}

cout<<"Do you want to stretch the image?Press 1 to do so.\n";

cin>>r1;

if (r1==1)
{
    ofstream streatch;

    streatch.open("streachedimage.pnm");

    streatch<<"P2\n"<<"# CREATOR: GIMP PNM Filter Version 1.1\n"<<x3<<" "<<y3<<"\n"<<"255\n";

    for(i=0;i<x3;i++)

{
    for(j=0;j<y3;j++)

    {

    stretcher[i][j]=(arra[i][j]/255)*255;

    }
}
for(i=0;i<x3;i++)
{

    for(j=0;j<y3;j++)

    {

    streatch<<'\t'<<stretcher[i][j];

    }
}

streatch.close();

}

cout<<"Do you want to perform a Gaussian filter? Press 1 to do so.\n";
cin>>t;
if (t==1)
{
for(x1=0;x<x3;x++)
    {
        for(y=0;y<y3;y++)
        {
            for(x=0;x<(x3*y3);x++)
            {
            mean1[x]=(arra[x1][v]+arra[x1][v+1]+arra[x1][v+2]+arra[x1+1][v]+arra[x1+2][v+1]
                          +arra[x1+1][v+2]+arra[x1+2][v]+arra[x1+2][v+1]+arra[x1+2][v+2])/9;
            }
        }
    }
    for(x1=0;x1<x3;x++)
    {
        for(y=0;y<y3;y++)
        {
            for(x=0;x<(x3*y3);x++)
            {
                standard[x]=(sqrt(pow((mean1[x]-arra[x1][y]),2)+pow((mean1[x]-arra[x1+1][y]),2)+pow((mean1[x]-arra[x1+2][y]),2)+pow((mean1[x]-arra[x1][y+1]),2)+pow((mean1[x]-arra[x1+1][y+1]),2)+pow((mean1[x]-arra[x1+2][y+1]),2)+pow((mean1[x]-arra[x1][y+2]),2)+pow((mean1[x]-arra[x1+1][y+2]),2)+pow((mean1[x]-arra[x1+2][y+2]),2)))/8;
            }
        }
    }
    for(x=0;x<x3;x++)
    {
        for(y=0;y<y3;y++)
        {
         for(x1=0;x<(x3*y3);x1++)
         {
            gaussian[x][y]=(1/(2*pi*pow(standard[x1],2)))*pow(e1,-(pow(x,2)+pow(y,2)/2*(pow(standard[x],2))));
         }
        }
    }
    ofstream gaussian1;
    gaussian1.open("Gaussian.pnm");
    for(x=0;x<x3;x++)
    {
        for(y=0;y<y3;y++)
        {
            gaussian1<<'\t'<<gaussian[x][y];
        }
    }
gaussian1.close();
}
filter1.close();

file.close();

filter2.close();


return 0;

}




