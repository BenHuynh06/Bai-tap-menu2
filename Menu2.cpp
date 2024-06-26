#include <stdio.h>
#include <stdbool.h>

void input(int *n);
bool isLeapYear(int);
bool Date(int day, int month, int year);
void printFibonacci(int);
void userChoice(int, int);
void inputDate(int *day, int *month, int *year);
bool evenNumbers(int n);
int sumEven(int n);

int main () {
    int n, choice;
    // choice = n = 0;
    userChoice (choice, n);
    return 0;
}

void userChoice(int choice, int n) {
    do {
        printf ("\n1 - Fibonacci sequence.\n");
        printf ("2 - Check a date.\n");
        printf ("3 - Sum of even integers from 0 to n.\n");
        printf ("4 - Quit.\n");
        printf ("Please choose 1 operation: ");
        scanf ("%d", &choice);
        
        switch (choice) {
            case 1:
                do {
                    input (&n);
                } while (n < 0);
                if (n > 0) {
                    printFibonacci(n);
                } else {
                    printf ("Nhap so nguyen duong.\n");
                }
            break;
            
            case 2:
                int day, month, year;
                do {
                    inputDate(&day, &month, &year);
                } while (n < 0);
                if (Date(day, month, year)) {
                    printf ("Ngay thang hop le.\n");
                } else {
                    printf ("Ngay thang khong hop le.\n");
                }
            break;
            
            case 3: 
                do {
                    input (&n);
                } while (n < 0);
                if (n > 0) {
                    sumEven(n);
                } else {
                    printf ("Loi!");
                }
            break;
            
            case 4:
                printf ("Bye Bye!");
            break;
            
            default: 
                printf ("Khong the thuc hien.\n");
                break;
        }
    } while (choice != 4);
}

void input (int *n) {
    printf ("Nhap so nguyen duong: ");
    scanf ("%d", n);
}

void printFibonacci(int n) {
    int a = 0, b = 1, next;
    printf ("Day so Fibonacci: ");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        printf ("%d", next);
    }
    printf ("\n");
}

// Check nam nhuan
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

// check ngay thang
bool Date(int day, int month, int year) {
    // kiem tra nam
    if (year < 1) {
        return false;
    }

    // kiem tra thang
    if (month < 1 || month > 12) {
        return false;
    }

    // So ngay trong tung thang
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // kiem tra nam nhuan
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    // kiem tra ngay
    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }

    return true;
}

void inputDate(int *day, int *month, int *year) {
    printf("Nhap ngay: ");
    scanf("%d", day);
    printf("Nhap thang: ");
    scanf("%d", month);
    printf("Nhap nam: ");
    scanf("%d", year);
}

int sumEven(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += i;
        } 
    }
    printf ("Sum even = %d", sum);
     if (n<0) {
        printf ("n > 0");
    }
    return sum;
}
