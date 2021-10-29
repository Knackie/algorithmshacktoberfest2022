"""
Python3 program for Naive Pattern Search
Program that searches a text and returns all the indexes at which the substring is present in a string using naive search.
"""


def search(pat: str, txt: str) -> list:
    """
    :param pat: the substring to be found
    :type pat: str
    :param txt: the string in which pat needs to be found in
    :type txt: str
    :return: list with the indexes of the substring

    Tests:
    >>> search("ABA","AABAABAABAA")
    [1, 4, 7]
    >>> search("AB","ABABABABA")
    [0, 2, 4, 6]
    >>> search("1","ABCDE")
    []
    """

    pat_len = len(pat)
    txt_len = len(txt)
    indexes = []
    # Loop to iterate through the index of each element
    for x in range(txt_len - pat_len + 1):
        increment = 0
        while increment < pat_len:
            if txt[x + increment] != pat[increment]:
                # The elements of txt and pat are not equal.
                break

            # 1 is added to the increment to check against the next element in the next iteration.
            increment += 1

        # If the loop broke when the length of the pattern is equal to the
        # length of the substring sound in the text.
        # This implies, it is part of the text until pat is over.
        # This means that the pattern is in the text at that position.
        if increment == pat_len:
            indexes.append(x)

    return indexes


if __name__ == "__main__":
    pat = "AB"
    txt = "ABCDABBACDA"
    indexes = search(pat, txt)
    print(indexes)
