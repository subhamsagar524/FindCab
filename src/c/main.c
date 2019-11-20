#include<stdio.h>

struct driver
{
    char id[20];
    char name[30];
    int lat;
    int lon;
};

int main (void)
{
    printf("Welcome \nFind Cab\n");
    
    int lat, lon;   //Input Variables
    
    //Prompt user for the location
    printf("Enter your location(lat lon) : ");
    scanf("%d %d", &lat, &lon); //Get location
    
    return 0;
}
