@ECHO OFF

SET project=%cd%
SET code=%project%\code

IF NOT EXIST build MKDIR build

IF NOT DEFINED DevEnvDir (
	CALL "D:\VS\2019\VC\Auxiliary\Build\vcvars64.bat" >NUL
)

SET debug_flags=^
	-Zi^
	-Od^
	-MTd^
	-DEBUG

SET common_compiler_flags=^
	%debug_flags%^
	-nologo^
	-FC^
	-fp:fast^
	-GR-^
	-EHa-^
	-Oi^
	-MTd^
	-TC^
    -ferror-limit=50^
	-Wall^
	-WX^
    -Wno-unused-parameter^
    -Wno-cast-align^
    -Wno-unused-variable^
    -Wno-undef^
    -Wno-unused-macros^
    -Wno-extra-semi-stmt^
    -Wno-unused-function^
    -Wno-microsoft-anon-tag -fms-extensions^
    -Wno-missing-braces^
    -Wno-microsoft-include

SET defines=^
    -D_CRT_SECURE_NO_WARNINGS^
	-DJAI_SLOW=1^
    -DJAI_INTERNAL=1

SET linker_flags=^
	-link^
	-incremental:no^
	-opt:ref

SET include_directories=^
	-I %project%\include

PUSHD build

REM Preprecessor Output

clang-cl^
	%defines%^
	%include_directories%^
	%common_compiler_flags%^
    -c -P -C^
	%code%\main.c

REM COMPLILE
clang-cl^
	%defines%^
	%include_directories%^
	%common_compiler_flags%^
	%code%\main.c^
	-Feray

POPD
