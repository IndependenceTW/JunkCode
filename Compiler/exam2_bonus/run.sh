read -p "enter the test case number: " case_number
g++ follow.cpp -o follow
./follow <${case_number}.in >${case_number}.out
cat ${case_number}.out
