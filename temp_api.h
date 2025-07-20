//
// Created by User on 6/20/2025.
//

#ifndef TEMP_API_H
#define TEMP_API_H


typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureRecord;

int load_csv(const char* filename, TemperatureRecord* records, int max_records);


void print_monthly_avg(TemperatureRecord records[], int size, int month);
void print_monthly_min(TemperatureRecord records[], int size, int month);
void print_monthly_max(TemperatureRecord records[], int size, int month);

void print_yearly_avg(TemperatureRecord records[], int size);
void print_yearly_min(TemperatureRecord records[], int size);
void print_yearly_max(TemperatureRecord records[], int size);

void print_full_report(TemperatureRecord records[], int size);


void print_help(void);


#endif //TEMP_API_H
