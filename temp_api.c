//
// Created by User on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"


int load_csv(const char* filename, TemperatureRecord* records, int max_records) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open error");
        return -1;
    }

    int count = 0;
    int line_num = 1;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        if (count >= max_records) {
            printf("Maximum record limit reached (%d).\n", max_records);
            break;
        }

        int y = 0, mo = 0, d = 0, h = 0, mi = 0, t = 0;


        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &y, &mo, &d, &h, &mi, &t) == 6) {
            if (y >= 1000 && mo >= 1 && mo <= 12 &&
                d >= 1 && d <= 31 &&
                h >= 0 && h <= 23 &&
                mi >= 0 && mi <= 59 &&
                t >= -99 && t <= 99) {

                records[count++] = (TemperatureRecord){y, mo, d, h, mi, t};

                } else {
                    printf("Invalid value range on line %d: %s", line_num, line);
                }
        } else {
            printf("Invalid format on line %d: %s", line_num, line);
        }

        line_num++;
    }

    fclose(file);
    return count;
}

void print_monthly_avg(TemperatureRecord records[], int size, int month) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++)
        if (records[i].month == month) {
            sum += records[i].temperature;
            count++;
        }
    if (count > 0)
        printf("Average monthly temperature %d: %.2f\n", month, (float)sum / count);
    else
        printf("No monthly data %d\n", month);
}

void print_monthly_min(TemperatureRecord records[], int size, int month) {
    int min = 100, found = 0;
    for (int i = 0; i < size; i++)
        if (records[i].month == month) {
            if (!found || records[i].temperature < min) min = records[i].temperature;
            found = 1;
        }
    if (found)
        printf("Monthly minimum %d: %d\n", month, min);
}

void print_monthly_max(TemperatureRecord records[], int size, int month) {
    int max = -100, found = 0;
    for (int i = 0; i < size; i++)
        if (records[i].month == month) {
            if (!found || records[i].temperature > max) max = records[i].temperature;
            found = 1;
        }
    if (found)
        printf("Monthly maximum %d: %d\n", month, max);
}

void print_yearly_avg(TemperatureRecord records[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += records[i].temperature;
    if (size > 0)
        printf("Annual average temperature: %.2f\n", (float)sum / size);
}

void print_yearly_min(TemperatureRecord records[], int size) {
    int min = 100;
    for (int i = 0; i < size; i++)
        if (records[i].temperature < min) min = records[i].temperature;
    printf("Minimum for the year: %d\n", min);
}

void print_yearly_max(TemperatureRecord records[], int size) {
    int max = -100;
    for (int i = 0; i < size; i++)
        if (records[i].temperature > max) max = records[i].temperature;
    printf("Maximum for the year: %d\n", max);
}

void print_full_report(TemperatureRecord records[], int size) {
    printf("#   Year     Month   Records  AvgTemp     MaxTemp  MinTemp\n");

    int year = (size > 0) ? records[0].year : 0;
    int total_count = 0;
    int total_sum = 0;
    int year_max = -100;
    int year_min = 100;

    for (int m = 1; m <= 12; m++) {
        int count = 0;
        int sum = 0;
        int max = -100;
        int min = 100;

        for (int i = 0; i < size; i++) {
            if (records[i].month == m) {
                int t = records[i].temperature;
                sum += t;
                if (t < min) min = t;
                if (t > max) max = t;
                count++;
            }
        }

        float avg = (count > 0) ? (float)sum / count : 0;

        if (count > 0) {
            printf("%2d  %4d   %5d   %7d   %7.2f   %7d   %7d\n",
                   m, year, m, count, avg, max, min);
        } else {
            printf("%2d  %4d   %5d   %7s   %7s   %7s\n",
                   m, year, m, "-", "-", "-");
        }

        total_count += count;
        total_sum += sum;
        if (count > 0) {
            if (min < year_min) year_min = min;
            if (max > year_max) year_max = max;
        }
    }

    float year_avg = (total_count > 0) ? (float)total_sum / total_count : 0;
    printf("\nYear statistics: average = %.2f, max = %d, min = %d\n",
           year_avg, year_max, year_min);
}



void print_help(void) {
    printf("Usage:\n");
    printf("  -h                Shows this message\n");
    printf("  -f <file.csv>     Choose CSV-file\n");
    printf("  -m <month>        Display statistics for a specific month\n");
}