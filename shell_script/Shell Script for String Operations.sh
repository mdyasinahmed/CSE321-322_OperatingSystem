string="$1"
substring="${string:3:5}"  # Extracts substring from index 3 of length 5
length="${#string}"         # Finds the length of the string

echo "Substring: $substring"
echo "Length: $length"
