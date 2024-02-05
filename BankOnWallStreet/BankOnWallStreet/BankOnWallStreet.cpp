#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string cardNumber;
    string pinCode;
    double balance;

public:
    BankAccount(const string& cardNumber, const string& pinCode, double initialBalance)
        : cardNumber(cardNumber), pinCode(pinCode), balance(initialBalance) {}

    bool authenticate() {
        for (int i = 0; i < 3; ++i) {
            string enteredPin;
            cout << "Введите ПИН код: ";
            cin >> enteredPin;

            if (enteredPin == pinCode) {
                cout << "Успешная авторизация.\n";
                return true;
            }
            else {
                cout << "Не верный ПИН код, повторите попытку: " << 2 - i << "\n";
            }
        }

        cout << "Карта заблокирована. Для разблокировки сделайне перервод по номеру 8-917-490-00-00, в размере 1000 рублей.\n";
        return false;
    }

    void displayBalance() const {
        cout << "Ваш баланс: " << balance << "р\n";
    }

    void withdrawCash() {
        double amount;
        cout << "Введите сумму перевода: ";
        cin >> amount;

        if (amount >= 5 && amount <= balance) {
            balance -= amount;
            cout << "Успешный перевод, ваш баланс: " << balance << "р\n";
        }
        else {
            cout << "Неверная сумма или недостаточно средств.\n"; 
        }
    }

    void depositCash() {
        double amount;
        cout << "Введите сумму для депозита: ";
        cin >> amount;

        if (amount >= 5) {
            balance += amount;
            cout << "Успешное пополнение, ваш баланс: " << balance << "р\n";
        }
        else {
            cout << "Неверная сумма депозита. Депозит должен быть больше 5 рублей.\n";
        }
    }

    void payMobileBill() {
        double amount;
        cout << "Введите сумму депозита на мобильный номер: ";
        cin >> amount;

        cout << "Какой оператор у этого мобильного номера? (1 - МТС | 2 - Билайн): ";
        int operatorChoice;
        cin >> operatorChoice;

        double commissionRate = (operatorChoice == 1) ? 0.05 : 0.07;
        double totalAmount = amount * (1 + commissionRate);

        if (totalAmount <= balance) {
            balance -= totalAmount;
            cout << "Успешное пополнение мобильного. Текущий баланс: " << balance << "р\n";
        }
        else {
            cout << "Недостаточно средств.\n";
        }
    }
};

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