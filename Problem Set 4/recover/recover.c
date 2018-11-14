#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
	// Buffer
	uint8_t buffer[512];
	// Get the file name
	char *infile = argv[1];
	// Counter for file name
	int counter = 0;
	// File to write
	FILE *outfile = NULL;

	// Ensure proper usage
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./recover image\n");
        return 1;
	}

	// Open input file
    FILE *file = fopen(infile, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Iterate over file content
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
    	// Check if the first four bytes are a JPEG signature
    	if (buffer[0] == 0xff && buffer[1] == 0xd8 && 
    		buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
    	{
    		// Close the file, if it is opened
            if (outfile != NULL)
                fclose(outfile);
            
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            // Open a new JPEG file for writing
            outfile = fopen(filename, "w");
            
            counter++;
    	}

    	if (outfile != NULL)
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
    }

     if (outfile != NULL)
        fclose(outfile);
    
    fclose(file);

	return 0;
}