#include <stdio.h>
#include <stdlib.h>

// Kieran Herron
// COP 3502 -013
// Lab Assignment 6

// Goal - write recrusion function that goes through file and returns index to desired val

int search(int numbers[], int low, int high, int value);
void printArray(int numbers[], int sz);

int main() {

    int i;
    int numImputs;
    char * str;
    float average;
    int value;
    int index;
    int * numArray = NULL;
    int countOfNums;

    FILE * inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numImputs);


    while (numImputs-- > 0) 
    {
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
    

}


int search(int numbers[], int low, int high, int value) {

    // catch if statements
    if(high < 0) {
        return(-1);
    }

    if(low > high) {
        return(-1);
    }
    // end of catch if statements

    int midVal = 1 + ((high - 1) / 2);

    // binary search, first checking mid val, then upper and lower 
    if(numbers[midVal] == value) {
        return(midVal);
    }
    else if(numbers[midVal] > value) {
        return (search(numbers, low, midVal-1, value) );
    }
    else if(numbers[midVal] < value) {
        return(search(numbers, midVal+1, high, value));
    }
    // base, index not present
    else {
        return(-1);
    }
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for(i=0; i < sz ; ++i) {
        printf("%d", numbers[i]);
    }
    printf("\n");
}

