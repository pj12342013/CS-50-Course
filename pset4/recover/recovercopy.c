#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("usage ./recover filename.type");
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];

    FILE* input = fopen(argv[1], "r");

    int jpeg_found = 0;

    int filecount = 0;

    FILE* picture = NULL;


    if(input == NULL)
    {
        printf("No JPEG detected");
        return 1;
    }

    while(fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] & 0xf0)
        {
            if (jpeg_found == 1)
            {
                fclose(input);
            }

            else
            {
                jpeg_found = 1;
            }


            char filename[8];
            sprintf(filename, "%03i.jpg", filecount);
            filecount++;
        }
        if(jpeg_found == 1 )
        {
            fwrite(buffer, BUFFER_SIZE, 1, picture);
        }
    }
    fclose(input);
    fclose(picture);

    return 0;
}