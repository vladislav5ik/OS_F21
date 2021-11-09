#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    struct input_event ev;
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (fd == -1){
        printf("can't open file");
        return -1;
    }
    ssize_t n;
    while (1) {
        n = read(fd, (void *) &ev, sizeof(ev));
        int type = (int)ev.type;
        if (type == 0){
            printf("RELEASED");
        } else if (type == 1){
            printf("PRESSED");
        } else if (type == 4){ //on my computer REPEATED type is 4
            printf("REPEATED");
        }
        printf(" code: 0x%04x (%d), value: %d\n",
                (int)ev.code, (int)ev.code, (int)ev.value);
    }
    return 0;
}
