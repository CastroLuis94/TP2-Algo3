make ej2_testeo;make ej2;
echo 'Generando Tests'

echo "Generando 1"
python3 generador_ej2.py > temp_test1;
echo "Generando 2"
python3 generador_ej2_completo.py > temp_test2;
echo "Generando 3"
python3 generador_ej2_desconectadas.py > temp_test3;
echo "Generando 4"
python3 generador_ej2_fuertemente_conexa.py > temp_test4;
echo "Generando 5"
python3 generador_ej2_random_fijo.py > temp_test5;
echo "Generando 6"
python3 generador_ej2_fc_fijo.py > temp_test6;
echo 'Inicia Test 1';
./ej2_testeo < temp_test1; cat ejercicio2_test1.csv > ej2test1;
echo 'Finaliza Test'
echo 'Inicia Test 2';
./ej2_testeo < temp_test2; cat ejercicio2_test1.csv > ej2test2;
echo 'Finaliza Test'
echo 'Inicia Test 3';
./ej2_testeo < temp_test3; cat ejercicio2_test1.csv > ej2test3;
echo 'Finaliza Test'
echo 'Inicia Test 4';
./ej2_testeo < temp_test4; cat ejercicio2_test1.csv > ej2test4;
echo 'Finaliza Test'
echo 'Inicia Test 5';
./ej2_testeo < temp_test5; cat ejercicio2_test1.csv > ej2test5;
echo 'Finaliza Test'
echo 'Inicia Test 6';
./ej2_testeo < temp_test6; cat ejercicio2_test1.csv > ej2test6;
echo 'Finaliza Test'
