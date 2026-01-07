#include <stdio.h>
#include<conio.h>
#define max_students 100
#define P printf
#define S scanf
int main()
{
    int grades[max_students],n_students,choice;
    double average,sum;

    while(choice!=5) 
	{
        P("\n Student Grade Analysis");
        P("\n 1. Enter student grades");
        P("\n 2. Calculate class average");
        P("\n 3. Find highest and lowest grades");
        P("\n 4. Count passed and failed students");
        P("\n 5. Exit");
        P("\n Enter your choice: ");
        S("%d", &choice);
        switch (choice) 
		{
            case 1:
                P("\n Enter the number of students in the class: ");
                S("%d", &n_students);

                if (n_students<= 0||n_students>max_students)
				{
                    P("\n Invalid number of students. Please enter a value between 1 and %d.",max_students);
                    break;
                }

                for (int i=0;i<n_students; i++) 
				{
                    P("\n Enter grade for student %d: ",i+1);
                    S("%d",&grades[i]);
                    if (grades[i]<0 || grades[i]>100) 
					{
                        P("\n Invalid grade. Please enter a value between 1 and 100.");
                        i--;
                    }
                }
                break;

            case 2:
                if (n_students== 0)
				{
                    P("\n No grades have been entered. Please enter grades first.");
                    break;
                }
                int sum1;
				sum1=0;
                for (int i=0;i<n_students; i++) 
				{
                    sum1=sum1+grades[i];
                }

                average=sum1/n_students;
                P("\n Class average: %.2f", average);
                break;

            case 3:
                if(n_students== 0) 
				{
                    P("\n No grades have been entered. Please enter grades first.");
                    break;
                }
				int highest,lowest;
                highest = grades[0];
                lowest = grades[0];
                for (int i=1;i<n_students; i++) 
				{
                    if (grades[i]>highest)
					{
                        highest=grades[i];
                    }
                    if (grades[i]<lowest) 
					{
                        lowest=grades[i];
                    }
                }
                P("\n Highest grade: %d", highest);
                P("\n Lowest grade: %d", lowest);
                break;
            case 4:
                if (n_students== 0) 
				{
                    P("\n No grades have been entered. Please enter grades first.");
                    break;
                }
                int passed,failed; 
                passed = 0;
                failed = 0;
                for (int i=0;i<n_students;i++) 
				{
                    if (grades[i]>= 60) 
					{
                        passed++;
                    } 
					else 
					{
                        failed++;
                    }
                }
                P("\n Number of passed students: %d", passed);
                P("\n Number of failed students: %d", failed);
                break;
            case 5:
				P("\n Exiting the program. Goodbye!");
				break;      
        }
    }

}
