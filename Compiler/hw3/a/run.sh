read -p "enter the test case number: " case_number
./stack_base <./input/${case_number}.in >./output/${case_number}.out
cat ./output/${case_number}.out