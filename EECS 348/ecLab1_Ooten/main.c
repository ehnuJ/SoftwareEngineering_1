#include <stdio.h>

// Preferences of each department for each programmer
const int department_preferences[5][5] = {
    {1, 5, 3, 2, 4},
    {1, 3, 4, 2, 5},
    {3, 4, 2, 5, 1},
    {3, 1, 2, 4, 5},
    {4, 3, 1, 2, 5}
};

// Preferences of each programmer for each department
const int programmer_preferences[5][5] = {
    {3, 1, 2, 5, 4},
    {4, 3, 1, 5, 2},
    {2, 5, 4, 1, 3},
    {4, 5, 2, 1, 3},
    {3, 2, 1, 5, 4},
};

// Varible for whether or not a programmer has been assigned to a department
int assigned[5] = {0, 0, 0, 0, 0};

// The department assigned to each programmer
int assignments[5] = {-1, -1, -1, -1, -1};

// Returns the index of the first unassigned programmer on a department's preference list
int get_unassigned_programmer(int department) {
    for (int i = 0; i < 5; i++) {
        int programmer = department_preferences[department][i] - 1;
        if (assigned[programmer] == 0) {
            return programmer;
        }
    }
    return -1;
}

// Assigns a programmer to a department
void assign_programmer(int programmer, int department) {
    assigned[programmer] = 1;
    assignments[department] = programmer;
}

int main() {
    // Assign each department their top choice
    for (int i = 0; i < 5; i++) {
        int programmer = get_unassigned_programmer(i);
        assign_programmer(programmer, i);
    }
    
    // Organizes priorities and rearranges the assignments to match preferences
    for (int i = 0; i < 5; i++) {
        if (assigned[i] == 0) {
            for (int j = 0; j < 5; j++) {
                if (programmer_preferences[i][j] == assignments[j]) {
                    int current_programmer = assignments[j];
                    assign_programmer(i, j);
                    assigned[current_programmer] = 0;
                    break;
                }
            }
        }
    }
    
    // Prints assignments
    for (int i = 0; i < 5; i++) {
        printf("Department #%d will get Programmer #%d\n", i + 1, assignments[i] + 1);
    }
    
    return 0;
}