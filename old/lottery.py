def extract_lottery_numbers(string, numbers_left):
    """
    All conditions are taken care of except "no duplicate numbers"
    """

    # ---------------------------------------------------------------------------- #
    #                                   BASE CASE                                  #
    # ---------------------------------------------------------------------------- #

    # Base Case where we found one correct pick
    if len(string) == 0 and numbers_left == 0:
        return [""]

    # Base Cases where we found wrong pick
    bad_case1 = len(string) == 0 and numbers_left != 0
    bad_case2 = len(string) != 0 and numbers_left == 0

    # Can't consider a 0 as a number anywher
    # Not a base case but a wrong pick
    bad_case3 = len(string) != 0 and string[0] == '0'

    # if encounter any wrong pick, return empty result
    if bad_case1 or bad_case2 or bad_case3:
        return []

    # ---------------------------------------------------------------------------- #
    #                                RECURSIVE CASE                                #
    # ---------------------------------------------------------------------------- #

    # List to store all possible answers
    ans = []

    # --------------------- OPTION1: SELECT ONLY SINGLE DIGIT -------------------- #

    # select only single digit, recursive call for the remaining string
    values = extract_lottery_numbers(string[1:], numbers_left - 1)

    # Append the selected digit to the answers of the remaining string
    ans = [string[0] + " " + value for value in values]

    # ------------------------ OPTION2: SELECT TWO DIGITS ------------------------ #

    # Opiton2 is valid only if there are ateleast 2 digits remaining in the string
    # and the first digit is less than '6'
    if len(string) >= 2 and string[0] < '6':

        # select two digits, recursive call for the remaining string
        values = extract_lottery_numbers(string[2:], numbers_left - 1)

        # append the selected digits to the answers of the remaining string
        ans += [string[:2] + " " + value for value in values]

    # ---------------------------------------------------------------------------- #

    return ans


def remove_those_with_repititions(possibilities):
    """
    Given a set of picks remove those where numbers occur more than once
    """

    filterd_possibilities = []

    for poss in possibilities:
        x = poss.strip().split()
        if (len(x) == len(set(x))):
            filterd_possibilities.append(poss.strip())

    return filterd_possibilities


if __name__ == "__main__":
    t = int(input().strip())

    while t > 0:
        lottery = input().strip()
        possibilities = extract_lottery_numbers(lottery, 7)
        possibilities = remove_those_with_repititions(possibilities)
        possibilities.sort()
        for poss in possibilities:
            print(f"{lottery} -> {poss.strip()}")
        t -= 1
