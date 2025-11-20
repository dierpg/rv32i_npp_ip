# rv32i_npp_ip
Este es un core RISC-V adaptado de Goossens (2023) con el set de instrucciones 
RV32I.

## En desarrollo
```
- RV32F
```

## Simulacion

Asegurarse de tener instalado Vitis 2023.2, despues de eso se debe ejecutar:
```
vitis_hls -f script.tcl
```

## Testbench

Para modificar el testbench revise el archivo test_bench_rv32i_npp_ip.cpp, en el debe cargar
un archivo hex con las palabras del programa como se muestra desde la linea 4 a la 6.