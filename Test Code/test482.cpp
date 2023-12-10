#include <stdio.h>
#include <sysinfo.h>

void display_system_info() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total RAM: %lu\n", info.totalram);
        printf("Free RAM: %lu\n", info.freeram);
        printf("Total swap space: %lu\n", info.totalswap);
        printf("Total number of processes: %d\n", info.procs);
    } else {
        printf("Error retrieving system information\n");
    }
}

int main() {
    display_system_info();
    return 0;
}
