#include"PQueue.h"

int compareDateTime(DateTime* dt1, DateTime* dt2) {
    if (dt1->year > dt2->year)
        return -1;
    else if (dt1->year < dt2->year)
        return 1;

    if (dt1->month > dt2->month)
        return -1;
    else if (dt1->month < dt2->month)
        return 1;

    if (dt1->day > dt2->day)
        return -1;
    else if (dt1->day < dt2->day)
        return 1;

    return 0;  // DateTime structs are equal
}