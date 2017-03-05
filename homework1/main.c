#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


#define ANSI_COLOR_RED     "\x1b[31m" //с++
#define ANSI_COLOR_GREEN   "\x1b[32m" //c#
#define ANSI_COLOR_YELLOW  "\x1b[33m" //javascript
#define ANSI_COLOR_BLUE    "\x1b[34m" // python
#define ANSI_COLOR_MAGENTA "\x1b[35m" //java 
#define ANSI_COLOR_CYAN    "\x1b[36m" //c
#define ANSI_COLOR_RESET   "\x1b[0m"


void color_output(){
    printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");
}
void string_copy(char *from, char *to) {

    while ((*to++ = *from++) != '\0')
        ;
}

void print_dir(char *dir){
    DIR           *d;
    struct dirent *dir;
    char* one_filename = malloc(256);
    
    d = opendir(".");
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
            else{
                print_dir(dir->d_name);
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



}

struct Lang {
   char  title[256];
   char  author[256];
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
        color_output();
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