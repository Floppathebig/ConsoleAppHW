#include <stdio.h>
#include "temp_api.h"

int main() {
    TemperatureRecord data[] = {
        {2024, 1, 1, 10, 30, -5},
        {2024, 1, 2, 11, 15, 0},
        {2024, 2, 3, 12, 0, 3},
        {2024, 2, 4, 13, 45, 7},
        {2024, 3, 5, 14, 20, 12}
    };
    int size = sizeof(data) / sizeof(data[0]);


    print_monthly_avg(data, size, 1);
    print_monthly_min(data, size, 1);
    print_monthly_max(data, size, 1);

    print_yearly_avg(data, size);
    print_yearly_min(data, size);
    print_yearly_max(data, size);

    return 0;
}
