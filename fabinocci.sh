echo "Enter the number of terms of the series:"
read n
echo "The series are:"

a=0
b=1

for((i=0;i<n;i++))
do
    echo "$a"
    r=$(( $a + $b))
    a=$b
    b=$r
done