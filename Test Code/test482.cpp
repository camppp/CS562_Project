#include <stdio.h>
#include <sys/sysinfo.h>

void displaySystemInfo() {
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) != 0) {
        fprintf(stderr, "Failed to retrieve system information\n");
        return;
    }

    printf("Total RAM: %lu KB\n", sys_info.totalram / 1024);
    printf("Free RAM: %lu KB\n", sys_info.freeram / 1024);
    printf("Total Swap: %lu KB\n", sys_info.totalswap / 1024);
    printf("Total Processes: %u\n", sys_info.procs);
}

int main() {
    displaySystemInfo();
    return 0;
}
