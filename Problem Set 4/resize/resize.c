// Problem Set 4 - Resize (less comfortable)
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // Remember scale factor and filenames
    int scale_size = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Create outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;
    
    // Rescale the new dimension for the outfile
    out_bi.biWidth *= scale_size;
    out_bi.biHeight *= scale_size;

    // Determine padding for scanlines of both infile and outfile
    int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Determine the outfile biSizeImage and bfSize (biSizeImage + 54 bytes header files)
    out_bi.biSizeImage = abs(out_bi.biHeight) * (out_bi.biWidth * sizeof(RGBTRIPLE) + out_padding);
    out_bf.bfSize = (out_bi.biSizeImage + 54);
    
    // Write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < scale_size; j++)
        {
            // Set pointer to beginning of line
            fseek(inptr, 54 + (bi.biWidth * 3 + in_padding) * i, SEEK_SET);
            
            // Iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // Temporary storage
                RGBTRIPLE triple;
        
                // Read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // Iterate each pixel n times
                for (int l = 0; l < scale_size; l++)
                {
                    // Write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // Then add it back to outfile
            for (int y = 0; y < out_padding; y++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // Success
    return 0;
}
