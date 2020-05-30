#include "UnitOfView.h"

void UnitOfView::MenuSelect(char choice) 
{
    switch (choice)
    {
        case '1':
            _signInUpView.RenderLoginView();
            break;

        case '2':
            _signInUpView.RenderRegisterView();
            break;

        case '3':
            exit(0);
            break;

        default: 
            cout << "Nie ma takiej opcji w menu!";
    };

    system("cls");
}