#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


void string_copy(char *from, char *to) {

    while ((*to++ = *from++) != '\0')
        ;
}

struct Lang {
   char  title[50];
   char  author[];
   char  subject[100];
   int   book_id;
};

int main() {

    // 4 for files
    // 8 for dirs
    DIR           *d;
    struct dirent *dir;
    char* one_filename = malloc(256);
    d = opendir(".");



    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            //printf("%d\n", dir->d_type);
            //printf("%s\n", one_filename);

            if(dir->d_type != DT_DIR){
                printf("%s\n", dir->d_name);
                string_copy(dir->d_name, one_filename);
                if(one_filename[0] != '.'){
                    printf("%s\n", one_filename);
                    char iter = 0;
                    int iter_num = 0;
                    while(iter != '\0'){
                        iter = one_filename[iter_num];
                        iter_num += 1;
                    }
                }
            }  
            // ecли имя не . и не ..
            //if(dir->d_type == directory)
                // рекурсивный вызов
                //printf("%s\n", dir->d_name);
            string_copy(dir->d_name, one_filename);
/*
                if(one_filename[0] != '.'){
                    printf("%s\n", one_filename);
                    char iter = 0;
                    int iter_num = 0;
                    while(iter != '\0'){
                        iter = one_filename[iter_num];
                        iter_num += 1;
                    }
                }
*/
        }

        closedir(d);
    }

    return(0);
}