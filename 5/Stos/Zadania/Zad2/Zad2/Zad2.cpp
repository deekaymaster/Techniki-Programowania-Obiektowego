//Napisz program, który będzie sprawdzał, czy nawiasy w danym ciągu są poprawnie
//sparowane.Program będzie korzystał ze stosu do sprawdzenia równoważności
//nawiasów.
//Instrukcje:
//a.Utwórz klasę BracketChecker, która będzie zawierała metodę checkBrackets,
//która przyjmie jako argument ciąg znaków(np.std::string), a następnie zwróci
//true, jeśli nawiasy w ciągu są poprawnie sparowane, lub false, jeśli nie.
//b.Wewnątrz metody checkBrackets utwórz pusty stos(wykorzystując
//    std::stack<char>).
//    c.Przejdź po każdym znaku w ciągu wejściowym.
//    d.Jeśli napotkasz otwierający nawias((, [, { ), dodaj go na stos.
//    e.Jeśli napotkasz zamykający nawias(),], }), sprawdź, czy stos nie jest pusty.Jeśli
//    jest pusty, zwróć false, ponieważ znaleziono zamykający nawias bez
//    odpowiadającego mu otwierającego nawiasu.
//    f.Jeśli stos nie jest pusty, pobierz element ze stosu i sprawdź, czy odpowiada on
//    otwierającemu nawiasowi aktualnego zamykającego nawiasu.Jeśli nie
//    odpowiada, zwróć false.
//    g.Po zakończeniu iteracji po wszystkich znakach, sprawdź, czy stos jest pusty.
//    Jeśli nie jest, zwróć false, ponieważ znaleziono więcej otwierających nawiasów
//    niż zamykających.
//    h.Jeśli wszystkie nawiasy są poprawnie sparowane i stos jest pusty, zwróć true.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BracketChecker {
public:
    static bool checkBrackets(string& str) {
        stack<char> myStack;

        for (char character : str) {
            if (character == '(' || character == '[' || character == '{') {
                myStack.push(character);
            }
            else if (character == ')' || character == ']' || character == '}') {
                if (myStack.empty()) {
                    return false;
                }
                else {
                    char open = myStack.top();
                    myStack.pop();
                    if ((character == ')' && open != '(') ||
                        (character == ']' && open != '[') ||
                        (character == '}' && open != '{')) {
                        return false;
                    }
                }
            }
        }
        return myStack.empty(); // Sprawdzamy, czy stos jest pusty (wszystkie nawiasy są sparowane)
    }
};

int main()
{
    std::string test1 = "(){}[]"; // Poprawnie sparowane nawiasy
    std::string test2 = "([]{})"; // Poprawnie sparowane nawiasy
    std::string test3 = "({)}";   // Błędnie sparowane nawiasy
    std::string test4 = "(((";    // Błędnie sparowane nawiasy
    std::string test5 = ")}{(";   // Błędnie sparowane nawiasy

    std::cout << "Test 1: " << (BracketChecker::checkBrackets(test1) ? "Poprawne" : "Bledne") << std::endl;
    std::cout << "Test 2: " << (BracketChecker::checkBrackets(test2) ? "Poprawne" : "Bledne") << std::endl;
    std::cout << "Test 3: " << (BracketChecker::checkBrackets(test3) ? "Poprawne" : "Bledne") << std::endl;
    std::cout << "Test 4: " << (BracketChecker::checkBrackets(test4) ? "Poprawne" : "Bledne") << std::endl;
    std::cout << "Test 5: " << (BracketChecker::checkBrackets(test5) ? "Poprawne" : "Bledne") << std::endl;

    return 0;
}
