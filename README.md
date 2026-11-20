# Quiz and Score Management System

## C Programming Mini Hackathon - UPES

### Project Information

- **Project Title:** Quiz and Score Management System
- **Course:** C Programming Lab
- **Batch:** 51
- **Team Members:**
  - Atharva Aggarwal
  - Sanidhaya
  - Akshit

---

## 1. Problem Statement

The **Quiz and Score Management System** is a command-line application developed using the C programming language.

The program presents multiple-choice questions to a participant, accepts answers, checks whether the answers are correct, and calculates the participant's final score and percentage.

The main purpose of this project is to apply basic C programming concepts to create a simple and functional quiz application.

---

## 2. Objectives

The main objectives of this project are:

- To develop a simple menu-driven quiz application.
- To store quiz questions, options, and correct answers.
- To accept the participant's name and answers.
- To display questions one by one.
- To check answers automatically.
- To calculate the final score.
- To calculate the percentage obtained by the participant.
- To demonstrate fundamental C programming concepts.

---

## 3. Features

The current program provides the following features:

- Simple command-line interface.
- Menu with **Take Quiz** and **Exit** options.
- Stores questions using a C structure.
- Four options for every question: A, B, C, and D.
- Accepts uppercase and lowercase answers.
- Immediate feedback after every answer.
- Automatic score calculation.
- Percentage calculation.
- Displays the participant's name and final result.
- Allows another quiz attempt after completing a quiz.

---

## 4. C Programming Concepts Used

The project uses the following C programming concepts:

### Structures

A `struct` is used to store the question, four options, and correct answer together.

```c
typedef struct {
    char question[150];
    char options[4][50];
    char correct_ans;
} Quiz;
```

### Arrays

Arrays are used to store multiple quiz questions and their options.

### Strings

Character arrays are used to store the participant's name, questions, and answer options.

### Loops

- `while` loop is used for the main menu.
- `for` loop is used to display questions.
- A nested `for` loop is used to display the four options.

### Conditional Statements

`if` and `else` statements are used to:

- Check the menu choice.
- Check whether an answer is correct.
- Convert lowercase answers to uppercase.

### Input and Output

`printf()` and `scanf()` are used to communicate with the user.

---

## 5. Program Working

The program works according to the following steps:

1. Start the program.
2. Initialize the quiz questions and correct answers.
3. Display the main menu.
4. User selects:
   - `1` - Take Quiz
   - `2` - Exit
5. If **Take Quiz** is selected:
   - Reset score to `0`.
   - Ask for the participant's name.
   - Display each question.
   - Display four options from A to D.
   - Accept the participant's answer.
   - Convert lowercase input to uppercase if required.
   - Compare the answer with the stored correct answer.
   - Increase the score for every correct answer.
6. After all questions are completed:
   - Display participant's name.
   - Display final score.
   - Calculate and display percentage.
7. Return to the main menu.
8. Exit when the user selects option `2`.

---

## 6. Algorithm

```text
START

Initialize quiz questions
Set score = 0

Display Main Menu

1. Take Quiz
2. Exit

Read user choice

IF choice = 1

    Set score = 0
    Input participant name

    FOR every question

        Display question
        Display options A-D

        Input answer

        Convert answer to uppercase if required

        IF answer = correct answer
            Display "Correct!"
            Increase score
        ELSE
            Display "Incorrect!"
            Display correct answer
        END IF

    END FOR

    Calculate percentage
    Display name, score and percentage

ELSE
    Exit program

END IF

END
```

---

## 7. Source Code

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char question[150];
    char options[4][50];
    char correct_ans;
} Quiz;

