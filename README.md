# BlitzMax for AmigaOS

This is amiga only fork of BlitzMax to minimize download.   At this time there is no MaxIDE and all programming and compiling is from the command line.

* Installing on AmigaOS4.X:

Install current AmigaOS SDK from:
http://www.hyperion-entertainment.biz/index.php/downloads?view=download&layout=form&file=82

cd _src\amiga
execute install

In user startp up modify a path add "path to bin"
ie.  path add work:blitzmax/bin

To create hello world

Notepad hello.bmx


```blitzmax
Print "Hello World"
```

Compiling

```
bmk makeapp hello
```
Run the newly created executable hello

A few of the samples are in the samples directory
compile all with simlar command lines.
bmk makeapp oldskool2
bmk makeapp breakout


