start=$1
end=$2

for ((num=start; num<end; num++))  # Change the loop condition to num<end
do
    current=$num #Store the current number for comparison
    reversed=0

    while [ $current -gt 0 ]
    do
        digit=$((current % 10))
        reversed=$(( reversed * 10 + digit ))
        current=$((current / 10))
    done

    if [ $num -eq $reversed ]
    then
        echo "$num"
    fi

done
