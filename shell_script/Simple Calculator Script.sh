echo "Enter first number: "
read num1
echo "Enter second number: "
read num2
echo "Enter operator (+, -, *, /): "
read operator

case $operator in
    +) result=$(echo "$num1 + $num2" | bc);;
    -) result=$(echo "$num1 - $num2" | bc);;
    *) result=$(echo "$num1 * $num2" | bc);;
    /)
        if [ $num2 -eq 0 ]; then
            echo "Division by zero is not allowed."
            exit 1
        else
            result=$(echo "$num1 / $num2" | bc);
        fi;;
    *) echo "Invalid operator"; exit 1;;
esac

echo "The result is: $result"
