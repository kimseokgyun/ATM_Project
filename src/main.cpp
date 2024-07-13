#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <fstream>
#include <yaml-cpp/yaml.h>

#define default_mode 
// #define testcase

class Account {
public:
    Account(int balance = 0) : balance(balance) {}
    
    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        if (amount < 0) {
            throw std::invalid_argument("입금금액은 음수일수 없습니다.");
        }
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount < 0) {
            throw std::invalid_argument("출금금액은 음수일수 없습니다");
        }
        if (amount > balance) {
            throw std::invalid_argument("잔액부족");
        }
        balance -= amount;
    }

private:
    int balance;
};

class Bank {
public:
    bool validatePIN(const std::string& cardNumber, const std::string& pin) {
        // Pin correct == true , incorrect ==false
        return cardData[cardNumber].first == pin;
    }

    bool accountExists(const std::string& cardNumber) const {
        return cardData.find(cardNumber) != cardData.end();
    }

    Account& getAccount(const std::string& cardNumber) {
        //return Pin String
        return cardData[cardNumber].second;
    }

    void addCard(const std::string& cardNumber, const std::string& pin, int initialBalance) {
        cardData[cardNumber] = std::make_pair(pin, Account(initialBalance));
    }

private:
    std::unordered_map<std::string, std::pair<std::string, Account>> cardData;
};

class ATMController {
public:
    ATMController(Bank& bank) : bank(bank), currentAccount(nullptr) {}

    void insertCard(const std::string& cardNumber) {
        this->cardNumber = cardNumber;
    }

    bool enterPIN(const std::string& pin) {
        if (bank.validatePIN(cardNumber, pin)) {
            currentAccount = &bank.getAccount(cardNumber);
            return true;
        }
        return false;
    }

    int seeBalance() const {
        ensureAuthenticated();
        return currentAccount->getBalance();
    }

    void deposit(int amount) {
        ensureAuthenticated();
        currentAccount->deposit(amount);
    }

    void withdraw(int amount) {
        ensureAuthenticated();
        currentAccount->withdraw(amount);
    }

    void transfer(const std::string& toCardNumber, int amount) {
        ensureAuthenticated();
        if (!bank.accountExists(toCardNumber)) {
            throw std::invalid_argument("잘못된 계좌번호");
        }
        currentAccount->withdraw(amount);
        bank.getAccount(toCardNumber).deposit(amount);
    }


private:
    void ensureAuthenticated() const {
        if (!currentAccount) {
            throw std::runtime_error("No authenticated account");
        }
    }

    Bank& bank;
    std::string cardNumber;
    Account* currentAccount;
};

void loadCustomers(const std::string& filename, Bank& bank) {
    YAML::Node customers = YAML::LoadFile(filename);
    for (const auto& customer : customers["customers"]) {
        std::string cardNumber = customer["card_number"].as<std::string>();
        std::string pin = customer["pin"].as<std::string>();
        int initialBalance = customer["initial_balance"].as<int>();
        bank.addCard(cardNumber, pin, initialBalance);
    }
}

int main() {



    Bank bank;
    // Load customers from YAML file
    loadCustomers("customers.yaml", bank);

    ATMController atm(bank);

    #ifndef testcase
     while (true) {
        std::string cardNumber;
        std::cout << "카드번호를 입력하세요: ";
        std::cin >> cardNumber;

        atm.insertCard(cardNumber);
        
        std::string pin;
        std::cout << "PIN 입력하세요: ";
        std::cin >> pin;

        if (atm.enterPIN(pin)) {
            std::cout << "PIN is correct." << std::endl;
            
            int choice;

            while (true) {
                std::cout << "\nSelect an option:\n";
                std::cout << "[1] 입금\n";
                std::cout << "[2] 출금\n";
                std::cout << "[3] 잔금확인\n";
                std::cout << "[4] 송금하기\n";
                std::cout << "[5] 나가기\n";
                std::cout << "Enter choice: ";
                std::cin >> choice;

                if (choice == 1) {
                    int amount;
                    std::cout << "입금금액: ";
                    std::cin >> amount;
                    atm.deposit(amount);
                    std::cout << "입금 $" << amount << ". 현재잔고: $" << atm.seeBalance() << std::endl;
                } else if (choice == 2) {
                    int amount;
                    std::cout << "출금금액: ";
                    std::cin >> amount;
                    try {
                        atm.withdraw(amount);
                        std::cout << "출금: $" << amount << ". 현재잔고: $" << atm.seeBalance() << std::endl;
                    } catch (const std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                } else if (choice == 3) {
                    std::cout << "현재잔고 $" << atm.seeBalance() << std::endl;
                } else if (choice == 4) {
                    std::string toCardNumber;
                    int amount;
                    std::cout << "송금할 계좌번호: ";
                    std::cin >> toCardNumber;
                    std::cout << "송금할 금액: ";
                    std::cin >> amount;
                    try {
                        atm.transfer(toCardNumber, amount);
                        std::cout << "송금: $" << amount << " to " << toCardNumber << ". 현재잔고: $" << atm.seeBalance() << std::endl;
                    } catch (const std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                } else if (choice == 5) {
                    std::cout << "나가기를 선택하셨습니다. 다시 시작하려면 새 카드번호를 입력하세요.\n";
                    break;
                } else {
                    std::cout << "잘못된 옵션 선택" << std::endl;
                }
            }
        } else {
            std::cout << "잘못된 PIN번호" << std::endl;
        }
    }
    #endif

    #ifdef testcase
    std::string test_cardNumber="1234-5678-9876-5432";
    std::string test_pin = "5432";
    atm.insertCard(test_cardNumber);
    atm.enterPIN(test_pin);
    

    test_cardNumber="1234-5678-9876-5432";
    test_pin = "1234";
    atm.insertCard(test_cardNumber);
    atm.enterPIN(test_pin);
    atm.deposit(50000);
    atm.transfer("2345-6789-8765-4321", 50000);
    test_cardNumber="2345-6789-8765-4321";
    test_pin = "5678";
    atm.insertCard(test_cardNumber);
    atm.enterPIN(test_pin);
    atm.seeBalance();
    #endif

    return 0;
}