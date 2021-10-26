#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "sys/types.h"

int main(){
    DIR *dirp = opendir("tmp/");
    if (dirp == NULL) {
        return -1;
    }

    //storing files information into array
    //each entry contain information about the inode and the name of the file
    struct dirent *files[100], *file;
    int files_count = 0;
    while ((file = readdir(dirp)) != NULL) {
      files[files_count] = file;
      files_count += 1;
    }

    //solution by looking through all files with all other files for a link
    for (int i = 0; i < files_count; i++) {
        // count how many hard links the file has
        int link_count = 0;
        for (int j = 0; j < files_count; j++) {
            // check if files are linked
            if (files[i]->d_ino == files[j]->d_ino) {
                link_count += 1;
            }
        }
        //display all links if there is more than one
        if (link_count > 1) {
            printf("\n%s - ", files[i]->d_name);
            for (int j = 0; j < files_count; ++j) {
                if (files[i]->d_ino == files[j]->d_ino)
                    printf("%s, ", files[j]->d_name);
            }
        }
    }
    closedir(dirp);
    return 0;
}
