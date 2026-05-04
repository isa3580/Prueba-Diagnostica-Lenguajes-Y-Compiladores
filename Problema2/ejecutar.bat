@echo off
color 0a
title Consola de Ejecucion - Problema 2
cls

echo =====================================================
echo           VALIDADOR DE CADENAS FEN (C)
echo =====================================================
echo.

:: 1. Verificar si existe el archivo .c
if not exist "problema2.c" (
    color 0c
    echo [ERROR] No se encontro el archivo 'problema2.c' en esta carpeta.
    echo Asegurate de que el .bat este en la misma carpeta que el codigo.
    pause
    exit
)

echo [INFO] Archivo detectado: problema2.c

:: 2. Intentar compilar
echo [INFO] Compilando...
gcc problema2.c -o problema2.exe 2> errores.txt

:: 3. Verificar si el comando 'gcc' funciono
if %errorlevel% neq 0 (
    if not exist validador_fen.exe (
        color 0c
        echo No se reconoce el comando 'gcc'. 
        echo.
        echo SOLUCION: Abre tu codigo en Dev-C++ y presiona F11. 
    ) else (
        color 0c
        echo Error de sintaxis en el codigo. Revisa 'errores.txt'.
    )
    pause
    exit
)

:: 4. Ejecutar si todo salio bien
echo Compilacion exitosa. Iniciando...
echo -----------------------------------------------------
echo.

problema2.exe

echo.
echo -----------------------------------------------------
echo Programa finalizado.
pause