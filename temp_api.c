//
// Created by User on 6/20/2025.
//
#include <stdio.h>
#include "temp_api.h"




void print_monthly_avg(TemperatureRecord records[], int size, int month) {
    printf("Average temperature for month %02d\n", month);
}

void print_monthly_min(TemperatureRecord records[], int size, int month) {
    printf("Minimum temperature for month %02d\n", month);
}

void print_monthly_max(TemperatureRecord records[], int size, int month) {
    printf("Maximum temperature for month %02d\n", month);
}

void print_yearly_avg(TemperatureRecord records[], int size) {
    printf("Average temperature for the year\n");
}

void print_yearly_min(TemperatureRecord records[], int size) {
    printf("Minimum temperature for the year\n");
}

void print_yearly_max(TemperatureRecord records[], int size) {
    printf("Maximum temperature for the year\n");
}