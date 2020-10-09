from myFunctions import (inSingleQuotes, numBetweenQuotes,
                         inOpTable, inListOf, assignAddress, printTableData)


literalTable, symbolTable, poolTable = [], [], []


loc_cntr = 0
poolTableCount = 1
f = open("input.txt", "r")
for line in f:
    for word in line.split():
        if word == "START":
            loc_cntr = int(line.split()[-1]) - 1
            break

        if word == "MOVER":
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
