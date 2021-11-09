#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//define keyboard codes for some letters on my computer
#define C 46
#define A 30
#define P 25
#define E 18
#define V 47
#define S 31


int main(){
    struct input_event ev;
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (fd == -1){
        printf("can't open file");
        return -1;
    }

    printf("This program recognizes shortcuts.\n");
    printf("Avaliable shortcuts are: PE, CAP, VS\n");
    ssize_t n;
    // queue to recognize letter sequences
    int queue[] = {0,0,0};
    while (1) {
        n = read(fd, (void *) &ev, sizeof(ev));
        int code = (int)ev.code;
        if ((int)ev.type == 1 && (int)ev.value == 1){ //when pressed the button
            //updating queue
            queue[0] = queue[1];
            queue[1] = queue[2];
            queue[2] = code;

            //check if shortcut was pressed
            if (queue[1] == P && queue[2] == E){
                printf("I passed the Exam!\n");
            }
            if (queue[0] == C && queue[1] == A && queue[2] == P){
                printf("Get some cappuccino!\n");
            }
            if (queue[1] == V && queue[2] == S){
                printf("Vladislav Spigin\n");
            }
        }
    }
    return 0;
}

