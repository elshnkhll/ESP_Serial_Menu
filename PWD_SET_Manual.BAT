@echo off
START PuTTY.exe -serial COM30 -sercfg "115200,8,n,1,N"
rem                        ^- put port number of the RECORDER here
rem pause
