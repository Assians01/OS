# This shell program counts the number of words, characters, white spaces, and special symbols in a given text.
# Get the text from the user.
read -p "Enter the text: " text
# Count the number of words.
num_words=$(echo $text | wc -w)
# Count the number of characters.
num_chars=$(echo $text | wc -c)
# Count the number of white spaces.
num_spaces=$(echo $text | tr -cd '[:space:]' | wc -c)
# Count the number of special symbols.
num_special=$(echo $text | tr -cd '[:punct:]' | wc -c)
# Print the results.
echo "Number of words: $num_words"
echo "Number of characters: $num_chars"
echo "Number of white spaces: $num_spaces"
echo "Number of special symbols: $num_special"