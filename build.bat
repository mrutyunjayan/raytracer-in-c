@echo off
call J:\"Program Files (x86)"\"Microsoft Visual Studio"\2019\Community\VC\Auxiliary\Build\vcvarsall.bat x86_amd64
set opts=-FC -GR- -EHa- -nologo -Zi -W0
set code=%cd%
pushd build
clang-cl %opts% %code%\code\main.c -Feraytracer
popd
