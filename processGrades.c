#include <stdio.h>

void processGrades(int grades[], int num_grades) {
	int sum = 0;
	int max_grade;
	int min_grade;
	
	int i;
	
	printf("For previously inputted grades:\n");
	
	for(i = 0; i < num_grades; i++) {
		sum += grades[i];
		if((i == 0) || (grades[i] > max_grade)) {
			max_grade = grades[i];
		}
		if((i == 0) || (grades[i] < min_grade)) {
			min_grade = grades[i];
		}
	}
	
	printf("Largest grade is %d.\n", max_grade);
	printf("Smallest grade is %d.\n", min_grade);
	printf("Average grade is %d.\n", sum / num_grades);
	
}