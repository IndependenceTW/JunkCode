read -p "enter the test case number: " case_number
./matrix <./input/${case_number}.in >./output/${case_number}.out
cat ./output/${case_number}.out