#include "PQueue.h"
int daysSince2000(Date date) {
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = 0;
    int years = date.year - 2000;

    days = years * 365 + years / 4 - years / 100 + years / 400;

    for (int i = 0; i < date.month - 1; i++) {
        days += monthDays[i];
    }

    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0) && date.month > 2) {
        days += 1;
    }

    days += date.day;

    return days;
}