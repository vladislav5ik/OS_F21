#include <stdio.h>
#include <dirent.h>

int main(){
    DIR *dirp = opendir("/");
    if (dirp == NULL) {
        return -1;
    }
    struct dirent *file;
    while ((file = readdir(dirp)) != NULL) {
      printf("\n%s", file->d_name);
    }
    closedir(dirp);
    return 0;
}
