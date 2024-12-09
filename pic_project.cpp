#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_password_strong(char password[]) 
{
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length = strlen(password);

    for (int i = 0; i < length; i++) 
	{
        if (isupper(password[i])) has_upper = 1;  
        if (islower(password[i])) has_lower = 1;  
        if (isdigit(password[i])) has_digit = 1;  
        if (strchr("!@#$%^&*()_+-=,./<>?;:'\"[]{}|", password[i])) has_special = 1; 
    }

    if (length < 8) {
        printf("Your password is too short! It needs to be at least 8 characters.\n");
        return 0;
    }
    if (!has_upper) {
        printf("Your password needs at least one uppercase letter (like A, B, C).\n");
        return 0;
    }
    if (!has_lower) {
        printf("Your password needs at least one lowercase letter (like a, b, c).\n");
        return 0;
    }
    if (!has_digit) {
        printf("Your password needs at least one number (like 1, 2, 3).\n");
        return 0;
    }
    if (!has_special) {
        printf("Your password needs at least one special character (like @, #, !).\n");
        return 0;
    }

    printf("Great! Your password is strong.\n");
    return 1;
}

int main() 
{
    char password[100];
    printf("Hello! Let's make your password strong.\n");

    while (1) 
	{
        printf("Enter your password: ");
        scanf("%s", password);
        if (is_password_strong(password)) 
		{
            break;  
        }
    }

    return 0;
}
