make ej2_testeo;make ej2;
echo 'Inicia Test 5';
python3 generador_ej2_random_fijo.py > temp_test5;./ej2_testeo < temp_test5; cat ejercicio2_test1.csv > ej2test5;
echo 'Finaliza Test'
echo 'Inicia Test 6';
python3 generador_ej2_fc_fijo.py > temp_test6;./ej2_testeo < temp_test6; cat ejercicio2_test1.csv > ej2test6;
echo 'Finaliza Test'
