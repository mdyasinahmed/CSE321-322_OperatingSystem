for file in "$@"; do
    if [ -f "$file" ]; then
        tr 'a-z' 'A-Z' < "$file" > "${file^^}"
    else
        echo "$file does not exist."
    fi
done
