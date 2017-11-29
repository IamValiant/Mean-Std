#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	FILE* file = fopen("textname.txt", "r");
	char line[256];   //save a line
	char str[20];    //save the second list
	double distance;   //the value of the second list(changed to double first)
	double mean,std,sum = 0,sum_square = 0;
	int length = 0;
	if (file == NULL)
	{
		return 0;
	}
	while (fgets(line, sizeof(line), file)) { //fgets read file by lines, ended by while circle at the end of the file
		sscanf(line, "%*s %s", str);//sscanf analysis the data by lines, pass the first line(see the usage of sscanf)
		distance = atof(str);     //change to double
		length = length +1;     //the length of the list
		sum = sum + distance;
		sum_square = sum_square + distance*distance;   //the sum of the square
		printf("%f\n", distance);
		//printf("%p\n",&distance);    //print the position, here all data are the same position
	}
	printf("%d\n%f\n", length,sum);
	mean = sum / length;
	std = sqrt((sum_square - 2 * sum*mean + length*mean*mean)/(length-1));  //(n-1):length-1
	printf("%f\n%f\n", mean,std);
	fclose(file);
	getchar();     //keep waiting
	return 0;
}
