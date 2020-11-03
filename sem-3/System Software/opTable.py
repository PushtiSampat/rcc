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