int main() {
    Quiz list[3] = {
        {"What is the correct syntax to output 'Hello World' in Python?",
         {"print('Hello World')", "echo('Hello World')",
          "p('Hello World')", "printf('Hello World')"}, 'A'},

        {"Which data type is mutable in Python?",
         {"tuple", "list", "string", "integer"}, 'B'},

        {"How do you start a comment in Python?",
         {"//", "/*", "#", "<!--"}, 'C'}
    };

    char name[50], ans;
    int score = 0, choice;

    while (1) {
        printf("\n=== QUIZ SYSTEM ===\n");
        printf("1. Take Quiz\n");
        printf("2. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1 || choice == 2)
            break;

        if (choice == 1) {
            score = 0;

            printf("Enter name: ");
            scanf("%s", name);

            for (int i = 0; i < 3; i++) {
                printf("\nQ%d: %s\n", i + 1, list[i].question);

                for (int j = 0; j < 4; j++) {
                    printf("%c. %s\n",
                           'A' + j,
                           list[i].options[j]);
                }

                printf("Your answer (A-D): ");
                scanf(" %c", &ans);

                if (ans >= 'a' && ans <= 'z')
                    ans -= 32;

                if (ans == list[i].correct_ans) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect! (Correct: %c)\n",
                           list[i].correct_ans);
                }
            }

            printf("\n--- Result for %s ---\n", name);
            printf("Score: %d/3 (%.1f%%)\n",
                   score,
                   (score / 3.0) * 100);
        }
    }

    printf("Exiting...\n");

    return 0;
}
```

---

## 8. How to Compile and Run

### Using GCC

Save the source code as:

```text
quiz.c
```

Compile the program:

```bash
gcc quiz.c -o quiz
```

Run on Windows:

```bash
quiz.exe
```

Run on Linux/macOS:

```bash
./quiz
```

The program can also be compiled and executed using a suitable C IDE/compiler.

---

## 9. Sample Output

```text
=== QUIZ SYSTEM ===
1. Take Quiz
2. Exit
Enter choice: 1

Enter name: Atharva

Q1: What is the correct syntax to output 'Hello World' in Python?
A. print('Hello World')
B. echo('Hello World')
C. p('Hello World')
D. printf('Hello World')

Your answer (A-D): A
Correct!

Q2: Which data type is mutable in Python?
A. tuple
B. list
C. string
D. integer

Your answer (A-D): B
Correct!

Q3: How do you start a comment in Python?
A. //
B. /*
C. #
D. <!--

Your answer (A-D): C
Correct!

--- Result for Atharva ---
Score: 3/3 (100.0%)
```

---

## 10. Score Calculation

The percentage is calculated using:

```text
Percentage = (Score / Total Questions) × 100
```

For example, if the participant answers 2 out of 3 questions correctly:

```text
Percentage = (2 / 3) × 100
           = 66.7%
```

In the C program:

```c
(score / 3.0) * 100
```

`3.0` is used so that floating-point division is performed and decimal percentages can be displayed.

---

## 11. Current Limitations

The current version is a basic prototype and has some limitations:

- It currently contains only **3 questions**.
- Questions are fixed inside the source code.
- Scores are not saved permanently.
- There is no leaderboard.
- The participant's name input does not support spaces properly.
- Answer validation can be improved to strictly accept only A-D.
- A performance category is not currently displayed.

---

## 12. Future Improvements

The project can be improved by adding:

- At least 5 or more quiz questions.
- More quiz categories.
- Random question selection.
- Different difficulty levels.
- Performance categories such as Excellent, Good, Average, etc.
- File handling to save participant scores.
- Multiple participant records.
- Leaderboard functionality.
- Better input validation.
- Timer-based questions.
- Improved user interface.

---

## 13. Conclusion

The **Quiz and Score Management System** is a simple C programming project that demonstrates the practical use of structures, arrays, strings, loops, conditional statements, user input, and arithmetic calculations.

The program successfully presents multiple-choice questions, checks the participant's answers, calculates the score, and displays the final percentage.

The project provided practical experience in designing program logic, implementing a menu-driven application, testing the program, and working collaboratively as a team.

---

## Team Members

**Batch 51**

- **Atharva Aggarwal**
- **Sanidhaya**
- **Akshit**

**UPES - C Programming Mini Hackathon**
