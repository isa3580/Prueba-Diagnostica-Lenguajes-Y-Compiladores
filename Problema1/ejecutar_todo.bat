@echo off
setlocal
title Pipeline de Ejecucion - Problema 1 (C++ & Java)
color 0a

:: Limpiar consola
cls
echo =====================================================
echo    SISTEMA DE COMPILACION Y EJECUCION AUTOMATICA
echo           PROYECTO: EXPANSION BINOMIAL
echo =====================================================
echo.

:: 1. VERIFICACION DE ARCHIVOS FUENTE
echo [PASO 1] Verificando archivos fuente...
set "faltan_archivos=0"

if not exist "Problema1.java" (
    echo [ERROR] No se encuentra Problema1.java
    set "faltan_archivos=1"
)
if not exist "problema1.cpp" (
    echo [ERROR] No se encuentra problema1.cpp
    set "faltan_archivos=1"
)

if "%faltan_archivos%"=="1" (
    color 0c
    echo.
    echo Asegurese de que los archivos .java y .cpp esten en esta carpeta.
    pause
    exit
)
echo [OK] Archivos detectados correctamente.
echo.

:: 2. COMPILACION C++
echo [PASO 2] Compilando modulo C++ (Memoria Dinamica)...
:: Usamos g++ para el archivo .cpp
g++ problema1.cpp -o modulo_cpp.exe
if %errorlevel% neq 0 (
    color 0c
    echo [CRITICO] Error al compilar C++. Verifique el codigo.
    pause
    exit
)
echo [OK] Ejecutable de C++ generado.
echo.

:: 3. COMPILACION JAVA
echo [PASO 3] Compilando modulo Java...
javac Problema1.java
if %errorlevel% neq 0 (
    color 0c
    echo [CRITICO] Error al compilar Java. Verifique el JDK.
    pause
    exit
)
echo [OK] Clases de Java generadas.
echo.

:: 4. EJECUCION
echo =====================================================
echo           INICIANDO PRUEBAS DE EJECUCION
echo =====================================================
echo.

echo --- EJECUTANDO MODULO C++ (Triangulo de Pascal) ---
modulo_cpp.exe
echo.
echo -----------------------------------------------------
echo --- EJECUTANDO MODULO JAVA (Expansion Binomial) ---
java Problema1
echo.

:: 5. FINALIZACION
echo =====================================================
echo            PROCESO FINALIZADO EXITOSAMENTE
echo =====================================================
echo.
echo Los resultados se han guardado en los archivos .txt correspondientes.
echo.
pause