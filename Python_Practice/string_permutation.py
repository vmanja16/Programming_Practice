def isUnique(string):
	"""
	Check string is unique using hash table
	"""
    table = {}
    for letter in string:
        if letter in table:
            return False
        else:
            table[letter] = 1
    return True


def isUnique2(string):
	"""
	Check string is unique w/o extra dataStructures
	"""
    for first in range(len(string)):
        for next in range(first+1,len(string)):
            if string[first] == string[next]:
                return False

    return True

	
def isPermutation(first,second):
	""" 
	Check if String B is a permuation of String A
    """
	# check same length
    if (len(first) != len(second)):
        return False

    table = {}

    # put first in a table
    for letter in first:
        if letter in table:
            table[letter] += 1
        else:
            table[letter] = 1

    # check second

    for letter in second:
        if letter in table:
            table[letter] -= 1
            if table[letter] < 0:
                return False
        else:
            return False

    return True


def isPalindromePermutation(string):
	"""
	Check if string is the permuation of a palindrome
	"""
    string = string.strip().lower()
    # Can only have one letter with and odd count
    table = {}

    # put character frequencies in a table
    for letter in string:
        if letter in table:
            table[letter] += 1
        else:
            table[letter] = 1

    # Palindromes can only have 1 odd max
    oddCount = False
    for number in table.values():
        if number & 1:
            if not oddCount:
                oddCount = True
            else:
                return False
            
    return True

def permutations(s):
	"""
	Return a list of permuations of a string
	"""
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

