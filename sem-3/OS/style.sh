ls -l | tr -s ' ' |cut -d ' ' -f 1-9 -s | awk '{print $1" | "$3" |\033[36;1m "$9 "\033[0m"}'

# ---------- apply style on your string ----------
# https://stackoverflow.com/questions/2924697/how-does-one-output-bold-text-in-bash

# 1. echo -e: The `-e` option means that escaped (backslashed) strings will be interpreted
# 2. \033: escaped sequence represents beginning/ending of the style
# 3. lowercase m: indicates the end of the sequence
# 4. 1: Bold attribute (see below for more)
# 5. [0m: resets all attributes, colors, formatting, etc.

# 0 - Normal Style
# 1 - Bold
# 2 - Dim
# 3 - Italic
# 4 - Underlined
# 5 - Blinking
# 7 - Reverse
# 8 - Invisible
