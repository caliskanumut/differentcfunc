#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 const float deltat = 0.001;

float norm2(float v1,float v2)
{
   float temp = v1*v1;
   float temp2 = v2*v2;
   float norma =  sqrt(temp) - sqrt(temp2);
   return norma; 

}

float forwardeuler(float dz,float z,float deltat){

    z += dz*deltat; 
    return z;
}

void printfunction(float arr[],int size,int srtind)
{   
    int i = 0;
    for(i = srtind; i < srtind + size; i++)
    {
        printf("%d. %f ",i,arr[i]);
    }
     printf("\n");
}

float minmax(float arr[], int size, int strind){
   float max = arr[0];
   float min = arr[0];
   int i = 0;
    for(i = strind; i < strind + size; i++)
    {
        if(arr[i] > max){
           max = arr[i];  
           }
         if(arr[i] < min){
            min = arr[i];
         }
    }
    return min,max;
}

int main()
{
    float dz = 3.0;
    float z = 2.0;
    int i = 0;
    const int init = 10;
    float vellarr[init];
    float temp;
    int size = 10;
    int framesize = 5;
    int strind = 5;

    float minvel1;
    float maxvel1;
    for(i= 0; i < size; i++ ){
    z = forwardeuler(dz,z,deltat);
    temp = norm2(dz,z);
    vellarr[i] = z;
    }

    printfunction(vellarr,framesize, strind);

    minvel1,maxvel1 = minmax(vellarr, 15, 0);
    

    printf("%f \n",temp);
    printf("%f \n",vellarr[99]);

     printf("Min: %f Max: %f \n",minvel1,maxvel1);
    return 0;
}