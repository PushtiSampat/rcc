assemblerDirectives = {"START": 1, "END": 2, "ORIGIN": 3,
                       "EQU": 4, "LTORG": 5, }

declarativeStatements = {"DC": 1, "DS": 2, }

imperativeStatements = {
    "STOP": 0, "ADD": 1, "SUB": 2, "MULT": 3, "MOVER": 4,
    "MOVEM": 5,
    "COMP": 6, "BC": 7, "DIV": 8, "READ": 9, "PRINT": 10,
}

registers = {"AREG": 1, "BREG": 1, "CREG": 1, "DREG": 1, }

flags = {"LT": 1, "LE": 1, "EQ": 1, "GT": 1, "GE": 1, "ANY": 1, }

opTable = [assemblerDirectives, declarativeStatements,
           imperativeStatements, registers, flags]


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

literalTable, symbolTable, poolTable = [], [], []


loc_cntr = 0
poolTableCount = 1
f = open("input2.txt", "r")
for line in f:
    for word in line.split():
        if word == "START":
            loc_cntr = int(line.split()[-1]) - 1
            break

        if word == "MOVER" or word == "MOVEM" or word == "PRINT" or word == "ADD" or word == "READ":
            loc_cntr = int(loc_cntr) + 1  # loc_cntr + 1
            lastWord = line.split()[-1]
            if inSingleQuotes(lastWord):
                num = numBetweenQuotes(lastWord)
                if not inListOf(literalTable, num):
                    literalTable.append([num, "-"])
            else:
                if not inListOf(symbolTable, lastWord):
                    symbolTable.append([lastWord, "-"])
            break

        if word == "LTORG" or word == "END":
            poolTable.append(poolTableCount)

        if word[0] == '=':
            poolTableCount += 1
            num = numBetweenQuotes(word)
            loc_cntr += 1
            assignAddress(literalTable, num, loc_cntr)

        if not inOpTable(word):
            if not line.split()[0][0] == '=':
                if not inListOf(symbolTable, word):
                    firstWord = line.split()[0]
                    secondWord = line.split()[1]
                    if not (secondWord == 'DS' or secondWord == 'DC'):
                        symbolTable.append([word, "-"])
                    else:
                        loc_cntr += 1
                        assignAddress(symbolTable, firstWord, loc_cntr)
                    if line.split()[0] == word:
                        assignAddress(symbolTable, word, loc_cntr + 1)
                        pass
poolTable.append(poolTableCount)

printTableData(literalTable, symbolTable, poolTable)
f.close()
