@ECHO off
REM Valid values are:
REM  - clean: Will erase the contents of the bin/ directory
REM  - build: Will build the project
REM  - run: Will run the executable (builds the project if not built already)

FOR %%G IN (%*) DO (
    IF /I "%%G" == "CLEAN" (
        echo clean!!
        rd /s /q bin
        mkdir bin
    ) ELSE IF /I "%%G" == "BUILD" (
        echo build!!
        IF NOT EXIST "bin" (mkdir bin)
        make tests
    ) ELSE IF /I "%%G" == "RUN" (
        echo run!!
        IF NOT EXIST "bin" (mkdir bin)
        make run-tests
    )
)