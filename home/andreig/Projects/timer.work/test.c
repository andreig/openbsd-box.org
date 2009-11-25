#include <stdio.h>

float timetotal, minutes, hours;
int main (void)
{
	timetotal= 3610;
	minutes = timetotal / 60.0;
	timetotal -= (int) minutes*60.0;
	minutes = (int) minutes;
	hours = minutes / 60.0;
	minutes -= (int) hours*60;
	hours = (int) hours;
	printf("Time Elapsed: %02.0f:%02.0f:%02.0f (H:M:S)\n",hours, minutes, timetotal);
	//sleep(1);
	//printf("%s\n",timestring);
	//sprintf(timestring,"Time Elapsed: %.0lf:%.0lf:%.0lf (H:M:S)",hours, minutes, timetotal);
}
