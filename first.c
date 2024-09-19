#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char * readline(FILE *fp, char *buffer)
{
    int ch;
    int i = 0;
    size_t buff_len = 0;

    buffer = malloc(buff_len + 1);
    if (!buffer) return NULL;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        buff_len++;
        void *tmp = realloc(buffer, buff_len + 1); 
        if (tmp == NULL) 
        {
            free(buffer);
            return NULL;
        }
        buffer = tmp;

        buffer[i] = (char) ch;
        i++;
    }
    buffer[i] = '\0';

    // Detect end
    if (ch == EOF && (i == 0 || ferror(fp)))
    {
        free(buffer);
        return NULL;
    }
    return buffer;
}

void lineByline(FILE * file, int option_nonblank, int option_showend)
{
    char *s;
    int i = 0; // 줄 번호

    // 가독성을 위해 이렇게 구현함
    while ((s = readline(file, 0)) != NULL)
    {
        if(option_nonblank)
        {
            i++;
            printf("%d  ", i);
        }
        printf("%s", s);
        free(s);
        if(option_showend)
        {
            printf("$\n");
        }
        else
        {
            printf("\n");
        }
    }
}

int main (int argc, char* argv[])
{
    FILE*  fd;
    char*  filename;
    int    option_nonblank = 0;
    int    option_showend = 0;
    int    c;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: cat ./file [option]\n");
        return -1;
    }

    filename = argv[1];

    // getopt는 리눅스에서만 사용 가능
    while ((c = getopt (argc, argv, "ENn")) != -1)
    {
        switch (c)
        {
            case 'E':
                option_showend = 1;
                continue;
            case 'n':
            case 'N':
                option_nonblank = 1;
                continue;
        }
    }

    // 파일 열기
    fd = fopen(filename, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: %s: file not found\n", filename);
        return -1;
    }
    lineByline(fd, option_nonblank, option_showend);
    return 0;
}
