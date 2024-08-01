#include<stdio.h>

int main(){
	int total, data, answer;
	float present, absent, attendance, percentage;
	printf("\nEnter the Total Attendace: ");
	scanf("%d", &total);
	printf("Enter the Percentage/Attendance: ");
	scanf("%d", &answer);
	if(answer<=100){
		percentage=answer;
		present = percentage*total/100;
	}
	else if(answer>100){
		present=answer;
		percentage=present*100/total;
	}
	absent = total-present;
	
	
	do{
		printf("\n\n\nYou are present for %.0f hours or %.1f days", present, present/7);
		printf("\n\n\nYou are absent for %.0f hours or %.1f days", absent, absent/7);
		printf("\n\n\nYour Attendance : %.2f", present*100/total);
		printf("\n\n\nTotal Attendance: %d\n", total);
		
		printf("\n\nAdd more data!\n\n");
		scanf("%d", &data);
		if(data>0){
			present+=(float)data;
			total+=data;
			}
			
			else if(data<0){
				total+=data*-1;
				absent+=(float)data*-1;
				}
				}
				while(data!=0);
				
				
				return 0;
				}
