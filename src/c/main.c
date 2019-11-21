#include<stdio.h>
#include<string.h>
#define FILE_NAME "input.txt"
#define MAX_LINE 125

int checkFile();
char* getdatabyline(int lineno);

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
    static int n;	//Processing Variables

    //Check the file and assign the number drivers registered
    n = checkFile();
    printf("\nWe are having %d drivers with us.\n", n);
    
    //Fetch the raw data from the file
    char raw[n][MAX_LINE];
    for (int i = 0; i <= n; i ++)
	strcpy(raw[i], getdatabyline(i)); 
    
    //Prompt user for the location
    printf("Enter your location(lat lon) : ");
    scanf("%d %d", &lat, &lon); //Get location
    
    
    return 0;
}

int checkFile()
{
    FILE *fp; 
    int count = 0;  // Line counter (result) 
    char c;  // To store a character read from file 
  
    // Open the file 
    fp = fopen(FILE_NAME, "r"); 
  
    // Check if file exists 
    if (fp == NULL) 
    { 
        printf("Could not open file %s", FILE_NAME); 
        return 0; 
    } 
  
    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1; 
  
    // Close the file 
    fclose(fp); 
    return count;
}

char* getdatabyline(int lineno)
{
    FILE *fp;
    static char c[MAX_LINE];	//To store a buffer read from file

    fp = fopen(FILE_NAME, "r");	//Open the file

    //Check if file exists
    if (fp == NULL)
        printf("Could not open file %s", FILE_NAME);
    
    // Extracting data from the file
    int i;
    for (i = 0; i < lineno; i++)
	fgets(c, sizeof(c), fp);

    fclose(fp);	//Close the file
    return c;
}
