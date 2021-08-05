# Raylib-BorderMaster

> You need mingw installed to

> ```https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download```

## Installing mingw
> (1) When installing if on windows please make sure to change architecutre to x86_64
>
>  (2) ![Installation(1)](https://user-images.githubusercontent.com/79944945/128419345-ae1f83fe-0290-41ef-ae49-29877cf6ea89.png)

> (3) keep trach of the file location and follow these instructions
> 
> (4) ![Installation(2)](https://user-images.githubusercontent.com/79944945/128420310-2ffca41f-2927-4171-aaa5-fdb6969728d2.png)
> 
> (5) you will be greeted with a screen that looks like this:
>
>(6) ![installation(3)](https://user-images.githubusercontent.com/79944945/128420393-d46ad773-77eb-4b67-b976-48636c8e20f8.png)





> here is command to build the file (can also do this in a make file(command use on windows))
>```g++ ../main.cpp -o game.exe -o1 -Wall -std=c++11 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm```
