#! /bin/bash

RED='\033[0;31m'
NC='\033[0m'
success=0
fail=0

mkdir -p output
cd tests
for OUT in *;
do
	../expert_system $OUT > ../output/$OUT 2>&1
	diff "../diff/$OUT" "../output/$OUT"
	if [ $? == 1 ]
	then
		echo -e "${RED}$OUT KO${NC}"
		((fail++))
	else
		((success++))
	fi
	../expert_system $OUT -b > ../output/$OUT 2>&1
	diff "../diffb/$OUT" "../output/$OUT"
	if [ $? == 1 ]
	then
		echo -e "${RED}b_$OUT KO${NC}"
		((fail++))
	else
		((success++))
	fi
done
echo $success "success"
echo $fail "fail"
