#include <stdio.h>
#include <string.h>

typedef struct {
    char question[150];
    char options[4][50];
    char correct_ans;
} Quiz;

int main() {
    Quiz list[3] = {
        {"What is the correct syntax to output 'Hello World' in Python?", {"print('Hello World')", "echo('Hello World')", "p('Hello World')", "printf('Hello World')"}, 'A'},
        {"Which data type is mutable in Python?", {"tuple", "list", "string", "integer"}, 'B'},
        {"How do you start a comment in Python?", {"//", "/*", "#", "<!--"}, 'C'}
    };

    char name[50], ans;
    int score = 0, choice;

    while (1) {
        printf("\n=== QUIZ SYSTEM ===\n1. Take Quiz\n2. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1 || choice == 2) break;

        if (choice == 1) {
            score = 0;
            printf("Enter name: ");
            scanf("%s", name);

            for (int i = 0; i < 3; i++) {
                printf("\nQ%d: %s\n", i + 1, list[i].question);
                for (int j = 0; j < 4; j++) {
                    printf("%c. %s\n", 'A' + j, list[i].options[j]);
                }
                printf("Your answer (A-D): ");
                scanf(" %c", &ans);
                if (ans >= 'a' && ans <= 'z') ans -= 32; 

                if (ans == list[i].correct_ans) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect! (Correct: %c)\n", list[i].correct_ans);
                }
            }
            printf("\n--- Result for %s ---\nScore: %d/3 (%.1f%%)\n", name, score, (score / 3.0) * 100);
        }
    }
    printf("Exiting...\n");
    return 0;
}
