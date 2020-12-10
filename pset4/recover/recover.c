#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("usage ./recover filename.type\n");
        return 1;
    }



    FILE* input = fopen("card.raw", "r");

    if(input == NULL)
    {
        printf("No JPEG detected\n");
        return 1;
    }

    FILE* picture = NULL;

    unsigned char buffer[BUFFER_SIZE];

    int jpeg_found = 0;

    int filecount = 0;

    while(fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] & 0xe0)
        {
            if (jpeg_found == 1)
            {
                fclose(picture);
            }

            else
            {
                jpeg_found = 1;
            }


            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            picture = fopen(filename, "w");
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
