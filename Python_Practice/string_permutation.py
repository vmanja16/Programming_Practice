def permutations(s):
    # base case
    if len(s) == 1:
        return [s]

    returnList = []
    for index in range(len(s)):
        startChar = s[index]
        rest = s[:index] + s[index+1:]


        for perm in permutations(rest):
            returnList.append(startChar +  perm)

    return returnList

theList = permutations("abcd")
print(theList)
