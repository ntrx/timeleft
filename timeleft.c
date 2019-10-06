#include <stdio.h>
#include <time.h>

int main(void) {
	printf("Timeleft Organizer v1.05 starting...\n");
	// init	
	int days;
	int hours;
	int mins;
	
	int res_mons, res_days, res_hours, res_mins;
	int left_hours, left_mins;
	
	int months[12][2] = { {1,31},
						  {2,28},
						  {3,31},
						  {4,30},
						  {5,31},
						  {6,30},
						  {7,31},
						  {8,31},
						  {9,30},
						  {10,31},
						  {11,30},
						  {12,31}};
						  						   
	time_t t ;
	// get current time
	t = time(NULL);
	struct tm tm = *localtime(&t);
	
	int status = 1;
	// core
	while (status) {
		printf("Current time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
		printf("input values:\n");
		printf("input days: ");
		scanf("%d", &days);
		printf("input hours: ");
		scanf("%d", &hours);
		printf("input minutes: ");
		scanf("%d", &mins);
				
		// get current time
		t = time(NULL);
		tm = *localtime(&t);
		res_mons = tm.tm_mon+1;
		res_days = tm.tm_mday+days;
		
		left_hours = 23 - tm.tm_hour;
		left_mins = 59 - tm.tm_min;		
		
		if ((res_days - months[tm.tm_mon][1]) >= 1) {
			res_mons += 1;
			res_days = (res_days - months[tm.tm_mon-1][1]);
		}
		
		if (hours > left_hours) {
			res_days += 1;
		}
		
		res_hours = (tm.tm_hour+hours)%24;
		if (res_hours == 24) {
			res_days += 1;
			res_hours = 0;
		}
		res_mins = tm.tm_min+mins;
		if (res_mins >= 60) {
			res_mins %= 60;
			res_hours += 1;
		}

	
		// output
		printf("DATA:\n %02d.%02d %02d:%02d\n", res_mons, res_days, res_hours, res_mins);
		printf("\nif need more, type '1': ");
		scanf("%d",&status);
	}
	
	return 0;
}

// changes:
// v1.01
// last: 19.08.2017

// [fix] - new time calculated after minutes are inputed.
// [fix 30.08.17] - no more adding one day default.
// --ver. 1.03

// [fix 24.05.19] - min error (00:60:00) now displayed like regular (01:00:00)
// [fix 24.05.19] - month end is normally calced without edge fault (32.05)
// [fix 24.05.19] - while day not ends correctly working turning to next day
// --- ver. 1.04

// [fix 01.09.19] - fix month offset
// --- ver. 1.05

// [fix 20.09.10] - fix non-initialized time on startup
