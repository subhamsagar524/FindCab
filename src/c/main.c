#include<stdio.h>    //Used for printf, scanf, getc, fgets, FILE, EOF
#include<string.h>   //Used for strcpy, strlen
#define FILE_NAME "input.txt"
#define MAX_LINE 125
#define MAX_DATA 4
#define TOINT 48
#define MAX_ID 20
#define MAX_NAME 30

//Function Prototypes Decalarations
int checkFile();
char* getdatabyline(int lineno);
int intconvert(char *num);

//Defining the driver data-type
struct driver
{
    char id[MAX_ID];
    char name[MAX_NAME];
    int lat;
    int lon;
};

//Main function-Execution of code starts from here
int main (void)
{
    printf("Welcome \nFind Cab\n");
    
    int lat, lon;   //Input Variables
    static int n;	//Processing Variables
    int i, a, j, cnt;	//Processing Variables

    //Check the file and assign the number of drivers registered
    n = checkFile();
	
    struct driver data[n];    //Storage for driver details
    printf("\nWe are having %d drivers with us.\n", n);
    
    //Fetch the raw data from the file
    char raw[n][MAX_LINE];
    for (i = 0; i <= n; i++)
	strcpy(raw[i], getdatabyline(i));
    
    //Extract the data from the array and split it to word and store them in driver data type
    char str[MAX_LINE];
    char splitStrings[MAX_DATA][MAX_LINE];
    for (a = 1; a <= n; a++)
    {
	strcpy(str, raw[a]);

	j = 0; cnt = 0;
	for (i = 0; i <= (strlen(str)); i++)
	{
	    //If space or NULL is found, assign NULL to splitStrings
	    if (str[i] == ' ' || str[i] == '\0')
	    {
	        splitStrings[cnt][j] = '\0';
		cnt++;	//For next word
		j = 0;	//For next word, init index 0
	    }
	    else
	    {
	        splitStrings[cnt][j] = str[i];
		j++;
	    }
	}
	//Storing the data in the driver storage unit
	strcpy(data[a-1].id, splitStrings[0]);
	strcpy(data[a-1].name, splitStrings[3]);
	data[a-1].lat = intconvert(splitStrings[1]);
	data[a-1].lon = intconvert(splitStrings[2]);
    }

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

int intconvert(char *num)
{
    int result, i;
    result = 0;
    for (i = 0; num[i] != '\0'; i++)
        result = (result * 10) + (num[i] - TOINT);    //The ASCII value of digit starts from 48 Ex: "3" -> (int)51
    return result;
}
//Programmed by Subham Sagar Paira https://www.github.com/subhamsagar524/
//Source : FindCab https://www.github.com/subhamsagar524/FindCab
