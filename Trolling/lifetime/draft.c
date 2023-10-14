#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int     main()
{
        //Setting timezones
        setenv("TZ", "Asia/Singapore", 1); //set TZ environment variable to Singapore TZ.
        tzset(); //Update tz info
        time_t current_time;
        struct tm *local_time_info;
        time(&current_time); //Get current time
        local_time_info = localtime(&current_time); //convert current time to SG TZ

        //Obtaining birthday input
        int     day, month, year;
        printf("GREETINGS.\nThis is program will calculate how long you have been alive.\n");
        printf("Enter your birthday (DDMMYYYY) to begin.\n");
        while (1)
        {
                if (scanf("%02d%02d%4d", &day, &month, &year) == 3)
                {
                        if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1000 &&
                                year <= (local_time_info->tm_year + 1900))
                        {
                                printf("You have entered your birthday as: %02d/%02d/%4d.\n", day, month, year);
                                break;
                        }
                        else
                        {
                                printf ("Brudder please input your birthday in this format: DDMMYYYY.");
                                scanf("%*[^\n]");
                        }
                }
                else
                {
                        printf("You have entered an invalid number of arguments, use this format: DDMMYYY only.\n");
                        scanf("%*[^\n]");
                }
        }
        //Processing birthday input starts
        printf("To start, the current date and time is: %02d/%02d/%4d  %02d:%02d:%02d.\n", 
                local_time_info->tm_mday,
                local_time_info->tm_mon + 1,
                local_time_info->tm_year + 1900,
                local_time_info->tm_hour,
                local_time_info->tm_min,
                local_time_info->tm_sec);
        //Processing basic lifetime
        int     month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //days in the months
        int     passed_bday = 1;
        int     yetyear, yetmonth, yetday = 0;
        if (local_time_info->tm_mon + 1 < month) //if current month is less than bmonth - means bday hasn't passed.
        {
                yetyear = year + 1; //minus 1 to year age 
                yetmonth = ((12 - month) + local_time_info->tm_mon + 1); //current 10/07 == bmon 10/10 - now 9 months old 12 - (10-7)
                passed_bday = 0;
        }
        if (local_time_info->tm_mon + 1 == month && local_time_info->tm_mday < day) // 10/10 == 15/10
        {
                yetyear = year + 1;
                yetmonth = 11;
                yetday = (month_days[month] - (day - local_time_info->tm_mday));
                passed_bday = 0;
        }
        if (day == local_time_info->tm_mday && month == local_time_info->tm_mon + 1)
                printf("It's your birthday! Idk why you'd be using this on your bday but happy birthday!\n");
        if (passed_bday) //if bday has passed
        {
                printf("You are now %d years, %d months, %d days, %d hours, %d minutes and %d seconds old.\n", 
                        local_time_info->tm_year + 1900 - year,
                        local_time_info->tm_mon + 1 - month,
                        local_time_info->tm_mday - day,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);
                //Processing for age in months
                int     totalmon = (12 * (local_time_info->tm_year + 1900 - year - 1)) + 
                        ((12 - month) + local_time_info->tm_mon + 1);
                printf("Your age in months is: %d", totalmon);
                //Processing for age in days
                int     i = 1;
                int     totaldays;
                while (i < local_time_info->tm_mon + 1)
                {
                        totaldays += month_days[i];
                        i++;
                }
        }
        else if (!passed_bday)
        {
                printf("You are now %d years, %d months, %d days, %d hours, %d minutes and %d seconds old.\n", 
                        local_time_info->tm_year + 1900 - yetyear,
                        yetmonth,
                        yetday,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);
                //Processing for age in months
                int     totalmon = (12 * (local_time_info->tm_year + 1900 - yetyear)) + yetmonth;
                printf("Your age in months is: %d", totalmon);
        }
        
        //Processing for age in days
        /*
        int     totaldays;
        int     i = 1;
        
        while (i < month)
        */
}