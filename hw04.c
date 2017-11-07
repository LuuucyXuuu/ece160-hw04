#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,	//synonym
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3,
} Mode;

typedef struct {
  char *first_name;		//data members, actual first name is not stored in student struct
  char *last_name;  
  char *major;
  int year;
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
	case MAJOR_AND_NAME:
	  printf("%s % s %s\n", s.major, s.first_name, s.last_name);
      break;
	case YEAR_AND_NAME:
	  printf("%d % s %s\n", s.year, s.first_name, s.last_name);
	  break;
	case YEARS_LEFT_AND_NAME:
	  printf("%d % s %s\n", (s.year - 2017), s.first_name, s.last_name);
      break;
  }
}

int main(int argc, char *argv[]) {
  
  char *filename = argv[1];         //looks at second argument on command line which is the text file
  FILE *fp = fopen(filename, "r");  //ready for reading
  char buffer[256];                 //character array is created for storing an entire line of the input text file
  Student string_array[256];        //empty students in array
  
  if (fp == NULL) {		//empty file or unopenable
    printf("Could not open %s\n", filename);
    return -1;
	
  }
  
  int i = 0;
  char first_name[256];		//temporarily store first_name
  char last_name[256];
  char major[256];
  int year;          
  
  while ((fgets(buffer,255,fp))!= NULL){	//has nothing to read
	  //read input file
	sscanf(buffer, "%s %s %s %d", first_name, last_name, major, &year);		//reading from buffer and putting into variables
    string_array[i].first_name = (char*)malloc(strlen(first_name)+1);       //setting equal to character pointer
	string_array[i].last_name = (char*)malloc(strlen(last_name)+1);
    string_array[i].major = (char*)malloc(strlen(major)+1);
	string_array[i].year = year;
	
	stpcpy(string_array[i].first_name,first_name);		//string copy
	stpcpy(string_array[i].last_name,last_name);        //filling up string array
	stpcpy(string_array[i].major,major);
	
	i++;
  }
  
  while (1){
	int index, mode;		//identify which students data to extract
	printf("Please enter index and mode\n");
	fscanf(stdin,"%d %d", &index, &mode);
	print_student(mode,string_array[index]);
  }
  return 0;
}

