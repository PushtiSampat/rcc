# import re


# text = "Jaii Swaminarayan"
# result = re.search("^Jai", text)
# # result = re.findall("\d", text)

# if result:
#     print(result)
# else:
#     print(result)
import re

txt = "hello world"

#Check if the string ends with 'world':

x = re.findall("world$", txt)
if x:
  print("Yes, the string ends with 'world'")
else:
  print("No match")

