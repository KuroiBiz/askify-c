// A Program Can Ask Qs To User, Give Facts and Show Summaries. Written in C by Akiro Sato.

#include <stdio.h>
#include <string.h>

#define MAX_Q 10
#define MAX_LEN 50

// Ask Qs to user
void askQuestions(char *questions[], char answers[][MAX_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: ", questions[i]);

        if (fgets(answers[i], MAX_LEN, stdin) != NULL) {
            answers[i][strcspn(answers[i], "\n")] = 0; // trim newline
        } else {
            answers[i][0] = '\0'; // fallback if input fails
        }
    }
}

// Display Facts
void showFacts(char *facts[], int count) {
    printf("\n--- Fun Facts ---\n");
    for (int i = 0; i < count; i++) {
        printf("> %s\n", facts[i]);
    }
}

// Display Summary
void showSummary(char *questions[], char answers[][MAX_LEN], int count) {
    printf("\n--- Summary ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s\n", questions[i], answers[i]);
    }
}

// Main Function
int main() {
    // Qs
    char *questions[] = {
        "What's your fav song?",
        "Fav anime?",
        "Fav food?",
        "What's your name?"
    };

    // Facts
    char *facts[] = {
        "Music can affect your mood.",
        "Anime is a major part of Japanese culture.",
        "Food reflects traditions and lifestyle.",
        "Names often carry cultural meaning."
    };

    int count = sizeof(questions) / sizeof(questions[0]);
    int factCount = sizeof(facts) / sizeof(facts[0]);

    // Ensure we don't exceed buffer
    if (count > MAX_Q) count = MAX_Q;

    char answers[MAX_Q][MAX_LEN];

    // Functions
    showFacts(facts, factCount);
    askQuestions(questions, answers, count);
    showSummary(questions, answers, count);

    return 0;
}