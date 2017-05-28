make ej2_testeo;make ej2
python3 generador-ej2.py > temp_test1;./ej2_testeo < temp_test1; cat ejercicio2_test1.csv > ej2test1;
python3 generador-ej2-completo.py > temp_test2;./ej2_testeo < temp_test2; cat ejercicio2_test1.csv > ej2test2;
python3 generador-ej2-desconectadas.py > temp_test3;./ej2_testeo < temp_test3; cat ejercicio2_test1.csv > ej2test3;
python3 generador-ej2-fuertemente-conexa.py > temp_test4;./ej2_testeo < temp_test4; cat ejercicio2_test1.csv > ej2test4;
rm temp_test*;
