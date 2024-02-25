while :
do
    echo "menu :"
    echo "1.Addition"
    echo "2. Subtraction"
    echo "3. Division"
    echo "4. Modulus"

    echo "Enter choice:"
    read choice

    if [ $choice -eq 1 ]
    then
        echo "Enter num1:"
        read a
        echo "Enter num2:"
        read b
        result=$(($a + $b ))
        echo "result = $result"

    elif [ $choice -eq 2 ]
    then
         echo "Enter num1:"
        read a
        echo "Enter num2:"
        read b
        result=$(($a - $b ))
        echo "result = $result"

    elif [ $choice -eq 3 ]
    then
         echo "Enter num1:"
        read a
        echo "Enter num2:"
        read b
        result=$(($a / $b ))
        echo "result = $result"

     elif [ $choice -eq 4 ]
    then
         echo "Enter num1:"
        read a
        echo "Enter num2:"
        read b
        result=$(($a % $b ))
        echo "result = $result"
    fi

done