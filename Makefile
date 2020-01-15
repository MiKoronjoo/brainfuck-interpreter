bfi: bfi.o
    gcc bfi.o -o bfi

bfi.o:
    gcc -c bfi.c

clean:
    rm *.o bfi
