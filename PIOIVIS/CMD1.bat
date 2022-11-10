::Ввод Данных:: 
@echo putipapki = %1
set size=1024
::Проверка на наличие папки::
if exist "%1" (
    @echo ------------Papka Naydena--------------
    dir %1 /o:s | find ".txt">result.txt
    for /f "delims=" %%i in (result.txt) do set "var=%%i" & Goto :print
    :print
    set var=%var:~36%
    del result.txt
    cd /d %1
    ren "%var%" deletedfile.txt
    forfiles /M *.txt /C "cmd /c if @fsize LSS %size% (del /f "%1\deletedfile.txt") "
) else (
    @echo ------------Takoy Papki Net--------------
    timeout 5
    pause
)
pause
