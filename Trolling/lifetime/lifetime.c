#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> //This is for LC_NUMBERIC

//Process remaining lifespan
	//This is done using / and %.
	//gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
void	remaining_lifespan(unsigned int	totalseconds, unsigned int gender_sec)
{
	unsigned int	exyear, exmon, exweek, exday, exhour, exmin, exsec, remaining_seconds;
	
	remaining_seconds = gender_sec - totalseconds; //Get remaining seconds to process in y,m,w,d,h,m,s
	float percentage_lived = ((float)totalseconds / gender_sec) * 100; //Calculate percent lived
	float percentage_left = ((float)remaining_seconds / gender_sec) * 100; //Calculte percent left
	exyear = remaining_seconds / 31536000; //How many years using /
	remaining_seconds %= 31536000; //Get remaininder after calculating years by %
	exmon = remaining_seconds / (30.44 * 24 * 3600); //Approximate days in a month is 30.44
	remaining_seconds %= 2630016; //This is how many days left after months
	exweek = remaining_seconds / 604800; //calculate for weeks
	remaining_seconds %= 604800;
	exday = remaining_seconds / 86400; //calculate days
	remaining_seconds %= 86400;
	exhour = remaining_seconds / 3600; //calculate hours
	remaining_seconds %= 3600;
	exmin = remaining_seconds / 60; //calculate mins
	exsec = remaining_seconds % 60; //set last remaining secs
	printf("You still have \x1b[31m%d years\x1b[0m, \x1b[32m%d months\x1b[0m, \x1b[33m%d weeks\x1b[0m, \x1b[33m%d days\x1b[0m, \x1b[34m%d hours\x1b[0m, \x1b[34m%d minutes\x1b[0m, \x1b[34m%d seconds\x1b[0m left.\n", 
		exyear,
		exmon,
		exweek,
		exday,
		exhour,
		exmin,
		exsec);
	printf("You are \x1b[94m%%%.2f\x1b[0m through your current life and have \x1b[91m%%%.2f\x1b[0m left.\n", percentage_lived, percentage_left);
}
//This is for those whose life has exceeded average lifespan
	//Only diff is that totalseconds is more than expected lifespan
	//gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
void	over_LE(unsigned int totalseconds, unsigned int gender_sec)
{
	unsigned int	exyear, exmon, exweek, exday, exhour, exmin, exsec, remaining_seconds;
	
	printf("WOW u r a dino");
	remaining_seconds = totalseconds - gender_sec; //Get difference in seconds to process in y,m,w,d,h,m,s
	float percentage_more = (((float)remaining_seconds / gender_sec) * 100) - 100; //Calculte percent more
	exyear = remaining_seconds / 31536000; //How many years using /
	remaining_seconds %= 31536000; //Get remaininder after calculating years by %
	exmon = remaining_seconds / (30.44 * 24 * 3600); //Approximate days in a month is 30.44
	remaining_seconds %= 2630016; //This is how many days left after months
	exweek = remaining_seconds / 604800; //calculate for weeks
	remaining_seconds %= 604800;
	exday = remaining_seconds / 86400; //calculate days
	remaining_seconds %= 86400;
	exhour = remaining_seconds / 3600; //calculate hours
	remaining_seconds %= 3600;
	exmin = remaining_seconds / 60; //calculate mins
	exsec = remaining_seconds % 60; //set last remaining secs
	printf("You have lived %d years, %d months, %d weeks, %d days, %d hours, %d minutes, %d seconds more than expected!\n", 
		exyear,
		exmon,
		exweek,
		exday,
		exhour,
		exmin,
		exsec);
	printf("You have lived %%%.2f more than expected!", percentage_more);
}

