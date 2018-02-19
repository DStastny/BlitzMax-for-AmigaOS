# BlitzMax for AmigaOS4.X

This is AmigaOS4.X only fork of BlitzMax to minimize download.   At this time there is no MaxIDE as maxgui modules have yet to be ported.

Graphics support is currently with MiniGL.
Tested on Wazp3d however it is missing some of the proper masking and is painfully slow under emulation.

All programming favorite text editor and compiling is from the command line.

* Installing on AmigaOS4.X:

Install current [AmigaOS SDK](http://www.hyperion-entertainment.biz/index.php/downloads?view=download&layout=form&file=82)


```
cd <installdir>_src\amiga
```
execute install

In userstartp up modify a path add "path to bin"

```
;BEGIN BMX
Assign BMX: <installdir>
path add BMX:bin
;END BMX
```


To create hello world

Notepad hello.bmx


```blitzmax
Print "Hello World"
```

**Compiling**

```
bmk makeapp hello
```
Run the newly created executable hello

A few of the samples are in the samples directory
compile all with simlar command lines.
```
bmk makeapp oldskool2
```
```
bmk makeapp breakout
```

Thanks to Mark Sibly for making this available under a very liberal Zlib licensing.

All feedback and comments from any more experienced AmigaOS Coders appreciated as my experience on platform is limited.


