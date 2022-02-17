// struct contains arrays for every number in different lines
struct Numbers {
    const char *zero[7] = {
            "  ***  ",
            " *   * ",
            "*     *",
            "*     *",
            "*     *",
            " *   * ",
            "  ***  ",
    };
    const char *one[7] = {
            "     **",
            "    * *",
            "   *  *",
            "      *",
            "      *",
            "      *",
            "      *",
    };
    const char *two[7] = {
            "  **** ",
            "**    *",
            "      *",
            "    ** ",
            "  **   ",
            "**     ",
            "*******",
    };
    const char *three[7] = {
            " ***** ",
            "**   **",
            "     **",
            "   **  ",
            "     **",
            "**   **",
            " ***** ",
    };
    const char *four[7] = {
            "*     *",
            "*     *",
            "*     *",
            "*******",
            "      *",
            "      *",
            "      *",
    };
    const char *five[7] = {
            "*******",
            "*      ",
            "****** ",
            "      *",
            "      *",
            "*     *",
            " ***** ",
    };
    const char *six[7] = {
            " ******",
            "**     ",
            "*      ",
            "****** ",
            "*     *",
            "*     *",
            " ***** ",
    };
    const char *seven[7] = {
            "*******",
            "      *",
            "     **",
            "    ** ",
            "   **  ",
            "  **   ",
            "  **   ",
    };
    const char *eight[7] = {
            " ***** ",
            "*     *",
            "*     *",
            " ***** ",
            "*     *",
            "*     *",
            " ***** ",
    };
    const char *nine[7] = {
            " ***** ",
            "*     *",
            "*     *",
            " ******",
            "      *",
            "      *",
            " ***** ",
    };
};

//                                  functions to print all numbers

// receives structure and index and returns string with that index from structure
const char *printZero(Numbers nums, int index) {
    return nums.zero[index];
}

const char *printOne(Numbers nums, int index) {
    return nums.one[index];
}

const char *printTwo(Numbers nums, int index) {
    return nums.two[index];
}

const char *printThree(Numbers nums, int index) {
    return nums.three[index];
}

const char *printFour(Numbers nums, int index) {
    return nums.four[index];
}

const char *printFive(Numbers nums, int index) {
    return nums.five[index];
}

const char *printSix(Numbers nums, int index) {
    return nums.six[index];
}

const char *printSeven(Numbers nums, int index) {
    return nums.seven[index];
}

const char *printEight(Numbers nums, int index) {
    return nums.eight[index];
}

const char *printNine(Numbers nums, int index) {
    return nums.nine[index];
}