# Questions

## What's `stdint.h`?

`stdint.h` is a header file in the C standard library that allows programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, along with the defined min and max values for each type, using macros.

TODO

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are unsigned and signed integer types from `stdint.h`. Using well-defined types makes the code far easier and safer to port since you won't get any surprises when one machine interprets int as 16-bit and another as 32-bit. What you type is what you get when you use them.

TODO

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

- `BYTE` - 1 byte (8 bits)
- `DWORD` - 4 bytes (32 bits)
- `LONG` - 4 bytes (32 bits)
- `WORD` - 2 bytes (16 bits)

TODO

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must contain an ASCII B and an ASCII M. In hex, the first two bytes should be 0x424D (B is 0x42 and M is 0x4D). A little-endian `uint16_t` would see this 0x4D42 because the least significant value is stored in the least significant bit.

TODO

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the BMP file. `biSize` is the the size of the structure.

TODO

## What does it mean if `biHeight` is negative?

If `biHeight` is positive, the image is bottom up. If `biHeight` is negative, the image is bottom down.

TODO

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` specifies the BMP's color depth - the number of bits per pixel.

TODO

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

`fopen` might return a NULL pointer if the file that fopen is trying to open doesn't exist.

TODO

## Why is the third argument to `fread` always `1` in our code?

`fread`'s third argument is always 1 because we are iterating over every pixel.

TODO

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 = 3`. This step ensures the number of bytes in every row is a multiple of 4.

TODO

## What does `fseek` do?

`fseek` allows us to change the offset of a pointer.

TODO

## What is `SEEK_CUR`?

`SEEK_CUR` is the current position indicator in the file.

TODO

## Whodunit?

It was Professor Plum with the candlestick in the library.

TODO
