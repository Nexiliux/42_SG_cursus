#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> //This is for LC_NUMBERIC

int     main()
{
	//Setting locales
	setlocale(LC_NUMERIC, "en_US.UTF-8");// Set the locale to use commas as thousands separators
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
                                printf ("Brudder please input your birthday in this format: DDMMYYYY.\n");
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
        int     tyear, tmon, tday = 0; //Setting temporary variables
        int	passed_bday = 1; //Default setting of whether birthday has passed

	//Check if birthday has passed yet
		//This processes the temporary variables for bef bday
	if (local_time_info->tm_mon + 1 < month) //if current month is less than bmonth - means bday hasn't passed.
        {
                tyear = year + 1; //minus 1 to year age
		if (local_time_info->tm_mday >= day) //current day has passed bday
		{
			tmon = ((12 - month) + local_time_info->tm_mon + 1); //months lived
			tday = (local_time_info->tm_mday - day);
		}
		if (local_time_info->tm_mday < day) //current day haven't pass bday
		{
                	tmon = ((12 - month) + local_time_info->tm_mon + 1 - 1);//current 10/07 == bmon 10/10 - now 9 months old cos 12 - (10-7)
			tday = ((31 - day) + local_time_info->tm_mday); // this formula calculates days remaining based on 1mon = 31 days
		}
                passed_bday = 0;
        }
        if (local_time_info->tm_mon + 1 == month && local_time_info->tm_mday < day) // 10/10 == 15/10 ; day hasn't passed yet
        {
                tyear = year + 1;
                tmon = 11;
                tday = ((31 - day) + local_time_info->tm_mday);
                passed_bday = 0;
        }

	//Processing for those whose birthday has not passed yet
	if (!passed_bday)
        {
                printf("You are now %d years, %d months, %d days, %d hours, %d minutes and %d seconds old.\n", 
                        local_time_info->tm_year + 1900 - tyear,
                        tmon,
                        tday,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);
		
		//Finding leap years
		int	leapyear = 0;
		int	lyear = year;
		while (year <= local_time_info->tm_year + 1900)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				leapyear++;
			lyear++;
		}

                //Processing for age in months
                int     totalmon = (12 * (local_time_info->tm_year + 1900 - tyear)) + tmon;
                printf("Your age in months is: %'d.\n", totalmon);

		//Processing for age in weeks
                int     i = 1;
                unsigned int	totaldays = 0;
                while (i < month)
                {
                        totaldays += month_days[i];
                        i++;
                }
                totaldays += (local_time_info->tm_year + 1900 - tyear) * 365;
		totaldays += tday + leapyear;
		int	totalweeks = totaldays / 7;
		if ((totaldays % 7))
			totalweeks -= 1;
		printf("Your age in weeks is: %'d.\n", totalweeks);

		//Processing for age in days
		printf("Your age in days is: %'d.\n", totaldays);

		//Processing for age in hours
		unsigned int	totalhours = ((totaldays * 24) + local_time_info->tm_hour);
		printf("Your age in hours is: %'d.\n", totalhours);

		//Processing for age in minutes
		unsigned int	totalmins = ((totalhours * 60) + local_time_info->tm_min);
		printf("Your age in minutes is: %'d.\n", totalmins);

		//Processing for age in seconds
		unsigned int	totalseconds = ((totalmins * 60) + local_time_info->tm_sec);
		printf("Your age in seconds is: %'d.\n", totalseconds);

		//Process life expectancy.

		printf("Program has ended.");
        }
	//Processing for those whose birthday has passed
        if (day == local_time_info->tm_mday && month == local_time_info->tm_mon + 1)
                printf("It's your birthday! Idk why you'd be using this on your bday but happy birthday!\n");
        if (passed_bday)
        {
                printf("You are now %d years, %d months, %d days, %d hours, %d minutes and %d seconds old.\n", 
                        local_time_info->tm_year + 1900 - year,
                        local_time_info->tm_mon + 1 - month,
                        local_time_info->tm_mday - day,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);

		//Finding leap years
		int	leapyear = 0; //This will represent a leap year found. Days will add same number
		int	lyear = year; //This is to iterate through from bday till now
		while (year <= local_time_info->tm_year + 1900)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) //Leap year conditions
				leapyear++;
			lyear++;
		}

                //Processing for age in months
                int     totalmon = (12 * (local_time_info->tm_year + 1900 - year - 1)) + 
                        ((12 - month) + local_time_info->tm_mon + 1);
                printf("Your age in months is: %'d.\n", totalmon);

		//Processing for age in weeks
                int     i = month + 1;
                unsigned int     totaldays = 0;
                while (i <= local_time_info->tm_mon + 1)
                {
                        totaldays += month_days[i];
                        i++;
                }
                totaldays += ((local_time_info->tm_year + 1900 - year) * 365);
		totaldays += (local_time_info->tm_mday - day) + leapyear;
		int	totalweeks = totaldays / 7;
		if ((totaldays % 7))
			totalweeks -= 1;
		printf("Your age in weeks is: %'d.\n", totalweeks);

                //Processing for age in days
		printf("Your age in days is: %'d.\n", totaldays);

		//Processing for age in hours
		unsigned int	totalhours = ((totaldays * 24) + local_time_info->tm_hour);
		printf("Your age in hours is: %'d.\n", totalhours);

		//Processing for age in minutes
		unsigned int	totalmins = ((totalhours * 60) + local_time_info->tm_min);
		printf("Your age in minutes is: %'d.\n", totalmins);

		//Processing for age in seconds
		unsigned int	totalseconds = ((totalmins * 60) + local_time_info->tm_sec);
		printf("Your age in seconds is: %'d.\n", totalseconds);

		//Process life expectancy.
		printf("--------------------------------------------------------------------\n");
		printf("The program will now calculate how long you have to live.\n");
		printf("It will be based on the life expectancy in Singapore as of 2022.\n");
		printf("This is 80.7 years for males and 85.2 years for females.\n");
		unsigned int	exyear, exmon, exweek, exday, exhour, exmin, exsec;
		//Find difference for males || add percentages to everything
		printf("If you are MALE, these r ur stats.\n");
		if (totalseconds > 2545278000)
		{
			printf("WOW u r an old dood");
			int	diff = totalseconds - 2545278000;
			float percentage = ((float)diff / 2545278000) * 100;
			printf("You have lived %%%.2d more than 80.7 years.\n", percentage);
			printf("You are now %d years, %d months, %d days, %d hours, %d minutes and %d seconds older than the life expectancy.\n", 
			local_time_info->tm_year + 1900 - year,
			local_time_info->tm_mon + 1 - month,
			local_time_info->tm_mday - day,
			local_time_info->tm_hour,
			local_time_info->tm_min,
			local_time_info->tm_sec);
			exyear = diff / 31540000;
			exmon = diff / 2628000;
			exweek = diff / 604800;
			exday = diff / 86400;
			exhour = diff / 3600
		}
		totalseconds - 
		printf("Program has ended.");
        }
}