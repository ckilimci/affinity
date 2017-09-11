#include <stdio.h>
#include <stdlib.h>
#define __USE_GNU
#include <sched.h>
#include <unistd.h>

#define PROCESS_LIMIT 10

static int process = 1;

void do_process() {
	while (1) {
	};
}

int main(int argc, char*argv[]){
    const int first_cpu = 1;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(first_cpu, &cpuset);

    int pid = fork();
    if (pid) {
        printf("First Task!\n");
        CPU_ZERO(&cpuset);
        CPU_SET(first_cpu, &cpuset);
        pid_t this_pid = getpid();
        sched_setaffinity(this_pid, sizeof(cpu_set_t), &cpuset);
        sched_getaffinity(this_pid, sizeof(cpu_set_t), &cpuset);
        if (CPU_ISSET(first_cpu, &cpuset)) {
            printf("First thread Pid:%d CPU:%d\n", this_pid, first_cpu);
        }
        int wait = 1000000000;
        while (wait>0) {
            wait--;
        }
        return 0;
    }

    int children_cpu;
    while (process < PROCESS_LIMIT) {
        pid = fork();
        if (pid) {
            CPU_ZERO(&cpuset);
            if (0 == process % 4) 
                children_cpu = 2;
            else 
                children_cpu = 3;    
            CPU_SET(children_cpu, &cpuset);
            pid_t this_pid = getpid();
            sched_setaffinity(this_pid, sizeof(cpu_set_t), &cpuset);
            sched_getaffinity(this_pid, sizeof(cpu_set_t), &cpuset);
            if (CPU_ISSET(children_cpu, &cpuset)) {
                printf("Children:%d Pid:%d CPU:%d\n", process, this_pid, children_cpu);
            }
            do_process();
            return 0;
        }
        process++;
    }

    return 0;
}