char	*horoscope(int day, int mon)
{
	//For horoscope, got a few ways to do it: hardcoding months and converting bday to which day in the year
	if ((day >= 22 && mon == 12) || (day <= 19 && mon == 1))
		return ("♑  \x1b[31mCapricorn\x1b[0m ♑");
	if ((day >= 20 && mon == 1) || (day <= 18 && mon == 2))
		return ("♒  \x1b[34mAquarius\x1b[0m ♒");
	if ((day >= 19 && mon == 2) || (day <= 20 && mon == 3))
		return ("♓  \x1b[36mPisces\x1b[0m ♓");
	if ((day >= 21 && mon == 3) || (day <= 19 && mon == 4))
		return ("♈  \x1b[91mAries\x1b[0m ♈");
	if ((day >= 20 && mon == 4) || (day <= 20 && mon == 5))
		return ("♉  \x1b[33mTaurus\x1b[0m ♉");
	if ((day >= 21 && mon == 5) || (day <= 20 && mon == 6))
		return ("♊  \x1b[32mGemini\x1b[0m ♊");
	if ((day >= 21 && mon == 6) || (day <= 22 && mon == 7))
		return ("♋  \x1b[34mCancer\x1b[0m ♋");
	if ((day >= 23 && mon == 7) || (day <= 22 && mon == 8))
		return ("♌  \x1b[91mLeo\x1b[0m ♌");
	if ((day >= 23 && mon == 8) || (day <= 22 && mon == 9))
		return ("♍  \x1b[93mVirgo\x1b[0m ♍");
	if ((day >= 23 && mon == 9) || (day <= 22 && mon == 10))
		return ("♎  \x1b[35mLibra\x1b[0m ♎");
	if ((day >= 23 && mon == 10) || (day <= 21 && mon == 11))
		return ("♏  \x1b[31mScorpio\x1b[0m ♏");
	if ((day >= 22 && mon == 11) || (day <= 21 && mon == 12))
		return ("♐  \x1b[33mSagittarius\x1b[0m ♐");
}

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
        printf("\x1b[31mGREETINGS.\n\x1b[32mThis program will calculate how long you have been alive.\a\x1b[0m\n");
        printf("\x1b[33mEnter your birthday (DDMMYYYY) to begin.\x1b[0m\n");
        while (1)
        {
                if (scanf("%02d%02d%4d", &day, &month, &year) == 3)
                {
                        if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1 &&
                                year <= (local_time_info->tm_year + 1900))
                        {
                                printf("You have entered your birthday as: \x1b[36m%02d/%02d/%4d.\x1b[0m\n", day, month, year);
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
	//Horoscope processing starts
	printf("Your horoscope is: \x1b[35m%s\n\n\x1b[0m", horoscope(day, month));
	
        //Processing birthday input starts
        printf("To start, the current date and time is: \x1b[32m%02d/%02d/%4d  %02d:%02d:%02d.\x1b[0m\n", 
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
			tday = ((month_days[local_time_info->tm_mon + 1] - day) + local_time_info->tm_mday); // this formula calculates days remaining based on 1mon = 31 days
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Processing for those whose birthday has not passed yet
	if (!passed_bday)
        {
		int	nyear = local_time_info->tm_year + 1900 - tyear; //This was a mistake
                printf("You are now \x1b[33m%d\x1b[0m years,\x1b[33m%d\x1b[0m months, \x1b[33m%d\x1b[0m days, \x1b[33m%d\x1b[0m hours, \x1b[33m%d\x1b[0m minutes and \x1b[33m%d\x1b[0m seconds old.\n", 
                        local_time_info->tm_year + 1900 - tyear,
                        tmon,
                        tday,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);
		
		//Finding leap years
		int	leapyear = 0; //This will represent a leap year found. Days will add same number
		int	lyear = year; //This is to iterate through from bday till now
		//if (local_time_info->tm_mon + 1 >= 3 || (local_time_info->tm_mon + 1 == 2 && local_time_info->tm_mday == 29))
		//	leapyear += 1;
		while (lyear <= local_time_info->tm_year + 1900)
		{
			if ((lyear % 4 == 0 && lyear % 100 != 0) || (lyear % 400 == 0))
				leapyear++;
			lyear++;
		}

                //Processing for age in months
                int     totalmon = (12 * nyear) + tmon;
                printf("Your age in months is: \x1b[32m%'d.\x1b[0m\n", totalmon);

		//Processing for age in weeks
                int     i = 0;
                unsigned int	totaldays = 0;
                while (++i < local_time_info->tm_mon + 1)
                        totaldays += month_days[i];
		int	j = 13; //To count backwards from previous year's months since last bday
		while (--j > i)
                        totaldays += month_days[j];
                totaldays += nyear * 365;
		totaldays += tday + leapyear;
		int	totalweeks = totaldays / 7;
		if ((totaldays % 7))
			totalweeks -= 1;
		printf("Your age in weeks is: \x1b[32m%'d.\x1b[0m\n", totalweeks);

		//Processing for age in days
		printf("Your age in days is: \x1b[33m%'d.\x1b[0m\n", totaldays);

		//Processing for age in hours
		unsigned int	totalhours = ((totaldays * 24) + local_time_info->tm_hour);
		printf("Your age in hours is: \x1b[34m%'d.\x1b[0m\n", totalhours);

		//Processing for age in minutes
		unsigned int	totalmins = ((totalhours * 60) + local_time_info->tm_min);
		printf("Your age in minutes is: \x1b[34m%'d.\x1b[0m\n", totalmins);

		//Processing for age in seconds
		unsigned int	totalseconds = ((totalmins * 60) + local_time_info->tm_sec);
		printf("Your age in seconds is: \x1b[34m%'d.\x1b[0m\n", totalseconds);

		//Process life expectancy.
		printf("\x1b[33m--------------------------------------------------------------------------------------------------\n");
		printf("\x1b[32mThe program will now calculate how long you have to live.\x1b[0m\n");
		printf("It will be based on the life expectancy in \x1b[31mSingapore as of 2022.\x1b[0m\n");
		printf("This is \x1b[36m80.7 years for males\x1b[0m and \x1b[35m85.2 years for females\x1b[0m.\n");
		printf("\x1b[33;1m--------------------------------------------------------------------------------------------------\x1b[0m\n");
		printf("\x1b[36mIf you are MALE, these are your stats:\x1b[0m\n");
		unsigned int	gender_sec = 2546698320; //gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
		if (totalseconds > gender_sec)
			over_LE(totalseconds, gender_sec);

		//Process remaining lifespan
			//This is done using / and %.
		else
			remaining_lifespan(totalseconds, gender_sec);
		printf("\n");
		printf("\x1b[35mIf you are FEMALE, these are your stats:\x1b[0m\n");
		gender_sec = 2686299200; //gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
		if (totalseconds > gender_sec) 
			over_LE(totalseconds, gender_sec);

		//Process remaining lifespan
			//This is done using / and %.
		else
			remaining_lifespan(totalseconds, gender_sec);
		printf("\x1b[33;1m--------------------------------------------------------------------------------------------------\x1b[0m\n");
		printf("\x1b[1mProgram has ended.\n");
        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Processing for those whose birthday has passed
        if (day == local_time_info->tm_mday && month == local_time_info->tm_mon + 1)
                printf("It's your birthday! Idk why you'd be using this on your bday but happy birthday!\n");
        if (passed_bday)
        {
		int	nyear = local_time_info->tm_year + 1900 - year; //This was a mistake but nvm just use
		int	nmon = local_time_info->tm_mon + 1 - month;
		int	nday = local_time_info->tm_mday - day;
		if (local_time_info->tm_mday < day)
			{
				nday += 31;
				nmon -= 1;
			}
                printf("You are now \x1b[31m%d years\x1b[0m, \x1b[32m%d months\x1b[0m, \x1b[33m%d days\x1b[0m, \x1b[34m%d hours\x1b[0m, \x1b[34m%d minutes\x1b[0m, \x1b[34m%d seconds\x1b[0m old.\n", 
                        nyear,
                        nmon,
                        nday,
                        local_time_info->tm_hour,
                        local_time_info->tm_min,
                        local_time_info->tm_sec);

		//Finding leap years
		int	leapyear = 0; //This will represent a leap year found. Days will add same number
		int	lyear = year; //This is to iterate through from bday till now
		while (lyear <= local_time_info->tm_year + 1900)
		{
			if ((lyear % 4 == 0 && lyear % 100 != 0) || (lyear % 400 == 0)) //Leap year conditions
				leapyear++;
			lyear++;
		}

                //Processing for age in months
                int     totalmon = (12 * (nyear - 1)) + 
                        ((12 - month) + local_time_info->tm_mon);
                printf("Your age in months is: \x1b[32m%'d.\x1b[0m\n", totalmon);

		//Processing for age in weeks
                int     i = month + 1;
                unsigned int     totaldays = 0;
                while (i <= local_time_info->tm_mon + 1)
                {
                        totaldays += month_days[i];
                        i++;
                }
                totaldays += (nyear * 365);
		totaldays += (local_time_info->tm_mday - day) + leapyear;
		int	totalweeks = totaldays / 7;
		if ((totaldays % 7))
			totalweeks -= 1;
		printf("Your age in weeks is: \x1b[32m%'d.\x1b[0m\n", totalweeks);

                //Processing for age in days
		printf("Your age in days is: \x1b[33m%'d.\x1b[0m\n", totaldays);

		//Processing for age in hours
		unsigned int	totalhours = ((totaldays * 24) + local_time_info->tm_hour);
		printf("Your age in hours is: \x1b[34m%'d.\x1b[0m\n", totalhours);

		//Processing for age in minutes
		unsigned int	totalmins = ((totalhours * 60) + local_time_info->tm_min);
		printf("Your age in minutes is: \x1b[34m%'d.\x1b[0m\n", totalmins);

		//Processing for age in seconds
		unsigned int	totalseconds = ((totalmins * 60) + local_time_info->tm_sec);
		printf("Your age in seconds is: \x1b[34m%'d.\x1b[0m\n", totalseconds);

		//Process life expectancy.
		printf("\x1b[33m--------------------------------------------------------------------------------------------------\n");
		printf("\x1b[32mThe program will now calculate how long you have to live.\x1b[0m\n");
		printf("It will be based on the life expectancy in \x1b[31mSingapore as of 2022.\x1b[0m\n");
		printf("This is \x1b[36m80.7 years for males\x1b[0m and \x1b[35m85.2 years for females\x1b[0m.\n");
		printf("\x1b[33;1m--------------------------------------------------------------------------------------------------\x1b[0m\n");
		printf("\x1b[36mIf you are MALE, these are your stats:\x1b[0m\n");
		unsigned int	gender_sec = 2546698320; //gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
		if (totalseconds > gender_sec)
			over_LE(totalseconds, gender_sec);

		//Process remaining lifespan
			//This is done using / and %.
		else
			remaining_lifespan(totalseconds, gender_sec);
		printf("\n");
		printf("\x1b[35mIf you are FEMALE, these are your stats:\x1b[0m\n");
		gender_sec = 2686299200; //gender_sec is the expected lifespan in seconds of both genders; 2,686,299,200(F) & 2,546,698,320(M)
		if (totalseconds > gender_sec) 
			over_LE(totalseconds, gender_sec);

		//Process remaining lifespan
			//This is done using / and %.
		else
			remaining_lifespan(totalseconds, gender_sec);
		printf("\x1b[33;1m--------------------------------------------------------------------------------------------------\x1b[0m\n");
		printf("\x1b[1mProgram has ended.\n");
        }
}