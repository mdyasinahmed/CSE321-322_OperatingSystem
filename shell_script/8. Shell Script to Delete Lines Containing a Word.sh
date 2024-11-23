for file in "$@"; do
    if [ -f "$file" ]; then
        sed -i "/$2/d" "$file"
    else
        echo "$file does not exist."
    fi
done

