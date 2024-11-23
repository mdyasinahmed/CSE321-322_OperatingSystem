for i in {1..5}
do
    for j in {1..5}
    do
        result=$((i * j))
        echo -n "$result "
    done
    echo
done
