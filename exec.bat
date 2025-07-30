@echo off

set root_dir=%cd%
set src_dir=%root_dir%\src
set include_dir=%root_dir%\dll\include

set /a cont=0

if %1==limpar (
    call :limpa
) else if %1==copiar (
    call :copia_lib
) else if %1==build (
    call :limpa
    call :copia_lib
) else if %1==push (
    call :push
)

goto :fim

:limpa
    del /s /q %include_dir%\*

    echo Foi efetuada a limpesa
exit /b 0

:copia_lib
    xcopy %src_dir% %include_dir% /s /q
    del /s /q %include_dir%\*.cpp

    echo Foi realizada a copia dos arquivos de cabecalho
exit /b 0

:push
    git add .

    set /p msg="Commit MSG: "
    git commit -m "%msg%"

    git push -u origin main
exit /b 0

:fim
if ErrorLevel = 0 echo Finalizado com sucesso!
if ErrorLevel = 1 echo Houve um erro.
