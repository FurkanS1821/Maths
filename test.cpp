#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
    if (x == 2) // x is prime if 2
    {
        return true;
    }

    if (x % 2 == 0) // x is not prime if is even
    {
        return false;
    }

    double sqrt = sqrtf(x);
    for (int i = 3; i <= sqrt; i += 2) // odd numbers which are 3 or higher
    {
        if (!isPrime(i)) // skip if not prime
        {
            continue;
        }

        if (x % i == 0) // not prime if can be divided
        {
            return false;
        }
    }

    return true; // prime if it passed all these tests
}

int ebob(int a, int b) // Highest common divisor
{
    int starred = 1, lastPrime = 2;
    while (a != 1 && b != 1)
    {
        if (a % lastPrime == 0 && b % lastPrime == 0)
        {
            starred = lastPrime;
            a /= lastPrime;
            b /= lastPrime;
        }
        else if (a % lastPrime == 0)
        {
            a /= lastPrime;
        }
        else if (b % lastPrime == 0)
        {
            b /= lastPrime;
        }
        else
        {
            do
            {
                lastPrime++;
            } while (!isPrime(lastPrime));
        }
    }

    return starred;
}

int ekok(int a, int b) // Lowest common factor
{
    int lastPrime = 2;
    long result = 1;
    while (a != 1 || b != 1)
    {
        if (a % lastPrime == 0 && b % lastPrime == 0)
        {
            a /= lastPrime;
            b /= lastPrime;
            result *= lastPrime;
        }
        else if (a % lastPrime == 0)
        {
            a /= lastPrime;
            result *= lastPrime;
        }
        else if (b % lastPrime == 0)
        {
            b /= lastPrime;
            result *= lastPrime;
        }
        else
        {
            do
            {
                lastPrime++;
            } while (!isPrime(lastPrime));
        }
    }

    return result;
}

void askForEkokEbob()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "H.C.D.: " << ebob(a, b) << ", L.C.F.: " << ekok(a, b) << endl;
}

void askForPrimeNumber()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;
    cout << x << " is " << (!isPrime(x) ? "not" : "") << " prime." << endl;
}

int main()
{
    askAgain:
    cout << "What do you want to get? (E: HCD/LCF, A: prime number): ";
    char x;
    cin >> x;
    if (x == 'E' || x == 'e')
    {
        askForEkokEbob();
    }
    else if (x == 'A' || x == 'a')
    {
        askForPrimeNumber();
    }
    else
    {
        goto askAgain;
    }
    return 0;
}