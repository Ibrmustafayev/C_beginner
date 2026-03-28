#include <stdio.h>

struct Student {
    char name[50];
    int grades[3];
};

void add_student(struct Student *students, int std_num);
void show_all_students(struct Student *students, int std_num);
float find_average(int grades[]);
void show_sorted_by_average(struct Student *students, int std_num, float *averages, int *indexes);
void show_strst_wkst(struct Student *students, int std_num, float *averages, int *indexes, int is_sorted);

int main() {
    int std_num = 0, is_sorted = 0;
    struct Student students[30] = {};
    float averages[30];
    int indexes[30];
    while(1) {
        printf("\n\n=== Menu ===\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Show sorted by average\n");
        printf("4. Show strongest & weakest\n");
        printf("5. Exit\n");
        char choice;
        printf("\nChoice: ");
        scanf(" %c", &choice);
        if (choice == '5') {printf("Goodbye!!!"); break;}
        else if (choice == '1') {add_student(students, std_num); std_num++;}
        else if (choice == '2') {show_all_students(students, std_num);}
        else if (choice == '3') {show_sorted_by_average(students, std_num, averages, indexes); is_sorted = 1;}
        else if (choice == '4') {show_strst_wkst(students, std_num, averages, indexes, is_sorted);}
        else {printf("Error: invalid choice option.");}
    }
}

void add_student(struct Student *students, int std_num) {
    if (std_num >= 30) {
        printf("Error: database is full.");
    } else {
        printf("\nName:   ");
        fgets(&students[std_num].name, 50, stdin);
        students[std_num].name[strcspn(students[std_num].name, "\n")] = '\0';
        printf("Grades: ");
        for (int i = 0; i < 3; i++) {scanf("%d", &students[std_num].grades[i]);}
    }
}

void show_all_students(struct Student *students, int std_num) {
    if (std_num != 0) {
        printf("\n");
        for(int i = 0; i < std_num; i++) {
            printf("%d. %s [%d|%d|%d]\n", i + 1, students[i].name, students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        }
    } else {
        printf("Please, add student first.");
    }
}

float find_average(int grades[]) {
    return (grades[0] + grades[1] + grades[2]) / 3.0f;
}

void show_sorted_by_average(struct Student *students, int std_num, float *averages, int *indexes) {
    if (std_num != 0) {
        for (int i = 0; i < std_num; i++) {averages[i] = find_average(students[i].grades); indexes[i] = i;}
    
        for (int i = 0; i < std_num - 1; i++) {
            int max_idx = i;
            for (int j = i + 1; j < std_num; j++) {
                if (averages[j] > averages[max_idx]) {
                    max_idx = j;
                }
            }
            if (max_idx != i) {
                float transit = averages[i];
                averages[i] = averages[max_idx];
                averages[max_idx] = transit;

                int transit_index = indexes[i];
                indexes[i] = indexes[max_idx];
                indexes[max_idx] = transit_index;
            }
        }
        for (int i = 0; i < std_num; i++) {printf("%d. %s (avg: %.2f)\n", i + 1, students[indexes[i]].name, averages[i]);}
    } else {
        printf("Please, add student first.");
    }
}

void show_strst_wkst(struct Student *students, int std_num, float *averages, int *indexes, int is_sorted) {
    if (is_sorted) {
        printf("The strongest: %s (avg: %.2f)", students[indexes[0]].name, averages[0]);
        printf("\nThe weakest:   %s (avg: %.2f)", students[indexes[std_num - 1]].name, averages[std_num - 1]);
    } else {
        printf("Please, sort first");
    }
}
