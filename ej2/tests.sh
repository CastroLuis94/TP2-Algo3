make ej2_testeo;make ej2;
echo 'Inicia Test 1';
python3 generador-ej2.py > temp_test1;./ej2_testeo < temp_test1; cat ejercicio2_test1.csv > ej2test1;
echo 'Finaliza Test'
echo 'Inicia Test 2';
python3 generador-ej2-completo.py > temp_test2;./ej2_testeo < temp_test2; cat ejercicio2_test1.csv > ej2test2;
echo 'Finaliza Test'
echo 'Inicia Test 3';
python3 generador-ej2-desconectadas.py > temp_test3;./ej2_testeo < temp_test3; cat ejercicio2_test1.csv > ej2test3;
echo 'Finaliza Test'
echo 'Inicia Test 4';
python3 generador-ej2-fuertemente-conexa.py > temp_test4;./ej2_testeo < temp_test4; cat ejercicio2_test1.csv > ej2test4;
echo 'Finaliza Test'
