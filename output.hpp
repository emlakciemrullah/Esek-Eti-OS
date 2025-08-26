#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#define vga_start 0xb8000

void syswrite(const unsigned char *buffer, int row, unsigned char attribute){
    unsigned short *vga = (unsigned short *)vga_start;
    int index = row * 80, trow = row;

    while(*buffer){
        if(*buffer == '\n'){
            trow++;
            index = trow * 80;
            buffer++;
            continue;
        }
        vga[index] = *buffer | (attribute << 8);

        index++;
        buffer++;
    }
}

void sysclear(){
    unsigned short *vga = (unsigned short *)vga_start;
    unsigned short blank = ' ' | (0x0F << 8);

    for(int i = 0; i < 80 * 25; i++){
        vga[i] = blank;
    }
}


#endif
