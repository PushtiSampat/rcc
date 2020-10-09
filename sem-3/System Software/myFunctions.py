from opTable import opTable


def inSingleQuotes(word):
    count = word.count('\'')
    if count == 2:
        return True
    return False


def numBetweenQuotes(word):
    s = ""
    start = False
    for letter in word:
        if start is True and letter == '\'':
            return s
        if start is True:
            s += letter
        if letter == "'":
            start = True


def inOpTable(word):
    for dict_item in opTable:
        if word.strip(",") in dict_item:
            return True


def inListOf(twoDList, word):
    for x in twoDList:
        if x[0] == word:
            return True
    return False


def assignAddress(twoDList, word, value):
    for x in twoDList:
        if x[0] == word:
            x[1] = value


def printTableData(literalTable, symbolTable, poolTable):
    print("\nLiteral Table")
    print("-------------")
    for x in literalTable:
        print(x)

    print("\nSymbol Table")
    print("-------------")
    for x in symbolTable:
        print(x)

    print("\nPool Table")
    print("-------------")
    for x in poolTable:
        print(x)
