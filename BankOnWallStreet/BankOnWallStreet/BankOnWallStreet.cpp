#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(0, "");
    BankAccount account("1234567890123456", "1234", 30000);

    if (account.authenticate()) {
        int choice;
        do {
            cout << "\nвыберите операцию:\n"
                << "1. Показать текущий баланс\n"
                << "2. Снять наличные\n"
                << "3. Внести депозит\n"
                << "4. Оплатить мобильные услуги оператора\n"
                << "5. Выход\n";

            cin >> choice;

            switch (choice) {
            case 1:
                account.displayBalance();
                break;
            case 2:
                account.withdrawCash();
                break;
            case 3:
                account.depositCash();
                break;
            case 4:
                account.payMobileBill();
                break;
            case 5:
                cout << "Выход... Спасибо!\n";
                break;
            default:
                cout << "Не верный выбор операции.\n";
            }
        } while (choice != 5);
    }

    return 0;
}