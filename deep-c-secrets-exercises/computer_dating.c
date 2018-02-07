/*
 Computer Dating
 When will the time_t's wrap around? Write a program to find out.
 1. Look at the definition of time_t. This is in file /usr/include/time.h.
 2. Code a program to place the highest value into a variable of type time_t, then
    pass it to ctime() to convert it into an ASCII string. Print the string.
    Note that ctime has nothing to do with the language C,
    it just means "convert time."
 For how many years into the future does the anonymous technical writer who removed
 the comment have to worry about being dogged by a UNIX daemon?
 Amend your program to find out.
 1. Obtain the current time by calling time().
 2. Call difftime() to obtain the number of seconds between now and the highest
		value of time_t.
 3. Format that value into years, months, weeks, days, hours, and minutes. Print it.
 Is it longer than your expected lifetime?
 */

#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

/* on Ubuntu time_t is defined as long int */

int main() {
	time_t max = LONG_MAX;
	while (gmtime(&max) == 0) {
		max /= 2;
	}
	printf("The final time is %s \n", asctime(gmtime(&max)));
	time_t current = time(&current);
	time_t seconds = difftime(max, current);
	long unsigned years = seconds / 60 / 60 / 24 / 365; // more or less :)
	seconds = seconds - (years * 365 * 24 * 60 * 60);
	long unsigned months = seconds / 60 / 60 / 24 / 30; // more or less :)
	seconds = seconds - (months * 30 * 24 * 60 * 60);
	long unsigned days = seconds / 60 / 60 / 24;
	seconds = seconds - (days * 24 * 60 * 60);
	long unsigned hours = seconds / 60 / 60;
	seconds = seconds - (hours * 60 * 60);
	long unsigned minutes = seconds / 60;

	printf("The daemon will awake in %ld years, %ld months, %ld days, %ld hours,"
			" %ld minutes...\nmore or less", years, months, days, hours, minutes);
}

