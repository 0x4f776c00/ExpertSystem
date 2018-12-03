#! /bin/bash

RED='\033[0;31m'
NC='\033[0m'
success=0
fail=0

mkdir -p output
cd tests
for OUT in *;
do
	echo $OUT
	../expert_system $OUT > ../output/$OUT 2>&1
	diff "../diff/$OUT" "../output/$OUT"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "${RED}$OUT KO${NC}"
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "${RED}$OUT Error diff${NC}"
	fi
	../expert_system $OUT -b > ../output/$OUT 2>&1
	diff "../diffb/$OUT" "../output/$OUT"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "${RED}b_$OUT KO${NC}"
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "${RED}$OUT Error diff${NC}"
	fi
done
echo $success "success"
echo $fail "fail"
