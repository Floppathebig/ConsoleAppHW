#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"

#define MAX_RECORDS 800000

int main(int argc, char* argv[]) {
    TemperatureRecord* records = malloc(sizeof(TemperatureRecord) * MAX_RECORDS);
    if (!records) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int count = 0;
    int month = 0;
    char* filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            print_help();
            return 0;
        } else if (!strcmp(argv[i], "-f") && i + 1 < argc) {
            filename = argv[++i];
        } else if (!strcmp(argv[i], "-m") && i + 1 < argc) {
            month = atoi(argv[++i]);
        }
    }

    if (!filename) {
        printf("Error: choose file with -f <filename>\n");
        return 1;
    }

    count = load_csv(filename, records, MAX_RECORDS);
    if (count <= 0) {
        printf("No data.\n");
        return 1;
    }

    if (month > 0) {
    print_monthly_avg(records, count, month);
    print_monthly_min(records, count, month);
    print_monthly_max(records, count, month);
} else {
    print_full_report(records, count);
}
    free(records);
    return 0;
}